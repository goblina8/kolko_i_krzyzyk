//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#include "pole.hh"
#include "plansza.hh"
#include <iostream>
using namespace std;

plansza:: plansza(int size)
{
    int r = 0;
    int c = 0;
    this->size = size;
    turn = 1; //zawsze zaczyna gracz
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            tab[i][j] = pole(c+r);
            r++;
        }
        c = c+10;
    }
}

int plansza:: whatSize()
{
    return this->size;
}

bool plansza:: whoseTurn()
{
    return this->turn;
}

char plansza:: changeTurn(char XO)
{
    if (whoseTurn())
    {
        this->turn = 0;
    }
    else
    {
        this->turn = 1;
    }
    if (XO == 'X')
    {
        XO = 'O';
    }
    else
    {
        XO = 'X';
    }
    return XO;
}

plansza plansza:: changePole(char XO, int column, int row)
{
    this->tab[column-1][row-1] = (this->tab[column-1][row-1]).changeSign(XO);  
    return *this;
}

void plansza:: displayPlansza()
{
    cout << "  ";
    for (int i = 0; i <this->whatSize(); i++)
    {
        cout << " " << i+1 << "  ";
    }
    for (int i = 0; i < this->whatSize(); i++)
    {
       cout << endl << i+1 << " ";
       for (int j = 0; j < this->whatSize(); j++) 
       {
            (tab[i][j]).displayPole();
            cout << " ";
       }
    }
    cout << endl;
}

bool plansza:: isEmpty(int column, int row)
{
    if ((this->tab[column-1][row-1]).whatSign() == 'e')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool plansza:: isEnd(char XO)
{
    int g = 3;
    //w zależności od rozmiaru planszy - by wygrać należy mieć 3,4 lub 5 znaków w linii
    if ((this->size == 3)||(this->size == 4)|| (this->size == 5))
    {
        g = 3;
    } 
    else if ((this->size == 6)||(this->size == 7))
    {
        g = 4;
    }
    else if ((this->size == 8)||(this->size == 9))
    {
        g = 5;
    }
    int howManyInColumn = 0;
    int howManyInRow = 0;
    int howManyInCrossL = 0;
    int howManyInCrossR = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((this->tab[i][j]).whatSign() == XO)
            {
                //cout << "tab[" << i << "][" << j << "]" << endl;
                for (int k = 0; k < g; k++)
                {
                    if ((i+k) < this->size)
                    {
                        if (((this->tab)[i+k][j]).whatSign() == XO) 
                        {
                            howManyInColumn++;
                            //cout << "dodano w kolumnie" << endl;
                        }
                    }
                    if ((j+k) < this->size)
                    {
                        if (((this->tab)[i][j+k]).whatSign() == XO) 
                        {
                            howManyInRow++;
                            //cout << "dodano w rzedzie" << endl;
                        }
                    }
                    if (((i+k) < this->size) && ((j-k) >= 0))
                    {
                        if (((this->tab)[i+k][j-k]).whatSign() == XO) 
                        {
                            howManyInCrossL++;
                            //cout << "dodano na ukos" << endl;
                        }
                    }
                    if (((i+k) < this->size) && ((j+k) < this->size))
                    {
                        if (((this->tab)[i+k][j+k]).whatSign() == XO) 
                        {
                            howManyInCrossR++;
                            //cout << "dodano na ukos" << endl;
                        }
                    }
                }
                //cout << "kolumna: " << howManyInColumn << "ukosR: " << howManyInCrossR << "ukosL: " << howManyInCrossL << "rzad: " << howManyInColumn << endl; 
                if ((howManyInColumn == g)||(howManyInCrossL == g)||(howManyInRow == g)||(howManyInCrossR == g))
                {
                    return 1;
                }
                else
                {
                    //cout << "zeruje" << endl;
                    howManyInColumn = 0;
                    howManyInCrossL = 0;
                    howManyInCrossR = 0;
                    howManyInRow = 0;
                }
            }
        }
    }
    cout << endl;
    return 0;
}