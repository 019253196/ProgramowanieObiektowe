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

Cell* Tablica::getCell(int x, int y)
{
	return this->arr[y][x];
}

int Tablica::createTab(int x, int y)
{
	this->y = y;
	this->x = x;
	this->arr = new Cell** [this->y];
	for(int i = 0; i < this->y; i++)
	{
		(this->arr)[i] = new Cell* [this->x];
		for (int j = 0; j < x; j++)
		{
			this->arr[i][j] = new Cell;
		}
	}
	this->zeroTab();
	return 0;
}

void Tablica::deleteTab()
{
	if(this->arr!=NULL)
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
				this->arr[i][j]->clearCell();
			}
		}
	}
}


void Tablica::changeTabSize(int x, int y)
{
	Tablica* buffer = new Tablica(x,y);
	for(int i = 0; i < buffer->y && i < this->y; i++)
		{
			for(int j = 0; j < buffer->x && j < this->x;  j++)
			{
				buffer->arr[i][j] = this->arr[i][j];
			}
		}
	this->deleteTab();
	this->x = buffer->x;
	this->y = buffer->y;
	this->arr = buffer->arr;
}


void Tablica::updateCell(int x, int y)
{
	string a = "";
	cout << "Wprowadz zmiane: ";
	cin >> a;
	this->arr[y][x]->setCellValue(a);
}

int Tablica::saveTab()
{
	fstream file;
	file.open("Tablica.txt", ios::out|ios::trunc);
	if(file.good())
	{
		file.write((const char *) &this->x, sizeof(this->x));
		file.write((const char *) &this->y, sizeof(this->y));
		for(int i = 0; i < this->y; i++)
		{
			for(int j = 0; j < this->x; j++)
			{
				string a = this->getCell(j, i)->getString();
				file.write((const char *) a.c_str(), a.size());
				file.write((const char*) "\0", 1);
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
	file.open("Tablica.txt", ios::out|ios::in);
	if(file.good())
	{
		file.read((char *) &x, sizeof(x));
		file.read((char *) &y, sizeof(y));
		this->deleteTab();
		Tablica* buffer = new Tablica(x,y);
		cout << x << " " << y << endl;
		for(int i = 0; i < buffer->y; i++)
		{
			for(int j = 0; j < buffer->x; j++)
			{
				string a = "";
				while(1)
				{
					char x; 
					file.read((char*) &x, 1);
					if (x == '\0')
					{
						break;
					}
					else
					{
						a += x;
					}
				}
				buffer->arr[i][j]->setCellValue(a);
			}
		}
		file.close();
		this->x = buffer->x;
		this->y = buffer->y;
		this->arr = buffer->arr;
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
		int *v = this->arr[a][i]->getInt_p();
		if(v != NULL)
		{
			sum += *v;
		}
	}
	return sum;
}

int Tablica::sumColumn(int a)
{
	int sum = 0;
	for(int i = 0; i < this->y; i++)
	{
		int *v = this->arr[i][a]->getInt_p();
		if(v != NULL)
		{
			sum += *v;
		}
	}
	return sum;
}

int Tablica::largest(int a1, int a2, int b1, int b2)
{
	int max = 0;
	for(int i = a1; i <= b1; i++)
	{
		for(int j = a2; j <=b2; j++)
		{
			int *v = this->arr[i][j]->getInt_p();
			if(v != NULL)
			{
				if(*v > max)
				{
					max = *v;
				}
			}
		}
	}
	return max;
}

int Tablica::smallest(int a1, int a2, int b1, int b2)
{
	bool minIsSet = false;
	int min = 0;
	for(int i = a1; i <= b1; i++)
	{
		for(int j = a2; j <= b2; j++)
		{
			int *v = this->arr[i][j]->getInt_p();
			if(!minIsSet)
			{
				if(v != NULL)
				{
					min = *v;
					minIsSet = true;
				}
			}
			if(minIsSet)
			{
				if(v != NULL)
				{
					if(*v < min)
					{
						min = *v;
					}
				}
			}
		}
	}
	return min;
}

double Tablica::average(int a1, int a2, int b1, int b2)
{
	int sum = 0;
	int n = 0;
	for(int i = a1; i <= b1; i++)
	{
		for(int j = a2; j <= b2; j++)
		{
			int* v;
			v = this->arr[i][j]->getInt_p();
			if(v != NULL)
			{
				sum = sum + *v;//= *v;
				n++;
			}
		}
	}
	return sum/n;
}

Tablica::~Tablica()
{
	this->deleteTab();
}