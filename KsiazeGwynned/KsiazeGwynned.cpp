#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <Windows.h>

using namespace std;

class Gracz {
	string imie;
public:
	int drewno = 0;
	int kamien = 0;
	int metal = 0;
	int liczba_wojsk = 1000;
	int czas_do_bitwy = 300;
	string rejestracja() {
		cout << endl;
		cout << "  Witaj wielmożny podaj swoje imię : ";
		cin >> imie;
		system("cls");
		cout << endl;
		cout << "  Witaj " << imie << ". Jest wiek VIII a ty, wcielisz się w rolę jednego z Walijskich władców." << endl << endl;;
		_getch();
		cout << "  W tamtym okresie plemiona Walijskie musiały zmierzyć się z inwazją Anglosasów." << endl << endl;
		_getch();
		cout << "  Twoje ziemie leżą w strategicznym punkcie, jeśli stracisz panowanie nad nimi" << endl;
		cout << "  twoi sojusznicy nie będą mieli szans na obronę, to od ciebie zależy twoja i ich niepodległość!" << endl << endl;
		_getch();
		cout << "  Zdobywaj surowce i dysponuj nimi mądrze, zgromadź więcej wojowników niż ma twój przeciwnik, by wygrać bitwę." << endl;
		cout << "  Przeciwnik ma wystarczająco wojsk na 3 ataki, jeśli odeprzesz wszystkie 3, wygrasz wojnę." << endl;
		cout << "  Gdy czas do bitwy ubiegnie końca rozpocznie się pojedynek." << endl << endl;
		_getch();
		cout << "  Nie zdołasz pokonać przeciwników, gdy zaniedbasz rozbudowę osady." << endl;
		cout << "  Do ulepszania budowli niezbędna jest odpowiednia ilośc surowców," << endl;
		cout << "  którą możemy wyczytać przed możliwością ulepszenia." << endl << endl;
		_getch();
		cout << "  Podnoszenie poziomu lasu, kamieniołomu czy kopalni podniesie Ci zarobki godzinowe," << endl;
		cout << "  a z kolei poziom koszar pozwoli ci na rekrutację i lepszą opłacalność rekrutajci wojsk." << endl << endl;
		_getch();
		cout << "  W ratuszu istnieje opcja wyboru 'Zwiadowcy', pod którą kryje się ważny dla ciebie list," << endl;
		cout << "  przeczytaj go, a ułatwi Ci on ustalenie strategii gry." << endl << endl;
		_getch();
		cout << "  Po skończonym wstępnie zostaniesz przeniesiony do menu, w którym będziesz mogł" << endl;
		cout << "  przenosić się pomiędzy miejscami, zdobywać surowce, jak i pobierać " << endl;
		cout << "  informacje na temat postaci, ilości zrekrutowanych wojsk czy ilości pozostałego czasu do starcia. " << endl << endl;
		_getch();
		cout << "  Pamiętaj, aby prawidłowo zarządzać czasem, co jest niezbędne do zebrania większej ilości wojsk od wroga." << endl << endl;
		cout << "  Powodzenia !!!" << endl << endl;


		cout << "  Naciśnij dowolny klawisz, by rozpocząć grę" << endl;
		_getch();
		system("cls");
		return imie;
	}
	void idz_ratusz() {
		system("cls");
		cout << endl;
		cout << "  Witaj w ratuszu, tu możesz sprawdzić stan swoich surowców" << endl << endl;
		cout << "  Ulepsz koszary       [1]" << endl;
		cout << "  Ulepsz las           [2]" << endl;
		cout << "  Ulepsz kamieniołom   [3]" << endl;
		cout << "  Ulepsz kopalnia      [4]" << endl;
		cout << "  Zwiadowcy            [5]" << endl;
		cout << "  Wróć do osady        [6]" << endl;
	}
	void idz_koszary() {
		system("cls");
		cout << endl;
		cout << "  Witaj w koszarach, tu możesz rekrutować nowych wojowników" << endl << endl;
		cout << "  Rekrutuj wojska      [1]" << endl;
		cout << "  Wróć do osady        [2]" << endl;
	}
	void idz_las() {
		system("cls");
		cout << endl;
		cout << "  Witaj w lesie, tu możesz pracować za drewno" << endl << endl;
		cout << "  Pracuj(drewno)       [1]" << endl;
		cout << "  Wróć do osady        [2]" << endl;
	}
	void idz_kamieniolom() {
		system("cls");
		cout << endl;
		cout << "  Witaj w kamieniołomie tu możesz pracować za kamień" << endl << endl;
		cout << "  Pracuj(kamień)       [1]" << endl;
		cout << "  Wróć do osady        [2]" << endl;
	}
	void idz_kopalnia() {
		system("cls");
		cout << endl;
		cout << "  Witaj w kopalni tu możesz pracować za metal" << endl << endl;
		cout << "  Pracuj(metal)        [1]" << endl;
		cout << "  Wróć do osady        [2]" << endl;
	}
	void zasoby() {

		cout << " ----------------------------------" << endl;
		cout << "  Do bitwy zostało " << czas_do_bitwy << "h" << endl;
		cout << "  Oto stan twoich surowców:" << endl;
		cout << "  Drewno: " << drewno << " kłód" << endl;
		cout << "  Kamien: " << kamien << " skał" << endl;
		cout << "  Metal: " << metal << " sztabek" << endl;
		cout << "  Wojska: " << liczba_wojsk << endl;
		cout << " ----------------------------------" << endl;

	}
};

