#ifndef PKMNPATTERNREDESIGN_HITPOINTS_H
#define PKMNPATTERNREDESIGN_HITPOINTS_H
#include <iostream>

class HitPoints
{
public:
    explicit HitPoints(int baseHP);

    int getCurrent() const;
    int getBase() const;
    int getAsNumCounters() const;

    void adjust(int amount);
    void set(int amount);

private:
    int current;
    int base;

    void keepInBounds();
    static void round(int& val);
};


#endif //PKMNPATTERNREDESIGN_HITPOINTS_H
