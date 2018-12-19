#include "funkcje.h" 
#include "klasy.h"



bool inicjalizacja()
{
	if (!inicjalizacjaObiektow(1)) return 0;
	return 1;
}

bool inicjalizacjaObiektow(uint8_t maxPostaci)
{
	return 0;
}

void _delay_ms(int opoznienie)
{
	static sf::Clock zegar;//???
	static sf::Time czas;//???
	while (1)
	{
		czas = zegar.getElapsedTime();
		if (czas.asMilliseconds() > opoznienie)
		{
			zegar.restart();
			break;
		}
	}
}

void komunikat(sf::RenderWindow &oknoPoprzednie, sf::RenderWindow &oknoAktualne, const string &tekst)
{
	oknoAktualne.setVisible(0);
	sf::RenderWindow infoOkno(sf::VideoMode(1000, 60), "Potwierdzenie", sf::Style::None);

	sf::Font czcionka;
	sf::Text tekstInfo;
	czcionka.loadFromFile(nazwaCzcionki[numerCzcionki]);

	tekstInfo.setFont(czcionka);
	tekstInfo.setFillColor(sf::Color::Black);
	tekstInfo.setString(tekst);
	tekstInfo.setPosition(sf::Vector2f(10, 10));

	infoOkno.clear(sf::Color::Red);
	infoOkno.draw(tekstInfo);
	infoOkno.display();

	while (infoOkno.isOpen())
	{
		sf::Event event;
		while (infoOkno.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Enter:
					infoOkno.close();
					infoOkno.close();
					oknoAktualne.close();
					if ((&oknoAktualne) != (&oknoPoprzednie))
						oknoPoprzednie.setVisible(1);
					break;
				case sf::Keyboard::T:
					infoOkno.close();
					infoOkno.close();
					oknoAktualne.close();
					if ((&oknoAktualne) != (&oknoPoprzednie))
						oknoPoprzednie.setVisible(1);
					break;
				case sf::Keyboard::Escape:
					infoOkno.close();
					oknoAktualne.close();
					if ((&oknoAktualne) != (&oknoPoprzednie))
						oknoPoprzednie.setVisible(1);
					break;
				case sf::Keyboard::N:
					infoOkno.close();
					oknoAktualne.setVisible(1);
					break;
				}
				break;
			}
		}
	}
}

void komunikat(sf::RenderWindow &oknoAktualne, const string &tekst)
{
	oknoAktualne.setVisible(0);
	sf::RenderWindow infoOkno(sf::VideoMode(1000, 60), "Komunikat", sf::Style::None);

	sf::Font czcionka;
	sf::Text tekstInfo;
	czcionka.loadFromFile(nazwaCzcionki[numerCzcionki]);

	tekstInfo.setFont(czcionka);
	tekstInfo.setFillColor(sf::Color::Black);
	tekstInfo.setString(tekst);
	tekstInfo.setPosition(sf::Vector2f(10, 10));

	infoOkno.clear(sf::Color::Red);
	infoOkno.draw(tekstInfo);
	infoOkno.display();

	while (infoOkno.isOpen())
	{
		sf::Event event;
		while (infoOkno.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Enter:
					infoOkno.close();
					oknoAktualne.setVisible(1);
					break;
				case sf::Keyboard::Escape:
					infoOkno.close();
					oknoAktualne.setVisible(1);
					break;
				}
				break;
			}
		}
	}
}

