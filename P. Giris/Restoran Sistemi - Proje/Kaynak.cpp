/*************************************************************************
**				    Sakarya Üniversitesi
**			Bilgisayar ve Bilişim Bilimleri Fakültesi
**			       Bilgisayar Mühendisliği Bölümü
**   				  Programlamaya Giriş Dersi
*
*
* 				Proje Numarası: 1
* 				Öðrenci Adı: İsmail Konak
* 				Öðrenci Numarası: 
* 				Ders Grubu: 
*
***************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <chrono>
#include <thread>
#include <vector>
using namespace std;

struct Tarih {
	int gun, ay, yil;
};

class Urun {
private:
	string u_ad;
	string u_kategori;
	Tarih u_uretim_t;
	Tarih u_son_tuketim_t;
	float u_kalori_per_gram;
	float u_stok_adet;
	float u_fiyat;
public:
	void urun_kaydet() {
		cout << endl << "Urun Adi: ";
		cin.ignore();
		getline(cin, u_ad);
		cout << endl << "Urun Kategori: ";
		
		getline(cin, u_kategori);
		cout << endl << "Urun Uretim Tarihi - Gun: ";
		cin >> u_uretim_t.gun;
		cout << endl << "Urun Uretim Tarihi - Ay: ";
		cin >> u_uretim_t.ay;
		cout << endl << "Urun Uretim Tarihi - Yil: ";
		cin >> u_uretim_t.yil;
		cout << endl << "Urun Son Tuketim Tarihi - Gun: ";
		cin >> u_son_tuketim_t.gun;
		cout << endl << "Urun Son Tuketim Tarihi - Ay: ";
		cin >> u_son_tuketim_t.ay;
		cout << endl << "Urun Son Tuketim Tarihi - Yil: ";
		cin >> u_son_tuketim_t.yil;
		cout << endl << "Urun Gram Basina Kalori: ";
		cin >> u_kalori_per_gram;
		cout << endl << "Urun Stok Bilgisi (Katý->Kg, Sývý->L): ";
		cin >> u_stok_adet;
		cout << endl << "Urun Fiyat (TL): ";
		cin >> u_fiyat;
		cout << endl << "Urun basariyla kaydedildi.";
	}
	void urun_kaydet (string ad, string kategori, Tarih uretim,
		Tarih tuketim, float calgr, float stok, float fiyat) {
		u_ad = ad; u_kategori = kategori;
		u_uretim_t = uretim; u_son_tuketim_t = tuketim;
		u_kalori_per_gram = calgr; u_stok_adet = stok;
		u_fiyat = fiyat;
	}

	string ad_ver() {
		return u_ad;
	}
	string kategori_ver() {
		return u_kategori;
	}
	string uretim_ver() {
		return to_string(u_uretim_t.gun) + "/" + to_string(u_uretim_t.ay) + "/" + to_string(u_uretim_t.yil);
	}
	string tuketim_ver() {
		return to_string(u_son_tuketim_t.gun) + "/" + to_string(u_son_tuketim_t.ay) + "/" + to_string(u_son_tuketim_t.yil);
	}
	float kalori_ver() {
		return u_kalori_per_gram;
	}
	float stok_ver() {
		return u_stok_adet;
	}
	float fiyat_ver() {
		return u_fiyat;
	}

};

struct Malzeme {
	string isim;
	float miktar;
	string olcu;
};

class Yemek {
private:
	Malzeme* malzemeler;

public:
	int malzeme_say;
	string isim;
	Yemek(string ism, int x) : malzemeler(new Malzeme[x]) {
		malzeme_say = x;
		isim = ism;
	};
	Malzeme* malzemeleri_dondur() {
		return malzemeler;
	}
	void malzemeleri_kaydet() {
		// Malzeme sayýsýnca i sayýsý döndürülür
		for (int i = 0; i < malzeme_say; i++) {
			Malzeme eklenek;
			cout << "Malzemenin ismini giriniz: ";
			cin.ignore();
			getline(cin, eklenek.isim);
			cout << "Malzemenin olcu birimini giriniz (gr,ml,adet vb.): ";
			cin >> eklenek.olcu;
			cout << "Malzemenin miktarýný giriniz: ";
			cin >> eklenek.miktar;
			malzemeler[i] = eklenek;

		}
	}
	void malzemeleri_kaydet(Malzeme* malzeme) {
		malzemeler = malzeme;
	}


};
void sleep(int x) {
	this_thread::sleep_for(chrono::milliseconds(x));
}
void depo_ekle(Urun urun);
int depo_sil(string isim);
void depo_guncelleme(string isim, int ozellik_satiri, string yeni_deger);
void depo_rapor_alma();
float depo_rapor_alma(string isim, int ozellik_satiri,int yazdir);
void default_depo_urunleri();
void yemek_ekle(Yemek yemek);
int yemek_sil(string isim);
void yemek_malzeme_guncelleme(string yemek_isim, string ozellik, string yeni_deger, string yeni_olcu);
void bolum_belirle(string dosya_ismi, string kelime, int degerler[2]);
void malzemeler_rapor_alma();
int malzemeler_rapor_alma(string isim, string ozellik);
void default_yemekler();
void yemek_depo_kontrol(string yemek, bool islemlerigoster);
void alisveris_listesi(float miktar, string tur, string isim);
float yemek_maliyet(string isim);
int indexofthis(vector<string> yemek_isimleri, string yemek);
void yemekler_goruntuleme();
void alisveris_listesi_goruntule();
int kac_yemek_var();

int main() {

	int sec, sec2, sec3, sec4, sec5;
	char ch1, ch2, ch3;
	do {
		system("CLS");
		cout << "			Los Pollos Hermanos'a Hos Geldiniz			" << "\n \n";
		cout << "Menu" << endl;
		cout << "*******************************" << endl;
		cout << "1) Depo islemleri" << endl;
		cout << "2) Yemek islemleri" << endl;
		cout << "3) Alisveris listesini goruntule" << endl;
		cout << "4) Satis islemleri" << endl;
		cout << "Seciminiz: "; cin >> sec;
		switch (sec)
		{
		case 1:
		{
			cout << "\t 1) Depoyu goruntule" << endl;
			cout << "\t 2) Depodaki bir urun hakkinda bilgi al" << endl;
			cout << "\t 3) Depoya bir urun ekle" << endl;
			cout << "\t 4) Depodan urun sil" << endl;
			cout << "\t 5) Depodaki bir urunun ozelliklerini guncelle" << endl;
			cout << "Seciminiz: "; cin >> sec2;
			switch (sec2)
			{
			case 1:
			{
				depo_rapor_alma();
				break;
			}

			case 2:
			{
				string urun_isim;
				cout << "Urun ismi: ";
				cin.ignore();
				getline(cin, urun_isim);
				int sonuc= depo_rapor_alma(urun_isim, -1, 1);
				if (sonuc == -123)
					cout << "Aradiginiz urun depoda bulunamadi"<<endl;
				break;
			}

			case 3:
			{
				Urun urun;
				urun.urun_kaydet();
				depo_ekle(urun);
				cout << "Urun depoya eklendi" << endl;
				break;
			}
			case 4:
			{
				string urun;
				cout << "Silinecek urunu giriniz: ";
				cin.ignore();
				getline(cin, urun);
				int sonuc = depo_sil(urun);
				if (sonuc == -123)
					cout << "Silmek istediginiz urun depoda bulunamadi"<<endl;
				else
					cout << "Urun depodan silindi" << endl;
				break;
			}
			case 5:
			{
				string urun;
				int ozellik;
				string yeni_deger;
				cout << "Guncellenecek urunu giriniz: ";
				cin.ignore();
				getline(cin, urun);
				int sonuc = depo_rapor_alma(urun, -1, 1);
				if (sonuc == -123)
					cout << "Guncellemek istediginiz urun depoda bulunamadi" << endl;
				else{
					cout << "\n Hangi ozelligi guncellemek istersiniz\n";
					cout << "(1:Kategori, 2:Uretim Tarihi, 3:Son Tuketim Tarihi, 4:Cal/Gr, 5:Stok, 6:Fiyat)";
					cout << "\n Ozellik No: "; cin >> ozellik;
					cout << "Ilgili ozelligin yeni degeri: ";
					cin.ignore();
					getline(cin, yeni_deger);
					depo_guncelleme(urun, ozellik, yeni_deger);
					cout << "Urun guncellendi" << endl;
				}

			}
			//end of switch depo
			}
			break;
		}

		case 2:
		{
			cout << "\t 1) Yemekleri goruntule" << endl;
			cout << "\t 2) Yemekler listesindeki bir yemek hakkinda bilgi al" << endl;
			cout << "\t 3) Yemekler listesine yemek ekle" << endl;
			cout << "\t 4) Yemekler listesinden yemek sil" << endl;
			cout << "\t 5) Yemekler listesinden bir yemegi guncelle" << endl;
			cout << "Seciminiz: "; cin >> sec;
			switch (sec)
			{
			case 1:
			{
				cout << to_string(kac_yemek_var()) << " adet yemek bulundu: \n\n";
				yemekler_goruntuleme();
				break;
			}

			case 2:
			{
				string yemek_isim;
				cout << "Yemek ismi: ";
				cin.ignore();
				getline(cin, yemek_isim);
				cout << "\n";
				int sonuc = malzemeler_rapor_alma(yemek_isim, "hepsi");
				if (sonuc == -123)
					cout << "Aradiginiz yemek, yemek listesinde bulunamadi" << endl;
				break;
			}

			case 3:
			{
				int mal_say;
				string yemek_i;
				cout << "Eklenecek yemegin ismi: ";
				cin.ignore();
				getline(cin, yemek_i);
				cout << "Eklenecek yemegin malzeme sayisi: "; cin >> mal_say;
				Yemek yemek(yemek_i, mal_say);
				yemek.malzemeleri_kaydet();
				yemek_ekle(yemek);
				cout << "Yemek basariyla eklendi" << endl;
				break;
			}
			case 4:
			{
				string yemek_i;
				cout << "Silinecek yemegin ismi: "; 
				cin.ignore();
				getline(cin, yemek_i);
				int sonuc = yemek_sil(yemek_i);
				if (sonuc == -123)
					cout << "Silmek istediginiz yemek, yemek listesinde bulunamadi"<<endl;
				else {
					cout << "Yemek basariyla silindi" << endl;
				}
				break;
			}
			case 5:
			{
				string yemek_i;
				string ozellik;
				string yeni_deger_ham;
				cout << "Guncellenecek yemegin ismi: ";
				cin.ignore();
				getline(cin, yemek_i);
				int sonuc = malzemeler_rapor_alma(yemek_i, "hepsi");

				if (sonuc == -123)
					cout << "Guncellemek istediginiz yemek, yemek listesinde bulunamadi" << endl;
				else {
					cout << "\n Hangi malzemenin degerini guncellemek istersiniz: "; getline(cin, ozellik);
					cout << "Guncellencek ozelligin yeni degeri ne olsun (orn: 100 gr): "; getline(cin, yeni_deger_ham);
					int bosluk = yeni_deger_ham.find(" ");
					string deg = yeni_deger_ham.substr(0, bosluk);
					string olcu = yeni_deger_ham.substr(bosluk + 1, string::npos - bosluk + 1);
					yemek_malzeme_guncelleme(yemek_i, ozellik, deg, olcu);
					cout << "Yemek guncellendi" << endl;
				}
				break;
			}

			//end of stich yemekler		
			}
			break;
		}

		case 3:
		{
			alisveris_listesi_goruntule();
			break;
		}
		case 4:
		{
			const int yemek_sayi = kac_yemek_var();
			vector<int> yemek_adetleri(yemek_sayi);
			vector<int> yemek_adetleri_baslangic(yemek_sayi);
			vector<string> yemek_isimleri(yemek_sayi);
			vector<float> yemek_maliyetleri(yemek_sayi);
			float total_maliyet = 0;
			float total_satis = 0;
			float karzarar;
			ifstream yemekler;
			yemekler.open("yemekler.txt");
			string text;
			int index = 0;
			// ilgili dosyadaki her satýr sýrayla while döngüsü dödnükçe aracýlýðýyla "text" deðiþkenine atanýr
			while (getline(yemekler, text)) {
				if (text.find("Yemek") != string::npos) {
					string isim = text.substr(text.find(':') + 2, text.find("(") - (text.find(':') + 3));
					yemek_isimleri[index] = isim;
					yemek_depo_kontrol(isim, 0);
					yemek_maliyetleri[index] = yemek_maliyet(isim);
					index += 1;
				}
			}
			char say_sec;
			cout << "Her bir yemek cesidinden ayni sayida mi hazirlansin (E/h): "; cin >> say_sec;
			if (say_sec != 'h') {
				int sayi;
				cout << "Her bir yemekten kac adet hazirlansin: "; cin >> sayi;
				for (int i=0; i < yemek_sayi; i++)
					yemek_adetleri[i] = sayi;
			}
			else {
				int sayi;
				for (int i=0; i < yemek_sayi; i++)
				{
					cout << "'" << yemek_isimleri[i] << "' adli yemekten kac adet hazirlansin: ";
					cin >> sayi;
					yemek_adetleri[i] = sayi;
				}
			}
			yemek_adetleri_baslangic = yemek_adetleri;

			for (int i = 0; i < yemek_sayi; i++) {
				total_maliyet += yemek_maliyetleri[i] * yemek_adetleri[i];
			}
			cout << "Tesekkurler" << endl;
			cout << "Hazirlanacak yemekler icin gerekli malzemeler kontrol ediliyor";
			sleep(300); cout << "."; sleep(300); cout << "."; sleep(300); cout << "." << endl;
			cout << "Eksik malzemeler alisveris listesine ekleniyor";
			sleep(300); cout << "."; sleep(300); cout << "."; sleep(300); cout << "." << endl;

			cout << "Yemekler hazirlandi" << endl;
			cout << "Hazirlanan "+ to_string(yemek_sayi) + " cesit yemek icin toplam maliyet: " << total_maliyet << " TL \n";
			cout << "Satis menusune yonlendiriliyorsunuz" << endl;
			sleep(1500);
			system("CLS");
			cout << "\t \t Satis Menusune Hos Geldiniz" << endl;
			// Kullanýcý istediði sürece tekrar tekrar satýþ yapýlabilmesine olanak saðlar
			do {
				string yemek;
				cout << "Satilacak yemek: " << endl;
				getline(cin >> ws, yemek);
				int i_of_yemek = indexofthis(yemek_isimleri, yemek);
				while (i_of_yemek < -500) {
					cout << "Arattiginiz yemegin bugun satisi yapilmamaktadir, baska yemek seciniz" << endl;
					cout << "Satilacak yemek: "; getline(cin, yemek);

					i_of_yemek = indexofthis(yemek_isimleri, yemek);
				}
				int yemek_adet = yemek_adetleri[i_of_yemek];
				if (yemek_adet > 0) {
					cout << "Yemekten " << yemek_adet << " adet var, kac tane satin almak istersiniz? \n" << "Adet: "; cin >> sec2;
					while (sec2 > yemek_adet) {
						cout << "Bugun bu kadar yemek hazirlanmadi, lutfen adet sayisini " << yemek_adet + 1 << "altina dusurun" << endl;
						cout << "Adet: "; cin >> sec2;
					}
					yemek_adetleri[i_of_yemek] -= sec2;
					total_satis += (yemek_maliyet(yemek) + yemek_maliyet(yemek) * 0.15) * sec2;
					cout << "Satis gerceklesti, siparis tutari: " << (yemek_maliyet(yemek) + yemek_maliyet(yemek) * 0.15) * sec2 << endl;
				}
				else {
					cout << "Sectiginiz yemekten elimizde kalmadi" << endl;
				}
				cout << "\n \n Baska bir satis yapmak ister misiniz (E/h)? "; cin >> ch1;
			} while (ch1 != 'h');
			system("CLS");
			cout << "\t\t Gunluk Rapor" << endl;
			for (int i = 0; i < yemek_sayi; i++) {
				string yemek = yemek_isimleri[i];
				int siparis_sayi = yemek_adetleri_baslangic[i] - yemek_adetleri[i];
				float yemek_mal = yemek_maliyet(yemek);
				cout << yemek << " -- Uretilen= " << yemek_adetleri_baslangic[i] << " -- Satilan= " << siparis_sayi << " -- Kar / Zarar=  " << ((yemek_mal + yemek_mal * 0.30) * siparis_sayi) - (yemek_mal * yemek_adetleri[i]) << " TL\n";
				cout << "*******************************************************************************" << endl;
			}
			cout << "Toplam Maliyet: " << total_maliyet << " TL \n";
			cout << "Toplam Satis: " << total_satis << " TL \n";
			cout << "Kar & Zarar: " << total_satis - total_maliyet << " TL \n";


			break;
		}
		default:
			break;
		}
		cout << "Baska islem yapmak ister misiniz (E/h): "; cin >> ch1;
	} while (ch1 != 'h');
	


	return 0;
}

int kac_yemek_var() {
	ifstream yemekler("yemekler.txt");
	string text;
	int sayi=0;
	while (getline(yemekler, text)) {
		if (text.find("Adi") != string::npos)
			sayi += 1;
	}
	return sayi;
}
int indexofthis(vector<string> yemek_isimleri, string yemek) {
	int i = 0;
	int index = -10000;
	for (i; i < yemek_isimleri.size(); i++) {
		cout << "(" + yemek_isimleri[i] + "==" + yemek + ")"<<endl;
		if (yemek_isimleri[i] == yemek) {
			index = i;
			break;
		}
	}
	return index;
}

void bolum_belirle(string dosya_ismi, string kelime,int degerler[2]) {
	ifstream malzemeler(dosya_ismi);
	string text;
	int satir = 1;
	int ilgili = -1000000;
	int ilgili_son = -10000;
	// ilgili dosyadaki her satýr sýrayla while döngüsü dödnükçe aracýlýðýyla "text" deðiþkenine atanýr
	while (getline(malzemeler, text)) {
		if (text.find(kelime) != string::npos && text.find("Adi") != string::npos && ilgili < 0) {
			ilgili = satir;
		}
		if (string::npos != text.find_first_of("*") && ilgili >= 0 && ilgili_son < 0) {
			ilgili_son = satir;
		}
		if (ilgili_son > 0 && ilgili >= 0)
			break;
		satir++;
	}
	malzemeler.close();
	degerler[0] = ilgili;
	degerler[1] = ilgili_son;

}

void depo_ekle(Urun urun) {
	ofstream depo;
	depo.open("depo.txt", ios_base::app);
	depo << "Urun Adi: " << urun.ad_ver() << endl;
	depo << "\t Urun Kategorisi: " << urun.kategori_ver() << endl;
	depo << "\t Urun Uretim Tarihi: " << urun.uretim_ver() << endl;
	depo << "\t Urun Son Tuketim Tarihi: " << urun.tuketim_ver() << endl;
	depo << "\t Urun Gram Basina Kalori (gr/kcal): " << urun.kalori_ver() <<endl;
	depo << "\t Urun Stok Adeti: " << urun.stok_ver() << endl;
	depo << "\t Urun Fiyati (TL): " << urun.fiyat_ver() << endl;
	depo << "********************************************************************************";
	depo << endl;
	depo.close();
}

int depo_sil(string isim) {
	ifstream depo("depo.txt");
	ofstream temp("temp.txt");
	string text;
	
	int satir = 1;
	int ilgili=-10000;
	bool gecmi;
	// ilgili dosyadaki her satýr sýrayla while döngüsü dödnükçe aracýlýðýyla "text" deðiþkenine atanýr
	while (getline(depo, text)) {
		// Ýlgili dosyada isim degiskeni içindeki kelime bulunduðunda o kelimenin bulundugu satýrý bulmamýza yarayan blok
		if (text.find(isim) != string::npos && text.find("Adi") != string::npos && ilgili<0) {
			ilgili = satir;
		}
		// Satir numarasi istenen araliktaysa bloðu çalýþtýrarak, istenilen kisimda islem yapilabilmesine olanak saglar
		if ((ilgili + 8 > satir && satir >= ilgili)!=1) {
			temp << text << endl;
		}
		
		satir++;
	}
	depo.close();
	temp.close();
	remove("depo.txt");
	rename("temp.txt", "depo.txt");

	if (ilgili < -50)
		return -123;
	else
		return 1;
}

void depo_guncelleme(string isim, int ozellik_satiri, string yeni_deger) {
	ifstream depo("depo.txt");
	ofstream temp("temp.txt");
	string text;
	int satir = 1;
	int ilgili = -10;
	// ilgili dosyadaki her satýr sýrayla while döngüsü dödnükçe aracýlýðýyla "text" deðiþkenine atanýr
	while (getline(depo, text)) {
		// Ýlgili dosyada isim degiskeni içindeki kelime bulunduðunda o kelimenin bulundugu satýrý bulmamýza yarayan blok
		if (text.find(isim) != string::npos && text.find("Adi") != string::npos) {
			ilgili = satir;
		}
		// Satir numarasi istenen araliktaysa bloðu çalýþtýrarak, istenilen kisimda islem yapilabilmesine olanak saglar
		if (ilgili + 8 > satir && satir >= ilgili) {
			if (satir == ilgili + ozellik_satiri) {
				int pos = text.find_first_of(':') + 2;
				text.replace(pos, 15, yeni_deger);
				temp << text << endl;
			}
			else {
				temp << text << endl;
			}
		}
		else {
			temp << text << endl;
		}
		satir++;
	}
	
	temp.close();
	depo.close();
	remove("depo.txt");
	bool failed = !ifstream("depo.txt");
	if (failed==1){
		int a = rename("temp.txt", "depo.txt");
	}
	
}

void depo_rapor_alma() {
    fstream fp;
	char ch;
	fp.open("depo.txt", fstream::in);

    while(fp>>noskipws>>ch)
        cout<<ch;
    fp.close();
    cout<<endl;
}

float depo_rapor_alma(string isim, int ozellik_satiri,int yazdir) {
	ifstream depo("depo.txt");
	string text;
	int satir = 1;
	int ilgili = -10000;
	float deger=-1;
	// ilgili dosyadaki her satýr sýrayla while döngüsü dödnükçe aracýlýðýyla "text" deðiþkenine atanýr
	while (getline(depo, text)) {
		// Ýlgili dosyada isim degiskeni içindeki kelime bulunduðunda o kelimenin bulundugu satýrý bulmamýza yarayan blok
		if (text.find(isim) != string::npos && text.find("Adi") != string::npos && ilgili < 0) {
			ilgili = satir;
		}
		// Satir numarasi istenen araliktaysa bloðu çalýþtýrarak, istenilen kisimda islem yapilabilmesine olanak saglar
		if (ilgili + 8 > satir && satir >= ilgili && ozellik_satiri != -1) {
			if (satir == ilgili + ozellik_satiri) {
				int pos = text.find_first_of(':') + 2;
				string deger_s = text.substr(pos, (string::npos - pos));
				//cout << text<< endl;
				deger  = stof(deger_s);
				if (yazdir == 1)
					cout << "Ilgili ozelligin degeri: " << deger_s << endl;
			}
		}
		else if (ilgili + 8 > satir && satir >= ilgili && ozellik_satiri == -1) {
			cout << text << endl;
		}
		satir++;
	}
	depo.close();

	if (ilgili > -50)
		return deger;
	else
		return -123;
}


/*********************************************************************************************************/


