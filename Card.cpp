// Cards are only created at the beginning. Loaded in from protobuf and constructed inside deck zone

#include "Card.h"

Card::Card(const CardData& cd)
{
    if (cd.cType.equals(CardType::PKMN))
        cData = std::make_unique<PkmnData>(*cd.castPkmnData());
    else if (cd.cType.equals(CardType::ENERGY))
        cData = std::make_unique<EnergyData>(*cd.castEnergyData());
    else if (cd.cType.equals(CardType::TRAINER))
        cData = std::make_unique<TrainerData>(*cd.castTrainerData());
    else
        throw std::runtime_error("Attempting to construct Card with invalid CardType");

    if (!cData)
        throw std::runtime_error("Derived CardData cast returned nullptr");
}


std::unique_ptr<Card> Card::make(const CardData& cd)
{


}



bool Card::validateCD(const CardData& cd)
{


}