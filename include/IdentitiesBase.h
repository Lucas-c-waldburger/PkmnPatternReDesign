#ifndef PKMNPATTERNREDESIGN_IDENTITIESBASE_H
#define PKMNPATTERNREDESIGN_IDENTITIESBASE_H
#include <iostream>


template <class Child, typename T = int>
class IdentitiesBase
{
public:
    inline IdentitiesBase(T val) : value(val) {};
    virtual ~IdentitiesBase() {};
    inline IdentitiesBase& operator=(const T& val) { this->value = val; return *this; }

    inline operator T& () { return value; }

    inline const bool equals(const Child& rhs) const { return this->value == rhs.value; }

    inline const bool matchesWith(const Child& rhs) const
    {
        return (this->value == anyVal && rhs.value != nullVal) ||  // CardID::ANY matches with any cId EXCEPT CardID::NULL_ID
               (rhs.value == anyVal && this->value != nullVal) ||
               this->value == rhs.value;
    }
private:
    T value;

protected:
    static const T nullVal;
    static const T anyVal;
};

template <class Child, typename T>
const T IdentitiesBase<Child, T>::nullVal = -1;

template <class Child, typename T>
const T IdentitiesBase<Child, T>::anyVal = 0;



#endif //PKMNPATTERNREDESIGN_IDENTITIESBASE_H