void yemek_ekle(Yemek yemek) {
	ofstream yemekler;
	ofstream malzemeler;
	yemekler.open("yemekler.txt", ios_base::app);
	malzemeler.open("malzemeler.txt", ios_base::app);
	yemekler << "Yemek Adi: " << yemek.isim <<" (malzeme sayisi: "<<yemek.malzeme_say<< ")" << "\n \n";
	malzemeler << "Yemek Adi: " << yemek.isim << "\n";
	malzemeler << "Malzemeler: "<< "\n";
	for (int i=0;i<yemek.malzeme_say;i++){
		Malzeme malzeme = yemek.malzemeleri_dondur()[i];
		malzemeler <<"\t" << malzeme.miktar <<" "+ malzeme.olcu + " " << malzeme.isim << endl;
	}
	malzemeler << "********************************************************************************";
	malzemeler << endl;
	malzemeler.close();
	yemekler.close();
}

int yemek_sil(string isim) {
	ifstream yemek("yemekler.txt");
	ofstream temp("temp.txt");
	string text;
	int satir = 1;
	int ilgili=-100000;
	// ilgili dosyadaki her satýr sýrayla while döngüsü dödnükçe aracýlýðýyla "text" deðiþkenine atanýr
	while (getline(yemek, text)) {
		// Ýlgili dosyada isim degiskeni içindeki kelime bulunduðunda o kelimenin bulundugu satýrý bulmamýza yarayan blok
		if (text.find(isim)!= string::npos && ilgili <0) {
			ilgili = satir;
		}
		else if (satir == ilgili+1 && ilgili >= 0) {
			ilgili = satir-1;
		}
		else {
			temp << text << endl;
		}
		satir++;
	}
	yemek.close();
	temp.close();
	remove("yemekler.txt");
	rename("temp.txt", "yemekler.txt");

	int ilgili_satirlar_malz[2];
	bolum_belirle("malzemeler.txt", isim, ilgili_satirlar_malz);
	ifstream malzemeler("malzemeler.txt");
	ofstream temp2("temp.txt");
	satir = 1;
	while (getline(malzemeler, text)) {
		// Ýlgili dosyada isim degiskeni içindeki kelime bulunduðunda o kelimenin bulundugu satýrý bulmamýza yarayan blok
		if ((ilgili_satirlar_malz[1] >= satir && satir >= ilgili_satirlar_malz[0]) != 1) {
			temp2 << text << endl;
		}
		satir++;
	}
	malzemeler.close();
	temp2.close();
	remove("malzemeler.txt");
	rename("temp.txt", "malzemeler.txt");

	if (ilgili < -50)
		return -123;
	else
		return 1;
	
}

