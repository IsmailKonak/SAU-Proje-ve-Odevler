
/*************************************************************************
**							Sakarya Üniversitesi
**				  Bilgisayar ve Biliþim Bilimleri Fakültesi
**					   Bilgisayar Mühendisliði Bölümü
**   					  Programlamaya Giriþ Dersi
*
*
* 				Ödev Numarasý: 2
* 				Öðrenci Adý: Ýsmail Konak
* 				Öðrenci Numarasý: G221210046
* 				Ders Grubu: A
*
***************************************************************************/


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;



class Karmasik_Sayi {
private:
	float reel, sanal;
public:
	Karmasik_Sayi(float r = 0, float s = 0) { reel = r;   sanal = s; }

	void ifade() { cout<< reel << " + (" << sanal << ")i" << endl; }
	Karmasik_Sayi operator + (Karmasik_Sayi const & karmasik_sayi2) {
		Karmasik_Sayi sonuc;
		sonuc.reel = reel + karmasik_sayi2.reel;
		sonuc.sanal = sanal + karmasik_sayi2.sanal;
		return sonuc;
	}
	Karmasik_Sayi operator + (float sayi) {
		Karmasik_Sayi sonuc;
		sonuc.reel = reel + sayi;
		sonuc.sanal = sanal;
		return sonuc;
	}
	Karmasik_Sayi operator - (Karmasik_Sayi const& karmasik_sayi2) {
		Karmasik_Sayi sonuc;
		sonuc.reel = reel - karmasik_sayi2.reel;
		sonuc.sanal = sanal - karmasik_sayi2.sanal;
		return sonuc;
	}
	Karmasik_Sayi operator - (float sayi) {
		Karmasik_Sayi sonuc;
		sonuc.reel = reel - sayi;
		sonuc.sanal = sanal;
		return sonuc;
	}
	Karmasik_Sayi operator * (Karmasik_Sayi const& karmasik_sayi2) {
		Karmasik_Sayi sonuc;
		sonuc.reel = reel * karmasik_sayi2.reel + (-1) * (sanal * karmasik_sayi2.sanal);
		sonuc.sanal = reel * karmasik_sayi2.sanal + karmasik_sayi2.reel * sanal;
		return sonuc;
	}
	Karmasik_Sayi operator * (float sayi) {
		Karmasik_Sayi sonuc;
		sonuc.reel = reel * sayi;
		sonuc.sanal = sayi * sanal;
		return sonuc;
	}
	Karmasik_Sayi operator / (Karmasik_Sayi const& karmasik_sayi2) {
		Karmasik_Sayi sonuc;
		sonuc.reel = (reel* karmasik_sayi2.reel - (-1)*(sanal* karmasik_sayi2.sanal))/(pow(karmasik_sayi2.reel,2) + pow(karmasik_sayi2.sanal,2));
		sonuc.sanal = (karmasik_sayi2.reel*sanal - reel* karmasik_sayi2.sanal) / (pow(karmasik_sayi2.reel, 2) + pow(karmasik_sayi2.sanal, 2));
		return sonuc;
	}
	Karmasik_Sayi operator / (float sayi) {
		Karmasik_Sayi sonuc;
		sonuc.reel = reel / sayi;
		sonuc.sanal = sanal / sayi;
		return sonuc;
	}
	void operator += (Karmasik_Sayi const& karmasik_sayi2) {
		reel = reel + karmasik_sayi2.reel;
		sanal = sanal + karmasik_sayi2.sanal;
	}
	void operator += (float sayi) {
		reel = reel + sayi;
		
	}
	void operator -= (Karmasik_Sayi const& karmasik_sayi2) {
		reel = reel - karmasik_sayi2.reel;
		sanal = sanal - karmasik_sayi2.sanal;
	}
	void operator -= (float sayi) {
		reel = reel - sayi;
	}
	void operator *= (Karmasik_Sayi const& karmasik_sayi2) {
		Karmasik_Sayi islem;
		islem.reel = reel * karmasik_sayi2.reel + (-1) * (sanal * karmasik_sayi2.sanal);
		islem.sanal = reel * karmasik_sayi2.sanal + karmasik_sayi2.reel * sanal;
		reel = islem.reel;
		sanal = islem.sanal;
	}
	void operator *= (float sayi) {
		reel = reel * sayi;
		sanal = sayi * sanal;
	}
	void operator /= (Karmasik_Sayi const& karmasik_sayi2) {
		Karmasik_Sayi islem;
		islem.reel = (reel * karmasik_sayi2.reel - (-1) * (sanal * karmasik_sayi2.sanal)) / (pow(karmasik_sayi2.reel, 2) + pow(karmasik_sayi2.sanal, 2));
		islem.sanal = (karmasik_sayi2.reel * sanal - reel * karmasik_sayi2.sanal) / (pow(karmasik_sayi2.reel, 2) + pow(karmasik_sayi2.sanal, 2));
		reel = islem.reel;
		sanal = islem.sanal;
	}
	void operator /= (float sayi) {
		reel = reel/sayi;
		sanal = sanal/sayi;
	}
	void kutupsal_gosterim() {
		double tan_a = sanal / reel;
		float pi = 3.14159265359;
		double a = atan(tan_a*(180/pi));
		cout << sqrt(pow(sanal, 2) + pow(reel, 2)) << "( cis("<< a <<"))"<<endl;
	}

};

