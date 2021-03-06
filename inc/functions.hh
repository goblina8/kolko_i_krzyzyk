//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#ifndef FUNCTIONS
#define FUNCTIONS
#include "plansza.hh"
using namespace std; 

void menu();
void move(plansza game, int opponent);
plansza playerMove(plansza game, char XO);
plansza computerMove(plansza game, char XO);
bool end(plansza game, char XO);
int minmaxAB(plansza game, int depth, bool isMax, char XO, int A, int B);
#endif