void yemek_malzeme_guncelleme(string yemek_isim, string ozellik, string yeni_deger,string yeni_olcu) {
	ifstream malzemeler("malzemeler.txt");
	ofstream temp2("temp.txt");
	string text;
	int satir = 1;
	int ilgili_satirlar[2];
	bolum_belirle("malzemeler.txt", yemek_isim, ilgili_satirlar);
	// ilgili dosyadaki her satýr sýrayla while döngüsü dödnükçe aracýlýðýyla "text" deðiþkenine atanýr
	while (getline(malzemeler, text)) {
		// Satir numarasi istenen araliktaysa bloðu çalýþtýrarak, istenilen kisimda islem yapilabilmesine olanak saglar
		if (ilgili_satirlar[1] >= satir && satir >= ilgili_satirlar[0]) {
			if (string::npos!=text.find(ozellik)) {
				
				temp2 <<"\t" << yeni_deger + " " + yeni_olcu + " " + ozellik << endl;
			}
			else{
				temp2 << text << endl;
			}
		}
		else {
			temp2 << text << endl;
		}
		satir++;
	}
	malzemeler.close();
	temp2.close();
	remove("malzemeler.txt");
	rename("temp.txt", "malzemeler.txt");
}

void yemekler_goruntuleme() {
	fstream fp;
	char ch;
	fp.open("yemekler.txt", fstream::in);
	while (fp >> noskipws >> ch)
		cout << ch;
	fp.close();
	cout << endl;
}
void malzemeler_rapor_alma() {
	fstream fp;
	char ch;
	fp.open("malzemeler.txt", fstream::in);
	while (fp >> noskipws >> ch)
		cout << ch;
	fp.close();
	cout << endl;
}

