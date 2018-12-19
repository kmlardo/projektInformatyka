#include "klasy.h"
#include "main.h"

menu::menu(int numerMenu)
{
	aktualneMenu = numerMenu;
	numerOpcji = 0;
	enterFlag = false;
	int x = 150;
	int y = 100;
	switch (numerMenu)
	{
	case 1:
	{
		menuPozycja[0].setFont(czcionkaMenu);
		menuPozycja[0].setFillColor(sf::Color::White);
		menuPozycja[0].setString("WCZYTAJ");
		menuPozycja[0].setPosition(sf::Vector2f(x - 50, y - 35));
		menuPozycja[1].setFont(czcionkaMenu);
		menuPozycja[1].setFillColor(sf::Color::White);
		menuPozycja[1].setString("NOWA GRA");
		menuPozycja[1].setPosition(sf::Vector2f(x - 25, 2 * y - 35));
		menuPozycja[2].setFont(czcionkaMenu);
		menuPozycja[2].setFillColor(sf::Color::White);
		menuPozycja[2].setString("OPCJE");
		menuPozycja[2].setPosition(sf::Vector2f(x, 3 * y));
		menuPozycja[3].setFont(czcionkaMenu);
		menuPozycja[3].setFillColor(sf::Color::White);
		menuPozycja[3].setString("WYJSCIE");
		menuPozycja[3].setPosition(sf::Vector2f(x, 4 * y + 15));
	}
	break;
	case 2:
	{
		menuPozycja[0].setFont(czcionkaMenu);
		menuPozycja[0].setFillColor(sf::Color::White);
		menuPozycja[0].setString("Nick");
		menuPozycja[0].setPosition(sf::Vector2f(x, 70 + 2 * 20));
		menuPozycja[1].setFont(czcionkaMenu);
		menuPozycja[1].setFillColor(sf::Color::White);
		menuPozycja[1].setString("Wiek");
		menuPozycja[1].setPosition(sf::Vector2f(x, 170 + 3 * 20));
		menuPozycja[2].setFont(czcionkaMenu);
		menuPozycja[2].setFillColor(sf::Color::White);
		menuPozycja[2].setString("Poziom");
		menuPozycja[2].setPosition(sf::Vector2f(x, 270 + 4 * 20));
		menuPozycja[3].setFont(czcionkaMenu);
		menuPozycja[3].setFillColor(sf::Color::White);
		menuPozycja[3].setString("Pojazd");
		menuPozycja[3].setPosition(sf::Vector2f(x, 370 + 5 * 20));
		menuPozycja[4].setFont(czcionkaMenu);
		menuPozycja[4].setFillColor(sf::Color::White);
		menuPozycja[4].setString("Zapisz");
		menuPozycja[4].setPosition(sf::Vector2f(x, 470 + 6 * 20));
	}
	break;
	case 3:
	{
		menuPozycja[0].setFont(czcionkaMenu);
		menuPozycja[0].setFillColor(sf::Color::White);
		menuPozycja[0].setString("Czcionka nr: ");
		menuPozycja[0].setPosition(sf::Vector2f(x, 70 + 2 * 20));
		menuPozycja[1].setFont(czcionkaMenu);
		menuPozycja[1].setFillColor(sf::Color::White);
		menuPozycja[1].setString("Zapisz");
		menuPozycja[1].setPosition(sf::Vector2f(x, 170 + 3 * 20));
	}
	break;
	case 4:
	{
		menuPozycja[0].setFont(czcionkaMenu);
		menuPozycja[0].setFillColor(sf::Color::White);
		menuPozycja[0].setString("1 - ");//+gracz);
		menuPozycja[0].setPosition(sf::Vector2f(x, 70 + 2 * 20));
		menuPozycja[1].setFont(czcionkaMenu);
		menuPozycja[1].setFillColor(sf::Color::White);
		menuPozycja[1].setString("2 - PUSTY");
		menuPozycja[1].setPosition(sf::Vector2f(x, 170 + 3 * 20));
		menuPozycja[2].setFont(czcionkaMenu);
		menuPozycja[2].setFillColor(sf::Color::White);
		menuPozycja[2].setString("3 - PUSTY");
		menuPozycja[2].setPosition(sf::Vector2f(x, 270 + 4 * 20));
		menuPozycja[3].setFont(czcionkaMenu);
		menuPozycja[3].setFillColor(sf::Color::White);
		menuPozycja[3].setString("POWROT");
		menuPozycja[3].setPosition(sf::Vector2f(x, 370 + 5 * 20));
	}
	break;
	}

}

menu::~menu()
{
}

