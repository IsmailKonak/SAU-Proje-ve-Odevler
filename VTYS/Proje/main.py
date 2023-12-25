import os 
import sys
import time
import psycopg2
import getpass
import ast
import re 
import csv 
from io import StringIO
from AddContent import AddContent
from AddQuiz import AddQuiz
import openai
import json

# openai.api_base = 'https://api.endpoints.anyscale.com/v1'
openai.api_key = "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"

conn = psycopg2.connect(
    host="localhost",
    database="ProjeYeniTest",
    user="postgres",
    password="Migennes1")

cur = conn.cursor()

# Resetting THE DATABASE
sql_files = ["CreateTables.sql", "CreateFunctions.sql", "CreateTriggers.sql", "CreateStoredProcedures.sql", "OdevIcinVeriler.sql"]
for file in sql_files:
    with open(file, 'r') as f:
        cur.execute(f.read())
        conn.commit()
        f.close()
AddContent()
AddQuiz()

class TutorBot():

    #GLOBAL VARIABLES
    def __init__(self):
        self.is_logged_in = False
        self.user_id = -1
        self.konu_id = -1
        self.alt_baslik_id = -1
        self.egitim_quiz = -1

    # Güncelleme
    def sifremi_unuttum(self):
        os.system('cls')
        print("Şifremi unuttum ekranına hoş geldiniz.")
        print("Lütfen mail adresinizi giriniz.")
        email = input("Email: ")
        yeni_sifre = getpass.getpass("Yeni şifreniz: ")
        try:
            cur.execute(f"CALL \"ChangePassword\"('{email}', '{yeni_sifre}')")    
            print("Şifreniz güncellendi. Giriş yapma ekranına gidiliyor...")
            time.sleep(1)
            self.oturum_ac()
        except:
            print("Böyle bir mail adresi bulunamadı.")
            getpass.getpass("Devam etmek için bir tuşa basınız...")
            self.main()
        
    def sinav_sonuclarimi_listele(self):
        print("\n Sınav Sonuçlarınız: \n")
        SQL = f"""SELECT ("User"."Username","Quiz"."quiz_name","UserQuizResult"."ScoreinPercentage","UserQuizResult"."AttempDate") FROM "UserQuizResult" RIGHT OUTER JOIN "User" ON "User"."user_id" = "UserQuizResult"."user_id" INNER JOIN "Quiz" ON "Quiz"."quiz_id" = "UserQuizResult"."quiz_id" WHERE "User"."user_id" = {self.user_id};"""
        cur.execute(SQL)
        fetch = cur.fetchall()
        print("Kullanıcı Adı - Quiz Adı - Puan - Tarih")
        print("----------------------------------------")
        for row in fetch:
            isim, quiz_name, score, tarih = self.parse_out(row)
            print(f"{isim} - {quiz_name} - {score} - {tarih}")
        getpass.getpass("Devam etmek için bir tuşa basınız...")
        self.ana_menu()

    def kullanici_ismi(self):
        cur.execute(f"SELECT \"Username\" FROM \"User\" WHERE \"user_id\" = {self.user_id}")
        fetch = cur.fetchall()
        kullanici_ismi = fetch[0][0]
        return kullanici_ismi

    def kullanici_email(self):
        cur.execute(f"SELECT \"Email\" FROM \"User\" WHERE \"user_id\" = {self.user_id}")
        fetch = cur.fetchall()
        kullanici_email = fetch[0][0]
        return kullanici_email
    # Silme
    def hesabi_sil(self):
        os.system('cls')
        print("Hesabınızı silmek istediğinize emin misiniz? (e/H)")
        input1 = input(">>> ")
        if input1.lower() == "e":
            print("Hesabınız silinmesi için bilgileriniz kontrol ediliyor...")
            email = input("Email: ")
            password = getpass.getpass("Password: ")
            cur.execute(f"CALL \"DeleteMyAccount\"('{email}','{password}')")
            conn.commit()
            print("Hesabınız silindi. Ana menüye dönülüyor...")
            time.sleep(1)
            self.is_logged_in = False
            self.user_id = -1
            self.konu_id = -1
            self.alt_baslik_id = -1
            self.egitim_quiz = -1
        else:   
            print("İşlem iptal edildi. Ana menüye dönülüyor...")
            time.sleep(1)
            self.ana_menu()
    # Arama
    def konu_ara(self):
        os.system('cls')
        print("Lütfen aramak istediğiniz konuyu giriniz: ")
        arama = input(">>> ")
        cur.execute(f"SELECT (\"subject_name\",\"subject_id\") FROM \"Subject\" WHERE \"subject_name\" LIKE '%{arama}%'")
        rows = cur.fetchall()
        for row in rows:
            isim, id = self.parse_out(row)
            print(f"{id} - {isim}")
        if len(rows) == 0:
            print("Aradığınız konu bulunamadı.")
        else:
            print("Bu konuda eğitim almak ister misiniz? (E/h)")
            input1 = input(">>> ")
            if input1 == "E":
                self.konu_id = id
                self.alt_baslik_sec()
                self.tercih_yap()   

    def verilebilir_subjectler(self):
        print("Aşağıdaki konularda eğitim alabilirsiniz: ")
        cur.execute(f"SELECT (\"subject_name\",\"subject_id\") FROM \"Subject\"")
        rows = cur.fetchall()
        for row in rows:
            isim, id = self.parse_out(row)
            print(f"{id} - {isim}")

    def parse_out(self, string):
        string = str(string)
        without_beg  = string.replace("('(","")
        without_end = without_beg.replace(")',)","") 
        reader = csv.reader(StringIO(without_end))
        parsed = next(reader)
        for i in range(len(parsed)):
            parsed[i] = parsed[i].replace('"', "")
            try:
                parsed[i] = int(parsed[i])
            except:
                pass
        return parsed

    def verilebilir_basliklar(self, subject_id):
        os.system('cls')
        cur.execute(f"SELECT (\"topic_id\",\"TopicName\",\"TopicDescription\") FROM \"Topic\" WHERE \"subject_id\" = {subject_id}")
        rows = cur.fetchall()
        for row in rows:
            id, isim, aciklama, = self.parse_out(row)
            print(f"{id} - {isim} - {aciklama}")

    def oturum_ac(self):
        os.system('cls')
        print("Oturum açma ekranına hoş geldiniz.")
        email = input("Email: ")
        password = getpass.getpass("Password: ")
        cur.execute(f"SELECT \"AuthenticateUser\"('{email}','{password}')")
        fetch = cur.fetchall()
        result = int(fetch[0][0])
        if result != -1:
            print("Başarılı bir şekilde giriş yaptınız.")
            time.sleep(1)
            self.is_logged_in = True
            self.user_id = result
        else:
            os.system('cls')
            print("Böyle bir kullanıcı bulunamadı.")
            print("Tekrar denemek için 1'e basınız")
            print("Şifremi unuttum için 2'e basınız")
            print("Ana menüye dönmek için herhangi bir tuşa basınız.")
            input1 = input(">>> ")
            if input1 == "1":
                self.oturum_ac()
            elif input1 == "2":
                self.sifremi_unuttum()
            else:   
                self.main()
    # Ekleme
    def kayit_ol(self):
        os.system('cls')
        username = input("Username: ")
        email = input("Email: ")
        password = getpass.getpass("Password: ")
        cur.execute(f"CALL \"SignUp\"('{username}', '{email}', '{password}');")
        conn.commit()
        cur.execute(f"SELECT \"AuthenticateUser\"('{email}','{password}')")
        fetch = cur.fetchall()
        id = int(fetch[0][0])
        print("Kayıt başarılı bir şekilde tamamlandı.")
        print("Profiliniz hakkında ek bilgi girmek ister misiniz? (E/h)")
        input1 = input(">>> ")
        print(input1)
        print(input1.lower())
        os.system('PAUSE')
        if input1.lower() == "e":
            self.profil_ek_bilgiler(id)

    def profil_ek_bilgiler(self, user_id):
        # Öğrenci mi?
        print("Lütfen aşağıdaki bilgileri doldurunuz.")
        print("Öğrenci misiniz? (E/h)")
        input1 = input(">>> ")
        okul_seviyesi = ""
        if input1.lower() == "e":
            print("1) İlköğretim")
            print("2) Ortaöğretim")
            print("3) Yükseköğretim")
            okul_seviyesi = input(">>> ")
            if okul_seviyesi == "1":
                print("Okulunuzun adı: ")
                okul_adi = input(">>> ")
                print("Sınıfnız: ")
                sinif = int(input(">>> "))
                cur.execute(f"CALL \"AdditionalUserInfoPHS\"({user_id},'PSS','{okul_adi}',{sinif})")
                conn.commit()
            elif okul_seviyesi == "2":
                print("Lisenizin adı: ")
                okul_adi = input(">>> ")
                print("Sınıfnız: ")
                sinif = int(input(">>> "))
                cur.execute(f"CALL \"AdditionalUserInfoPHS\"({user_id},'HSS','{okul_adi}',{sinif})")
                conn.commit()
            elif okul_seviyesi == "3":
                print("Üniversitenizin adı: ")
                okul_adi = input(">>> ")
                print("Bölümünüz: ")
                bolum = input(">>> ")
                print("Sınıfnız: ")
                sinif = int(input(">>> "))
                cur.execute(f"CALL \"AdditionalUserInfoCS\"({user_id},'{okul_adi}','{bolum}',{sinif})")
                conn.commit()
        # Adres bilgileri
        print("Adresinizi giriniz: ")
        print("Ülke: ")
        ulke = input(">>> ")
        print("Şehir: ")
        sehir = input(">>> ")
        print("Mahalle: ")
        mahalle = input(">>> ")
        print("Cadde: ")
        cadde = input(">>> ")
        
        cur.execute(f"CALL \"AddAddressInfo\"({user_id},'{cadde}','{mahalle}','{sehir}','{ulke}')")
        conn.commit()
        print("Print bilgileriniz kaydedildi. Ana menüye dönülüyor...")
        time.sleep(1)

    def konu_sec(self):
        os.system('cls')
        print("Eğitim Sistemine Hoş Geldiniz !")
        print("1) Konu Ara")
        print("2) Konu Seç")
        print("3) Ana Menüye Dön")
        input1 = input(">>> ")
        if input1 == "1":
            self.konu_ara()
        elif input1 == "2":
            self.verilebilir_subjectler()
            print("\n Lütfen bir konu seçiniz: ")
            self.konu_id = int(input(">>> "))
            self.alt_baslik_sec()
            self.tercih_yap()

        elif input1 == "3":
            self.ana_menu()
       
    def alt_baslik_sec(self):
        os.system('cls')
        self.verilebilir_basliklar(self.konu_id)
        print("\n Lütfen bir alt başlık seçiniz: ")
        print("(Bir önceki aşamaya dönmek için '0' ı seçiniz.)")
        self.alt_baslik_id = int(input(">>> "))
        if self.alt_baslik_id == 0:
            self.konu_sec()
    
    def egitim_al(self):
        os.system('cls')
        cur.execute(f"SELECT (\"ContentName\",\"ContentText\") FROM \"Content\" WHERE \"topic_id\" = {self.alt_baslik_id}")
        fetch = cur.fetchall()
        for row in fetch:
            isim, text = self.parse_out(row)
            print(f"{isim}: \n{text}")
            getpass.getpass("Devam etmek için bir tuşa basınız...")
            os.system('cls')
    
    def find_float_numbers(self, text):
        # Use regex to find all floating-point numbers in the text
        float_numbers = re.findall(r'\b\d+\.\d+\b', text)
        return [float(number) for number in float_numbers]

    def cevap_kontrol(self,kullanici_cevap, dogru_cevap):
        format_instructions = """\
        The output should be a markdown code snippet formatted in the following schema, including the leading and trailing "```json" and "```":

                    ```json
                    {
                            "positive": float  // return the positivity value
                    }
                    ```
        """
        prompt = f"""
                    You are a text comparison assistant. Your task is to compare two pieces of text and determine if they are equivalent or not. The first text is the correct answer, and the second text is the user's answer. Please provide a value or indication that reflects the degree of similarity between the two texts. Here is the information:
                    Correct Answer:
                    {dogru_cevap}
                    User's Answer:
                    {kullanici_cevap}

                    Now, analyze the user's answer and compare it with the correct answer. Consider various aspects such as semantic meaning, context, and language structure. After the analysis, provide a response or value that indicates whether the user's answer is true or not. If the user's answer is accurate, mention that it is correct; otherwise, specify the degree of inaccuracy or any differences you observe.
                    Note: Please make sure to focus on the content and meaning rather than superficial differences. Provide a detailed assessment, and if possible, suggest improvements or corrections. Thank you!
                    {format_instructions}
                    """
        
        llama = "meta-llama/Llama-2-70b-hf"
        gpt = "gpt-3.5-turbo-1106"
        chat_completion = openai.ChatCompletion.create(
        model=gpt,
        messages=[{"role": "user", "content": prompt}],
        temperature=0.5
        )
        result = chat_completion.choices[0].message.content
        return round(self.find_float_numbers(result)[0])

    def single_output_sql(self, sql):
        cur.execute(sql)
        fetch = cur.fetchall()
        return fetch[0][0]

    def profil(self):
        os.system('cls')
        print("\t Profil")
        print(f"Kullanıcı adı: ", self.kullanici_ismi())
        print(f"Email: ", self.kullanici_email())
        try:
            okul_ismi = self.single_output_sql(f"SELECT \"GetUserSchoolInfo\"({self.user_id}, 'school_name')")
            print(f"Okul: ", okul_ismi)
            school_type = self.single_output_sql(f"SELECT \"UserType\" FROM \"User\" WHERE \"user_id\" = {self.user_id}")
            if (school_type == "PSS" or school_type == "HSS"):
                sinif = self.single_output_sql(f"SELECT \"GetUserSchoolInfo\"({self.user_id}, 'grade')")
                print(f"Sınıf: ", sinif)
            elif school_type == "CSS":
                bolum = self.single_output_sql(f"SELECT \"GetUserSchoolInfo\"({self.user_id}, 'field')")
                print(f"Bölüm: ", bolum)
                sinif = self.single_output_sql(f"SELECT \"GetUserSchoolInfo\"({self.user_id}, 'grade')")
                print(f"Sınıf: ", sinif)
            cur.execute(f"SELECT (\"FullAddressText\") FROM \"Address\" WHERE \"address_id\" = (SELECT \"address_id\" FROM \"User\" WHERE \"user_id\" = {self.user_id})")
            fetch = cur.fetchall()
            adres = fetch[0][0]
            print(f"Adres: ", adres)
        except:

            print("Okul: ")
            print("Sınıf: ")
            print("Adres: ")
        
        self.sinav_sonuclarimi_listele()
        getpass.getpass("Devam etmek için bir tuşa basınız...")

    def sinava_gir(self):
        os.system('cls')
        cur.execute(f"SELECT (\"quiz_name\",\"quiz_id\") FROM \"Quiz\" WHERE \"topic_id\" = {self.alt_baslik_id}")
        fetch = cur.fetchall()
        isim,quiz_id = self.parse_out(fetch[0])
        print(f"{isim} quizine hoş geldiniz!")
        print("Quiz başlıyor...")
        time.sleep(2)
        #sorular
        cur.execute(f"SELECT (\"question_id\",\"question_text\") FROM \"Question\" WHERE \"quiz_id\" = {quiz_id}")
        fetch = cur.fetchall()
        sorular = []
        for row in fetch:
            soru_id, soru = self.parse_out(row)
            sorular.append({"soru_id": soru_id, "soru": soru})
        #cevaplar
        cevaplar = []
        for soru in sorular:
            cur.execute(f"SELECT (\"answer_id\",\"answer_text\") FROM \"Answer\" WHERE \"question_id\" = {soru['soru_id']}")
            fetch = cur.fetchall()
            for row in fetch:
                cevap_id, cevap = self.parse_out(row)
                cevaplar.append({"cevap_id": cevap_id, "cevap": cevap})        
        #quiz
        
        Sonuclar = []
        for i,soru in enumerate(sorular):
            os.system('cls')
            print(soru["soru"])
            kullanici_cevap = input(">>> ")
            result = self.cevap_kontrol(kullanici_cevap, cevaplar[i]["cevap"])
            cur.execute(f"""INSERT INTO \"UserAnswer\"(\"user_id\", \"answer_id\", \"UserAnswerText\",\"AnswerScore\") 
                        VALUES ({self.user_id}, {cevaplar[i]['cevap_id']}, '{kullanici_cevap}', {result})""")
            conn.commit()
            Sonuclar.append(result)
        print("Quiz bitti. Sonuçlarınız hesaplanıyor...")
        time.sleep(2)
        print(f"Sonuçlarınız: {sum(Sonuclar)}/{len(Sonuclar)}")
        cur.execute(f"""INSERT INTO \"UserQuizResult\"(\"user_id\", \"quiz_id\", \"Score\", \"AttempDate\") 
                        VALUES ({self.user_id}, {quiz_id}, {sum(Sonuclar)/len(Sonuclar)}, CURRENT_DATE)""")
        conn.commit()
        print("Ana menüye dönmek için bir tuşa basınız...")
        getpass.getpass(">>> ")

    def cikis_yap(self):
        self.is_logged_in = False
        self.user_id = -1
        self.konu_id = -1
        self.alt_baslik_id = -1
        self.egitim_quiz = -1
        print("Çıkış yapılıyor...")
        time.sleep(1)
        print("Çıkış başarılı. Hoşçakalın.")
        self.main()

    def tercih_yap(self):
        os.system('cls')
        print("Bu altbaşlık hakkında bilgi almak isterseniz '1' yi seçiniz.")
        print("Herhangi bir bilgi almadan sınava girmek için ise '2' yi seçiniz.")
        print("Geriye dönmek için '0' ı seçiniz.")
        input2 = input(">>> ")
        if (input2 == "1"):
            self.egitim_al()
            print("Eğitim bitti. Dilerseniz Quize geçebilirsiniz (Y/h)")
            e = input(">>> ")
            if e != "h":
                self.sinava_gir()
            

        elif (input2 == "2"):
            self.sinava_gir()

        elif (input2 == "0"):
            self.alt_baslik_sec()
            self.tercih_yap()

    def ana_menu(self):
        os.system('cls')
        print(f"\n Hoş geldiniz {self.kullanici_ismi()} !")
        print("1. Eğitim Al")
        print("2. Profil")
        print("3. Hesabımı sil")
        print("4. Çıkış Yap")
        sec = input(">>> ")
        if sec == "1":
            self.konu_sec()
        elif sec == "2":
            self.profil()
        elif sec == "3":
            self.hesabi_sil()
            self.main()
        elif sec == "4":
            self.cikis_yap()
        else:
            self.ana_menu()

        self.ana_menu()

    def main(self):
        os.system('cls')
        print("\n TutorBot sistemine hoş geldiniz !")
        print("Öncelikle lütfen giriş yapınız.")
        print("1. Giriş yap")
        print("2. Şifremi Unuttum")    
        print("3. Kayıt ol")
        print("Çıkmak için 'q' ya basınız.")
        input1 = input(">>> ")
        if (input1 == "1"):
            self.oturum_ac()
        elif (input1 == "2"):
            self.sifremi_unuttum()
        elif (input1 == "3"):
            print("Kayıt ol")
            self.kayit_ol()
            self.oturum_ac()
        elif (input1 == "q"):
            sys.exit()
        
        self.ana_menu()


TutorialBot = TutorBot()
TutorialBot.main()
