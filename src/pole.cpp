//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#include "pole.hh"
#include <iostream>
using namespace std;

pole::pole(int number)
{
    this->number = number;
    this->sign = 'e';
}

char pole:: whatSign()
{
    return this->sign;
}

int pole:: whatNumb()
{
    return this->number;
}

pole pole:: changeSign(char sign)
{
    this->sign = sign;
    return *this;
}

void pole:: displayPole()
{
    cout << "[";
    if (whatSign() == 'e')
    {
        cout << " ";
    }
    else
    {
        cout << whatSign();
    }
   cout << "]";
}

