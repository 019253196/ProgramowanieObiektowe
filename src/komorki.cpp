#include <iostream>
#include "komorki.h"
#include <string>

using namespace std;

Cell::Cell()
{
    this->val = "";
}

Cell::Cell(string x)
{
    this->val = x;
}

string Cell::getString()
{
    return this->val;
}

int* Cell::getInt_p()
{
    int *a = new int;
    string x = this->val;
    try
    {
        *a = stoi(x, nullptr, 10);
    }
	catch(const invalid_argument  e)
    {
        a = NULL;
    }
    return a;
}

void Cell::setCellValue(string x)
{
    this->val = x;
}

void Cell::clearCell()
{
    this->val = "";
}