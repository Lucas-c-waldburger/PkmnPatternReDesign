#ifndef PKMNPATTERNREDESIGN_CARDDATA_H
#define PKMNPATTERNREDESIGN_CARDDATA_H

#include "CDataIdentities.h"
#include "../Attacking/AttacksInterface.h"
#include "../Handler/ActiveHandler.h"


struct PkmnData;
struct EnergyData;
struct TrainerData;

struct CardData
{
    CardData(CardID id, CardType ct, EnergyType et);
    virtual ~CardData();

    CardID cId;
    CardName cName;
    CardType cType;
    EnergyType eType;

    virtual const PkmnData *castPkmnData() const;
    virtual const EnergyData *castEnergyData() const;
    virtual TrainerData *castTrainerData() const;
};

// Holds the raw data that is used to intantiate the implementation classes inside it's ActiveHandler;
struct PkmnData : public CardData
{

    PkmnData(CardID id, EnergyType et, Stage st,
             int bHp, EnergyType weak, EnergyType res);
    virtual ~PkmnData();

    Stage stage;
    int baseHp;
    EnergyType weakness;
    EnergyType resistance;
    // raw Attacks/AttacksInterface data
    // raw retreatCost data

    const PkmnData* castPkmnData() const override;

private:
    ActiveHandler activeHandler;
};


#endif //PKMNPATTERNREDESIGN_CARDDATA_H
