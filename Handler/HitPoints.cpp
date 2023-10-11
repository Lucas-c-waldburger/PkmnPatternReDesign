#include "HitPoints.h"


HitPoints::HitPoints(int baseHP) : base(baseHP), current(baseHP)
{}

int HitPoints::getCurrent() const { return current; }

int HitPoints::getBase() const { return base; }

void HitPoints::adjust(int amount)
{
    if (amount % 10)
        round(amount);

    current += amount;
    keepInBounds();
}

void HitPoints::set(int amount)
{
    current = amount;
    keepInBounds();
}

int HitPoints::getAsNumCounters() const
{
    return base - (base - current);
}

void HitPoints::round(int &val)
{
    int remainder = abs(val % 10);
    std::cout << "REMAINDER: " << remainder << '\n';
    val = (remainder < 5) ? val - remainder : val + (10 - remainder);
}

void HitPoints::keepInBounds()
{
    if (current > base)
        current = base;
    else if (current < 0)
        current = 0;
}


