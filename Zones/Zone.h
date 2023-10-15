#ifndef PKMNPATTERNREDESIGN_ZONE_H
#define PKMNPATTERNREDESIGN_ZONE_H
#include "../Card.h"
#include <vector>

class Zone
{
public:


private:
    std::vector<std::unique_ptr<Card>> cards;
};


#endif //PKMNPATTERNREDESIGN_ZONE_H
