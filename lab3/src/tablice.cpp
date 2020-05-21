#include <iostream>
#include <fstream>
#include "tablice.h"

using namespace std;



Tablica* createTab(int x, int y)
{
	Tablica *tab = new Tablica;
	tab->y = y;
	tab->x = x;
	tab->arr = new int* [tab->y];
	for(int i = 0; i < tab->y; i++)
	{
		(tab->arr)[i] = new int [tab->x];
	}
	zeroTab(tab);
	return tab;
}

void deleteTab(Tablica *tab)
{
	for(int i = 0; i < tab->y; i++)
	{
		delete (tab->arr)[i];
	}
	delete tab->arr;
	delete tab;
}

void zeroTab(Tablica *tab)
{
	for(int i = 0; i < tab->y; i++)
	{
		for(int j = 0; j < tab->x; j++)
		{
			(tab->arr)[i][j] = 0;
		}
	}
}


void changeTabSize(Tablica *tab, int x, int y)
{
	Tablica *buffer = createTab(x, y);
	zeroTab(buffer);
	for(int i = 0; i < buffer->y && i < tab->y; i++)
		{
			for(int j = 0; j < buffer->x && j < tab->x;  j++)
			{
				(buffer->arr)[i][j] = (tab->arr)[i][j];
			}
		}
	deleteTab(tab);
	*tab = *buffer;
}


void updateCell(Tablica *Tab, int x, int y)
{
	cout << "Wprowadz zmiane: ";
	cin >> (Tab->arr)[y][x];
}


int saveTab(Tablica tab)
{
	fstream file;
	file.open("Tablica.bin", ios::out|ios::binary|ios::trunc);
	if(file.good())
	{
		file.write((const char *) &tab.x, sizeof(tab.x));
		file.write((const char *) &tab.y, sizeof(tab.y));
		for(int i = 0; i < tab.y; i++)
		{
			file.write((const char *) tab.arr[i], tab.x * sizeof(int));
		}
	}
	else 
	{
		return 1;
	}
	file.close();
	return 0;
}


int loadTab(Tablica *tab)
{
	int x, y;
	fstream file;
	file.open("Tablica.bin", ios::out|ios::in|ios::binary);
	if(file.good())
	{
		file.read((char *) &x, sizeof(x));
		file.read((char *) &y, sizeof(y));
		deleteTab(tab);
		tab = createTab(x, y);
		cout << x << " " << y << endl;
		for(int i = 0; i < tab->y; i++)
		{
			file.read((char *) (tab->arr)[i], tab->x * sizeof(int));
		}
	}
	else
	{
		return 1;
	}
	return 0;
}

int sumRow(Tablica tab, int a)
{
	int sum = 0;
	for(int i = 0; i < tab.x; i++)
	{
		sum += tab.arr[a][i];
	}
	return sum;
}

int sumColumn(Tablica tab, int a)
{
	int sum = 0;
	for(int i = 0; i < tab.y; i++)
	{
		sum += tab.arr[i][a];
	}
	return sum;
}

int largest(Tablica tab, int a1, int a2, int b1, int b2)
{
	int max = tab.arr[a1][a2];
	for(int i = a1; i <= b1; i++)
	{
		for(int j = a2; j <=b2; j++)
		{
			if(tab.arr[i][j] > max) 
			{
				max = tab.arr[i][j];
			}
		}
	}
	return max;
}

int smallest(Tablica tab, int a1, int a2, int b1, int b2)
{
	int min = tab.arr[a1][a2];
	for(int i = a1; i <= b1; i++)
	{
		for(int j = a2; j <= b2; j++)
		{
			if(tab.arr[i][j] < min)
			{
				min = tab.arr[i][j];
			}
		}
	}
	return min;
}

double average(Tablica tab, int a1, int a2, int b1, int b2)
{
	double sum;
	int n = 0;
	for(int i = a1; i <= b1; i++)
	{
		for(int j = a2; j <= b2; j++)
		{
			sum += tab.arr[i][j];
			n++;
		}
	}
	return sum/n;
}