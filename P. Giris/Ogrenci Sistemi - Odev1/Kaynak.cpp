/*************************************************************************
* 							Sakarya Üniversitesi
*				  Bilgisayar ve Biliþim Bilimleri Fakültesi
*					   Bilgisayar Mühendisliði Bölümü
*   					  Programlamaya Giriþ Dersi
*
*
* 				Ödev Numarasý: 1
* 				Öðrenci Adý: Ýsmail Konak
* 				Öðrenci Numarasý: 
* 				Ders Grubu: 
*
*
***************************************************************************/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>
#include <string>

using namespace std;

struct Tarih {
	int gun;
	int ay;
	int yil;

};

struct Ogrenci {
	string adi, soyadi, no;
	float kisa_sinav_1, kisa_sinav_2, odev_1, odev_2, proje, vize, final_not;
	Tarih dogum_tarihi;
};

string isimler[30] = { "Ismail","Samet","Mehmet","Eysan","Fatma","Huseyin","Gizem","Mirza","Fatih","Yunus",
						"Bilgin","Emine","Melike","Ulvi","Murat","Deniz","Derya","Ahmet","Cihat","Taner",
							"Selma","Ramiz","Kenan","Ekrem","Sinan","Ahmet","Tevfik","Cengiz","Yusuf","Busra" };

string soyisimler[30] = { "Konak","Yilmaz","Sarraf","Sabanci","Engin","Cakar","Tutar","Pamuk","Mutlu","Donmez",
						"Araci","Sever","Ince","Terim","Tosun","Denizci","Tatli","Karay","Derin","Kara",
							"Bayrak","Ares","Akkurt","Aksit","Alev","Aktan","Kacik","Capa","Catakli","Cesur" };

Ogrenci ogrenciler[100];

string yuzluk_to_harf(float ders_notu);
float not_kontrol(float not_degeri, float min, float max);
Ogrenci ogrenci_rastgele_deger_ata(Ogrenci ogrenci, int min, int max);
Ogrenci ogrenci_kullanici_deger_ata(Ogrenci ogrenci);
void sinif_listesi(Ogrenci ogrenciler[100]);
void sinif_max_not(Ogrenci ogrenciler[100]);
void sinif_min_not(Ogrenci ogrenciler[100]);
float sinif_ortalama(Ogrenci ogrenciler[100], bool yazdir);
void sinif_std_sapma(Ogrenci ogrenciler[100]);
void sinif_basari_sirala_aralik(Ogrenci ogrenciler[100], float min, float max);
void sinif_basari_sirala_buyuktur(Ogrenci ogrenciler[100], float min);
void sinif_basari_sirala_kucuktur(Ogrenci ogrenciler[100], float max);
int ogrenci_liste_uzunluk_kontrol(Ogrenci ogrenciler[100]);
float yil_ici_not(Ogrenci ogrenci);
float basari_not(Ogrenci ogrenci);


