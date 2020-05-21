#include <iostream>
#include <fstream>
#include "tablice.h"
#include "tablice_wysw.h"

using namespace std;

Tablica::Tablica()
{
	this->x = 0;
	this->y = 0;
	this->tabExist = false;
}

Tablica::Tablica(int x, int y)
{
	this->createTab(x, y);
}

int Tablica::getX(void)
{
	return this->x;
}

int Tablica::getY(void)
{
	return this->y;
}

bool Tablica::getTabExist(void)
{
	return this->tabExist;
}

int Tablica::getCell(int x, int y)
{
	return this->arr[y][x];
}

int Tablica::createTab(int x, int y)
{
	this->y = y;
	this->x = x;
	this->arr = new int* [this->y];
	for(int i = 0; i < this->y; i++)
	{
		(this->arr)[i] = new int [this->x];
	}
	this->zeroTab();
	this->tabExist = true;
	return 0;
}

void Tablica::deleteTab()
{
	for(int i = 0; i < this->y; i++)
	{
		delete (this->arr)[i];
	}
	delete this->arr;
	this->x = 0;
	this->y = 0;
	this->tabExist = false;
}

void Tablica::zeroTab()
{
	for(int i = 0; i < this->y; i++)
	{
		for(int j = 0; j < this->x; j++)
		{
			this->arr[i][j] = 0;
		}
	}
}


void Tablica::changeTabSize(int x, int y)
{
	Tablica buffer(x, y);
	for(int i = 0; i < buffer.y && i < this->y; i++)
		{
			for(int j = 0; j < buffer.x && j < this->x;  j++)
			{
				buffer.arr[i][j] = this->getCell(j, i);
			}
		}
	displayTab(&buffer);
	this->deleteTab();
	this->x = buffer.x;
	this->y = buffer.y;
	this->arr = buffer.arr;
	this->tabExist = buffer.tabExist;
}


void Tablica::updateCell(int x, int y)
{
		cout << "Wprowadz zmiane: ";
		cin >> this->arr[y][x];
}


int Tablica::saveTab()
{
	fstream file;
	file.open("Tablica.bin", ios::out|ios::binary|ios::trunc);
	if(file.good())
	{
		file.write((const char *) &this->x, sizeof(this->x));
		file.write((const char *) &this->y, sizeof(this->y));
		for(int i = 0; i < this->y; i++)
		{
			file.write((const char *) this->arr[i], this->x * sizeof(int));
		}
		file.close();
		return 0;
	}
	else 
	{
		return 1;
	}
}


int Tablica::loadTab()
{
	int x, y;
	fstream file;
	file.open("Tablica.bin", ios::out|ios::in|ios::binary);
	if(file.good())
	{
		file.read((char *) &x, sizeof(x));
		file.read((char *) &y, sizeof(y));
		this->deleteTab();
		Tablica buffer(x, y);
		cout << x << " " << y << endl;
		for(int i = 0; i < buffer.y; i++)
		{
			file.read((char *) (buffer.arr)[i], buffer.x * sizeof(int));
		}
		file.close();
		this->x = buffer.x;
		this->y = buffer.y;
		this->arr = buffer.arr;
		this->tabExist = buffer.tabExist;
		return 0;
	}
	else
	{
		return 1;
	}
}

int Tablica::sumRow(int a)
{
	int sum = 0;
	for(int i = 0; i < this->x; i++)
	{
		sum += this->arr[a][i];
	}
	return sum;
}

int Tablica::sumColumn(int a)
{
	int sum = 0;
	for(int i = 0; i < this->y; i++)
	{
		sum += this->arr[i][a];
	}
	return sum;
}

int Tablica::largest(int a1, int a2, int b1, int b2)
{
	int max = this->arr[a1][a2];
	for(int i = a1; i <= b1; i++)
	{
		for(int j = a2; j <=b2; j++)
		{
			if(this->arr[i][j] > max) 
			{
				max = this->arr[i][j];
			}
		}
	}
	return max;
}

int Tablica::smallest(int a1, int a2, int b1, int b2)
{
	int min = this->arr[a1][a2];
	for(int i = a1; i <= b1; i++)
	{
		for(int j = a2; j <= b2; j++)
		{
			if(this->arr[i][j] < min)
			{
				min = this->arr[i][j];
			}
		}
	}
	return min;
}

double Tablica::average(int a1, int a2, int b1, int b2)
{
	double sum;
	int n = 0;
	for(int i = a1; i <= b1; i++)
	{
		for(int j = a2; j <= b2; j++)
		{
			sum += this->arr[i][j];
			n++;
		}
	}
	return sum/n;
}

Tablica::~Tablica()
{
	this->deleteTab();
}