void info(sf::RenderWindow &nazwaOkna)
{
	nazwaOkna.setVisible(0);
	sf::RenderWindow infoOkno(sf::VideoMode(800,800),"Informacje", sf::Style::None);

	sf::Font czcionka;
	sf::Text tekstInfo;
	sf::Text informacjeDlaGracza;
	czcionka.loadFromFile(nazwaCzcionki[numerCzcionki]);

	tekstInfo.setFont(czcionka);
	tekstInfo.setFillColor(sf::Color::White);
	tekstInfo.setString("Informacje");
	tekstInfo.setPosition(sf::Vector2f(10, 10));

	informacjeDlaGracza.setFont(czcionka);
	informacjeDlaGracza.setScale(0.65, 0.65);
	informacjeDlaGracza.setFillColor(sf::Color::White);
	informacjeDlaGracza.setString("Zatwierdzanie -> T lub Enter\nWyjscie / Powrot -> N lub Escape\nCzcionke mozna zmienic w opcjach\n\nSTEROWANIE:\nWSAD lub strzalkami\n\nZASADY:\nJak najszybszy czas\n\n * W przypadku kiedy przyspieszenie jest wieksze od przyczepnosci (wlasciwosci pojazdu)\nnastepuje poslizg i wyhamowanie pojazdu");
	informacjeDlaGracza.setPosition(sf::Vector2f(10, 120));

	infoOkno.clear(sf::Color::Blue);
	infoOkno.draw(tekstInfo);
	infoOkno.draw(informacjeDlaGracza);
	infoOkno.display();

	while (infoOkno.isOpen())
	{
		sf::Event event;
		while (infoOkno.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					infoOkno.close();
				}
				break;
			}
		}
	}

	nazwaOkna.setVisible(1);
}

void nowaGra(sf::RenderWindow &nazwaOkna)
{
	
	nazwaOkna.setVisible(0);
	_delay_ms(300);
	sf::RenderWindow nowaKonfiguracja(sf::VideoMode(400, 670), "Nowy profil", sf::Style::None);

	sf::Font czcionka;
	sf::Text tekstInfo;
	czcionka.loadFromFile(nazwaCzcionki[numerCzcionki]);

	tekstInfo.setFont(czcionka);
	tekstInfo.setFillColor(sf::Color::Black);
	tekstInfo.setString("Konfiguracja nowego profilu");
	tekstInfo.setPosition(sf::Vector2f(10, 10));

	gracz gracz1;

	menu menuKonfiguracji(drugie);
	menuKonfiguracji.enterFlag = false;

	while (nowaKonfiguracja.isOpen())
	{
		sf::Event event;
		while (nowaKonfiguracja.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Down:
					sf::milliseconds(200);
					if (menuKonfiguracji.numerOpcji < (numerOpcjiMenuKonfiguracji - 1)) menuKonfiguracji.numerOpcji++;
					break;
				case sf::Keyboard::Up:
					sf::milliseconds(200);
					if (menuKonfiguracji.numerOpcji > numerOpcjiMenuMin) menuKonfiguracji.numerOpcji--;
					break;
				case sf::Keyboard::Escape:
					sf::milliseconds(200);
					komunikat(nazwaOkna, nowaKonfiguracja, "Czy na pewno chcesz powrocic do menu glownego? ( T / N )");
					break;
				case sf::Keyboard::F1:
					sf::milliseconds(200);
					info(nowaKonfiguracja);
					break;
				case sf::Keyboard::Enter:
					sf::milliseconds(200);
					menuKonfiguracji.enterFlag = true;
					break;
				default:
					sf::milliseconds(200);
					break;
				}
				break;
			}
		}
		nowaKonfiguracja.clear(sf::Color::Cyan);
		nowaKonfiguracja.draw(tekstInfo);
		menuKonfiguracji.rysuj(nowaKonfiguracja);
		nowaKonfiguracja.display();

		if (menuKonfiguracji.enterFlag == true)
		{
			menuKonfiguracji.enterFlag = false;
			switch (menuKonfiguracji.numerOpcji)
			{
			case 0:
				//nazwa postaci
				ustawNazweGracza(gracz1, nowaKonfiguracja);
				break;
			case 1:
				//wiek
				ustawWiekGracza(gracz1, nowaKonfiguracja);
				break;
			case 2:
				//poziom
				ustawPoziomGracza(gracz1, nowaKonfiguracja);
				break;
			case 3:
				//pojazd
				zbudujPojazdGracza(gracz1, nowaKonfiguracja);
				break;
			case 4:
				//zapisz
				//gra(nowaKonfiguracja, gracz1);
				if (gracz1.sprawdzDaneGracza())
				{
					if(!zapis(gracz1))
						komunikat(nazwaOkna, nowaKonfiguracja, "Profil pomyslnie zapisany. Mozesz go wczytac z menu glownego. (ENTER)");
					else
						komunikat(nazwaOkna, nowaKonfiguracja, "Blad - profil nie moze zostac zapisany. (ENTER)");
				}
				else
					komunikat(nowaKonfiguracja, "Blad - dane gracza nie zostaly wypelnione! (Enter / Escape)");
				break;
			}
		}

	}
}

