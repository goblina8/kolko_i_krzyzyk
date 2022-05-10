//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#include "functions.hh"
#include "plansza.hh"
#include "pole.hh"
#include <iostream>
using namespace std;

char XO = 'O';
int opponent = 0;

void move(plansza game)
{
    while (!(end(game, XO)))
    {
        XO = game.changeTurn(XO);
        if(game.whoseTurn())
        	{ 
                cout << "RUCH GRACZA O" << endl;
    	        game = playerMove(game, XO);
            }
        else
 	    {
            cout << "RUCH GRACZA X" << endl;
            if (opponent)
    	        {
                   game = computerMove(game, XO);
                }
   	        else
            {
   	            game = playerMove(game, XO); 
      	    }
        }
        system("clear");
        game.displayPlansza();
        cout << endl; //usunac
    }
}

plansza playerMove(plansza game, char XO)
{
    int row = 0;
    int column = 0;
    int free = 0;
    while (free == 0)
    {
        while (!((row >= 1)&&(row <= game.whatSize())))
        {
            cout << "Podaj numer wiersza: ";
            cin >> row;
        }
        while (!((column >= 1)&&(column <= game.whatSize())))
        {
            cout << "Podaj numer kolumny: ";
            cin >> column;
        }
        cout << endl;
        if(game.isEmpty(row, column))
        {
            free = 1;
        }
        else
        {
            cout << "To pole jest już zajęte!" << endl;
            row = 0;
            column = 0;
        }
    }
    return game.changePole(XO, row, column);
}

plansza computerMove(plansza game, char XO)
{

}


bool end(plansza game, char XO)
{
    if (!(game.isEnd(XO)))
    {
        return 0;
    }
    else
    { 
        if (game.whoseTurn() == 1) //wygrywa gracz 1
        {
            cout << "WYGRYWA GRACZ O" << endl;
        }
        if (game.whoseTurn() == 0) //wygrywa komputer / gracz 2
        {
            cout << "WYGRYWA GRACZ X" << endl;
        }
        return 1;
    }
}


void menu()
{
    int size = 0;
    system("clear");
    while (!((size >= 3)&&(size <= 9)))
    {
        cout << "Podaj wymiary planszy: (cyfra z zakresu [3,9])" << endl;
        cin >> size;
    }
    /*
    while (!((opponent == 1)||(opponent==0)))
    {
        cout << "Czy chcesz grać z komputerem (1) czy z innym użytkownikiem (0)?" << endl;
        cin >> opponent;
    }
    */
    system("clear");
    plansza game = plansza(size);
    game.displayPlansza();
    move(game);
}