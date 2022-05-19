//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#ifndef PLANSZA
#define PLANSZA
#include "pole.hh"
using namespace std; 

class plansza
{
    private:
        int size;  
        pole tab[5][5]; //max wymiar planszy 10x10
        bool turn; //1X - gracz, 0O - komputer
    public:
        plansza(int size);
        bool whoseTurn();
        char changeTurn(char XO);
        plansza changePole(char XO, int column, int row);
        void displayPlansza();
        int whatSize();
        bool isEmpty(int column, int row);
        int isEnd(char XO); //0 gra trwa, 1 ktos wygral, 2 remis
};

#endif