void ustawNazweGracza(gracz &graczAktualny, sf::RenderWindow &nazwaOkna)
{
	
	bool enterFlag = 0;
	int i = 0;
	string inActive;

	nazwaOkna.setVisible(0);
	sf::RenderWindow infoOkno(sf::VideoMode(800, 120), "Pseudonim gracza", sf::Style::None);
	sf::Font czcionka;
	sf::Text tekstInfo;
	sf::Text nick;
	czcionka.loadFromFile(nazwaCzcionki[numerCzcionki]);

	tekstInfo.setFont(czcionka);
	tekstInfo.setFillColor(sf::Color::Black);
	tekstInfo.setString("Podaj nick (male litery):");
	tekstInfo.setPosition(sf::Vector2f(10, 10));
	nick.setFont(czcionka);
	nick.setFillColor(sf::Color::Black);
	nick.setPosition(sf::Vector2f(10, 60));
	infoOkno.clear(sf::Color::Red);
	infoOkno.draw(tekstInfo);
	infoOkno.display();

	while (infoOkno.isOpen())
	{
		sf::Event event;
		while (infoOkno.pollEvent(event))
		{
			switch (event.type)
			{			
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				default:
					break;
				case sf::Keyboard::Enter:
					enterFlag = true;
					graczAktualny.ustawNickGracza(nick.getString());
					break;
				case sf::Keyboard::Escape:
					komunikat(nazwaOkna, infoOkno, "Czy na pewno chcesz powrocic do konfiguracji? ( T / N )");
					break;
				case sf::Keyboard::F1:
					info(infoOkno);
					break;
				}
			case sf::Event::TextEntered:
				switch (event.text.unicode)
				{
				case 0:
					break;
				default:
					if((event.text.unicode >= 97) && (event.text.unicode <=122))
					nick.setString(nick.getString() + event.text.unicode);
					cout << event.text.unicode << endl;
					break;
				}
				break;
			}
		}
		
		infoOkno.clear(sf::Color::Red);
		infoOkno.draw(tekstInfo);
		infoOkno.draw(nick);
		infoOkno.display();

		if (enterFlag)
		{
			enterFlag=false;
			if (graczAktualny.podajNickGracza() == "\0")
				komunikat(infoOkno, "Wypelnij nazwe gracza! (Enter / Escape)");
			else
			{
				infoOkno.close();
				nazwaOkna.setVisible(1);
			}
		}
	}
}

void ustawWiekGracza(gracz &graczAktualny, sf::RenderWindow &nazwaOkna)
{
	int i = 0;
	int wiek = 0;

	nazwaOkna.setVisible(0);
	sf::RenderWindow infoOkno(sf::VideoMode(800, 120), "Wiek gracza", sf::Style::None);
	sf::Font czcionka;
	sf::Text tekstInfo;
	sf::Text wiekTekst;
	czcionka.loadFromFile(nazwaCzcionki[numerCzcionki]);

	tekstInfo.setFont(czcionka);
	tekstInfo.setFillColor(sf::Color::Black);
	tekstInfo.setString("Ustaw wiek: (UP / DOWN)");
	tekstInfo.setPosition(sf::Vector2f(10, 10));
	wiekTekst.setFont(czcionka);
	wiekTekst.setFillColor(sf::Color::Black);
	wiekTekst.setPosition(sf::Vector2f(10, 60));
	infoOkno.clear(sf::Color::Red);
	infoOkno.draw(tekstInfo);
	infoOkno.display();

	while (infoOkno.isOpen())
	{
		sf::Event event;
		while (infoOkno.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				default:
					break;
				case sf::Keyboard::Enter:
					if (wiek==0)
						komunikat(infoOkno, "Ustaw wiek gracza! (Enter / Escape)");
					else
					{
						graczAktualny.ustawWiekGracza(wiek);
						infoOkno.close();
						nazwaOkna.setVisible(1);
					}
					break;
				case sf::Keyboard::Escape:
					komunikat(nazwaOkna, infoOkno, "Czy na pewno chcesz powrocic do konfiguracji? ( T / N )");
					break;
				case sf::Keyboard::F1:
					info(infoOkno);
					break;
				case sf::Keyboard::Up:
					if (wiek < maxWiek) wiek++;
					break;
				case sf::Keyboard::Down:
					if (wiek > minWiek) wiek--;
					break;
				}
			}
		}
		
		wiekTekst.setString(to_string(wiek));

		infoOkno.clear(sf::Color::Red);
		infoOkno.draw(tekstInfo);
		infoOkno.draw(wiekTekst);
		infoOkno.display();

	}
}

