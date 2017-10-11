#include "VampireAttack.h"

VampireAttack::VampireAttack(Unit* unit, Unit* enemy, bool isAttack) {
    this->makeAttack(unit, enemy, isAttack);
}

VampireAttack::~VampireAttack() {}

void VampireAttack::makeAttack(Unit* unit, Unit* enemy, bool isAttack) {
    unit->ensureIsAlive();
    enemy->ensureIsAlive();
    if ( isAttack ) {
        enemy->subtractHitPoints(unit->getDamage());
        enemy->subtractHitPoints((int)((double)(enemy->getHitPointsLimit()) * (double)0.1));
        enemy->attack(unit, !isAttack);
    } else {
        enemy->subtractHitPoints(unit->getDamage()/2);
        enemy->subtractHitPoints((int)((double)(enemy->getHitPointsLimit()) * (double)0.1));
    }
}