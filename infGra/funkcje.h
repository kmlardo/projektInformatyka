#pragma once

#define minWiek 1
#define maxWiek 99

#include "main.h"
#include "klasy.h"

enum numerMenu
{
	pierwsze = 1,
	drugie,
	trzecie,
	czwarte
};

enum errNumerBledu
{
	errMuzyka = 0x0A,
	errTekstura,
	errCzcionka
};

const char nazwaPliku[] = { "plik.dat" };
const char tryb_w[] = { "w" };
const char tryb_r[] = { "r" };

//	****************	funkcjePierwsze	****************

bool inicjalizacja(void);
bool inicjalizacjaObiektow(uint8_t maxLiczbaPostaci);
void _delay_ms(int opoznienie);
void komunikat(sf::RenderWindow &oknoPoprzednie, sf::RenderWindow &oknoAktualne, const string &tekst);
void komunikat(sf::RenderWindow &oknoAktualne, const string &tekst);
void info(sf::RenderWindow &nazwaOkna);
void nowaGra(sf::RenderWindow &nazwaOkna);
void ustawNazweGracza(gracz &graczAktualny, sf::RenderWindow &nazwaOkna);
void ustawWiekGracza(gracz &graczAktualny, sf::RenderWindow &nazwaOkna);
void ustawPoziomGracza(gracz &graczAktualny, sf::RenderWindow & nazwaOkna);
void zbudujPojazdGracza(gracz &graczAktualny, sf::RenderWindow &nazwaOkna);
void gra(sf::RenderWindow &nazwaOkna, zapisGry &zapisAktualny);//, gracz &graczAktualny);
void opcje(sf::RenderWindow &nazwaOkna);
void wczytajGre(sf::RenderWindow &nazwaOkna);
int zapis(gracz & bufor);
int odczyt(zapisGry & bufor);

//	****************	funkcjeDrugie	****************

void wyborKolorow(pojazd &pojazd, int numer, int opcja);
void modulate(sf::VertexArray &points, double hue);