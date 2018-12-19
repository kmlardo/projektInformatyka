#include "klasy.h"

void pojazd::rysuj(sf::RenderWindow &nazwaOkna, int x, int y)
{
	pojazdSprajt.setPosition(x, y);
	nazwaOkna.draw(pojazdSprajt);
}

void pojazd::rysuj(sf::RenderWindow &nazwaOkna)
{
	pojazdSprajt.setPosition(this->x, this->y);
	pojazdSprajt.setRotation(this->rotacja);
	nazwaOkna.draw(pojazdSprajt);
}

void pojazd::uaktualnijObrot(void)
{
	if (dr != 0)
	{
		if((rotacja<maxSkret)&&(rotacja>-maxSkret))
			rotacja += dr;
		dr > 0 ? dr-- : dr++;
	}
}

void pojazd::normalizujObrot(void)
{
	if (rotacja != 0)
	{
		rotacja > 0 ? rotacja-- : rotacja++;
	}
}

void pojazd::normalizujSkret()
{
	if ((x < (prawaKrawedzTrasy - rotacja)) && (x > (lewaKrawedzTrasy - rotacja)))
	{
		x += rotacja*(predkosc/stalaCalkowaniaC3);
	}
}

void pojazd::skretLewo()
{
	if (dr > -maxSkret)
	{
		dr -= osiagi.przyczepnosc;
	}
	
}

void pojazd::skretPrawo()
{
	if (dr < maxSkret)
	{
		dr += osiagi.przyczepnosc;
	}
	
}

sf::Sprite pojazd::dajPojazd(void)
{
	return this->pojazdSprajt;
}

string pojazd::podajNazwePojazdu(void)
{
	return this->nazwa;
}

void pojazd::zwiekszPredkosc(void)
{
	if (predkosc < (osiagi.predkoscMaksymalna - osiagi.przyspieszenie))
	{
		predkosc += osiagi.przyspieszenie;
	}
	else if (predkosc < osiagi.predkoscMaksymalna)
	{
		predkosc += 1;
	}
	//else //vmax juz jest
}

void pojazd::zmniejszPredkosc(void)
{
	if (predkosc > (0 + osiagi.hamowanie))
	{
		predkosc -= osiagi.hamowanie;
	}
	else if (predkosc > 0)
	{
		predkosc -= 1;
	}
}

void pojazd::init(void)
{
	//pojazdImg.create(pojazdSzerokosc, pojazdWysokosc, sf::Color::Transparent);
	//tekstura.create(pojazdSzerokosc, pojazdWysokosc);
	//pojazdRect.height = pojazdWysokosc;
	//pojazdRect.width = pojazdSzerokosc;
	//pojazdRect.left = 0;
	//pojazdRect.top = 0;
	this->x = 550;
	this->y = 615;
}

void gracz::kopiuj(gracz &graczPtr)
{
	this->nick = graczPtr.nick;
	this->wiek = graczPtr.wiek;
	this->poziom = graczPtr.poziom;
	this->doswiadczenie = graczPtr.doswiadczenie;
	this->pojazd.nazwa = graczPtr.pojazd.nazwa;
	this->pojazd.osiagi = graczPtr.pojazd.osiagi;
	this->pojazd.wlasciwosci = graczPtr.pojazd.wlasciwosci;
	this->pojazd.wyglad = graczPtr.pojazd.wyglad;
}

