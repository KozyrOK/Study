#include "Attack.h"

Attack::Attack(Unit* unit, Unit* enemy, bool isAttack) {
    this->makeAttack(unit, enemy, isAttack);
}

Attack::~Attack() {}

void Attack::makeAttack(Unit* unit, Unit* enemy, bool isAttack) {
    unit->ensureIsAlive();
    enemy->ensureIsAlive();
    if ( isAttack ) {
        enemy->subtractHitPoints(unit->getDamage());
        enemy->attack(unit, !isAttack);
    } else {
        enemy->subtractHitPoints(unit->getDamage()/2);
    }
}
