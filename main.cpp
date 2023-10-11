#include <iostream>
#include "include/CDataIdentities.h"

int main() {
    //std::cout << std::boolalpha << (CardType::TRAINER.equals(CardType::TRAINER));

    //CardName cn1{"Electabuzz"}, cn2{"Hitmonlee"};

    CardID cId1{OwnerID::PLAYER_1, 1, 124};

    std::cout << cId1;
    //std::cout << std::boolalpha << CardID::ANY.matchesWith(cId1);
    return 0;
}
