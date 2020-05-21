#ifndef TABLICE_H
#define TABLICE_H
#include <iostream>

using namespace std;

class Tablica
{
	int **arr;
	int x;
	int y;
	bool tabExist;

	public:

	Tablica();                                                       //konstruktor z domyślnym rozmiarem 0,0

	Tablica(int x, int y);                                           //konstruktor z możliwością wprowadzenia rozmiaru 

	int getX(void);                                                  //zwraca aktualną liczbę kolumn

	int getY(void);                                                  //zwraca aktualną liczbę wierszy

	bool getTabExist(void);                                          //zwraca aktualną wartość tabExist

	int getCell(int x, int y);                                       //zwraca wartość w danej komórce

	/**
	 * @param[in] - ilość kolumn
	 * @param[in] - ilość wierszy
	 * @return - kod błędu lub 0 przy powodzeniu
 	* */
	int createTab(int x, int y);                                     //tworzy nową tablicę

	void zeroTab();                                                  //zeruje wszystkie komórki tablicy 

	void deleteTab();                                                //kasuje podaną tablice

	/**
	 * @param[in] x - nowa ilość kolumn
	 * @param[in] y - nowa ilość wierszy
	 * */
	void changeTabSize(int x, int y);                                //zmienia rozmiar tablicy

	/**
	 * @param[in] x - numer kolumny
	 * @param[in] y - numer wiersza
	 * */
	void updateCell(int x, int y);                                   //wprowadza zmiane do komorki

	/**
	 * @return - kod błędu lub 0 przy powodzenia
	 * */
	int saveTab();                                                   //zapisuje tablice do pliku .txt

	/**
	 * @return - kod błędu lub 0 przy powodzenia
	 * */
	int loadTab();                                                   //wczytuje tablice z pliku .txt

	/**
	 * @param[in] a - numer wiersza
	 * */
	int sumRow(int a);                                               //sumuje komórki w podanym wierszu

	/**
	 * @param[in] a - numer kolumny
	 * */
	int sumColumn(int a);                                            //sumuje komórki w podanej kolumnie

	/**
	 * @param[in] a1 - numer wiersza początku zakresu
	 * @param[in] a2 - numer kolumny początku zakresu
	 * @param[in] b1 - numer wiersza końca zakresu
	 * @param[in] b2 - numer kolumny końca zakresu
	 * @return - największa liczba
	 * */
	int largest(int a1, int a2, int b1, int b2);                     //wybiera największą liczbę spośród podanych

	/**
	 * @param[in] a1 - numer wiersza początku zakresu
	 * @param[in] a2 - numer kolumny początku zakresu
	 * @param[in] b1 - numer wiersza końca zakresu
	 * @param[in] b2 - numer kolumny końca zakresu
	 * @return - najmniejsza liczba
	 * */
	int smallest(int a1, int a2, int b1, int b2);                    //wybiera najmniejszą liczbę spośród podanych

	/**
	 * @param[in] a1 - numer wiersza początku zakresu
	 * @param[in] a2 - numer kolumny początku zakresu
	 * @param[in] b1 - numer wiersza końca zakresu
	 * @param[in] b2 - numer kolumny końca zakresu
	 * @return - średnia z podanego zakresu
	 * */
	double average(int a1, int a2, int b1, int b2);                  //oblicza średnią z podanych liczb

	~Tablica();

};
#endif
