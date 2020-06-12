#ifndef KOMORKI_H
#define KOMORKI_H
#include <iostream>

using namespace std;

class Cell
{
private:

    string val;                                                   //wartość lub tekst przypisany komórce

public:

    Cell(string x);                                               //konstruktor z możliwością wprowadzenia wartości

    Cell();                                                       //konstruktor z domyślną wartością 0
    
    /**
    * @return - tekst z komórce
    * */
    string  getString();                                          //zwraca napis w komórce

    /**
    * @return - wartość w komórce
    * */
    int* getInt_p();                                              //zwraca wartość w komórce (jeśli taka się w niej znajduje)

    /**
    * @param[in] x - tekst do przypisania
    * */
    void setCellValue(string x);                                  //przypisuje komórce podaną wartość

    void clearCell();                                             //czyści zawartość komórki
};
#endif