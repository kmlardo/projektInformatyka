#pragma once

#include "main.h"

extern int numerCzcionki;
extern char* nazwaCzcionki[3];

//****************	klasyTechniczne	****************
#define pojazdSzerokosc 100
#define pojazdWysokosc 175
#define numerOpcjiMenuMax 5
#define numerOpcjiMenuMin 0
#define numerOpcjiMenuGlowne 4
#define numerOpcjiMenuKonfiguracji 5
#define numerOpcjiMenuOpcji 2
#define numerOpcjiMenuProfil 4
#define numerOpcjiCzcionek 3
#define etapTworzeniaPojazduMax 5
#define numerKoloruMax 6
#define predkoscGranicznaRozmycia 10
#define iloscLiniiMax 5
#define stalaCalkowaniaC1 200 // nie wiem
#define maxStalaCalkowaniaC1 900 //max window height + wys s³upka
#define stalaCalkowaniaC2 1000 // dlugosc trasy
#define stalaCalkowaniaC3 100.0 // maks predkosc pojazdu
#define maxSkret 45.0
#define lewaKrawedzTrasy 200
#define prawaKrawedzTrasy 1000

enum enZmiana
{
	zmianaBrak=0,
	zmianaUp,
	zmianaDown
};

const string nazwaPojazdu[] =
{
	"brak",
	"Beemwu",
	"Passeratti"
};

const string informacjaWybor[] =
{
	"Wybierz marke pojazdu",
	"Wybierz kolor karoserii",
	"Wybierz kolor maski",
	"Wybierz kolor dachu",
	"Wybierz kolor szyb"
};



class menu
{
private:
	int aktualneMenu;
	sf::Font czcionkaMenu;
	sf::Text menuPozycja[numerOpcjiMenuMax];
	sf::Texture menuOff;
	sf::Texture menuOn;
	struct
	{
		unsigned int rozmiarX = 300;
		unsigned int rozmiarY = 100;
	}menuWyglad;
public:
	bool enterFlag = 0;
	menu(int numerMenu);
	~menu();
	uint8_t numerOpcji = 0;
	void rysuj(sf::RenderWindow &nazwaOkna);
};

class stanGry
{

};

//****************	klasyUzytkowe	****************

class pojazd
{
		float x;
		float y;
		float rotacja;
		float dx;
		float dy;
		float dr;
	sf::Image pojazdImg;
	sf::Texture tekstura;
	sf::Sprite pojazdSprajt;
	sf::IntRect pojazdRect;
	void pojazdZmienWyglad
	(
		sf::Color kolor,
		string lokalizacjaMaski
	);
	void pojazdCieniuj
	(
		string lokalizacjaMaski
	);
public:
	string nazwa;
	struct
	{
		uint8_t predkoscMaksymalna;
		uint8_t przyspieszenie;
		uint8_t przyczepnosc;
		uint8_t hamowanie;
		uint8_t odpornosc;
	}osiagi;
	struct 
	{
		uint8_t wytrzymalosc;
	}wlasciwosci;
	struct
	{
		typedef sf::Color kol;
		kol nadwozie;
		kol maska;
		kol dach;
		kol szyby;
	}wyglad;
	float predkosc;
	pojazd();
	void rysuj(sf::RenderWindow &nazwaOkna, int x, int y);
	void rysuj(sf::RenderWindow &nazwaOkna);
	sf::Sprite dajPojazd(void);
	void renderuj(void);
	void zwiekszPredkosc(void);
	void zmniejszPredkosc(void);
	void init(void);
	void uaktualnijObrot(void);
	string podajNazwePojazdu();
	void skretPrawo();
	void skretLewo();
	void normalizujObrot();
	void normalizujSkret();
};

class gracz
{
private:
	string nick;
	uint8_t wiek;
	bool poziom;
	uint8_t doswiadczenie;
	friend class interfejs;
	friend class zapisGry;
public:
	gracz();
	pojazd pojazd;
	string podajNickGracza();
	void ustawNickGracza(const string &podanyNick);
	void ustawWiekGracza(int podanyWiek);
	void ustawPoziomGracza(bool podanyPoziom);
	bool sprawdzDaneGracza();
	void kopiuj(gracz &graczPtr);
	bool podajPoziom(void);
};

class interfejs
{
	sf::Sprite wskaznikWytrzymalosci, stanTrasy;
	sf::Text nazwaGracza, timer, predkoscGracza;
	sf::Font czcionka;
	int czasGry = 0;
public:
	interfejs(string nickname);
	void rysujInterfejs(sf::RenderWindow &okno, int v);
	void uaktualnijTimer();
	void uaktualnijStanTrasy(int aktualnyStanTrasy);
};

class przeszkody
{
	//przeszkoda **przeszkodaPtr;
	static int iloscPrzeszkodMax;
protected:
	sf::Sprite przeszkodaSprite;
	sf::Texture tekstura;
	static int aktualnaIloscPrzeszkod;
public:
	przeszkody(bool poziomTrudnosci);
	przeszkody();
	~przeszkody();
	void utworzPrzeszkode(void);
};

class przeszkoda : public przeszkody
{
	bool dzialanie;//0 - minus, 1 - plus
	int wartosc;
	//sf::Sprite przeszkodaSprite;
	//sf::Texture tekstura;
public:
	int numerPrzeszkody;
	int x;
	int y;
	przeszkoda();
	~przeszkoda();
	//void czyUsunac(void);
	//void czyKolizja(gracz &auto);
};

class trasa
{
	sf::Sprite elementStalySpr;
	sf::Image elementStalyImg;
	sf::Texture elementStalyTex;
	sf::RectangleShape linia[iloscLiniiMax];
	int pozycjaLiniiY;
public:
	trasa();
	void rozmyjTrase(int predkosc);
	void rysujTrase(sf::RenderWindow &okno);
	void uaktualnijLinie(void);
	void ustawLinie(void);
};

class zapisGry
{
	char nick[20];//string nick;
	uint8_t wiek;
	bool poziom;
	uint8_t doswiadczenie;
	char nazwa[20];//string nazwa;
	struct
	{
		uint8_t predkoscMaksymalna;
		uint8_t przyspieszenie;
		uint8_t przyczepnosc;
		uint8_t hamowanie;
		uint8_t odpornosc;
	}osiagi;
	struct
	{
		typedef sf::Color kol;
		kol nadwozie;
		kol maska;
		kol dach;
		kol szyby;
	}wyglad;
public:
	void get(gracz &graczDoZapisania);
	void set(gracz &graczDoZapisania);
};