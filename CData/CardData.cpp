#include "CardData.h"

CardData::CardData(CardID id, CardName cn, CardType ct, EnergyType et) :
        cId(id), cName(cn), cType(ct), eType(et)
{}

CardData::~CardData()
{}

const PkmnData* CardData::castPkmnData() const { return nullptr; }
const EnergyData* CardData::castEnergyData() const { return nullptr; }
const TrainerData* CardData::castTrainerData() const { return nullptr; }



PkmnData::PkmnData(CardID id, CardName cn, EnergyType et, Stage st, int bHp, EnergyType weak, EnergyType res) :
        CardData(id, cn, CardType::PKMN, et), stage(st), baseHp(bHp), weakness(weak), resistance(res)
{}

PkmnData::~PkmnData()
{}

PkmnData::PkmnData(const PkmnData& rhs) : CardData(rhs.cId, rhs.cName, rhs.cType, rhs.eType),
                                          stage(rhs.stage), baseHp(rhs.baseHp), weakness(rhs.weakness), resistance(rhs.resistance),
                                          activeHandler(std::make_unique<ActiveHandler>(*rhs.activeHandler))
{}

const PkmnData* PkmnData::castPkmnData() const { return this; }



EnergyData::EnergyData(CardID id, CardName cn, EnergyType et, int val) :
CardData(id, cn, CardType::ENERGY, et), value(val)
{}

EnergyData::~EnergyData()
{}

const EnergyData* EnergyData::castEnergyData() const { return this; }



TrainerData::TrainerData(CardID id, CardName cn, EnergyType et) :
        CardData(id, cn, CardType::ENERGY, et)
{}

TrainerData::~TrainerData()
{}

const TrainerData* TrainerData::castTrainerData() const { return this; }