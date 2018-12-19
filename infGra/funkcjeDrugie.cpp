#include "funkcje.h" 
#include "klasy.h"


void wyborKolorow(pojazd &pojazd, int numer, int opcja)
{
	sf::Color listaKolorow[6] =
	{
		sf::Color::White,
		sf::Color::Cyan,
		sf::Color::Blue,
		sf::Color::Green,
		sf::Color::Magenta,
		sf::Color::Red
	};
	
	switch (numer)
	{
	case 1:
		pojazd.wyglad.nadwozie = listaKolorow[opcja];
		break;
	case 2:
		pojazd.wyglad.maska = listaKolorow[opcja];
		break;
	case 3:
		pojazd.wyglad.dach = listaKolorow[opcja];
		break;
	case 4:
		pojazd.wyglad.szyby = listaKolorow[opcja];
		break;
	default:
		break;
	}
}

void modulate(sf::VertexArray &points, double hue) {
	// First, Let's "sanitize" inputs a bit.
	// Don't accept negative numbers.
	if (hue < 0)
		hue = 0;
	// Lazy overflow by subtracting the integer portion of the number.
	else if (hue > 1)
		hue -= static_cast<int>(hue);

	// Now iterate over all "pixels" and upate their colors.
	for (unsigned int y = 0; y <= 500; ++y) {
		for (unsigned int x = 0; x <= 399; ++x) {
			// "Calculate" our missing HSV components with ranges from 0 to 1.
			const double s = x / 399.; // x is our saturation
			const double v = y / 500.; // y is our value

			// Pick the correct case based on our position on the color wheel.
			const int cs = hue * 6;

			// Calculate some helper values used in our cases below.
			const double f = hue * 6 - cs;
			const double p = v * (1 - s);
			const double q = v * (1 - s * f);
			const double t = v * (1 - s * (1 - f));

			switch (cs) {
			case 0:
			case 6:
				points[y * 400 + x].color = sf::Color(v * 255, t * 255, p * 255);
				break;
			case 1:
				points[y * 400 + x].color = sf::Color(q * 255, v * 255, p * 255);
				break;
			case 2:
				points[y * 400 + x].color = sf::Color(p * 255, v * 255, t * 255);
				break;
			case 3:
				points[y * 400 + x].color = sf::Color(p * 255, q * 255, v * 255);
				break;
			case 4:
				points[y * 400 + x].color = sf::Color(t * 255, p * 255, v * 255);
				break;
			case 5:
				points[y * 400 + x].color = sf::Color(v * 255, p * 255, q * 255);
				break;
			}
		}
	}
}