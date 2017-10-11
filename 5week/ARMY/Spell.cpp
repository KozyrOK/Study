#include "Spell.h"

Spell::Spell(SpellCaster* unit, Unit* enemy) {
    unit->ensureIsAlive();
    enemy->ensureIsAlive();
    this->cast(unit, enemy);
}

Spell::~Spell() {}

void Spell::cast(SpellCaster* unit, Unit* enemy) {
    if ( enemy->getUnitType() == 3 || unit->getMana() < 30 )
        return;
    double mMultiplier = 1;
    int untType = unit->getUnitType();
    int nmyType = enemy->getUnitType();
    if ( untType == 9 || untType == 10 )
        mMultiplier /= 2;
    if ( nmyType == 6 )
        mMultiplier *= 2;
    if ( untType == 10 ) {
        if ( nmyType == 4 || nmyType == 13 )
            mMultiplier = 2;
    }
    enemy->subtractHitPoints((int)((double)30*(double)mMultiplier));
    unit->subtractMana(30);
}