Karmasik_Sayi k_sayi_tanimla() {
	float reel, sanal;
	cout << "Bir karmasik sayi tanimlayin: " << endl;
	cout << setw(5) << " " << "Gercel (Reel) Kisim: ";
	cin >> reel;
	cout << setw(5) << " " << "Sanal (Imajiner) Kisim: ";
	cin >> sanal;
	Karmasik_Sayi sayi(reel, sanal);
	return sayi;
}
int parametre2() {
	int secim2;
	cout << "\n Parametre 2: " << endl;
	cout << setw(5) << " " << "1) Sonucu karmasik sayiya kaydet ve yazdir" << endl;
	cout << setw(5) << " " << "2) Sonucu yalnizca yazdir" << endl;
	cout << setw(5) << " " << "Seciminiz: "; cin >> secim2;
	return secim2;
}
int parametre1() {
	int secim3;
	cout << "\n Parametre 1: " << endl;
	cout << setw(5) << " " << "1) Bu karmasik sayi ile gercel bir sayi arasinda islem yap"<<endl;
	cout << setw(5) << " " << "2) Bu karmasik sayi ile karmasik bir sayi arasinda islem yap"<<endl;
	cout << setw(5) << " " << "Seciminiz: "; cin >> secim3;
	return secim3;
}


