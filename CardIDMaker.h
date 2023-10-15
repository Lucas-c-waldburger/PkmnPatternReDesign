#ifndef PKMNPATTERNREDESIGN_CARDIDMAKER_H
#define PKMNPATTERNREDESIGN_CARDIDMAKER_H
#include <map>
#include "CData/CDataEnums.h"


namespace CardIDMaker
{
    //const int DECK_CARD_LIMIT = 60;
    //const int NON_ENERGY_CARD_LIMIT = 4;

    class CardIDMaker
    {
    public:
        CardIDMaker(OwnerID ownId);
        int operator()(int rawCId);

    private:
        class CopyTracker
        {
        public:
            int getCopies(int rawCId);
            void add(int rawCId);
        private:
            std::map<int, int> trackerMap;
        };

        OwnerID ownerId;
        CopyTracker copyTracker;
    };

    // static bool validateCardID(const int cId);
};


#endif //PKMNPATTERNREDESIGN_CARDIDMAKER_H
