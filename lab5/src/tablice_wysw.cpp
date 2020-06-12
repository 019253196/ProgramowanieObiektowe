#include <iostream>
#include "tablice.h"

using namespace std;

void displayTab(Tablica *tab)
{
	int x = tab->getX(), y = tab->getY();
	for(int i = 0; i < (y); i++)
	{
		for(int j = 0; j < (x); j++)
		{
			cout << tab->getCell(j, i).getCellValue() << "|";
		}
		cout << endl;
	}
}