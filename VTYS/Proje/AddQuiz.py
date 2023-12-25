
import psycopg2

def AddQuiz():
    
    conn = psycopg2.connect(
        host="localhost",
        database="ProjeYeniTest",
        user="postgres",
        password="Migennes1")

    cur = conn.cursor()

    # Güneş Sistemi Quiz - Güneş
    gunes_quiz_gunes = [
        {"question": "Güneş, güneş sisteminin merkezinde bulunan nedir?", "answer": "Devasa bir yıldız"},
        {"question": "Güneş, enerji üretmek için hangi reaksiyonları kullanır?", "answer": "Termonükleer reaksiyonlar"},
        {"question": "Güneş sistemindeki diğer cisimleri çeken etki nedir?", "answer": "Büyük kütleçekimi"},
    ]
    # Güneş Sistemi Quiz - Merkür
    gunes_quiz_merkur = [
        {"question": "Merkür, güneş sistemindeki en küçük gezegenlerden biridir. Doğru mu yoksa yanlış mu?", "answer": "Doğru"},
        {"question": "Merkürün atmosferi nedir?", "answer": "Neredeyse yok denecek kadar ince"},
        {"question": "Merkür, güneşe olan yakınlığı nedeniyle hangi extreme koşullara sahiptir?", "answer": "Aşırı sıcaklık ve soğuklar"},
    ]
    # Güneş Sistemi Quiz - Venüs
    gunes_quiz_venus = [
        {"question": "Venüsün atmosferinde hangi kalın tabaka bulunur?", "answer": "Karbon dioksit"},
        {"question": "Venüsün yüzeyi nasıldır?", "answer": "Volkanik dağlar, dağ benzeri yapılar"},
        {"question": "Venüsün atmosferik sıcaklıkları açısından ortamı ne kadar zorlu kılar?", "answer": "Oldukça zorlu"},
    ]
    # Güneş Sistemi Quiz - Dünya
    gunes_quiz_dunya = [
        {"question": "Dünya, bilinen tek yaşam barındıran gezegen olarak öne çıkar. Doğru mu yoksa yanlış mu?", "answer": "Doğru"},
        {"question": "Dünyanın atmosferi, yaşam için gerekli olan hangi gazı içerir?", "answer": "Oksijen"},
        {"question": "Dünyanın yüzeyi hangi çeşitli özelliklerle kaplıdır?", "answer": "Okyanuslar, dağlar, vadiler ve çeşitli iklim bölgeleri"},
    ]
    # Güneş Sistemi Quiz - Mars
    gunes_quiz_mars = [
        {"question": "Marsın yüzey rengi nedir?", "answer": "Kızılımsı"},
        {"question": "Marsın kutuplarında ne bulunduğuna dair kanıtlar vardır. Bu nedir?", "answer": "Buzlu su"},
        {"question": "Marsın atmosferi nasıldır?", "answer": "İnce, devasa vadiler, dağlar ve eski nehir yatakları bulunur"},
    ]

    gunes_quizler = [gunes_quiz_gunes, gunes_quiz_merkur, gunes_quiz_venus, gunes_quiz_dunya, gunes_quiz_mars]
    isimler_gunes = ["Güneş", "Merkür", "Venüs", "Dünya", "Mars"]

    # Yıldızlar Quiz - Yıldızlar
    # Yıldızlar Quiz
    yildizlar_quiz = [
        {"question": "Soru 1: Yıldızlar, hangi gök cisminin çekirdeğindeki nükleer reaksiyonlarla ışık ve enerji üretirler?", "answer": "Yıldızlar, gök cisminin çekirdeğindeki nükleer reaksiyonlarla ışık ve enerji üretirler."},
        {"question": "Soru 2: Kırmızı Cüceler, genellikle hangi renkte görünürler ve neden?", "answer": "Kırmızı Cüceler, daha düşük kütleli ve soğuk oldukları için genellikle kırmızı renkte görünürler."},
        {"question": "Soru 3: Beyaz Cüceler ne zaman oluşur ve ne tür bir parlaklık gösterirler?", "answer": "Beyaz Cüceler, evrimini tamamlamış ancak kırmızı cüceden daha büyük olan yıldızlardır. Çekirdeklerindeki nükleer reaksiyonlar sona erdiğinde, dış katmanları uzaya dağılır ve sadece sıcak ve yoğun bir çekirdek kalır. Bu çekirdek, beyaz renkte parlar ve beyaz cüce adını alır."}
    ]
    # Kırmızı Cüceler Quiz
    kirmizi_cuceler_quiz = [
        {"question": "Soru 1: Kırmızı Cüceler ne tür yıldızlardır?", "answer": "Kırmızı Cüceler, evrimini tamamlamış küçük yıldızlardır."},
        {"question": "Soru 2: Kırmızı Cüceler genellikle hangi renkte görünürler?", "answer": "Kırmızı Cüceler genellikle kırmızı renkte görünürler."},
        {"question": "Soru 3: Kırmızı Cüceler nasıl enerji üretirler ve nasıl varlıklarını sürdürürler?", "answer": "Kırmızı Cüceler, uzun bir süre boyunca yavaşça soğuyarak ve enerji üreterek varlıklarını sürdürürler."}
    ]
    # Beyaz Cüceler Quiz
    beyaz_cuceler_quiz = [
        {"question": "Soru 1: Beyaz Cüceler hangi evrelerden geçer?", "answer": "Beyaz Cüceler, evrimini tamamlamış ancak kırmızı cüceden daha büyük olan yıldızlardır."},
        {"question": "Soru 2: Beyaz Cüceler nasıl bir parlaklık gösterirler?", "answer": "Beyaz Cüceler, çekirdeklerindeki nükleer reaksiyonlar sona erdiğinde, dış katmanları uzaya dağılır ve sadece sıcak ve yoğun bir çekirdek kalır. Bu çekirdek, beyaz renkte parlar ve beyaz cüce adını alır."},
        {"question": "Soru 3: Beyaz Cüceler hangi evrelerden geçtikten sonra oluşurlar?", "answer": "Beyaz Cüceler, evrimini tamamlamış ancak kırmızı cüceden daha büyük olan yıldızlardır."}
    ]
    # Kırmızı Devler Quiz
    kirmizi_devler_quiz = [
        {"question": "Soru 1: Kırmızı Devler ne tür yıldızlardır?", "answer": "Kırmızı Devler, büyük kütleli yıldızların evrimin sonlarına doğru geçtikleri evrelerdir."},
        {"question": "Soru 2: Kırmızı Devlerin çekirdeklerinde ne tür nükleer reaksiyonlar devam eder?", "answer": "Kırmızı Devlerin çekirdeklerindeki nükleer reaksiyonlar devam ederken dış katmanları genişleyerek kırmızımsı bir renk alır."},
        {"question": "Soru 3: Kırmızı Devler, evrimlerini tamamladıktan sonra ne tür bir sona sahip olabilirler?", "answer": "Kırmızı Devler, büyük miktarlarda enerji üretirler ve evrimlerini tamamladıktan sonra genellikle süpernova patlamalarıyla son bulurlar."}
    ]

    yildizlar_quizler = [yildizlar_quiz, kirmizi_cuceler_quiz, beyaz_cuceler_quiz, kirmizi_devler_quiz]
    isimler_yildizlar = ["Yıldızlar", "Kırmızı Cüceler", "Beyaz Cüceler", "Kırmızı Devler"]

    # Quiz for "Karadelikler"
    karadelikler_quiz = [
        {"question": "1. Nedir, çekirdeklerinde gerçekleşen çökme sonucunda ortaya çıkarlar?", "answer": "Karadelikler"},
        {"question": "2. Karadeliklerin özellikleri arasında kütlesel çekimleri nedeniyle ışığın dahi kaçamadığı hangi bölge bulunur?", "answer": "Olay Ufku"},
        {"question": "3. Karadeliklerin sonu, hangi teoriye göre açıklanır, bu teoriye göre karadelikler kendi kütlelerini radyasyonla kaybederler ve sonunda tamamen buharlaşırlar?", "answer": "Hawking Işıması"},
    ]
    # Quiz for "Karadeliklerin Özellikleri"
    karadelikler_ozellikleri_quiz = [
        {"question": "1. Karadeliklerin özellikleri arasında kütlesel çekimleri nedeniyle ışığın dahi kaçamadığı hangi bölge bulunur?", "answer": "Olay Ufku"},
        {"question": "2. Karadelikler, çevrelerindeki maddeyi emer ve bu maddeyi çekirdeklerine çekerler. Bu özellikleriyle hangi enerji kaynağı olabilirler?", "answer": "Yüksek enerjili parçacıkların ve x ışınlarının kaynağı"},
        {"question": "3. Hangi tür karadelik, çekirdeklerindeki nükleer reaksiyonlar sona erdiğinde dış katmanları uzaya dağılır ve sadece sıcak ve yoğun bir çekirdek kalır?", "answer": "Beyaz Cüce"},
    ]
    # Quiz for "Hawking Işıması"
    hawking_isimasi_quiz = [
        {"question": "1. Karadeliklerin sonu, hangi teoriye göre açıklanır, bu teoriye göre karadelikler kendi kütlelerini radyasyonla kaybederler ve sonunda tamamen buharlaşırlar?", "answer": "Hawking Işıması"},
        {"question": "2. Hawking ışıması süreci, karadeliklerin varlıklarını sürdürebilmeleri için neyin tükenmesinden sonra ortaya çıkar?", "answer": "Çekirdeğindeki nükleer yakıtın tükenmesinden"},
        {"question": "3. Hangi fizikçi tarafından öne sürülen Hawking ışıması teorisi, karadeliklerin evrenin uzun vadeli evriminde önemli bir rol oynadığını düşündürmektedir?", "answer": "Stephen Hawking"},
    ]

    karadelikler_quizler = [karadelikler_quiz, karadelikler_ozellikleri_quiz, hawking_isimasi_quiz]
    karadelikler_isim = ["Karadeliklerin Oluşumu", "Karadeliklerin Özellikleri", "Karadeliklerin Sonu"]

    # You can use these quiz lists for testing the knowledge of each content.

    """
    CREATE TABLE "Quiz"( 
        "quiz_id" SERIAL PRIMARY KEY,
        "quiz_name" VARCHAR(150) NOT NULL,
        "quiz_description" TEXT,
        "quiz_difficulty" INT NOT NULL,
        "topic_id" INT NOT NULL,
        CONSTRAINT fk_topic
            FOREIGN KEY("topic_id") REFERENCES "Topic"("topic_id")
    );

    CREATE TABLE "Question"(
        "question_id" SERIAL PRIMARY KEY,
        "question_text" TEXT NOT NULL,
        "question_difficulty" INT NOT NULL,
        "quiz_id" INT NOT NULL,
        CONSTRAINT fk_quiz
            FOREIGN KEY("quiz_id") REFERENCES "Quiz"("quiz_id")
    );

    CREATE TABLE "Answer"(
        "answer_id" SERIAL PRIMARY KEY,
        "answer_text" TEXT NOT NULL,
        "question_id" INT NOT NULL,
        CONSTRAINT fk_question
            FOREIGN KEY("question_id") REFERENCES "Question"("question_id")
    );

    CREATE TABLE "UserAnswer"(
        "useranswer_id" SERIAL PRIMARY KEY,
        "UserAnswerText" TEXT NOT NULL,
        "AnswerScore" INT NOT NULL,
        "answer_id" INT NOT NULL,
        "user_id" INT NOT NULL,

        CONSTRAINT fk_answer
            FOREIGN KEY("answer_id") REFERENCES "Answer"("answer_id"),

        CONSTRAINT fk_user
            FOREIGN KEY("user_id") REFERENCES "User"("user_id")
    );
    """
    for i in range(len(isimler_gunes)):
        cur.execute(f"INSERT INTO \"Quiz\"(\"quiz_name\", \"topic_id\") VALUES ('{isimler_gunes[i]} Quiz', {i+1})")
        conn.commit()
        for j in range(len(gunes_quizler[i])):
            cur.execute(f"INSERT INTO \"Question\"(\"question_text\", \"quiz_id\") VALUES ('{gunes_quizler[i][j]['question']}', {i+1})")
            conn.commit()
            cur.execute(f"SELECT \"question_id\" FROM \"Question\" WHERE \"question_text\" = '{gunes_quizler[i][j]['question']}'")
            fetch = cur.fetchall()
            question_id = int(fetch[0][0])
            cur.execute(f"INSERT INTO \"Answer\"(\"answer_text\", \"question_id\") VALUES ('{gunes_quizler[i][j]['answer']}', {question_id})")
            conn.commit()

    for i in range(len(isimler_yildizlar)):
        cur.execute(f"INSERT INTO \"Quiz\"(\"quiz_name\", \"topic_id\") VALUES ('{isimler_yildizlar[i]} Quiz', {i+6})")
        conn.commit()
        for j in range(len(yildizlar_quizler[i])):
            cur.execute(f"INSERT INTO \"Question\"(\"question_text\", \"quiz_id\") VALUES ('{yildizlar_quizler[i][j]['question']}', {i+6})")
            conn.commit()
            cur.execute(f"SELECT \"question_id\" FROM \"Question\" WHERE \"question_text\" = '{yildizlar_quizler[i][j]['question']}'")
            fetch = cur.fetchall()
            question_id = int(fetch[0][0])             
            cur.execute(f"INSERT INTO \"Answer\"(\"answer_text\", \"question_id\") VALUES ('{yildizlar_quizler[i][j]['answer']}', {question_id})")
            conn.commit()

    for i in range(len(karadelikler_isim)):
        cur.execute(f"INSERT INTO \"Quiz\"(\"quiz_name\", \"topic_id\") VALUES ('{karadelikler_isim[i]} Quiz', {i+14})")
        conn.commit()
        for j in range(len(karadelikler_quizler[i])):
            cur.execute(f"INSERT INTO \"Question\"(\"question_text\", \"quiz_id\") VALUES ('{karadelikler_quizler[i][j]['question']}', {i+10})")
            conn.commit()
            cur.execute(f"SELECT \"question_id\" FROM \"Question\" WHERE \"question_text\" = '{karadelikler_quizler[i][j]['question']}'")
            fetch = cur.fetchall()
            question_id = int(fetch[0][0])
            cur.execute(f"INSERT INTO \"Answer\"(\"answer_text\", \"question_id\") VALUES ('{karadelikler_quizler[i][j]['answer']}', {question_id})")
            conn.commit()

    conn.close()