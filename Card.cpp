//
// Created by Lower School Music on 10/12/23.
//

#include "Card.h"

Card::Card(const CardData& cd) : cData(new CardData(cd))
{}

Card::~Card()
{
    delete cData;
}