int main() {
	int secim;
	cout << "\t \t" << "Ogrenci Kaydetme Sistemine Hos Geldiniz" << "\n \n \n";

	cout << "Ogrenci kaydetme islemi icin 2 seceneginiz var:" << endl;
	cout << "1 -> Kaydedilecek ogrenciler ile ilgili veriler rastgele belirlensin" << endl;
	cout << "2 -> Kaydedilecek ogrenciler ile ilgili veriler kullanici tarafindan girilsin" << endl;
	cout << "Seciminiz: "; cin >> secim;

	// Kaydedilecek öðrenciler ile ilgili verilerin kayýt yöntemi seçimindeki, seçilmesi durumunda verilerin rastgele atanacaðý olan ilk if bloðu
	if (secim == 1) {
		// 100 öðrencinin verilerinin rastgele atanabilmesi amacýyla ogrenciler dizisinin 
		// indislerinin döndürülmesi için for döngüsü kullanýldý
		for (int i = 0; i < 100; i++) {
			ogrenciler[i].adi = isimler[rand() % 30];
			ogrenciler[i].soyadi = soyisimler[rand() % 30];

			// Öðrencilerin %10'una tekabül edecek, notu 0-40 arasýnda olacak olan listedeki 0. ile 10. kiþi arasýndaki kiþilerin belirlenmesi için if kullanýldý
			if (i < 10) {
				ogrenciler[i] = ogrenci_rastgele_deger_ata(ogrenciler[i], 0.0, 40.0);
			}
			// Öðrencilerin %50'sine tekabül edecek, notu 40-70 arasýnda olacak olan listedeki 10. ile 60. kiþi arasýndaki kiþilerin belirlenmesi için if kullanýldý
			if (10 <= i and i < 60) {
				ogrenciler[i] = ogrenci_rastgele_deger_ata(ogrenciler[i], 40.0, 70.0);
			}
			// Öðrencilerin %15'ine tekabül edecek, notu 70-80 arasýnda olacak olan listedeki 60. ile 75. kiþi arasýndaki kiþilerin belirlenmesi için if kullanýldý
			if (60 <= i and i < 75) {
				ogrenciler[i] = ogrenci_rastgele_deger_ata(ogrenciler[i], 70.0, 80.0);
			}
			// Öðrencilerin %25'ine tekabül edecek, notu 80-100 arasýnda olacak olan listedeki 75. ile 100. kiþi arasýndaki kiþilerin belirlenmesi için if kullanýldý
			if (75 <= i and i < 100) {
				ogrenciler[i] = ogrenci_rastgele_deger_ata(ogrenciler[i], 80.0, 100.0);
			}
		}
	}
	// Kaydedilecek öðrenciler ile ilgili verilerin kayýt yöntemi seçimindeki, seçilmesi durumunda verileri kullanýcýnýn atayacacaðý ikinci else if bloðu
	else if (secim == 2) {
		// 100 öðrencinin verilerinin kullanýcý tarafýndan atanabilmesi amacýyla ogrenciler dizisinin 
		// indislerinin döndürülmesi için for döngüsü kullanýldý
		for (int i = 0; i < 100; i++) {
			cout << "Ogrenci Kaydetme Sistemine Hosgeldiniz " << endl;
			cout << "Ogrenci Index: " << i << endl;
			ogrenciler[i] = ogrenci_kullanici_deger_ata(ogrenciler[i]);
			cout << "Tebrikler!!! Ogrenci basariyla kaydedildi" << endl;
			char devam;
			cout << "Baska bir ogrenci daha kaydetmek istiyor musun (e/H): "; cin >> devam;
			// Kullanýcýnýn öðrenci kaydetmeye devam edip etmek istemediðinin belirlenmesi için if kullanýldý
			if (devam != 'e')
				break;
		}
	}
	char devammi;
	// Ýþlemler Menüsünün kullanýcý istediði sürece kullanýlmasý için do while döngüsü kullanýldý
	do {
		system("cls");
		int islem_secim;
		cout << "Islemler Menusu: " << endl;
		cout << "1 - Sinif Listesini yazdir" << endl;
		cout << "2 - Sinifin en yuksek notunu yazdir" << endl;
		cout << "3 - Sinifin en dusuk notunu yazdir" << endl;
		cout << "4 - Sinifin not ortalamasini yazdir" << endl;
		cout << "5 - Siniftaki notlarin standart sapmasini yazdir" << endl;
		cout << "6 - Basari notu belirli bir aralikta olan ogrencileri listele" << endl;
		cout << "7 - Basari notu belirtilen bir degerin ustunde olan ogrencileri listele" << endl;
		cout << "8 - Basari notu belirtilen bir degerin altinda olan ogrencileri listele" << endl;

		cout << "Islem: "; cin >> islem_secim;
		// Kullanýcýnýn yaptýðý iþlem seçimine göre ilgili iþlem bloðunu çalýþtýracak switch-case yapýsý kullanýldý
		switch (islem_secim) {
		case 1:
			sinif_listesi(ogrenciler);
			break;

		case 2:
			sinif_max_not(ogrenciler);
			break;

		case 3:
			sinif_min_not(ogrenciler);
			break;
		case 4:
			sinif_ortalama(ogrenciler, 1);
			break;
		case 5:
			sinif_std_sapma(ogrenciler);
			break;
		case 6:
			int min_6, max_6;
			cout << "Maximum deger: "; cin >> max_6;
			cout << "Minimum deger: "; cin >> min_6;
			sinif_basari_sirala_aralik(ogrenciler, min_6, max_6);
			break;
		case 7:
			int min_7;
			cout << "Minimum deger: "; cin >> min_7;
			sinif_basari_sirala_buyuktur(ogrenciler, min_7);
			break;
		case 8:
			int max_8;
			cout << "Maximum deger: "; cin >> max_8;
			sinif_basari_sirala_kucuktur(ogrenciler, max_8);
			break;

		}
		cout << "\n \n \n" << "Baska bir islem yapmak ister misiniz (E/h): ";
		cin >> devammi;



	} while (devammi != 'h');


	return 0;
}