class Budowle : public Gracz {
public:
	int czas_pracy;
	int zarobki;

	void timer(int a) {
		system("cls");
		for (int i = a; i >= 1; i--)
		{
			cout << endl;
			cout << "  Pozostały czas pracy: ";
			cout << a << "h";
			a--;
			Sleep(200);
			system("cls");
		}
	}
	void wydobywaj() {
		cout << endl;
		cout << "  Ile godzin chcesz pracować?" << endl;
		cout << "  ";
		cin >> czas_pracy;
		timer(czas_pracy);
	}
};

class Ratusz : public Budowle {
public:
	int poziom = 1;
	int koszty_drewno = 80;
	int koszty_kamien = 100;
	int koszty_metal = 60;

	/*
	void ulepsz_ratusz() {
		cout << "  Ulepszyłeś ratusz do poziomu : " << poziom << endl;
		koszty_drewno = koszty_drewno + poziom * 10;
		koszty_kamien = koszty_kamien + poziom * 10;
		koszty_metal = koszty_metal + poziom * 10;
		poziom++;
		_getch();
		system("cls");
	}
	*/
};

class Koszary : public Budowle {
public:
	int rekruci;
	int poziom = 1;
	int koszty_drewno = 150;
	int koszty_kamien = 200;
	int koszty_metal = 350;

	void ulepsz_koszary() {
		system("cls");
		cout << endl;
		cout << "  Ulepszyłeś koszary do poziomu : " << poziom + 1 << endl;
		koszty_drewno = koszty_drewno + poziom * 10;
		koszty_kamien = koszty_kamien + poziom * 10;
		koszty_metal = koszty_metal + poziom * 10;
		poziom++;
		_getch();
		system("cls");
	}

	int* rekrutacja() {

		if (rekruci != 1)
		{
			cout << endl;
			cout << "  Zrekrutowałeś " << rekruci << " wojowników!" << endl;
		}
		else
		{
			cout << endl;
			cout << "  Zrekrutowałeś " << rekruci << " wojownika!" << endl;
		}
		int rekrutowanie[4] = { rekruci, Gracz::drewno, Gracz::kamien, Gracz::metal };
		return rekrutowanie;
	}
};

class Las : public Budowle {
public:
	int poziom = 1;
	int koszty_drewno = 100;
	int koszty_kamien = 50;
	int koszty_metal = 50;

	void ulepsz_las() {
		system("cls");
		cout << endl;
		cout << "  Ulepszyłeś las do poziomu : " << poziom + 1 << endl;
		koszty_drewno = koszty_drewno + poziom * 10;
		koszty_kamien = koszty_kamien + poziom * 10;
		koszty_metal = koszty_metal + poziom * 10;
		poziom++;
		_getch();
		system("cls");
	}

