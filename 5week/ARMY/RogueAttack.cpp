#include "RogueAttack.h"

RogueAttack::RogueAttack(Unit* unit, Unit* enemy, bool isAttack) {
    this->makeAttack(unit, enemy, isAttack);
}

RogueAttack::~RogueAttack() {}

void RogueAttack::makeAttack(Unit* unit, Unit* enemy, bool isAttack) {
    unit->ensureIsAlive();
    enemy->ensureIsAlive();
    if ( isAttack ) {
        enemy->subtractHitPoints(unit->getDamage());
    } else {
        enemy->subtractHitPoints(unit->getDamage()/2);
    }
}