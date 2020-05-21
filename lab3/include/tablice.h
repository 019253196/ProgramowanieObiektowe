#ifndef TABLICE_H
#define TABLICE_H
#include <iostream>

using namespace std;

struct Tablica
{
	int **arr;
	int x;
	int y;
};

/**
 * @param[in] - ilość kolumn
 * @param[in] - ilość wierszy
 * @return - wskaźnik na nowo stworzoną strukturę
 * */
Tablica* createTab(int x, int y);                                 //stworz nowa tablicę

void zeroTab(Tablica *tab);

/**
 * @param[in] tab - wskaźnik na strukture(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * */
void deleteTab(Tablica *tab);                                    //kasuje podaną tablice

/**
 * @param[in] tab - wskaźnik na strukture(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @param[in] x - nowa ilość kolumn
 * @param[in] y - nowa ilość wierszy
 * */
void changeTabSize(Tablica *tab, int x, int y);                  //zmien rozmiar tablicy

/**
 * @param[in] tab - wskaźnik na strukture(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @param[in] x - numer kolumny
 * @param[in] y - numer wiersza
 * */
void updateCell(Tablica *tab, int x, int y);                     //wprowadz zmiane do komorki

/**
 * @param[in] tab - wskaźnik na strukture(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @return - kod błędu lub 0 przy powodzenia
 * */
int saveTab(Tablica tab);                                      //zapisz tablice do pliku .txt

/**
 * @param[in] tab - wskaźnik na strukture(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @return - kod błędu lub 0 przy powodzenia
 * */
int loadTab(Tablica *tab);                                      //wczytaj tablice z pliku .txt

/**
 * @param[in] tab - struktura(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @param[in] a - numer wiersza
 * */
int sumRow(Tablica tab, int a);                                 //sumuje komórki w podanym wierszu

/**
 * @param[in] tab - struktura(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @param[in] a - numer kolumny
 * */
int sumColumn(Tablica tab, int a);                              //sumuje komórki w podanej kolumnie

/**
 * @param[in] tab - struktura(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @param[in] a1 - numer wiersza początku zakresu
 * @param[in] a2 - numer kolumny początku zakresu
 * @param[in] b1 - numer wiersza końca zakresu
 * @param[in] b2 - numer kolumny końca zakresu
 * @return - największa liczba
 * */
int largest(Tablica tab, int a1, int a2, int b1, int b2);       //wybiera największą liczbę spośród podanych

/**
 * @param[in] tab - struktura(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @param[in] a1 - numer wiersza początku zakresu
 * @param[in] a2 - numer kolumny początku zakresu
 * @param[in] b1 - numer wiersza końca zakresu
 * @param[in] b2 - numer kolumny końca zakresu
 * @return - najmniejsza liczba
 * */
int smallest(Tablica tab, int a1, int a2, int b1, int b2);      //wybiera najmniejszą liczbę spośród podanych

/**
 * @param[in] tab - struktura(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @param[in] a1 - numer wiersza początku zakresu
 * @param[in] a2 - numer kolumny początku zakresu
 * @param[in] b1 - numer wiersza końca zakresu
 * @param[in] b2 - numer kolumny końca zakresu
 * @return - średnia z podanego zakresu
 * */
double average(Tablica tab, int a1, int a2, int b1, int b2);    //oblicza średnią z podanych liczb

#endif