void zapisGry::get(gracz &graczDoZapisania)
{
	char temp[20] = { 0 };
	copy(graczDoZapisania.nick.begin(), (graczDoZapisania.nick.size() >= 20 ? graczDoZapisania.nick.begin() + 20 : graczDoZapisania.nick.end()), temp);
	strcpy(this->nick, temp);
	this->wiek = graczDoZapisania.wiek;
	this->poziom = graczDoZapisania.poziom;
	this->doswiadczenie = graczDoZapisania.doswiadczenie;
	copy(graczDoZapisania.pojazd.nazwa.begin(), (graczDoZapisania.pojazd.nazwa.size() >= 20 ? graczDoZapisania.pojazd.nazwa.begin() + 20 : graczDoZapisania.pojazd.nazwa.end()), temp);
	strcpy(this->nazwa, temp);
	this->osiagi.predkoscMaksymalna = graczDoZapisania.pojazd.osiagi.predkoscMaksymalna;
	this->osiagi.przyspieszenie=graczDoZapisania.pojazd.osiagi.przyspieszenie;
	this->osiagi.przyczepnosc=graczDoZapisania.pojazd.osiagi.przyczepnosc;
	this->osiagi.hamowanie=graczDoZapisania.pojazd.osiagi.hamowanie;
	this->osiagi.odpornosc=graczDoZapisania.pojazd.osiagi.odpornosc;
	this->wyglad.nadwozie=graczDoZapisania.pojazd.wyglad.nadwozie;
	this->wyglad.maska=graczDoZapisania.pojazd.wyglad.maska;
	this->wyglad.dach=graczDoZapisania.pojazd.wyglad.dach;
	this->wyglad.szyby=graczDoZapisania.pojazd.wyglad.szyby;
}

void zapisGry::set(gracz &graczDoZapisania)
{
	graczDoZapisania.nick=nick;
	graczDoZapisania.wiek = wiek;
	graczDoZapisania.poziom = poziom;
	graczDoZapisania.doswiadczenie = doswiadczenie;
	graczDoZapisania.pojazd.nazwa = nazwa;
	graczDoZapisania.pojazd.osiagi.predkoscMaksymalna = osiagi.predkoscMaksymalna;
	graczDoZapisania.pojazd.osiagi.przyspieszenie = osiagi.przyspieszenie;
	graczDoZapisania.pojazd.osiagi.przyczepnosc = osiagi.przyczepnosc;
	graczDoZapisania.pojazd.osiagi.hamowanie = osiagi.hamowanie;
	graczDoZapisania.pojazd.osiagi.odpornosc = osiagi.odpornosc;
	graczDoZapisania.pojazd.wyglad.nadwozie = wyglad.nadwozie;
	graczDoZapisania.pojazd.wyglad.maska = wyglad.maska;
	graczDoZapisania.pojazd.wyglad.dach = wyglad.dach;
	graczDoZapisania.pojazd.wyglad.szyby = wyglad.szyby;
}

int przeszkody::iloscPrzeszkodMax = 0;
int przeszkody::aktualnaIloscPrzeszkod = 0;

przeszkody::przeszkody()
{
	iloscPrzeszkodMax = 3;
	tekstura.create(200, 100);
	przeszkodaSprite.setTexture(tekstura);
	//przeszkodaPtr = new przeszkoda*[iloscPrzeszkodMax];
}

przeszkody::~przeszkody()
{
	//? a pojedyncze przeszkody
	//delete[] przeszkodaPtr;
}

przeszkody::przeszkody(bool poziomTrudnosci)
{
	tekstura.create(200, 100);
	przeszkodaSprite.setTexture(tekstura);
	if (poziomTrudnosci)
		iloscPrzeszkodMax = 5;
	else
		iloscPrzeszkodMax = 3;
	//przeszkodaPtr = new przeszkoda*[iloscPrzeszkodMax];
}

void przeszkody::utworzPrzeszkode(void)
{
	//if ((przeszkodaPtr[aktualnaIloscPrzeszkod] != NULL) && (aktualnaIloscPrzeszkod<iloscPrzeszkodMax))
	{
		//przeszkodaPtr[aktualnaIloscPrzeszkod] = new przeszkoda();
	}
}

przeszkoda::przeszkoda()
{
	aktualnaIloscPrzeszkod++;
	//tekstura.create(200, 100);
	srand(time(NULL));
	int liczba = rand() % 50 + 1;
	wartosc = liczba;
	liczba < 5 ? dzialanie = 1 : dzialanie = 0;
	//przeszkodaSprite.setTexture(tekstura);
	if (dzialanie)
		przeszkodaSprite.setColor(sf::Color::Green);
	else 
		przeszkodaSprite.setColor(sf::Color::Red);
	x = rand() % 1000 + 200;
	y = -100;
}

przeszkoda::~przeszkoda()
{
	aktualnaIloscPrzeszkod--;
	delete [] this;
}