int malzemeler_rapor_alma(string isim, string ozellik) {
	ifstream malzemeler("malzemeler.txt");
	string text;
	int satir = 1;
	int ilgili_satirlar[2] = {-100000,-10000};
	bolum_belirle("malzemeler.txt", isim, ilgili_satirlar);
	// ilgili dosyadaki her satýr sýrayla while döngüsü dödnükçe aracýlýðýyla "text" deðiþkenine atanýr
	while (getline(malzemeler, text)) {
		// Satir numarasi istenen araliktaysa bloðu çalýþtýrarak, istenilen kisimda islem yapilabilmesine olanak saglar
		if (ilgili_satirlar[1] >= satir && satir >= ilgili_satirlar[0]) {
	
			if (string::npos != text.find(ozellik) && ozellik != "hepsi") {
				cout << text << endl;
			}
			if (ozellik == "hepsi") {
				cout << text << endl;
			}
		}
		satir++;
	}
	if (ilgili_satirlar[0] < -50)
		return -123;
	else
		return 1;
}

void yemek_depo_kontrol(string yemek,bool islemlerigoster) {
	if (islemlerigoster == 1)
		cout << yemek << " adli yemegin kontrolu yapiliyor..." << endl;
	ifstream malzemeler;
	malzemeler.open("malzemeler.txt");
	ifstream yemekler;
	yemekler.open("yemekler.txt");
	
	string text1, text2, text3;
	int satir1, satir2, satir3;
	
	int malzeme_say=0;
	string secili_malzeme_text;
	string secili_malzeme_tur;
	float secili_malzeme_sayi=-987;
	float secili_malzeme_depo_sayi = -987;

	int atla;
	// ilgili dosyadaki her satýr sýrayla while döngüsü dödnükçe aracýlýðýyla "text" deðiþkenine atanýr
	while (getline(yemekler, text1)) {
		// Ýlgili dosyada isim degiskeni içindeki kelime bulunduðunda o kelimenin bulundugu satýrý bulmamýza yarayan blok
		if (text1.find(yemek) != string::npos) {
			int pos = text1.find(')');
			if (pos != string::npos) {
				string num = text1.substr(pos - 1, 1);
				malzeme_say = stoi(num);
			}
		}
	}
	
	for (int i = 0; i < malzeme_say; i++) {
		malzemeler.seekg(0, ios::beg);
		ifstream depo;
		depo.open("depo.txt");
		int ilgili_satir=-10, ilgili_satir2=-10;
		satir1 = 1;
		// istenen yemekler için gerekli malzemeler belirleniyor
		while (getline(malzemeler, text2)) {
			// ilgili satýrda "yemek" degiskenindeki kelime var mý kontrol eder
			if (text2.find(yemek) != string ::npos) {
				ilgili_satir = satir1;
			}
			if (satir1 == ilgili_satir + i + 2 && ilgili_satir > 0) {
				int s = text2.find(" ", 2);
				int s2 = text2.find(" ", s+1);
				int b = text2.find("\t");
				string num = text2.substr(b+1, s);
				secili_malzeme_sayi = stof(num);
				secili_malzeme_tur = text2.substr(s + 1, s2 - s); 
				secili_malzeme_text = text2.substr(s2 + 1, string::npos - s2);
				if (secili_malzeme_tur.find("gr") != string::npos || secili_malzeme_tur.find("ml") != string::npos)
					secili_malzeme_sayi *= 0.001;
				break;
			}
			satir1++;
		}
		satir2 = 1;
		while (getline(depo, text3)) {
			// ilgili satýrda "secili_malzeme_text" degiskenindeki kelime var mý kontrol eder
			if (text3.find(secili_malzeme_text) != string::npos) {
				ilgili_satir2 = satir2;
			}
			if (satir2 == ilgili_satir2 + 5) {
				string depo_sayi = text3.substr(text3.find(":")+2, string::npos - text3.find(":")+1);
				secili_malzeme_depo_sayi = stof(depo_sayi);
				
				break;

			}
			satir2++;
		}
		if (islemlerigoster == 1) {
			cout << '\n' << secili_malzeme_text << " adli malzeme kontrolu yapiliyor" << endl;
			cout << "Gereken: " << secili_malzeme_text << " -> " << secili_malzeme_sayi << endl;
			cout << "Depoda: " << secili_malzeme_text << " -> " << secili_malzeme_depo_sayi << endl;
		}
		// Depo ile gerekli malzemeler karsilastiriliyo, bunun sonucunda duruma göre depodan azaltma veya alisveris listesi olusturmaya gidiliyo
		depo.close();
		if (secili_malzeme_sayi <= secili_malzeme_depo_sayi) {
			if (islemlerigoster == 1)
				cout << "Depoda yeterince malzeme var, depodan aliniyor" << "\n";
			string yeni_miktar = to_string(secili_malzeme_depo_sayi - secili_malzeme_sayi);
			depo_guncelleme(secili_malzeme_text, 5, yeni_miktar);
		}
		else if (secili_malzeme_sayi> secili_malzeme_depo_sayi){
			if (islemlerigoster == 1)
				cout << "Depoda yeterince malzeme yok, alisveris listesi hazirlaniyor" << "\n \n";
			depo_guncelleme(secili_malzeme_text, 5, "0");
			float miktar = (secili_malzeme_depo_sayi - secili_malzeme_sayi) * (-1);
			alisveris_listesi(miktar,secili_malzeme_tur,secili_malzeme_text);
		}

	}
	if (islemlerigoster == 1)
		cout << "***************************************************" << endl;
}

