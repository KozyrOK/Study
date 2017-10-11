#ifndef SPELL_H
#define SPELL_H

class Unit;
class SpellCaster;

#include "Unit.h"
#include "SpellCaster.h"

class Spell {
    public:
        Spell(SpellCaster* unit, Unit* enemy);
        ~Spell();

        void cast(SpellCaster* unit, Unit* enemy);
};

#endif // SPELL_H