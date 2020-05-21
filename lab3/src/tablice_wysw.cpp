#include <iostream>
#include "tablice.h"

using namespace std;

void displayTab(Tablica* tab)
{
	for(int i = 0; i < (tab->y); i++)
	{
		for(int j = 0; j < (tab->x); j++)
		{
			cout << (tab->arr)[i][j] << "|";
		}
		cout << endl;
	}
}
