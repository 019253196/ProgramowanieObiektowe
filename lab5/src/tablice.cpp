#include <iostream>
#include <fstream>
#include "tablice.h"
#include "tablice_wysw.h"
#include "komorki.h"

using namespace std;

Tablica::Tablica()
{
	this->x = 0;
	this->y = 0;
	this->arr=NULL;
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
	return this->arr != NULL;
}

Cell Tablica::getCell(int x, int y)
{
	return *(this->arr[y][x]);
}

int Tablica::createTab(int x, int y)
{
	this->y = y;
	this->x = x;
	this->arr = new Cell** [this->y];
	for(int i = 0; i < this->y; i++)
	{
		(this->arr)[i] = new Cell* [this->x];
	}
	this->zeroTab();
	return 0;
}

void Tablica::deleteTab()
{
	if(this->arr==NULL)
	{
		for(int i = 0; i < this->y; i++)
		{
			delete (this->arr)[i];
		}
		delete this->arr;
		this->arr=NULL;
		this->x = 0;
		this->y = 0;
	}
}

void Tablica::zeroTab()
{
	if(this->arr!=NULL)
	{
		for(int i = 0; i < this->y; i++)
		{
			for(int j = 0; j < this->x; j++)
			{
				this->arr[i][j] = new Cell;
				this->arr[i][j]->setCellValue(0);
			}
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
				buffer.arr[i][j] = this->arr[i][j];
			}
		}
	this->deleteTab();
	this->x = buffer.x;
	this->y = buffer.y;
	this->arr = buffer.arr;
}


void Tablica::updateCell(int x, int y)
{
	int a = 0;
	cout << "Wprowadz zmiane: ";
	cin >> a;
	this->arr[y][x]->setCellValue(a);
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
			for(int j = 0; j < this->x; j++)
			{
				int a = this->getCell(j, i).getCellValue();
				file.write((const char *) &a, sizeof(int));
			}
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
			for(int j = 0; j < buffer.x; j++)
			{
				int a = 0;
				file.read((char *) &a, sizeof(int));
				buffer.arr[i][j]->setCellValue(a);
			}
		}
		file.close();
		this->x = buffer.x;
		this->y = buffer.y;
		this->arr = buffer.arr;
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
		sum += this->arr[a][i]->getCellValue();
	}
	return sum;
}

int Tablica::sumColumn(int a)
{
	int sum = 0;
	for(int i = 0; i < this->y; i++)
	{
		sum += this->arr[i][a]->getCellValue();
	}
	return sum;
}

int Tablica::largest(int a1, int a2, int b1, int b2)
{
	int max = this->arr[a1][a2]->getCellValue();
	for(int i = a1; i <= b1; i++)
	{
		for(int j = a2; j <=b2; j++)
		{
			if(this->arr[i][j]->getCellValue() > max) 
			{
				max = this->arr[i][j]->getCellValue();
			}
		}
	}
	return max;
}

int Tablica::smallest(int a1, int a2, int b1, int b2)
{
	int min = this->arr[a1][a2]->getCellValue();
	for(int i = a1; i <= b1; i++)
	{
		for(int j = a2; j <= b2; j++)
		{
			if(this->arr[i][j]->getCellValue() < min)
			{
				min = this->arr[i][j]->getCellValue();
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
			sum += this->arr[i][j]->getCellValue();
			n++;
		}
	}
	return sum/n;
}

Tablica::~Tablica()
{
	this->deleteTab();
}