void alisveris_listesi(float miktar, string tur, string isim){
	ofstream alisveris;
	alisveris.open("alisveris_listesi.txt", ios_base::app);
	alisveris << "\t" << miktar << " " << tur << " " << isim << endl;
	alisveris.close();
}

void alisveris_listesi_goruntule()
{
	fstream fp;
	char ch;
	fp.open("alisveris_listesi.txt", fstream::in);
	while (fp >> noskipws >> ch)
		cout << ch;
	fp.close();
	cout << endl;
}

float yemek_maliyet(string yemek) {
	ifstream yemekler;
	ifstream malzemeler;
	yemekler.open("yemekler.txt");
	malzemeler.open("malzemeler.txt");
	string text1, text2, text3;
	int satir1, satir2, satir3;
	int malzeme_say = 0;
	string secili_malzeme_text;
	string secili_malzeme_tur;
	float secili_malzeme_sayi = -987;
	float maliyet=0;
	int ilgili_satir=-98;
	int atla;
	// ilgili dosyadaki her satýr sýrayla while döngüsü dödnükçe aracýlýðýyla "text" deðiþkenine atanýr
	while (getline(yemekler, text1)) {
		// Ýlgili dosyada isim degiskeni içindeki kelime bulunduðunda o kelimenin bulundugu satýrý bulmamýza yarayan blok
		if (text1.find(yemek) != string::npos && malzeme_say == 0) {
			int pos = text1.find(')');
			if (pos != string::npos) {
				string num = text1.substr(pos - 1, 1);
				malzeme_say = stoi(num);
			}
		}
	}
	for (int i = 0; i < malzeme_say; i++) {
		malzemeler.seekg(0, ios::beg);
		satir1 = 1;
		// ilgili dosyadaki her satýr sýrayla while döngüsü dödnükçe aracýlýðýyla "text" deðiþkenine atanýr
		while (getline(malzemeler, text1)) {
			// Ýlgili dosyada isim degiskeni içindeki kelime bulunduðunda o kelimenin bulundugu satýrý bulmamýza yarayan blok
			if (text1.find(yemek) != string::npos && ilgili_satir < 0)
				ilgili_satir = satir1;
			// Satir numarasi istenen araliktaysa bloðu çalýþtýrarak, istenilen kisimda islem yapilabilmesine olanak saglar
			if (satir1 == ilgili_satir + i + 2 && ilgili_satir >= 0) {
				int s = text1.find(" ", 2);
				int s2 = text1.find(" ", s + 1);
				int b = text1.find("\t");
				string num = text1.substr(b + 1, s);
				secili_malzeme_sayi = stof(num);
				secili_malzeme_tur = text1.substr(s + 1, s2 - s);
				secili_malzeme_text = text1.substr(s2 + 1, string::npos - s2);
				if (secili_malzeme_tur.find("gr") != string::npos || secili_malzeme_tur.find("ml") != string::npos)
					secili_malzeme_sayi /= 1000;
				break;
			}
			satir1++;
		}
		maliyet += depo_rapor_alma(secili_malzeme_text,6,0)*secili_malzeme_sayi;
	}
	return maliyet;
}
