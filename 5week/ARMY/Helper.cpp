#include "Helper.h"

Helper::Helper(SpellCaster* unit, Unit* patient) {
    unit->ensureIsAlive();
    patient->ensureIsAlive();
    this->heal(unit, patient);
}

Helper::~Helper() {}

void Helper::heal(SpellCaster* unit, Unit* patient) {
    if ( patient->getUnitType() == 3 || unit->getMana() < 30 ) 
        return;
    double mMultiplier = 0.5;
    int untType = unit->getUnitType();
    int pttType = patient->getUnitType();
    if ( untType == 9 || untType == 10 )
        mMultiplier *= 2;
    patient->addHitPoints((int)((double)30*(double)mMultiplier));
    unit->subtractMana(30);
}