float yil_ici_not(Ogrenci ogrenci) {
	float result = ogrenci.kisa_sinav_1 * 0.07 + ogrenci.kisa_sinav_2 * 0.07 +
		ogrenci.odev_1 * 0.1 + ogrenci.odev_2 * 0.1 + ogrenci.proje * 0.16 + ogrenci.vize * 0.5;
	return result;
}

float basari_not(Ogrenci ogrenci) {
	float result = (ogrenci.final_not * 0.45) + (yil_ici_not(ogrenci) * 0.55);
	return result;
}

string yuzluk_to_harf(float ders_notu) {
	// Notun 90-100 arasýnda olmasý durumunun belirlenmesi için if kullanýldý 
	if (90.00 <= ders_notu and ders_notu <= 100.0)
		return "AA";
	// Notun 85-89 arasýnda olmasý durumunun belirlenmesi için else if kullanýldý
	else if (85.00 <= ders_notu and ders_notu <= 89.99)
		return "BA";
	// Notun 80-84 arasýnda olmasý durumunun belirlenmesi için else if kullanýldý
	else if (80.00 <= ders_notu and ders_notu <= 84.99)
		return "BB";
	// Notun 70-79 arasýnda olmasý durumunun belirlenmesi için else if kullanýldý
	else if (70.00 <= ders_notu and ders_notu <= 79.99)
		return "CB";
	// Notun 60-69 arasýnda olmasý durumunun belirlenmesi için else if kullanýldý
	else if (60.00 <= ders_notu and ders_notu <= 69.99)
		return "CC";
	// Notun 50-59 arasýnda olmasý durumunun belirlenmesi için else if kullanýldý
	else if (50.00 <= ders_notu and ders_notu <= 59.99)
		return "DC";
	// Notun 45-59 arasýnda olmasý durumunun belirlenmesi için else if kullanýldý
	else if (45.00 <= ders_notu and ders_notu <= 49.99)
		return "DD";
	// Notun 0-44 arasýnda olmasý durumunun belirlenmesi için else if kullanýldý
	else if (0.00 <= ders_notu and ders_notu <= 44.99)
		return "FF";
	// Notun 0-100 arasýnda olmamasý durumunun belirlenmesi için else kullanýldý
	else
		return "Bu notun harf karsiligi yoktur";
}

float not_kontrol(float not_degeri, float min, float max) {
	// Notun, önceden belirlenmiþ min deðerinden büyük, max deðerinden küçük olmasý durumunun belirlenmesi için if kullanýldý 
	if (min <= not_degeri and not_degeri <= max)
		return not_degeri;
	// Bir önceki koþul saðlanmadýðý durumda çalýþacak else bloðu
	else {
		cout << "Sorunlu!!! \n";
		cout << "Lutfen tekrar giriniz: "; cin >> not_degeri;
		return not_kontrol(not_degeri, min, max);
	}

}

Ogrenci ogrenci_rastgele_deger_ata(Ogrenci ogrenci, int min, int max) {
	ogrenci.kisa_sinav_1 = rand() % (max - min + 1) + min;
	ogrenci.kisa_sinav_2 = rand() % (max - min + 1) + min;
	ogrenci.odev_1 = rand() % (max - min + 1) + min;
	ogrenci.odev_2 = rand() % (max - min + 1) + min;
	ogrenci.proje = rand() % (max - min + 1) + min;
	ogrenci.vize = rand() % (max - min + 1) + min;
	ogrenci.final_not = rand() % (max - min + 1) + min;
	ogrenci.dogum_tarihi.yil = rand() % (2005 - 1197 + 1) + 1997;
	ogrenci.dogum_tarihi.ay = rand() % (12) + 1;
	ogrenci.dogum_tarihi.gun = rand() % (25) + 1;
	return ogrenci;
}

