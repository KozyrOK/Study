#ifndef ATTACK_H
#define ATTACK_H

class Unit;

#include <iostream>
#include "Unit.h"

class Attack {
public:
    Attack(Unit* unit, Unit* enemy, bool isAttack);
    virtual ~Attack();
    virtual void makeAttack(Unit* unit, Unit* enemy, bool isAttack);
};

#endif // ATTACK_H