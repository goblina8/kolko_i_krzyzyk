//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#ifndef POLE
#define POLE
using namespace std; 

class pole
{
    private:
        char sign;  //X,O,e
        int number;
    public:
        pole(int number);
        pole() {this->sign = 'e'; this->number = 0;}
        char whatSign();
        int whatNumb();
        pole changeSign(char sign);
        void displayPole();
};

#endif