Ogrenci ogrenci_kullanici_deger_ata(Ogrenci ogrenci) {
	cout << "Ogrenci Adi: "; cin >> ogrenci.adi;
	cout << "Ogrenci Soyadi: "; cin >> ogrenci.soyadi;
	cout << "Ogrenci Numarasi: "; cin >> ogrenci.no;
	cout << "Ogrenci Kisa Sinav 1 Notu: "; cin >> ogrenci.kisa_sinav_1;
	ogrenci.kisa_sinav_1 = not_kontrol(ogrenci.kisa_sinav_1, 0.0, 100.0);
	cout << "Ogrenci Kisa Sinav 2 Notu: "; cin >> ogrenci.kisa_sinav_2;
	ogrenci.kisa_sinav_2 = not_kontrol(ogrenci.kisa_sinav_2, 0.0, 100.0);
	cout << "Ogrenci Odev 1 Notu: "; cin >> ogrenci.odev_1;
	ogrenci.odev_1 = not_kontrol(ogrenci.odev_1, 0.0, 100.0);
	cout << "Ogrenci Odev 2 Notu: "; cin >> ogrenci.odev_2;
	ogrenci.odev_2 = not_kontrol(ogrenci.odev_2, 0.0, 100.0);
	cout << "Ogrenci Proje Notu: "; cin >> ogrenci.proje;
	ogrenci.proje = not_kontrol(ogrenci.proje, 0.0, 100.0);
	cout << "Ogrenci Vize Notu: "; cin >> ogrenci.vize;
	ogrenci.vize = not_kontrol(ogrenci.vize, 0.0, 100.0);
	cout << "Ogrenci Final Notu: "; cin >> ogrenci.final_not;
	ogrenci.final_not = not_kontrol(ogrenci.final_not, 0.0, 100.0);
	cout << "Ogrenci Dogum Gunu: "; cin >> ogrenci.dogum_tarihi.gun;
	ogrenci.dogum_tarihi.gun = not_kontrol(ogrenci.dogum_tarihi.gun, 1, 31);
	cout << "Ogrenci Dogum Ayi: "; cin >> ogrenci.dogum_tarihi.ay;
	ogrenci.dogum_tarihi.ay = not_kontrol(ogrenci.dogum_tarihi.ay, 1, 12);
	cout << "Ogrenci Dogum Yili: "; cin >> ogrenci.dogum_tarihi.yil;
	ogrenci.dogum_tarihi.yil = not_kontrol(ogrenci.dogum_tarihi.yil, 1995, 2006);
	return ogrenci;
}

void sinif_listesi(Ogrenci ogrenciler[100]) {
	int uzunluk = ogrenci_liste_uzunluk_kontrol(ogrenciler);
	int i = 0;
	int i_prev = i;
	char devam;
	/*
	 * Öðrencilerin yirmiþer yirmiþer yazdýrýlmasýnda, 20 öðrenci yazdýrýldýktan sonra yazdýrma iþlemine
	 * kullanýcý isteði doðrultusunda devam edilmesi için do while kullanýldý
	 */
	do {
		system("cls");
		// Öðrenci indisini en son indisten, 20 ilerideki indise kadar bir bir artýran for döngüsü
		for (; i < i_prev + 20; i++)
			cout << i + 1 << " - " << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << endl;

		i_prev = i;
		// Öðrenci indisi 100 den küçük olmasýný kontrol eden if bloðu
		if (i < uzunluk) {
			cout << "Yazdirma islemine devam etmek istiyor musunuz (E/h): "; cin >> devam;
		}
		else
			break;
	} while (devam != 'h');
}

void sinif_max_not(Ogrenci ogrenciler[100]) {
	int uzunluk = ogrenci_liste_uzunluk_kontrol(ogrenciler);
	float max_not = 0;
	int max_ogrenci;
	// 100 öðrencinin indisinin saydýrýlmasý için for döngüsü kullanýldý
	for (int i = 0; i < uzunluk; i++) {
		float ogrenci_notu = basari_not(ogrenciler[i]);
		// Notun, þimdiye kadarki en yüksek nottan büyük olup olmadýðýný kontrol eden if koþulu
		if (max_not < ogrenci_notu) {
			max_not = ogrenci_notu;
			max_ogrenci = i;
		}
	}
	cout << endl << "Siniftaki en yuksek not: " << endl;
	cout << ogrenciler[max_ogrenci].adi << " " << ogrenciler[max_ogrenci].soyadi << "   Basari Notu: " << max_not;
}

void sinif_min_not(Ogrenci ogrenciler[100]) {
	int uzunluk = ogrenci_liste_uzunluk_kontrol(ogrenciler);
	float min_not = 100;
	int min_ogrenci;
	// 100 öðrencinin indisinin saydýrýlmasý için for döngüsü kullanýldý
	for (int i = 0; i < uzunluk; i++) {
		float ogrenci_notu = basari_not(ogrenciler[i]);
		// Notun, þimdiye kadarki en düþük nottan küçük olup olmadýðýný kontrol eden if koþulu
		if (min_not > ogrenci_notu) {
			min_not = ogrenci_notu;
			min_ogrenci = i;
		}

	}
	cout << endl << "Siniftaki en dusuk not: " << endl;
	cout << ogrenciler[min_ogrenci].adi << " " << ogrenciler[min_ogrenci].soyadi << "   Basari Notu: " << min_not;
}

