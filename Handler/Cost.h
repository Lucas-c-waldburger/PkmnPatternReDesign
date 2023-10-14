#ifndef PKMNPATTERNREDESIGN_COST_H
#define PKMNPATTERNREDESIGN_COST_H
#include "../CData/CardData.h"
#include "../Player.h"
#include <vector>

class Cost
{
public:
    struct SubCost
    {
        SubCost(CardData cd, ZoneName cDest);

        CardData cData;
        ZoneName cDestination;
    };

    Cost(std::initializer_list<SubCost> sCs);
    ~Cost() = default;


    // static bool moveToDestination(Player& pl, const SubCost& sc);
    // static bool pay(Player& pl, std::unique_ptr<Card>& crd, Cost& cst);

private:
    std::vector<SubCost> subCosts;
};


#endif //PKMNPATTERNREDESIGN_COST_H