	int* wydobywaj_drewno() {
		wydobywaj();
		zarobki = czas_pracy * 10 * poziom;
		Gracz::drewno = Gracz::drewno + zarobki;
		int wydobywajdrewno[2] = { Gracz::drewno, czas_pracy };
		return wydobywajdrewno;
		system("cls");
	}
};

class Kamieniolom : public Budowle {
public:
	int poziom = 1;
	int koszty_drewno = 50;
	int koszty_kamien = 100;
	int koszty_metal = 50;

	void ulepsz_kamieniolom() {
		system("cls");
		cout << endl;
		cout << "  Ulepszyłeś kamieniołom do poziomu : " << poziom + 1 << endl;
		koszty_drewno = koszty_drewno + poziom * 10;
		koszty_kamien = koszty_kamien + poziom * 10;
		koszty_metal = koszty_metal + poziom * 10;
		poziom++;
		_getch();
		system("cls");
	}

	int* wydobywaj_kamien() {
		wydobywaj();
		zarobki = czas_pracy * 10 * poziom;
		Gracz::kamien = Gracz::kamien + zarobki;
		int wydobywajkamien[2] = { Gracz::kamien, czas_pracy };
		return wydobywajkamien;
		system("cls");
	}
};

class Kopalnia : public Budowle {
public:
	int poziom = 1;
	int koszty_drewno = 150;
	int koszty_kamien = 100;
	int koszty_metal = 50;

	void ulepsz_kopalnia() {
		system("cls");
		cout << endl;
		cout << "  Ulepszyłeś kopalnie do poziomu : " << poziom + 1 << endl;
		koszty_drewno = koszty_drewno + poziom * 10;
		koszty_kamien = koszty_kamien + poziom * 10;
		koszty_metal = koszty_metal + poziom * 10;
		poziom++;
		_getch();
		system("cls");
	}

	int* wydobywaj_metal() {
		wydobywaj();
		zarobki = czas_pracy * 10 * poziom;
		Gracz::metal = Gracz::metal + zarobki;
		int wydobywajmetal[2] = { Gracz::metal, czas_pracy };
		return wydobywajmetal;
		system("cls");
	}
};

class Przeciwnik {
public:
	int wojska = 1000;
	int numer_ataku = 1;


	int atakuj() {
		numer_ataku += 1;
		wojska += 500;
		return wojska;
	}
};


