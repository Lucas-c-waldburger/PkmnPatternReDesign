#ifndef PKMNPATTERNREDESIGN_CARDDATA_H
#define PKMNPATTERNREDESIGN_CARDDATA_H

#include "CDataIdentities.h"
#include "../Handler/ActiveHandler.h"
#include <memory>

// Attack and Trainer can share a funciton map?

struct PkmnData;
struct EnergyData;
struct TrainerData;

struct CardData
{
    CardData(CardID id, CardName cn, CardType ct, EnergyType et);
    virtual ~CardData();

    CardID cId;
    CardName cName;
    CardType cType;
    EnergyType eType;

    virtual const PkmnData *castPkmnData() const;
    virtual const EnergyData *castEnergyData() const;
    virtual const TrainerData *castTrainerData() const;
};

// Holds the raw data that is used to intantiate the implementation classes inside it's ActiveHandler;
struct PkmnData : public CardData
{

    PkmnData(CardID id, CardName cn, EnergyType et, Stage st,
             int bHp, EnergyType weak, EnergyType res);
    PkmnData(const PkmnData& rhs);
    virtual ~PkmnData();

    Stage stage;
    int baseHp;
    EnergyType weakness;
    EnergyType resistance;
    // raw Attacks/AttacksInterface data
    // raw retreatCost data

    const PkmnData* castPkmnData() const override;

private:
    std::unique_ptr<ActiveHandler> activeHandler;
};

struct EnergyData : public CardData
{
    EnergyData(CardID id, CardName cn, EnergyType et, int val);
    virtual ~EnergyData();

    int value;

    const EnergyData* castEnergyData() const override;
};

struct TrainerData : public CardData
{
    TrainerData(CardID id, CardName cn, EnergyType et);
    virtual ~TrainerData();

    // some other
    // relevant values
    // for resolving effects

    const TrainerData* castTrainerData() const override;
};


#endif //PKMNPATTERNREDESIGN_CARDDATA_H
