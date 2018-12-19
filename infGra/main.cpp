char pierwszaCzcionka[] = { "czcionki/msbf.ttf" };
char drugaCzcionka[] = { "czcionki/ElegantLux-Mager.otf" };
char trzeciaCzcionka[] = { "czcionki/Hagin Caps Medium.otf" };
int numerCzcionki = 0;
char* nazwaCzcionki[3] = { pierwszaCzcionka, drugaCzcionka , trzeciaCzcionka };

#include "funkcje.h"
#include "klasy.h"

int main()
{
	//sf::Texture tloMenuTekstura;
	//if (!tloMenuTekstura.loadFromFile("tekstury/menutlo.png"))
	//	return errTekstura;

	//sf::Sprite tloMenuSprite;
	//tloMenuSprite.setTexture(tloMenuTekstura);

	sf::RenderWindow menuMain(sf::VideoMode(400, 500), "Gra - Menu G³owne", sf::Style::None);

	menu menuGlowne(pierwsze);
	
	sf::Clock timer;

	// This vertex array is going to be used for drawing.
	// It includes one vertex/point/pixel per color.
	sf::VertexArray colors(sf::Points, 400 * 501);
	for (unsigned int y = 0; y <= 500; ++y) {
		for (unsigned int x = 0; x <= 399; ++x) {
			sf::Vertex &vertex(colors[y * 400 + x]);

			// Note that I "flip" the displayed texture here, by subtracting
			// x/y from 255 rather than just using x/y, but that's really just
			// to get the same orientation that you have.
			vertex.position.x = 399 - x;
			vertex.position.y = 500 - y;
		}
	}

	while (menuMain.isOpen())
	{

		sf::Event event;

		while (menuMain.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				menuMain.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Down:
					sf::milliseconds(200);
					if (menuGlowne.numerOpcji < (numerOpcjiMenuGlowne - 1)) menuGlowne.numerOpcji++;
					break;
				case sf::Keyboard::Up:
					sf::milliseconds(200);
					if (menuGlowne.numerOpcji > numerOpcjiMenuMin) menuGlowne.numerOpcji--;
					break;
				case sf::Keyboard::Escape:
					sf::milliseconds(200);
					komunikat(menuMain, menuMain, "Czy na pewno chcesz wyjsc? ( T / N )");
					break;
				case sf::Keyboard::F1:
					sf::milliseconds(200);
					info(menuMain);
					break;
				case sf::Keyboard::Enter:
					sf::milliseconds(200);
					menuGlowne.enterFlag = true;
					break;
				}
				break;
			}
		}
		modulate(colors, timer.getElapsedTime().asSeconds() / 15);
		menuMain.clear(sf::Color::Cyan);
		//menuMain.draw(tloMenuSprite);
		menuMain.draw(colors);
		menuGlowne.rysuj(menuMain);
		menuMain.display();
		if (menuGlowne.enterFlag)
		{
			menuGlowne.enterFlag &= 0x0;
			switch (menuGlowne.numerOpcji)
			{
			case 0:
				//wczytaj
				wczytajGre(menuMain);
				break;
			case 1:
				//nowa_gra
				nowaGra(menuMain);
				break;
			case 2:
				//opcje
				opcje(menuMain);
				break;
			case 3:
				//wyjscie
				komunikat(menuMain,menuMain, "Czy na pewno chcesz wyjsc? ( T / N )");
			}
		}
	}
	return 0;
}