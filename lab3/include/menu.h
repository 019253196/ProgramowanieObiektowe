#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "tablice.h"
#include "tablice_wysw.h"

using namespace std;

/**
 * @return - y - ilość wierszy tworzonej tablicy
 * */
int readSizeY();                                                       //pobranie rozmiaru tablicy od uzytkownika (pion)

/**
 * @return - x - ilość kolumn tworzonej tablicy
 * */
int readSizeX();                                                       //pobranie rozmiaru tablicy od uzytkownika (poziom)

void printMenu();                                                      //drukowanie menu

/**
 * @return - odp - odpowiedź lub kod błędu
 * */
int takeAnw();                                                         //pobranie odpowiedzi

/**
 * @return - numer wiersza
 * */
int whichRow();                                                        //pobranie numeru wiersza

/**
 * @return - numer kolumny
 * */
int whichColumn();                                                     //pobranie numeru kolumny

/**
 * @param[in] tab - wskaźnik na strukture(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @param[in] x - numer kolumny
 * @param[in] y - numer wiersza
 * @return - kod błędu lub 0 przy powodzenia
 * */
int checkCords(Tablica *tab, int x, int y);                            //sprawdza poprawność wprowadzonych koordynatów komórki

void fileCreatedCheck();                                               //drukuje komunikat o błędzie przy utworzeniu pliku

void fileOpenCheck();                                                  //drukuje komunikat o błędzie przy otwarciu pliku

/**
 * @param[in] tab - wskaźnik na strukture(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @param[in] a - numer wiersza
 * @return - kod błędu lub 0 przy powodzenia
 * */
int checkRow(Tablica *tab, int a);                                     //sprawdzenie podanego numeru wiersza

/**
 * @param[in] tab - wskaźnik na strukture(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @param[in] a - numer kolumny
 * @return - kod błędu lub 0 przy powodzenia
 * */
int checkColumn(Tablica *tab, int a);                                  //sprawdzenie podanego numeru kolumny

/**
 * @param[in] tab - wskaźnik na strukture(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @param[in] a1 - współrzędna y punktu 1
 * @param[in] a2 - współrzędna y punktu 1
 * @param[in] b1 - współrzędna y punktu 1
 * @param[in] b2 - współrzędna y punktu 1
 * @return - kod błędu lub 0 przy powodzenia
 * */
int checkRange(Tablica *tab, int a1, int a2, int b1, int b2);          //sprawdzenie podanego zakresu (funkcje smallest, largest, average)

/**
 * @param[in] tab - wskaźnik na strukture(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * @param[in] odp - odpowiedz
 * @return -1 by zamknąć program
 * */
int processAnw(Tablica *tab, int odp);                                 //przetwarzanie odpowiedzi

/**
 * @param[in] - wskaźnik na strukture(tablica dwuwymiarowa, rozmiar X, rozmiar Y)
 * */
void menuLoop(Tablica *tab);                                           //petla menu, jest w niej drukowana tablica

#endif