void menu::rysuj(sf::RenderWindow &nazwaOkna)
{
	czcionkaMenu.loadFromFile(nazwaCzcionki[numerCzcionki]);
	menuOff.loadFromFile("tekstury/menuoff.png");
	menuOn.loadFromFile("tekstury/menuon.png");

	unsigned int polowa = (nazwaOkna.getSize().x - menuWyglad.rozmiarX) / 2;
	uint8_t i;

	switch (aktualneMenu)
	{
	case 1:
		for (i = 0; i < numerOpcjiMenuGlowne; i++)
		{
			sf::RectangleShape poleWyboru;
			poleWyboru.setSize(sf::Vector2f(menuWyglad.rozmiarX, menuWyglad.rozmiarY));
			if (i == numerOpcji) poleWyboru.setTexture(&menuOff);
			else poleWyboru.setTexture(&menuOn);
			poleWyboru.setPosition(polowa, (i*menuWyglad.rozmiarY + 20 + i * 20));
			nazwaOkna.draw(poleWyboru);
			nazwaOkna.draw(menuPozycja[i]);
		}
		break;
	case 2:
		for (i = 0; i < numerOpcjiMenuKonfiguracji; i++)
		{
			sf::RectangleShape poleWyboru;
			poleWyboru.setSize(sf::Vector2f(menuWyglad.rozmiarX, menuWyglad.rozmiarY));
			if (i == numerOpcji) poleWyboru.setTexture(&menuOff);
			else poleWyboru.setTexture(&menuOn);
			poleWyboru.setPosition(polowa, (i*menuWyglad.rozmiarY + 70 + i * 20));
			nazwaOkna.draw(poleWyboru);
			nazwaOkna.draw(menuPozycja[i]);
		}
		break;
	case 3:
		for (i = 0; i < numerOpcjiMenuOpcji; i++)
		{
			sf::RectangleShape poleWyboru;
			poleWyboru.setSize(sf::Vector2f(menuWyglad.rozmiarX, menuWyglad.rozmiarY));
			if (i == numerOpcji) poleWyboru.setTexture(&menuOff);
			else poleWyboru.setTexture(&menuOn);
			poleWyboru.setPosition(polowa, (i*menuWyglad.rozmiarY + 70 + i * 20));
			nazwaOkna.draw(poleWyboru);
			nazwaOkna.draw(menuPozycja[i]);
		}
		break;
	case 4:
		for (i = 0; i < numerOpcjiMenuProfil; i++)
		{
			sf::RectangleShape poleWyboru;
			poleWyboru.setSize(sf::Vector2f(menuWyglad.rozmiarX, menuWyglad.rozmiarY));
			if (i == numerOpcji) poleWyboru.setTexture(&menuOff);
			else poleWyboru.setTexture(&menuOn);
			poleWyboru.setPosition(polowa, (i*menuWyglad.rozmiarY + 70 + i * 20));
			nazwaOkna.draw(poleWyboru);
			nazwaOkna.draw(menuPozycja[i]);
		}
		break;
	}
}

pojazd::pojazd()
{
	nazwa = "brak";
	pojazdImg.create(pojazdSzerokosc, pojazdWysokosc, sf::Color::Transparent);
	tekstura.create(pojazdSzerokosc, pojazdWysokosc);
	pojazdRect.height = pojazdWysokosc;
	pojazdRect.width = pojazdSzerokosc;
	pojazdRect.left = 0;
	pojazdRect.top = 0;
	wyglad.nadwozie = sf::Color::White;
	wyglad.szyby = sf::Color::White;
	wyglad.dach = sf::Color::White;
	wyglad.maska = sf::Color::White;
	pojazdSprajt.setOrigin(pojazdSzerokosc / 2, pojazdWysokosc / 2);

	//
	osiagi.hamowanie = 4;
	osiagi.odpornosc = 100;
	osiagi.predkoscMaksymalna = 100;
	osiagi.przyczepnosc = 5;
	osiagi.przyspieszenie = 3;
	//
}

void pojazd::pojazdZmienWyglad(sf::Color kolor, string lokalizacjaMaski)
{
	sf::Image pojazdMaska;
	pojazdMaska.loadFromFile(lokalizacjaMaski);
	sf::Image pojazdMaskaImg;
	pojazdMaskaImg.create(pojazdSzerokosc, pojazdWysokosc, kolor);
	pojazdMaskaImg.copy(pojazdMaska, 0, 0, pojazdRect, true);
	pojazdMaskaImg.createMaskFromColor(sf::Color::Black, 0);
	pojazdImg.copy(pojazdMaskaImg, 0, 0, pojazdRect, true);
	tekstura.update(pojazdImg);
	pojazdSprajt.setTexture(tekstura);
}

void pojazd::pojazdCieniuj(string lokalizacjaMaski)
{
	sf::Image pojazdMaska;
	pojazdMaska.loadFromFile(lokalizacjaMaski);
	pojazdImg.copy(pojazdMaska, 0, 0, pojazdRect, true);
	tekstura.update(pojazdImg);
	pojazdSprajt.setTexture(tekstura);
}

