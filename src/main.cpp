#include <iostream>
#include "../include/closest_pair_tonum.h"

int main(int argc, char* argw[])
{
    auto pair_1 = closet_pair_tonum(10);
    std::cout<<"("<< pair_1.n << ")" << pair_1.m << "\n";

    return 0;
}