void ustawPoziomGracza(gracz &graczAktualny, sf::RenderWindow &nazwaOkna)
{

	int i = 0;
	bool poziom = 0;

	nazwaOkna.setVisible(0);
	sf::RenderWindow infoOkno(sf::VideoMode(800, 120), "Poziom gracza", sf::Style::None);
	sf::Font czcionka;
	sf::Text tekstInfo;
	sf::Text poziomTekst;
	czcionka.loadFromFile(nazwaCzcionki[numerCzcionki]);

	tekstInfo.setFont(czcionka);
	tekstInfo.setFillColor(sf::Color::Black);
	tekstInfo.setString("Ustaw poziom: (UP / DOWN)");
	tekstInfo.setPosition(sf::Vector2f(10, 10));
	poziomTekst.setFont(czcionka);
	poziomTekst.setFillColor(sf::Color::Black);
	poziomTekst.setPosition(sf::Vector2f(10, 60));
	infoOkno.clear(sf::Color::Red);
	infoOkno.draw(tekstInfo);
	infoOkno.display();

	while (infoOkno.isOpen())
	{
		sf::Event event;
		while (infoOkno.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				default:
					break;
				case sf::Keyboard::Enter:
					graczAktualny.ustawPoziomGracza(poziom);
					infoOkno.close();
					nazwaOkna.setVisible(1);
					break;
				case sf::Keyboard::Escape:
					komunikat(nazwaOkna, infoOkno, "Czy na pewno chcesz powrocic do konfiguracji? ( T / N )");
					break;
				case sf::Keyboard::F1:
					info(infoOkno);
					break;
				case sf::Keyboard::Up:
					if (!poziom) poziom = true;
					break;
				case sf::Keyboard::Down:
					if (poziom) poziom = false;
					break;
				}
			}
		}

		if(poziom) poziomTekst.setString("Trudny");
		else poziomTekst.setString("Latwy");

		infoOkno.clear(sf::Color::Red);
		infoOkno.draw(tekstInfo);
		infoOkno.draw(poziomTekst);
		infoOkno.display();

	}
}

