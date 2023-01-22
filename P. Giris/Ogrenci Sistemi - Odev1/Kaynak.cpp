/*************************************************************************
* 							Sakarya �niversitesi
*				  Bilgisayar ve Bili�im Bilimleri Fak�ltesi
*					   Bilgisayar M�hendisli�i B�l�m�
*   					  Programlamaya Giri� Dersi
*
*
* 				�dev Numaras�: 1
* 				��renci Ad�: �smail Konak
* 				��renci Numaras�: 
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

	// Kaydedilecek ��renciler ile ilgili verilerin kay�t y�ntemi se�imindeki, se�ilmesi durumunda verilerin rastgele atanaca�� olan ilk if blo�u
	if (secim == 1) {
		// 100 ��rencinin verilerinin rastgele atanabilmesi amac�yla ogrenciler dizisinin 
		// indislerinin d�nd�r�lmesi i�in for d�ng�s� kullan�ld�
		for (int i = 0; i < 100; i++) {
			ogrenciler[i].adi = isimler[rand() % 30];
			ogrenciler[i].soyadi = soyisimler[rand() % 30];

			// ��rencilerin %10'una tekab�l edecek, notu 0-40 aras�nda olacak olan listedeki 0. ile 10. ki�i aras�ndaki ki�ilerin belirlenmesi i�in if kullan�ld�
			if (i < 10) {
				ogrenciler[i] = ogrenci_rastgele_deger_ata(ogrenciler[i], 0.0, 40.0);
			}
			// ��rencilerin %50'sine tekab�l edecek, notu 40-70 aras�nda olacak olan listedeki 10. ile 60. ki�i aras�ndaki ki�ilerin belirlenmesi i�in if kullan�ld�
			if (10 <= i and i < 60) {
				ogrenciler[i] = ogrenci_rastgele_deger_ata(ogrenciler[i], 40.0, 70.0);
			}
			// ��rencilerin %15'ine tekab�l edecek, notu 70-80 aras�nda olacak olan listedeki 60. ile 75. ki�i aras�ndaki ki�ilerin belirlenmesi i�in if kullan�ld�
			if (60 <= i and i < 75) {
				ogrenciler[i] = ogrenci_rastgele_deger_ata(ogrenciler[i], 70.0, 80.0);
			}
			// ��rencilerin %25'ine tekab�l edecek, notu 80-100 aras�nda olacak olan listedeki 75. ile 100. ki�i aras�ndaki ki�ilerin belirlenmesi i�in if kullan�ld�
			if (75 <= i and i < 100) {
				ogrenciler[i] = ogrenci_rastgele_deger_ata(ogrenciler[i], 80.0, 100.0);
			}
		}
	}
	// Kaydedilecek ��renciler ile ilgili verilerin kay�t y�ntemi se�imindeki, se�ilmesi durumunda verileri kullan�c�n�n atayacaca�� ikinci else if blo�u
	else if (secim == 2) {
		// 100 ��rencinin verilerinin kullan�c� taraf�ndan atanabilmesi amac�yla ogrenciler dizisinin 
		// indislerinin d�nd�r�lmesi i�in for d�ng�s� kullan�ld�
		for (int i = 0; i < 100; i++) {
			cout << "Ogrenci Kaydetme Sistemine Hosgeldiniz " << endl;
			cout << "Ogrenci Index: " << i << endl;
			ogrenciler[i] = ogrenci_kullanici_deger_ata(ogrenciler[i]);
			cout << "Tebrikler!!! Ogrenci basariyla kaydedildi" << endl;
			char devam;
			cout << "Baska bir ogrenci daha kaydetmek istiyor musun (e/H): "; cin >> devam;
			// Kullan�c�n�n ��renci kaydetmeye devam edip etmek istemedi�inin belirlenmesi i�in if kullan�ld�
			if (devam != 'e')
				break;
		}
	}
	char devammi;
	// ��lemler Men�s�n�n kullan�c� istedi�i s�rece kullan�lmas� i�in do while d�ng�s� kullan�ld�
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
		// Kullan�c�n�n yapt��� i�lem se�imine g�re ilgili i�lem blo�unu �al��t�racak switch-case yap�s� kullan�ld�
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
	// Notun 90-100 aras�nda olmas� durumunun belirlenmesi i�in if kullan�ld� 
	if (90.00 <= ders_notu and ders_notu <= 100.0)
		return "AA";
	// Notun 85-89 aras�nda olmas� durumunun belirlenmesi i�in else if kullan�ld�
	else if (85.00 <= ders_notu and ders_notu <= 89.99)
		return "BA";
	// Notun 80-84 aras�nda olmas� durumunun belirlenmesi i�in else if kullan�ld�
	else if (80.00 <= ders_notu and ders_notu <= 84.99)
		return "BB";
	// Notun 70-79 aras�nda olmas� durumunun belirlenmesi i�in else if kullan�ld�
	else if (70.00 <= ders_notu and ders_notu <= 79.99)
		return "CB";
	// Notun 60-69 aras�nda olmas� durumunun belirlenmesi i�in else if kullan�ld�
	else if (60.00 <= ders_notu and ders_notu <= 69.99)
		return "CC";
	// Notun 50-59 aras�nda olmas� durumunun belirlenmesi i�in else if kullan�ld�
	else if (50.00 <= ders_notu and ders_notu <= 59.99)
		return "DC";
	// Notun 45-59 aras�nda olmas� durumunun belirlenmesi i�in else if kullan�ld�
	else if (45.00 <= ders_notu and ders_notu <= 49.99)
		return "DD";
	// Notun 0-44 aras�nda olmas� durumunun belirlenmesi i�in else if kullan�ld�
	else if (0.00 <= ders_notu and ders_notu <= 44.99)
		return "FF";
	// Notun 0-100 aras�nda olmamas� durumunun belirlenmesi i�in else kullan�ld�
	else
		return "Bu notun harf karsiligi yoktur";
}

float not_kontrol(float not_degeri, float min, float max) {
	// Notun, �nceden belirlenmi� min de�erinden b�y�k, max de�erinden k���k olmas� durumunun belirlenmesi i�in if kullan�ld� 
	if (min <= not_degeri and not_degeri <= max)
		return not_degeri;
	// Bir �nceki ko�ul sa�lanmad��� durumda �al��acak else blo�u
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
	 * ��rencilerin yirmi�er yirmi�er yazd�r�lmas�nda, 20 ��renci yazd�r�ld�ktan sonra yazd�rma i�lemine
	 * kullan�c� iste�i do�rultusunda devam edilmesi i�in do while kullan�ld�
	 */
	do {
		system("cls");
		// ��renci indisini en son indisten, 20 ilerideki indise kadar bir bir art�ran for d�ng�s�
		for (; i < i_prev + 20; i++)
			cout << i + 1 << " - " << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << endl;

		i_prev = i;
		// ��renci indisi 100 den k���k olmas�n� kontrol eden if blo�u
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
	// 100 ��rencinin indisinin sayd�r�lmas� i�in for d�ng�s� kullan�ld�
	for (int i = 0; i < uzunluk; i++) {
		float ogrenci_notu = basari_not(ogrenciler[i]);
		// Notun, �imdiye kadarki en y�ksek nottan b�y�k olup olmad���n� kontrol eden if ko�ulu
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
	// 100 ��rencinin indisinin sayd�r�lmas� i�in for d�ng�s� kullan�ld�
	for (int i = 0; i < uzunluk; i++) {
		float ogrenci_notu = basari_not(ogrenciler[i]);
		// Notun, �imdiye kadarki en d���k nottan k���k olup olmad���n� kontrol eden if ko�ulu
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
	// 100 ��rencinin indisinin sayd�r�lmas� i�in for d�ng�s� kullan�ld�
	for (int i = 0; i < uzunluk; i++) {
		toplam_not += basari_not(ogrenciler[i]);
	}
	// Ortalaman�n ekrana yazd�r�lmak istenip istenmedi�inin belirlenmesi i�in if kullan�ld�	
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
	// 100 ��rencinin indisinin sayd�r�lmas� i�in for d�ng�s� kullan�ld�
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
	// 100 ��rencinin indisinin sayd�r�lmas� i�in for d�ng�s� kullan�ld�
	for (int i = 0; i < uzunluk; i++) {
		notu = basari_not(ogrenciler[i]);
		// Notun, �nceden belirlenmi� max de�erden k���k, min de�erden b�y�k olup olmad���n� kontrol eden if ko�ulu
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
	// 100 ��rencinin indisinin sayd�r�lmas� i�in for d�ng�s� kullan�ld�
	for (int i = 0; i < uzunluk; i++) {
		notu = basari_not(ogrenciler[i]);
		// Notun, �nceden belirlenmi� min de�erden b�y�k olup olmad���n� kontrol eden if ko�ulu
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
	// 100 ��rencinin indisinin sayd�r�lmas� i�in for d�ng�s� kullan�ld�
	for (int i = 0; i < uzunluk; i++) {
		notu = basari_not(ogrenciler[i]);
		// Notun, �nceden belirlenmi� max de�erden k���k olup olmad���n� kontrol eden if ko�ulu
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




