//
// Created by Megan Jones on 10/15/23.
//

#include "CardIDMaker.h"

int CardIDMaker::CardIDMaker::CopyTracker::getCopies(int rawCId)
{
    return trackerMap[rawCId];
}

void CardIDMaker::CardIDMaker::CopyTracker::add(int rawCId)
{
    trackerMap[rawCId] += 1;
}

CardIDMaker::CardIDMaker::CardIDMaker(OwnerID ownId) : ownerId(ownId)
{}

int CardIDMaker::CardIDMaker::operator()(int rawCId)
{
    copyTracker.add(rawCId);
    return static_cast<int>(ownerId) + (copyTracker.getCopies(rawCId) * 1000) + rawCId;
}