void zbudujPojazdGracza(gracz &graczAktualny, sf::RenderWindow &nazwaOkna)
{
	nazwaOkna.setVisible(0);
	sf::RenderWindow infoOkno(sf::VideoMode(600, 600), "Pojazd gracza", sf::Style::None);
	sf::Font czcionka;
	sf::Text tekstWybor;
	sf::Text tekstInfo;
	sf::Text poziomTekst;
	sf::Text tekstDodatkowy;
	czcionka.loadFromFile(nazwaCzcionki[numerCzcionki]);

	tekstInfo.setFont(czcionka);
	tekstInfo.setFillColor(sf::Color::Black);
	tekstInfo.setString("Indywidualizacja pojazdu gracza\n[ (UP / DOWN) i kontynuuj (ENTER) ]");
	tekstInfo.setPosition(sf::Vector2f(10, 10));
	poziomTekst.setFont(czcionka);
	poziomTekst.setFillColor(sf::Color::Black);
	poziomTekst.setPosition(sf::Vector2f(10, 60));
	
	infoOkno.clear(sf::Color::Red);
	infoOkno.draw(tekstInfo);
	infoOkno.display();

	tekstWybor.setFont(czcionka);
	tekstWybor.setFillColor(sf::Color::White);
	tekstWybor.setString(informacjaWybor[0]);
	tekstWybor.setPosition(sf::Vector2f(10, 160));

	tekstDodatkowy.setFont(czcionka);
	tekstDodatkowy.setFillColor(sf::Color::White);
	tekstDodatkowy.setPosition(sf::Vector2f(50, 220));
	tekstDodatkowy.setString(nazwaPojazdu[0]);

	bool enterFlag = false;
	int zmiana = zmianaBrak;
	int etapTworzeniaPojazdu = 0;
	int opcja = 0;

	graczAktualny.pojazd.nazwa = nazwaPojazdu[1];

	while (infoOkno.isOpen())
	{
		sf::Event event;
		while (infoOkno.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				default:
					break;
				case sf::Keyboard::Enter:
					enterFlag = true;
					break;
				case sf::Keyboard::Escape:
					komunikat(nazwaOkna, infoOkno, "Czy na pewno chcesz powrocic do konfiguracji? ( T / N )");
					break;
				case sf::Keyboard::F1:
					info(infoOkno);
					break;
				case sf::Keyboard::Up:
					zmiana = zmianaUp;
					break;
				case sf::Keyboard::Down:
					zmiana = zmianaDown;
					break;
				}
			}
		}
		
		if (enterFlag)
		{
			enterFlag = false;
			opcja = 0;
			if (etapTworzeniaPojazdu < etapTworzeniaPojazduMax - 1)
			{
				etapTworzeniaPojazdu++;
				tekstWybor.setString(informacjaWybor[etapTworzeniaPojazdu]);
			}
			else komunikat(nazwaOkna, infoOkno, "Czy na pewno chcesz powrocic do konfiguracji? ( T / N )");
		}

		if (zmiana!=zmianaBrak)
		{
			switch (etapTworzeniaPojazdu)
			{
			case 0:
				if (opcja == 0) opcja++;
				else opcja = 0;
				graczAktualny.pojazd.nazwa = nazwaPojazdu[opcja + 1];
				tekstDodatkowy.setString(nazwaPojazdu[opcja+1]);
				break;
			default:
				if ((opcja > 0) && (zmiana == zmianaDown))
				{
					opcja--;
					wyborKolorow(graczAktualny.pojazd, etapTworzeniaPojazdu, opcja);
				}
				if ((opcja < numerKoloruMax - 1) && (zmiana == zmianaUp))
				{
					opcja++;
					wyborKolorow(graczAktualny.pojazd, etapTworzeniaPojazdu, opcja);
				}
				break;
			}
			graczAktualny.pojazd.renderuj();
			zmiana = zmianaBrak;
		}

		infoOkno.clear(sf::Color::Red);
		infoOkno.draw(tekstInfo);
		infoOkno.draw(tekstWybor);
		infoOkno.draw(tekstDodatkowy);
		graczAktualny.pojazd.rysuj(infoOkno, 220, 400);
		infoOkno.display();
	}
}

void opcje(sf::RenderWindow &nazwaOkna)
{
	nazwaOkna.setVisible(0);
	_delay_ms(300);
	sf::RenderWindow opcje(sf::VideoMode(400, 670), "Opcje", sf::Style::None);

	sf::Font czcionka;
	sf::Text tekstInfo;
	sf::Text tekstCzcionka;
	czcionka.loadFromFile(nazwaCzcionki[numerCzcionki]);

	tekstInfo.setFont(czcionka);
	tekstInfo.setFillColor(sf::Color::Black);
	tekstInfo.setString("Opcje");
	tekstInfo.setPosition(sf::Vector2f(10, 10));

	tekstCzcionka.setFont(czcionka);
	tekstCzcionka.setFillColor(sf::Color::White);
	tekstCzcionka.setString(to_string(numerCzcionki + 1));
	tekstCzcionka.setPosition(sf::Vector2f(310, 110));

	menu menuKonfiguracji(trzecie);
	menuKonfiguracji.enterFlag = false;

	while (opcje.isOpen())
	{
		sf::Event event;
		while (opcje.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Down:
					if (menuKonfiguracji.numerOpcji < (numerOpcjiMenuOpcji - 1)) menuKonfiguracji.numerOpcji++;
					break;
				case sf::Keyboard::Up:
					if (menuKonfiguracji.numerOpcji > numerOpcjiMenuMin) menuKonfiguracji.numerOpcji--;
					break;
				case sf::Keyboard::Escape:
					komunikat(nazwaOkna, opcje, "Czy na pewno chcesz powrocic do menu glownego? ( T / N )");
					break;
				case sf::Keyboard::F1:
					info(opcje);
					break;
				case sf::Keyboard::Enter:
					menuKonfiguracji.enterFlag = true;
					break;
				default:
					break;
				}
				break;
			}
		}
		opcje.clear(sf::Color::Cyan);
		opcje.draw(tekstInfo);
		menuKonfiguracji.rysuj(opcje);
		opcje.draw(tekstCzcionka);
		opcje.display();

		if (menuKonfiguracji.enterFlag == true)
		{
			menuKonfiguracji.enterFlag = false;
			switch (menuKonfiguracji.numerOpcji)
			{
			case 0:
				//zmiana czcionki
				if (numerCzcionki < numerOpcjiCzcionek - 1)
					numerCzcionki++;
				else numerCzcionki = 0;
				tekstCzcionka.setString(to_string(numerCzcionki + 1));
				break;
			case 1:
				//powrot
				komunikat(nazwaOkna, opcje, "Czy na pewno chcesz powrocic do menu glownego? ( T / N )");
				break;
			}
		}

	}
}

