#include "Rand.h"


std::mt19937 Rand::Rand::getSeed()
{
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    return std::mt19937(seed);
}

int Rand::Rand::randInt(int low, int high)
{
    return std::uniform_int_distribution<>(low, high)(Rand::Rand::randEng);
}

std::mt19937 Rand::Rand::randEng = Rand::Rand::getSeed();


int Rand::FlipCoin::operator()()
{
    return std::uniform_int_distribution<>(0, 1)(Rand::Rand::randEng);
}

std::vector<int> Rand::FlipCoin::operator()(int numCoins)
{
    std::vector<int> flipResults;

    for (int i = 0; i < numCoins; i++)
        flipResults.push_back(Rand::Rand::randInt(0, 1));

    return flipResults;
}
