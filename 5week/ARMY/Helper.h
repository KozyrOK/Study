#ifndef HELPER_H
#define HELPER_H

class Unit;
class SpellCaster;

#include "Unit.h"
#include "SpellCaster.h"

class Helper {
    public:
        Helper(SpellCaster* unit, Unit* patient);
        ~Helper();
        void heal(SpellCaster* unit, Unit* patient);
};

#endif // HELPER_H