#include "HitPoints.h"


HitPoints::HitPoints(int baseHP) : base(baseHP), current(baseHP)
{}

int HitPoints::getCurrent() const { return current; }

int HitPoints::getBase() const { return base; }

void HitPoints::adjust(int amount)
{
    if (amount % 10)
    {
        std::string errMsg = "HP may only be adjusted by multiples of 10.\nValue entered: " + std::to_string(amount);
        throw std::domain_error(errMsg);
    }

    current += amount;
    keepInBounds();
}

void HitPoints::set(int amount)
{
    if (amount % 10)
    {
        std::string errMsg = "HP may only be set to a multiple of 10.\nValue entered: " + std::to_string(amount);
        throw std::domain_error(errMsg);
    }

    current = amount;
    keepInBounds();
}

int HitPoints::getAsNumCounters() const
{
    return base - (base - current);
}

void HitPoints::round(int& val)
{
    int sign = (val < 0) ? -1 : 1;
    int remainder = abs(val % 10);
    std::cout << "REMAINDER: " << remainder << '\n';
    val = (remainder < 5) ? (abs(val) - remainder) * sign :
                            (abs(val) + (10 - remainder)) * sign;
}

void HitPoints::keepInBounds()
{
    if (current > base)
        current = base;
    else if (current < 0)
        current = 0;
}