void gra(sf::RenderWindow &nazwaOkna, zapisGry &zapisAktualny)
{
	nazwaOkna.setVisible(0);
	sf::RenderWindow graOkno(sf::VideoMode(1200, 800), "GRA", sf::Style::None);
	
	gracz *graczAktualny=new gracz;
	zapisAktualny.set(*graczAktualny);
	graczAktualny->pojazd.renderuj();
	graczAktualny->pojazd.init();

	int aktualnyStanTrasy = 0;
	int dlugoscTrasy = stalaCalkowaniaC2;
	bool lewoFlaga = 0, prawoFlaga = 0;

	trasa trasaGry;
	trasaGry.ustawLinie();
	przeszkody *przeszkodyGry = new przeszkody(graczAktualny->podajPoziom());
	interfejs interfejsGry(graczAktualny->podajNickGracza());
	static sf::Clock zegarKlatki;
	static sf::Time  timerKlatki;
	static sf::Clock zegarRuchu;
	static sf::Time  timerRuchu;
	static sf::Clock  zegarLicznik;
	static sf::Time  timerLicznik;

	sf::Event event;
	
	graOkno.setKeyRepeatEnabled(1);
	
	while (graOkno.isOpen())
	{
		timerLicznik = zegarLicznik.getElapsedTime();
		if (timerLicznik.asSeconds() >= 1)
		{
			zegarLicznik.restart();
			interfejsGry.uaktualnijTimer();
		}

		if (graczAktualny->pojazd.predkosc < 1)
		{
			zegarRuchu.restart();
			lewoFlaga = 0; prawoFlaga = 0;
		}
		else
		{
			timerRuchu = zegarRuchu.getElapsedTime();
			if (timerRuchu.asMilliseconds() >= (stalaCalkowaniaC3/graczAktualny->pojazd.predkosc) )
			{
				trasaGry.rozmyjTrase(graczAktualny->pojazd.predkosc);
				zegarRuchu.restart();
				if(lewoFlaga) graczAktualny->pojazd.skretLewo();
				if(prawoFlaga) graczAktualny->pojazd.skretPrawo();
				trasaGry.uaktualnijLinie();
				graczAktualny->pojazd.uaktualnijObrot();
				graczAktualny->pojazd.normalizujObrot();
				graczAktualny->pojazd.normalizujSkret();
				lewoFlaga = 0; prawoFlaga = 0;
			}
		}
		
		//interfejsGry.uaktualnijStanTrasy(aktualnyStanTrasy);
		

		if (graOkno.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					komunikat(nazwaOkna, graOkno, "Czy na pewno chcesz zapisaæ i zakonczyc gre? ( T / N )");
					break;
				case sf::Keyboard::F1:
					info(graOkno);
					break;
				default:
					break;
				}
				break;
			}
		}
		
		timerKlatki = zegarKlatki.getElapsedTime();
		if (timerKlatki.asMilliseconds() >= 17)//~58FPS
		{
			zegarKlatki.restart();
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				graczAktualny->pojazd.zmniejszPredkosc();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				graczAktualny->pojazd.zwiekszPredkosc();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				prawoFlaga = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				lewoFlaga = 1;
			}

			graOkno.clear(sf::Color::Black);
			trasaGry.rysujTrase(graOkno);
			//gra.rysujPrzeszkody();
			graczAktualny->pojazd.rysuj(graOkno);
			interfejsGry.rysujInterfejs(graOkno, graczAktualny->pojazd.predkosc);
			graOkno.display();
		}

		
	}
	delete graczAktualny;
	delete przeszkodyGry;
}

