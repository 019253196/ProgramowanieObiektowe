#include <iostream>
#include "menu.h"
#include "tablice.h"
#include "tablice_wysw.h"

using namespace std;

int main()
	{
		Tablica *tab;
		int a = 0, b = 0;
		a = readSizeX();
		b = readSizeY();
		tab = createTab(a, b);
		menuLoop(tab);
		return 0;
	}
