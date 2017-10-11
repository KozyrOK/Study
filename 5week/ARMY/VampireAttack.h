#ifndef VAMPIRE_ATTACK_H
#define VAMPIRE_ATTACK_H

class Unit;

#include <iostream>
#include "Unit.h"

class VampireAttack {
public:
    VampireAttack(Unit* unit, Unit* enemy, bool isAttack);
    virtual ~VampireAttack();

    virtual void makeAttack(Unit* unit, Unit* enemy, bool isAttack);
};

#endif // VAMPIRE_ATTACK_H