float sinif_ortalama(Ogrenci ogrenciler[100], bool yazdir) {
	int uzunluk = ogrenci_liste_uzunluk_kontrol(ogrenciler);
	float toplam_not = 0;
	// 100 öðrencinin indisinin saydýrýlmasý için for döngüsü kullanýldý
	for (int i = 0; i < uzunluk; i++) {
		toplam_not += basari_not(ogrenciler[i]);
	}
	// Ortalamanýn ekrana yazdýrýlmak istenip istenmediðinin belirlenmesi için if kullanýldý	
	if (yazdir == 1) {
		cout << endl << "Sinifin Ortalamasi: " << toplam_not / float(uzunluk);
		return 0;
	}

	else
		return toplam_not / float(uzunluk);
}

void sinif_std_sapma(Ogrenci ogrenciler[100]) {
	int uzunluk = ogrenci_liste_uzunluk_kontrol(ogrenciler);
	float ort = sinif_ortalama(ogrenciler, 0);
	float not_eksi_ort_toplam=0;
	// 100 öðrencinin indisinin saydýrýlmasý için for döngüsü kullanýldý
	for (int i = 0; i < uzunluk; i++) {
		not_eksi_ort_toplam += pow((basari_not(ogrenciler[i]) - ort), 2);
	}

	cout << endl << "Sinifin Standart Sapmasi: " << sqrt((not_eksi_ort_toplam) / ((float)uzunluk));

}

void sinif_basari_sirala_aralik(Ogrenci ogrenciler[100], float min, float max) {
	int uzunluk = ogrenci_liste_uzunluk_kontrol(ogrenciler);
	float notu;
	system("cls");
	cout << "Isim Soyisim" << setw(23) << "Basari Notu" << setw(27) << "Harf Notu" << endl;
	cout << "*******************************************************************" << endl;
	// 100 öðrencinin indisinin saydýrýlmasý için for döngüsü kullanýldý
	for (int i = 0; i < uzunluk; i++) {
		notu = basari_not(ogrenciler[i]);
		// Notun, önceden belirlenmiþ max deðerden küçük, min deðerden büyük olup olmadýðýný kontrol eden if koþulu
		if (min <= notu and notu <= max) {
			cout << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << setw(23) << "Basari Notu: ";
			cout << setprecision(4) << notu << setw(17) << yuzluk_to_harf(basari_not(ogrenciler[i])) << endl;
		}
	}

}

void sinif_basari_sirala_buyuktur(Ogrenci ogrenciler[100], float min) {
	int uzunluk = ogrenci_liste_uzunluk_kontrol(ogrenciler);
	float notu;
	system("cls");
	cout << "Isim Soyisim" << setw(23) << "Basari Notu" << setw(27) << "Harf Notu" << endl;
	cout << "*******************************************************************" << endl;
	// 100 öðrencinin indisinin saydýrýlmasý için for döngüsü kullanýldý
	for (int i = 0; i < uzunluk; i++) {
		notu = basari_not(ogrenciler[i]);
		// Notun, önceden belirlenmiþ min deðerden büyük olup olmadýðýný kontrol eden if koþulu
		if (min < notu) {
			cout << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << setw(23) << "Basari Notu: ";
			cout << setprecision(4) << notu << setw(17) << yuzluk_to_harf(basari_not(ogrenciler[i])) << endl;
		}
	}

}

void sinif_basari_sirala_kucuktur(Ogrenci ogrenciler[100], float max) {
	int uzunluk = ogrenci_liste_uzunluk_kontrol(ogrenciler);
	float notu;
	system("cls");
	cout << "Isim Soyisim" << setw(23) << "Basari Notu" << setw(27) << "Harf Notu" << endl;
	cout << "*******************************************************************" << endl;
	// 100 öðrencinin indisinin saydýrýlmasý için for döngüsü kullanýldý
	for (int i = 0; i < uzunluk; i++) {
		notu = basari_not(ogrenciler[i]);
		// Notun, önceden belirlenmiþ max deðerden küçük olup olmadýðýný kontrol eden if koþulu
		if (notu < max) {
			cout << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << setw(23) << "Basari Notu: ";
			cout << setprecision(4) << notu << setw(17) << yuzluk_to_harf(basari_not(ogrenciler[i])) << endl;
		}
	}

}

int ogrenci_liste_uzunluk_kontrol(Ogrenci ogrenciler[100]) {
	int uzunluk = 0;
	for (int i = 0; i < 100; i++) {
		if (ogrenciler[i].adi.size() != 0) {
			uzunluk += 1;
		}
	}
	return uzunluk;
}