void pojazd::renderuj(void)
{
	//nadwozie
	pojazdZmienWyglad(wyglad.nadwozie, ("tekstury/maskaNadwozie" + nazwa + ".png"));
	//maska
	pojazdZmienWyglad(wyglad.maska, ("tekstury/maskaMaska" + nazwa + ".png"));
	//dach
	pojazdZmienWyglad(wyglad.dach, ("tekstury/maskaDach" + nazwa + ".png"));
	//szyby
	pojazdZmienWyglad(wyglad.szyby, ("tekstury/maskaSzyby" + nazwa + ".png"));
	//cieniowanie
	pojazdCieniuj("tekstury/maskaCieniowanie" + nazwa + ".png");
}

gracz::gracz()
{
	nick = "/0";
	wiek = 0;
	poziom = 0;
	pojazd.nazwa = nazwaPojazdu[0];
}

string gracz::podajNickGracza()
{
	return nick;
}

void gracz::ustawNickGracza(const string &podanyNick)
{
	nick = podanyNick;
}

void gracz::ustawWiekGracza(int podanyWiek)
{
	wiek = podanyWiek;
}

void gracz::ustawPoziomGracza(bool podanyPoziom)
{
	poziom = podanyPoziom;
}

bool gracz::sprawdzDaneGracza()
{
	if (nick=="/0") return false;
	if (wiek == 0) return false;
	if (pojazd.nazwa == nazwaPojazdu[0]) return false;
	return true;
}

bool gracz::podajPoziom(void)
{
	return this->poziom;
}

trasa::trasa()
{
	elementStalyImg.loadFromFile("tekstury/nawierzchniaStala.png");
	elementStalyTex.loadFromImage(elementStalyImg);
	elementStalySpr.setTexture(elementStalyTex);

	pozycjaLiniiY = -100;

	sf::Vector2f liniaRectSize(20, 100);

	for (char i = 0; i < iloscLiniiMax;i++)
	{
		linia[i].setSize(liniaRectSize);
		linia[i].setFillColor(sf::Color::White);
	}
}

void trasa::rozmyjTrase(int predkosc)
{
	if (predkosc > predkoscGranicznaRozmycia)
		elementStalyTex.setSmooth(1);
	else
		elementStalyTex.setSmooth(0);
		//elementStalyTex.loadFromImage(elementStalyImg);
	elementStalySpr.setTexture(elementStalyTex);
}
void trasa::rysujTrase(sf::RenderWindow &okno)
{
	okno.draw(elementStalySpr);
	for (int i = 0; i < iloscLiniiMax; i++)
	{
		okno.draw(linia[i]);
	}
}

void trasa::ustawLinie()
{
	for (char i = 0; i < iloscLiniiMax; i++)
	{
		linia[i].setPosition(585, pozycjaLiniiY);
		pozycjaLiniiY < maxStalaCalkowaniaC1
			? pozycjaLiniiY += stalaCalkowaniaC1 : pozycjaLiniiY = -100;
	}
}

void trasa::uaktualnijLinie()
{
	sf::Vector2f pozycja;
	for (char i=0; i < iloscLiniiMax; i++)
	{
		pozycja = linia[i].getPosition();
			pozycja.y < maxStalaCalkowaniaC1 ? 
				pozycja.y+=1 : pozycja.y = -100;
		linia[i].setPosition(pozycja);
	}
}

interfejs::interfejs(string nickname)
{
	czcionka.loadFromFile(nazwaCzcionki[numerCzcionki]);
	
	this->nazwaGracza.setString("Nick: "+nickname);
	this->nazwaGracza.setFont(czcionka);
	this->nazwaGracza.setScale(0.8,0.7);
	this->nazwaGracza.setFillColor(sf::Color::White);
	this->nazwaGracza.setPosition(10, 20);

	this->predkoscGracza.setString("V [km/h]: 0");
	this->predkoscGracza.setFont(czcionka);
	this->predkoscGracza.setScale(0.8, 0.7);
	this->predkoscGracza.setFillColor(sf::Color::White);
	this->predkoscGracza.setPosition(10, 70);
	
	this->timer.setFont(czcionka);
	this->timer.Bold;
	this->timer.setFillColor(sf::Color::Red);
	this->timer.setPosition(580, 10);
	this->timer.setString("Czas[s]: 0");
}

void interfejs::rysujInterfejs(sf::RenderWindow &okno, int v)
{
	//okno.draw(wskaznikWytrzymalosci);
	//okno.draw(stanTrasy);
	okno.draw(this->timer);
	okno.draw(this->nazwaGracza);
	predkoscGracza.setString("V[km / h]: "+to_string(v));
	okno.draw(this->predkoscGracza);
}

void interfejs::uaktualnijTimer()
{
	if (czasGry < INT32_MAX)
	{
		czasGry++;
	}
	timer.setString("Czas: "+to_string(czasGry));
}

void interfejs::uaktualnijStanTrasy(int aktualnyStanTrasy)
{

}