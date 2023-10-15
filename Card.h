#ifndef PKMNPATTERNREDESIGN_CARD_H
#define PKMNPATTERNREDESIGN_CARD_H
#include "CData/CardData.h"

class Card
{
public:
    ~Card();

    static std::unique_ptr<Card> make(const CardData& cd);
    static bool validateCD(const CardData& cd);

private:
    Card(const CardData& cd);

    std::unique_ptr<CardData> cData;
};


#endif //PKMNPATTERNREDESIGN_CARD_H
