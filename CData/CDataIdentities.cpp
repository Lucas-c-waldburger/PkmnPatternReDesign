#include "CDataIdentities.h"

/* Card Type */
CardType::CardType(int val) : IdentitiesBase<CardType>(val)
{}

CardType::~CardType()
{}

const CardType CardType::NULL_VALUE = IdentitiesBase<CardType>::nullVal,
               CardType::ANY = IdentitiesBase<CardType>::anyVal,
               CardType::PKMN = 1,
               CardType::ENERGY = 2,
               CardType::TRAINER = 3;


/* Energy Type */
EnergyType::EnergyType(int val) : IdentitiesBase<EnergyType>(val)
{}

EnergyType::~EnergyType()
{}



const EnergyType EnergyType::NULL_VALUE = IdentitiesBase<EnergyType>::nullVal,
                 EnergyType::ANY = IdentitiesBase<EnergyType>::anyVal,
                 EnergyType::WATER = 1,
                 EnergyType::FIRE = 2,
                 EnergyType::GRASS = 3,
                 EnergyType::ELECTRIC = 4,
                 EnergyType::PSYCHIC = 5,
                 EnergyType::FIGHTING = 6,
                 EnergyType::COLORLESS = 7;




/* Card Name */
CardName::CardName(const std::string& cNm) : IdentitiesBase<CardName, size_t>(std::hash<std::string>{}(cNm)),
                                             cNameStr(cNm)
{}

CardName::CardName(size_t st, const std::string& cNm) : IdentitiesBase<CardName, size_t>(st), cNameStr(cNm)
{}

CardName::~CardName()
{}

const std::string& CardName::str() const
{
    return cNameStr;
}

const CardName CardName::NULL_VALUE{ IdentitiesBase<CardName, size_t>::nullVal, "NULL_VALUE" },
               CardName::ANY{ IdentitiesBase<CardName, size_t>::anyVal, "ANY" };


/* Card ID */
CardID::CardID(OwnerID ownerId, int cpy, int dbNum) : IdentitiesBase<CardID>(CardID::assembleId(ownerId, cpy, dbNum))
{}

CardID::CardID(int i) : IdentitiesBase<CardID>(i)
{}

int CardID::assembleId(OwnerID ownerId, int cpy, int dbNum)
{
    return static_cast<int>(ownerId) + (cpy * 1000) + dbNum;
}

const CardID CardID::NULL_VALUE = IdentitiesBase<CardID>::nullVal,
             CardID::ANY = IdentitiesBase<CardID>::anyVal;