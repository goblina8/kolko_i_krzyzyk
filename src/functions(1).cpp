//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#include "functions.hh"
#include "plansza.hh"
#include "pole.hh"
#include <iostream>
using namespace std;

int howDeep = 2;
char XO = 'O';

void move(plansza game, int opponent)
{
    while (!(end(game, XO)))
    {
        XO = game.changeTurn(XO);
        cout << "RUCH GRACZA " << XO << endl;
        if(game.whoseTurn())
        	{ 
    	        game = playerMove(game, XO);
            }
        else
 	    {
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
    int bestScore = -100;
    int bestMove[2] = {1, 1};
    for (int i = 1; i < game.whatSize()+1; i++)
    {
        for (int j = 1; j < game.whatSize()+1; j++)
        {
            if(game.isEmpty(i,j) == 1)
            {
                game = game.changePole('X',i,j);
                int score = minmax(game, 0, false, 'X');
                game= game.changePole('e',i,j);
                if (score > bestScore)
                {
                    bestScore = score;
                    bestMove[0] = i;
                    bestMove[1] = j;
                }
            }
        } 
    }
    return game.changePole(XO,bestMove[0],bestMove[1]);
}

int minmax(plansza game, int depth, bool isMax, char XO)
{
    int score = game.isEnd(XO);
    if ((score == 1)&&(XO == 'X'))
    {
        return 10; //wygrywa X
    }
    if ((score == 1)&&(XO == 'O'))
    {
        return -10; //wygrywa O
    }
    if (game.isEnd(XO) == 2)
    {
        return 0; //remis
    }
    if (!(depth <= howDeep+1))
    {
        return 0;
    }
    if(isMax) //maximazer move
    {
        int bestScore = -100;
        for (int i = 1; i < game.whatSize()+1; i++)
        {
            for (int j = 1; j < game.whatSize()+1; j++)
            {
                if(game.isEmpty(i,j) == 1)
                {
                    game = game.changePole('X',i,j);
                    bestScore = max(bestScore, minmax(game, depth+1, false, 'O'));
                    game = game.changePole('e',i,j);
                }
            }
        }
        return bestScore;
    }
    else //minimazer move
    {
        int bestScore = 100;
        for (int i = 1; i < game.whatSize()+1; i++)
        {
            for (int j = 1; j < game.whatSize()+1; j++)
            {
                if(game.isEmpty(i,j) == 1)
                {
                    game = game.changePole('O',i,j);
                    bestScore = min(bestScore, minmax(game, depth+1, true, 'X'));
                    game = game.changePole('e',i,j);
                }
            }
        }
        return bestScore;

    }
    return 1;
}

bool end(plansza game, char XO)
{
    if ((game.isEnd(XO)==0))
    {
        return 0;
    }
    else if (game.isEnd(XO)==2)
    {
        cout << "REMIS" << endl;
        return 1;
    }
    else
    { 
        if (game.whoseTurn() == 1) //wygrywa gracz 1
        {
            cout << "WYGRYWA GRACZ " << XO << endl;
        }
        if (game.whoseTurn() == 0) //wygrywa komputer / gracz 2
        {
            cout << "WYGRYWA GRACZ " << XO << endl;
        }
        return 1;
    }
}

void menu()
{
    int opponent = 1;
    int size = 0;
    system("clear");
    while (!((size >= 3)&&(size <= 9)))
    {
        cout << "Podaj wymiary planszy: (cyfra z zakresu [3,5])" << endl;
        cin >> size;
    }
    while (!((opponent == 1)||(opponent==0)))
    {
        cout << "Czy chcesz grać z komputerem (1) czy z innym użytkownikiem (0)?" << endl;
        cin >> opponent;
    }
    if (opponent == 1)
    {
        switch(size)
        {
            case 3:
            {
                howDeep = 10;
                break;
            }
            case 4:
            {
                howDeep = 3;
                break;
            }
            case 5:
            {
                howDeep = 2;
                break;
            }
        }
    }
    system("clear");
    plansza game = plansza(size);
    game.displayPlansza();
    move(game,opponent);
}