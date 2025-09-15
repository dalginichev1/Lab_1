#include "closest_pair_tonum.h"
#include <cmath>

bool isPerfectsqrt(int num)
{
    int i = 0;

    if (num < 0)
    {
        return false;
    }
    int root = static_cast<int>(std::sqrt(num));
    return root * root == num;
}

NumberPair closest_pair_tonum(int number)
{
    int i = 0;
    int j = 0;

    if (number <= 5)
    {
        return {0, 0};
    }

    for (i = number - 1; i > 1; --i)
    {
        for (j = i - 1; j > 0; --j)
        {
            int diff = i - j;
            int sum = i + j;

            if (isPerfectsqrt(diff) && isPerfectsqrt(sum))
            {
                return {i ,j};
            }
        }
    }

    return {0, 0};
}