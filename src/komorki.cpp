#include <iostream>
#include "komorki.h"

using namespace std;

Cell::Cell()
{
    this->val = 0;
}

Cell::Cell(int x)
{
    this->val = x;
}

int Cell::getCellValue()
{
    return this->val;
}

void Cell::setCellValue(int x)
{
    this->val = x;
}