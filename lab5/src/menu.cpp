#include <iostream>
#include "tablice.h"
#include "menu.h"
#include "tablice_wysw.h"

using namespace std;


void printMenu()
	{
		cout << "=============MENU==============" << endl;
		cout << "1. Nowa tablica" << endl;
		cout << "2. Zmien rozmiar tablicy" << endl;
		cout << "3. Aktualizuj zawartosc tablicy" << endl;
		cout << "4. Zapisz tablice" << endl;
		cout << "5. Wczytaj tablice" << endl;
		cout << "6. Sumowanie wybranego wiersza" << endl;
		cout << "7. Sumowanie wybranej kolumny" << endl;
		cout << "8. Najwieksza liczba z podanego zakresu" << endl;
		cout << "9. Najmniejsza liczba z podanego zakresu" << endl;
		cout << "10. Srednia z podanego zakresu" << endl;
		cout << "11. Zakoncz" << endl;
	}

int takeAnw()
	{
		int odp;
		cout << "Wybor: ";
		cin >> odp;
		if(!cin.good())
		{
			cout << "cin fail" << endl;
			cin.clear();
			cin.ignore();
			return 0;
		}
		else return odp;
	}

int readSizeY()
{
	int y;
	cout << "Prosze podac liczbe wierszy: ";
	cin >> y;
	return y;
}

int readSizeX()
{
	int x;
	cout << "Prosze podac liczbe kolumn: " ;
	cin >> x;
	return x;
}

int whichRow()
{
	int row;
	cout << "Podaj wiersz: ";
	cin >> row;
	return row;
}

int whichColumn()
{
	int column;
	cout << "Podaj kolumne: ";
	cin >> column;
	return column;
}

int checkCords(Tablica *tab, int x, int y)
{
	if(x >= tab->getX() || x < 0 || y >= tab->getY() || y < 0)
	{
		cout << "Wykroczono poza zakres" << endl;
		return 1;
	}
	return 0;
}

void fileCreatedCheck()
{
	cout << "Nie udalo sie utworzyc pliku" << endl;
}

void fileOpenCheck()
{
	cout << "Nie udalo sie otworzyc pliku" << endl;
}

int checkRow(Tablica *tab, int a)
{
	if(a < 0 || a > tab->getY())
	{
		cout << "Niepoprawna liczba" << endl;
		return 1;
	}
	return 0;
}

int checkColumn(Tablica *tab, int a)
{
	if(a < 0 || a > tab->getX())
	{
		cout << "Niepoprawna liczba" << endl;
		return 1;
	}
	return 0;
}

int checkRange(Tablica *tab, int a1, int a2, int b1, int b2)
{
	if(a1 < 0 || a2 < 0 || b1 < 0 || b2 < 0 || a1 > b1 || a2 > b2 || a1 >= tab->getY() || a2 >= tab->getX() || b1 >= tab->getY() || b2 >= tab->getX())
	{
		cout << "Nieprawidlowy przedzial" << endl;
		return 1;
	}
	return 0;
}

int processAnw(Tablica *tab, int odp)
	{
		int a1 = 0, a2 = 0, b1 =0 , b2 = 0;
		switch(odp)
		{
			case 1:                                                           //1) Utwórz nową tablicę
				a1 = readSizeX();
				b1 = readSizeY();
				if(tab->getTabExist())
				{
					tab->deleteTab();
				}
				tab->createTab(a1, b1);
				break;
			case 2:                                                           //2) Zmień rozmiar tablicy
				a1 = readSizeX();
				b1 = readSizeY();
				tab->changeTabSize(a1, b1);
				break;
			case 3:                                                           //3) Aktualizuj rozmiar komórki
				a1 = whichRow();
				b1 = whichColumn();
				if(checkCords(tab, b1, a1))
				{
					break;
				}
				tab->updateCell(b1, a1);
				break;
			case 4:                                                           //4) Zapisz tablicę
				if(tab->saveTab())
				{
					fileCreatedCheck();
				}
				break;
			case 5:                                                           //5) Wczytaj tablicę
				if(tab->loadTab())
				{
					fileOpenCheck();
				}
				break; 
			case 6:                                                           //6) Sumuj wiersz
				a1 = whichRow();
				if(checkRow(tab, a1))
				{
					break;
				}
				cout << "Suma tego wiersza to: " << tab->sumRow(a1) << endl;
				a1 = 0;
				break;
			case 7:                                                           //7) Sumuj kolumnę
				a1 = whichColumn();
				if(checkColumn(tab, a1))
				{
					break;
				}
				cout << "Suma tej kolumny to: " << tab->sumColumn(a1) << endl;
				a1 = 0;
				break;
			case 8:                                                           //8) Największa wartość w przedziale
				cout << "Od: " << endl;
				a1 = whichRow();
				a2 = whichColumn();
				cout << "Do: " << endl;
				b1 = whichRow();
				b2 = whichColumn();
				if(checkRange(tab, a1, a2, b1, b2))
				{
					break;
				}
				cout << "Najwieksza wartosc to: " << tab->largest(a1, a2, b1, b2) << endl;
				break;
			case 9:                                                           //9) Najmniejsza wartość w przedziale
				cout << "Od: " << endl;
				a1 = whichRow();
				a2 = whichColumn();		
				cout << "Do: " << endl;
				b1 = whichRow();
				b2 = whichColumn();
				if(checkRange(tab, a1, a2, b1, b2))
				{
					break;
				}
				cout << "Najmniejsza wartosc to: " << tab->smallest(a1, a2, b1, b2) << endl;
				break;
			case 10:                                                          //10) Średnia z przedziału
				cout << "Od: " << endl;
				a1 = whichRow();
				a2 = whichColumn();		
				cout << "Do: " << endl;
				b1 = whichRow();
				b2 = whichColumn();
				if(checkRange(tab, a1, a2, b1, b2))
				{
					break;
				}
				cout << "Srednia wartosc to: " << tab->average(a1, a2, b1, b2) << endl;
				break;
			case 11:                                                          //11) Zakończ
				return -1;
			default: 
				cout << "Nieprawidlowa opcja" << endl;
		}	
	}

void menuLoop(Tablica *tab)
	{
		while(1)
		{
			displayTab(tab);
			printMenu();
			int anw = takeAnw();
			if(processAnw(tab, anw) == -1) 
			{
				break;
			}
		}
	}
