#ifndef PKMNPATTERNREDESIGN_RAND_H
#define PKMNPATTERNREDESIGN_RAND_H
#include <random>
#include <vector>

namespace Rand
{
    struct Rand
    {
        static std::mt19937 getSeed();
        static std::mt19937 randEng;
        static int randInt(int low, int high);
    };

    struct FlipCoin
    {
        int operator()();
        std::vector<int> operator()(int numCoins);
    };

    static FlipCoin flipCoin{};
};


#endif //PKMNPATTERNREDESIGN_RAND_H