int main() {
	int secim1, secim2, secim3;
	char devamtamam;
	cout << setw(35)<<" "<< "Karmasik Sayilarla Islem Menusune Hos Geldiniz" << "\n \n";
	Karmasik_Sayi baslangic_sayi = k_sayi_tanimla();
	// Ýþlem menüsü kullanýcý 'h' basmadýðý sürece çalýþmasý için do-while döngüsü kullanýldý
	do{
		system("CLS");
		cout << endl << endl << "Karmasik Sayiniz: ";
		baslangic_sayi.ifade();
		cout << "\n Bu karmasik sayi ile hangi islemi yapmak istersiniz? " << endl;
		cout << "1) Toplama" << endl;
		cout << "2) Cikarma" << endl;
		cout << "3) Carpma" << endl;
		cout << "4) Bolme" << endl;
		cout << "5) Kutupsal Gosterim"<< endl;
		cout << "Seciminiz: "; cin >> secim1;
		// Ýþlem menüsünde kullanýcýnýn yaptýðý seçimlere göre iþlem yapýlabilmesi için switch-case yapýsý koþul kullanýldý
		switch (secim1)
		{
		case 1:
			secim3 = parametre1();
			secim2 = parametre2();
			// Yapýlacak iþlemde kullanýcý tarafýndan girilecek sayýnýn
			// gerçel bir sayý olmasý durumunda çalýþacak if bloku
			if (secim3 == 2) {
				Karmasik_Sayi islem_sayi = k_sayi_tanimla();
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmesi durumunda çalýþacak if bloku
				if (secim2 == 1) {
					baslangic_sayi += islem_sayi;
					cout << "Sonuc: ";
					baslangic_sayi.ifade();
				}
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmemesi durumunda çalýþacak else if bloku
				else if (secim2 == 2) {
					cout << "Sonuc: ";
					(baslangic_sayi + islem_sayi).ifade();
				}
			}
			// Yapýlacak iþlemde kullanýcý tarafýndan girilecek sayýnýn
			// karmaþýk bir sayý olmasý durumunda çalýþacak else if bloku
			else if (secim3 == 1) {
				float sayi;
				cout << "Bir sayi giriniz: "; cin >> sayi;
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmesi durumunda çalýþacak if bloku
				if (secim2 == 1) {
					baslangic_sayi += sayi;
					cout << "Sonuc: ";
					baslangic_sayi.ifade();
				}
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmemesi durumunda çalýþacak else if bloku
				else if (secim2 == 2) {
					cout << "Sonuc: ";
					(baslangic_sayi + sayi).ifade();
				}
			}
			break;
		case 2:
			secim3 = parametre1();
			secim2 = parametre2();
			// Yapýlacak iþlemde kullanýcý tarafýndan girilecek sayýnýn
			// gerçel bir sayý olmasý durumunda çalýþacak if bloku
			if (secim3 == 2) {
				Karmasik_Sayi islem_sayi = k_sayi_tanimla();
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmesi durumunda çalýþacak if bloku
				if (secim2 == 1) {
					baslangic_sayi -= islem_sayi;
					cout << "Sonuc: ";
					baslangic_sayi.ifade();
				}
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmemesi durumunda çalýþacak else if bloku
				else if (secim2 == 2) {
					cout << "Sonuc: ";
					(baslangic_sayi - islem_sayi).ifade();
				}
			}
			// Yapýlacak iþlemde kullanýcý tarafýndan girilecek sayýnýn
			// karmaþýk bir sayý olmasý durumunda çalýþacak else if bloku
			else if (secim3 == 1) {
				float sayi;
				cout << "Bir sayi giriniz: "; cin >> sayi;
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmesi durumunda çalýþacak if bloku
				if (secim2 == 1) {
					baslangic_sayi -= sayi;
					cout << "Sonuc: ";
					baslangic_sayi.ifade();
				}
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmemesi durumunda çalýþacak else if bloku
				else if (secim2 == 2) {
					cout << "Sonuc: ";
					(baslangic_sayi - sayi).ifade();
				}
			}
			break;
		case 3:
			secim3 = parametre1();
			secim2 = parametre2();
			// Yapýlacak iþlemde kullanýcý tarafýndan girilecek sayýnýn
			// gerçel bir sayý olmasý durumunda çalýþacak if bloku
			if (secim3 == 2) {
				Karmasik_Sayi islem_sayi = k_sayi_tanimla();
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmesi durumunda çalýþacak if bloku
				if (secim2 == 1) {
					baslangic_sayi *= islem_sayi;
					cout << "Sonuc: ";
					baslangic_sayi.ifade();
				}
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmemesi durumunda çalýþacak else if bloku
				else if (secim2 == 2) {
					cout << "Sonuc: ";
					(baslangic_sayi * islem_sayi).ifade();
				}
			}
			// Yapýlacak iþlemde kullanýcý tarafýndan girilecek sayýnýn
			// karmaþýk bir sayý olmasý durumunda çalýþacak else if bloku
			else if (secim3 == 1) {
				float sayi;
				cout << "Bir sayi giriniz: "; cin >> sayi;
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmesi durumunda çalýþacak if bloku
				if (secim2 == 1) {
					baslangic_sayi *= sayi;
					cout << "Sonuc: ";
					baslangic_sayi.ifade();
				}
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmemesi durumunda çalýþacak else if bloku
				else if (secim2 == 2) {
					cout << "Sonuc: ";
					(baslangic_sayi * sayi).ifade();
				}
			}
			break;
		case 4:
			secim3 = parametre1();
			secim2 = parametre2();
			// Yapýlacak iþlemde kullanýcý tarafýndan girilecek sayýnýn
			// gerçel bir sayý olmasý durumunda çalýþacak if bloku
			if (secim3 == 2) {
				Karmasik_Sayi islem_sayi = k_sayi_tanimla();
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmesi durumunda çalýþacak if bloku
				if (secim2 == 1) {
					baslangic_sayi /= islem_sayi;
					cout << "Sonuc: ";
					baslangic_sayi.ifade();
				}
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmemesi durumunda çalýþacak else if bloku
				else if (secim2 == 2) {
					cout << "Sonuc: ";
					(baslangic_sayi / islem_sayi).ifade();
				}
			}
			// Yapýlacak iþlemde kullanýcý tarafýndan girilecek sayýnýn
			// karmaþýk bir sayý olmasý durumunda çalýþacak else if bloku
			else if (secim3 == 1) {
				float sayi;
				do { cout << "Bir sayi giriniz: "; cin >> sayi; } while (sayi == 0);
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmesi durumunda çalýþacak if bloku
				if (secim2 == 1) {
					baslangic_sayi /= sayi;
					cout << "Sonuc: ";
					baslangic_sayi.ifade();
				}
				// Yapýlacak iþlemin sonucunun iþlem yapýlan sayýya kaydedilmemesi durumunda çalýþacak else if bloku
				else if (secim2 == 2) {
					cout << "Sonuc: ";
					(baslangic_sayi / sayi).ifade();
				}
			}
		
			break;
		case 5:
			baslangic_sayi.kutupsal_gosterim();
			break;

		default:
			cout << "Bu numaralý tercih tanýmlanmadý, lütfen tekar tercih yapýnýz"<<endl;
			break;
		}
		cout << "\n \n Baska islem yapmak ister misiniz (E/h): "; cin >> devamtamam;
	} while (devamtamam != 'h');
	return 0;
}