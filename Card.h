#ifndef PKMNPATTERNREDESIGN_CARD_H
#define PKMNPATTERNREDESIGN_CARD_H
#include "CData/CardData.h"

class Card
{
public:
    using uPtr = std::unique_ptr<Card>;

    Card(const CardData& cd);
    ~Card();

private:
    CardData* cData;
};


#endif //PKMNPATTERNREDESIGN_CARD_H
