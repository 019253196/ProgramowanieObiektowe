#ifndef KOMORKI_H
#define KOMORKI_H
#include <iostream>

using namespace std;

class Cell
{
    private:
    int val;                                                      //wartość w komórce

    public:

    Cell();                                                       //konstruktor z domyślną wartością 0

    Cell(int x);                                                  //konstruktor z możliwością wprowadzenia wartości
    
    /**
    * @return - wartość w komórce
    * */
    int getCellValue();                                           //zwraca wartość w komórce

    /**
    * @param[in] x - wartość do przypisania
    * */
    void setCellValue(int x);                                     //przypisuje komórce podaną wartość
};
#endif