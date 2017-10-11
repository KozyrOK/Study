#ifndef ROGUE_ATTACK_H
#define ROGUE_ATTACK_H

#include <iostream>
#include "Unit.h"

class RogueAttack {
public:
    RogueAttack(Unit* unit, Unit* enemy, bool isAttack);
    virtual ~RogueAttack();

    virtual void makeAttack(Unit* unit, Unit* enemy, bool isAttack);
};

#endif // ROGUE_ATTACK_H