int zapis(gracz & bufor)
{
	zapisGry zapisAktualny;
	zapisAktualny.get(bufor);
	FILE *fp;
	fp = fopen("zapisGry.bin", "w");
	if (fp == NULL)
	{
		return 1;
	}
	fwrite(&zapisAktualny, sizeof(zapisGry), 1, fp);
	fclose(fp);
	return 0;
}

int odczyt(zapisGry & bufor)
{
	FILE *fp;
	fp = fopen("zapisGry.bin", "r");
	if (fp == NULL)
	{
		return 1;
	}
	fread(&bufor, sizeof(zapisGry), 1, fp);
	fclose(fp);
	return 0;
}

void wczytajGre(sf::RenderWindow &nazwaOkna)
{
	nazwaOkna.setVisible(0);
	_delay_ms(300);
	sf::RenderWindow wczytywanieOkno(sf::VideoMode(400, 670), "Wczytaj gre", sf::Style::None);

	sf::Font czcionka;
	sf::Text tekstInfo;
	sf::Text tekstCzcionka;
	czcionka.loadFromFile(nazwaCzcionki[numerCzcionki]);

	tekstInfo.setFont(czcionka);
	tekstInfo.setFillColor(sf::Color::Black);
	tekstInfo.setString("Profile: ");
	tekstInfo.setPosition(sf::Vector2f(10, 10));

	tekstCzcionka.setFont(czcionka);
	tekstCzcionka.setFillColor(sf::Color::White);
	tekstCzcionka.setString(to_string(numerCzcionki + 1));
	tekstCzcionka.setPosition(sf::Vector2f(310, 110));

	menu menuKonfiguracji(czwarte);
	menuKonfiguracji.enterFlag = false;

	zapisGry *zapisAktualny = new zapisGry;

	while (wczytywanieOkno.isOpen())
	{
		sf::Event event;
		while (wczytywanieOkno.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Down:
					if (menuKonfiguracji.numerOpcji < (numerOpcjiMenuProfil - 1)) menuKonfiguracji.numerOpcji++;
					break;
				case sf::Keyboard::Up:
					if (menuKonfiguracji.numerOpcji > numerOpcjiMenuMin) menuKonfiguracji.numerOpcji--;
					break;
				case sf::Keyboard::Escape:
					komunikat(nazwaOkna, wczytywanieOkno, "Czy na pewno chcesz powrocic do menu glownego? ( T / N )");
					break;
				case sf::Keyboard::F1:
					info(wczytywanieOkno);
					break;
				case sf::Keyboard::Enter:
					menuKonfiguracji.enterFlag = true;
					break;
				default:
					break;
				}
				break;
				
			}
		}
		wczytywanieOkno.clear(sf::Color::Cyan);
		wczytywanieOkno.draw(tekstInfo);
		menuKonfiguracji.rysuj(wczytywanieOkno);
		wczytywanieOkno.draw(tekstCzcionka);
		wczytywanieOkno.display();

		if (menuKonfiguracji.enterFlag == true)
		{
			menuKonfiguracji.enterFlag = false;
			switch (menuKonfiguracji.numerOpcji)
			{
			case 0:
				//profil 0
				if (!odczyt(*zapisAktualny))
				{
					gra(wczytywanieOkno, *zapisAktualny);
				}
				else komunikat(wczytywanieOkno, "Blad wczytywania ( Escape / Enter )");
				break;
			case 1:
				//profil 1
				/*cout << "przed: " << graczAktualny->podajNickGracza() << endl;
				cout << graczAktualny->pojazd.podajNazwePojazdu() << endl;
				if (odczyt(*graczAktualny))
				{
					cout << "nie ok" << endl;
				}
				else
				{
					cout << "ok" << endl;
					cout << (*graczAktualny).podajNickGracza() << endl;
					cout << graczAktualny->pojazd.podajNazwePojazdu() << endl;
				}*/

				break;
			case 2:
				//profil 2
				break;
			case 3:
				//powrot
				komunikat(nazwaOkna, wczytywanieOkno, "Czy na pewno chcesz powrocic do menu glownego? ( T / N )");
				break;
			}
		}

	}
	delete zapisAktualny;
}