int main()
{
	setlocale(LC_CTYPE, "Polish");
	Gracz gracz;
	Budowle budowle;
	Ratusz ratusz;
	Koszary koszary;
	Las las;
	Kamieniolom kamieniolom;
	Kopalnia kopalnia;
	Przeciwnik przeciwnik;
	//Nadanie nazwy dla gracza i wyjaśnienie mu zasad gry
	gracz.rejestracja();

	//Wyświetlenie wstępnego menu i zasobów gracza
	bool koniec_gry = true;
	while (koniec_gry)
	{
		do {
			char wybor;
			system("cls");
			cout << endl;
			cout << "  Wybierz, gdzie chcesz się udać: " << endl;
			cout << endl;

			cout << "  Ratusz             [1]" << endl;
			cout << "  Koszary            [2]" << endl;
			cout << "  Las                [3]" << endl;
			cout << "  Kamieniolom        [4]" << endl;
			cout << "  Kopalnia           [5]" << endl;
			cout << endl;
			gracz.zasoby();
			cout << "  ";
			cin >> wybor;
			system("cls");
			switch (wybor)
			{
				//ratusz
			case '1':
				gracz.idz_ratusz();
				cout << "  ";
				cin >> wybor;
				switch (wybor)
				{
				case '1':
					system("cls");
					cout << endl;
					cout << "  Ulepszenie koszar na poziom " << koszary.poziom + 1 << " wymaga:" << endl << endl;
					cout << "  " << koszary.koszty_drewno << " drewna" << endl;
					cout << "  " << koszary.koszty_kamien << " kamienia" << endl;
					cout << "  " << koszary.koszty_metal << " metalu" << endl << endl;
					cout << "  Ulepszenie            [1]" << endl;
					cout << "  Wyjdź                 [2]" << endl;
					cout << "  ";
					cin >> wybor;
					switch (wybor)
					{
					case '1':
						//ulepszanie koszar
						system("cls");
						if (koszary.koszty_drewno <= gracz.drewno && koszary.koszty_kamien <= gracz.kamien && koszary.koszty_metal <= gracz.metal) {
							gracz.drewno -= koszary.koszty_drewno;
							gracz.kamien -= koszary.koszty_kamien;
							gracz.metal -= koszary.koszty_metal;
							koszary.ulepsz_koszary();
						}
						else {
							cout << endl;
							cout << "  Drogi graczu twoja liczba surowców jest zbyt uboga, by ulepszyć koszary na poziom " << koszary.poziom << endl << endl;
							cout << "  Naciśnij dowolny klawisz, by wrócić do osady" << endl;
							_getch();
						}
						break;
					case '2':
						break;
					}
					break;



				case '2':

					//ulepszanie lasu
					system("cls");
					cout << endl;
					cout << "  Ulepszenie lasu na poziom " << las.poziom + 1 << " wymaga:" << endl << endl;
					cout << "  " << las.koszty_drewno << " drewna" << endl;
					cout << "  " << las.koszty_kamien << " kamienia" << endl;
					cout << "  " << las.koszty_metal << " metalu" << endl << endl;
					cout << "  Ulepszenie            [1]" << endl;
					cout << "  Wyjdź                 [2]" << endl;
					cout << "  ";
					cin >> wybor;
					switch (wybor)
					{
					case '1':
						if (las.koszty_drewno <= gracz.drewno && las.koszty_kamien <= gracz.kamien && las.koszty_metal <= gracz.metal) {
							gracz.drewno -= las.koszty_drewno;
							gracz.kamien -= las.koszty_kamien;
							gracz.metal -= las.koszty_metal;
							las.ulepsz_las();
						}
						else {
							cout << endl;
							cout << "  Drogi graczu twoja liczba surowców jest zbyt uboga, by ulepszyć las na poziom " << las.poziom << endl << endl;
							cout << "  Naciśnij dowolny klawisz, by wrócić do osady" << endl;
							_getch();
						}
						break;
					case '2':
						break;
					}
					break;

					break;
				case '3':
					//ulepszanie kamieniołomu
					system("cls");
					cout << endl;
					cout << "  Ulepszenie kamieniołomu na poziom " << kamieniolom.poziom + 1 << " wymaga:" << endl << endl;
					cout << "  " << kamieniolom.koszty_drewno << " drewna" << endl;
					cout << "  " << kamieniolom.koszty_kamien << " kamienia" << endl;
					cout << "  " << kamieniolom.koszty_metal << " metalu" << endl << endl;
					cout << "  Ulepszenie            [1]" << endl;
					cout << "  Wyjdź                 [2]" << endl;
					cout << "  ";
					cin >> wybor;
					switch (wybor)
					{
					case '1':
						if (kamieniolom.koszty_drewno <= gracz.drewno && kamieniolom.koszty_kamien <= gracz.kamien && kamieniolom.koszty_metal <= gracz.metal) {
							gracz.drewno -= kamieniolom.koszty_drewno;
							gracz.kamien -= kamieniolom.koszty_kamien;
							gracz.metal -= kamieniolom.koszty_metal;
							kamieniolom.ulepsz_kamieniolom();
						}
						else {
							cout << endl;
							cout << "  Drogi graczu twoja liczba surowców jest zbyt uboga, by ulepszyć kamieniołom na poziom " << kamieniolom.poziom << endl << endl;
							cout << "  Naciśnij dowolny klawisz, by wrócić do osady" << endl;
							_getch();
						}
						break;
					case '2':
						break;
					}
					break;
				case '4':
					//ulepszanie kopalni
					system("cls");
					cout << endl;
					cout << "  Ulepszenie kopalni na poziom " << kopalnia.poziom + 1 << " wymaga:" << endl << endl;
					cout << "  " << kopalnia.koszty_drewno << " drewna" << endl;
					cout << "  " << kopalnia.koszty_kamien << " kamienia" << endl;
					cout << "  " << kopalnia.koszty_metal << " metalu" << endl << endl;
					cout << "  Ulepszenie            [1]" << endl;
					cout << "  Wyjdź                 [2]" << endl;
					cout << "  ";
					cin >> wybor;
					switch (wybor)
					{
					case '1':
						if (kopalnia.koszty_drewno <= gracz.drewno && kopalnia.koszty_kamien <= gracz.kamien && kopalnia.koszty_metal <= gracz.metal) {
							gracz.drewno -= kopalnia.koszty_drewno;
							gracz.kamien -= kopalnia.koszty_kamien;
							gracz.metal -= kopalnia.koszty_metal;
							kopalnia.ulepsz_kopalnia();
						}
						else {
							cout << endl;
							cout << "  Drogi graczu twoja liczba surowców jest zbyt uboga, by ulepszyć kopalnie na poziom " << kopalnia.poziom << endl << endl;
							cout << "  Naciśnij dowolny klawisz, by wrócić do osady" << endl;
							_getch();
						}
					case '2':
						break;
					}
					break;
				case '5':
					system("cls");
					cout << endl;
					cout << "                                           WASZA KRÓLEWSKA MOŚĆ                                           " << endl;
					cout << "                                                                                                           " << endl;
					cout << "                                                                                                           " << endl;
					cout << "        Król:   Wczorajszego poranka wysłałem kilku naszych najlepszych zwiadowców                         " << endl;
					cout << "                w stronę wroga w celu sprawdzenia z jaką siłą będziemy musieli się uporać                  " << endl;
					cout << "                wiemy co się z nimi stało ?                                                                " << endl;
					cout << "                                                                                                           " << endl;
					cout << "       Człek:   Niedawno wszyscy wrócili zasapani bełkotali około " << przeciwnik.wojska << endl;
					cout << "                                                                                                           " << endl;
					cout << "        Król:   Świetna robota!!  To bardzo cenna wiedza, zabierajmy się do przygotowań                    " << endl;
					cout << "                nie wiele czasu pozostało do starcia.                                                      " << endl;
					cout << endl;
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "  Naciśnij dowolny klawisz, by wrócić do osady" << endl;
					_getch();
					break;
					//powrót do menu
				case '6':
					break;
				default:
					system("cls");
					cout << "Podaj prawidłową liczbę" << endl;
				}
				break;
				//koszary
			case '2':
				gracz.idz_koszary();
				cout << "  ";
				cin >> wybor;
				switch (wybor)
				{
					//rekrutacja wojsk
				case '1':
				{
					system("cls");

					cout << endl;
					cout << "  Witaj w menu rekrutacji" << endl;
					cout << endl;
					cout << "  Za 1 drewna , 1 kamienia , 1 metalu możesz zrekrutować " << koszary.poziom << " jednostek" << endl;
					cout << "  Wpisz ile wojowników chcesz zrekrutować: " << endl << endl;
					cout << "  Otrzymasz : " << koszary.poziom << " x" << " ";


					cin >> koszary.rekruci;
					koszary.rekruci = koszary.rekruci * koszary.poziom;
					system("cls");
					if (koszary.rekruci <= gracz.drewno && koszary.rekruci <= gracz.kamien && koszary.rekruci <= gracz.metal) {
						int* a = koszary.rekrutacja();
						gracz.liczba_wojsk += a[0];
						gracz.drewno -= koszary.rekruci;
						gracz.kamien -= koszary.rekruci;
						gracz.metal -= koszary.rekruci;
					}
					else
					{
						cout << endl;
						cout << "  Nie masz wystarczająco surowców, by zrekrutować tylu wojowników" << endl << endl;
					}
				}
				cout << endl;
				cout << "  Naciśnij dowolny klawisz, by wrócić do wioski" << endl;
				_getch();
				system("cls");
				break;
				case '2':
					break;
				default:
					system("cls");
					cout << endl;
					cout << "  Podaj prawidłową liczbę" << endl;
				}
				break;

				//las
			case '3':
				// wydobywanie drewna
				gracz.idz_las();
				cout << "  ";
				cin >> wybor;
				switch (wybor)
				{
				case '1':
				{
					system("cls");
					cout << endl;
					cout << "  Za jedną godzinę pracy zarobisz " << las.poziom * 10;
					cout << endl;
					int* a = las.wydobywaj_drewno();
					gracz.drewno = a[0];
					gracz.czas_do_bitwy -= a[1];

				}
				break;
				case '2':
					break;
				default:
					system("cls");
					cout << endl;
					cout << "  Podaj prawidłową liczbę" << endl;
				}
				break;
				//kamieniołom
			case '4':
				// wydobywanie kamienia
				gracz.idz_kamieniolom();
				cout << "  ";
				cin >> wybor;
				switch (wybor)
				{

				case '1':
				{
					system("cls");
					cout << endl;
					cout << "  Za jedną godzinę pracy zarobisz " << kamieniolom.poziom * 10;
					cout << endl;
					int* a = kamieniolom.wydobywaj_kamien();
					gracz.kamien = a[0];
					gracz.czas_do_bitwy -= a[1];
				}
				break;
				case '2':
					break;
				default:
					system("cls");
					cout << endl;
					cout << "  Podaj prawidłową liczbę" << endl;
				}
				break;
				//kopalnia
			case '5':
				//wydobywanie metalu
				gracz.idz_kopalnia();
				cout << "  ";
				cin >> wybor;
				switch (wybor)
				{
				case '1':

				case '2':
				{
					system("cls");
					cout << endl;
					cout << "  Za jedną godzinę pracy zarobisz " << kopalnia.poziom * 10;
					cout << endl;
					int* a = kopalnia.wydobywaj_metal();
					gracz.metal = a[0];
					gracz.czas_do_bitwy -= a[1];
				}
				break;
				case '3':
					break;
				default:
					system("cls");
					cout << endl;
					cout << "  Podaj prawidłową liczbę" << endl;
				}
				break;
			case '8':
				//dodawanie surowców w celu prezentacji gry
				//to nie była by część normalnej gry
				gracz.drewno += 10000;
				gracz.kamien += 10000;
				gracz.metal += 10000;
				gracz.czas_do_bitwy = 5;
				gracz.liczba_wojsk = 10000;
				break;
			default:
				cout << endl;
				cout << "  Podaj prawidłową liczbę" << endl;
				break;
			}
		} while (0);




		if (gracz.czas_do_bitwy <= 0) {
			cout << endl;
			cout << "  Nadszedł czas, " << przeciwnik.numer_ataku << " bitwa z naszym wrogiem" << endl;
			cout << "  My mamy " << gracz.liczba_wojsk << " wojsk" << endl;
			cout << "  A ich armia liczy " << przeciwnik.wojska << " wojowników" << endl << endl;
			cout << "  Naciśnij dowolny klawisz by zobaczyć wynik bitwy" << endl << endl;
			_getch();
			if (gracz.liczba_wojsk >= przeciwnik.wojska) {
				cout << "  Wygraliśmy dzięki naszej przewadze liczebnej!" << endl;
				cout << "  Chwała naszemu władcy!" << endl << endl;
				_getch();
			}
			else {
				cout << "  Nasze wojska zostały rozbite, bez armii nie mamy wyboru" << endl;
				cout << "  musimy się poddać i przekazać władzę wrogiej nacji, by" << endl;
				cout << "  zapobiec niszczeniu naszych miast" << endl << endl;
				cout << "  To koniec, przegraliśmy" << endl;
				_getch();
			}
			if (gracz.liczba_wojsk >= przeciwnik.wojska && przeciwnik.numer_ataku == 3) {
				cout << "  To było już nasze 3 zwycięstwo, po takiej porażce" << endl;
				cout << "  wrogie wojska szybko się nie pozbierają, nareszcie" << endl;
				cout << "  dzięki twojemu wspaniałemu dowodzeniu w naszym królestwie nastanie spokój." << endl;
				_getch();
			}
			gracz.liczba_wojsk -= przeciwnik.atakuj() - 500;
			gracz.czas_do_bitwy += 5;
		}

		if (przeciwnik.numer_ataku == 4 || gracz.liczba_wojsk < 0)
			koniec_gry = false;

	}







}

