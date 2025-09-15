#include <iostream>
#include "../include/closest_pair_tonum.h"

int main(int argc, char* argw[])
{
    int number = 0;

    while (std::cin >> number)
    {
        auto pair = closest_pair_tonum(number);
        std::cout << "(" << pair.n << " , " << pair.m << ")" << "\n"; 
    }
    
    return 0;
}