#include <cmath>

/* Define the weight of an integer as the number of 1's it has in its binary representation.
 * Given an integer, the following function finds the closest integer to it having the same weight, in O(1).
*/
unsigned long long closestIntSameWeight(const unsigned long long x)
{
    unsigned long long t;
    if (x & 1)
    {
        t = (x ^ (x - 1)) ^ (x - 1);
        t = ((t << 1) + 1) ^ (t >> 1);
        return x ^ t;
    }
    else
    {
        t = x ^ (x - 1);
        t = (((t << 1) + 1) - t) >> 1;
        return (x - t + (t >> 1));
    }
}

//Test if an integer is a power of 2, in O(1).
bool test_if_pow_2(unsigned long long x)
{
    if (x &= (x - 1))
        return 0;
    return 1;
}

// Find x mod 2^p in O(1).
unsigned long long mod_power_2(const unsigned long long x, const int p)
{
    return (x & ~((int)-pow(2, p)));
}

// Given an integer x, the following function swaps the ith and jth bits, in O(1).
unsigned long long swap_bits(unsigned long long x, const int i, const int j)
{

    if (((x >> i) & 1) != ((x >> j) & 1))
    {
        x ^= (unsigned long long)pow(2, i);
        x ^= (unsigned long long)pow(2, j);
    }

    return x;
}