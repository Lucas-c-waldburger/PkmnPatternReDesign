#ifndef PKMNPATTERNREDESIGN_CDATAIDENTITIES_H
#define PKMNPATTERNREDESIGN_CDATAIDENTITIES_H
#include "CDataEnums.h"
#include "../include/IdentitiesBase.h"
#include <functional>


class CardType : public IdentitiesBase<CardType>
{
public:
    CardType(int val);
    virtual ~CardType();

    static const CardType NULL_VALUE,
                          ANY,
                          PKMN,
                          ENERGY,
                          TRAINER;
};

class EnergyType : public IdentitiesBase<EnergyType>
{
public:
    EnergyType(int val);
    virtual ~EnergyType();

    static const EnergyType NULL_VALUE,
                            ANY,
                            WATER,
                            FIRE,
                            GRASS,
                            ELECTRIC,
                            PSYCHIC,
                            FIGHTING,
                            COLORLESS;
};

class CardName : public IdentitiesBase<CardName, size_t>
{
public:
    CardName(const std::string& cNm);
    ~CardName();

    const std::string& str() const;

    static const CardName NULL_VALUE,
                          ANY;
private:
    CardName(size_t st, const std::string& cNm);
    const std::string cNameStr;
};



class CardID : public IdentitiesBase<CardID>
{
public:
    CardID(OwnerID ownerId, int cpy, int dbNum);

    static const CardID NULL_VALUE,
                        ANY;

private:
    CardID(int i);
    static int assembleId(OwnerID ownerId, int cpy, int dbNum);
};




#endif //PKMNPATTERNREDESIGN_CDATAIDENTITIES_H
