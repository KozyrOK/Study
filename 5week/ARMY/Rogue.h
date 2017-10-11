#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"
#include "RogueAttack.h"

class Rogue : public Unit {
    protected:
        RogueAttack* rogueAttack;
    public:
        Rogue(int unitType = 2, std::string name = "Rogue", int hitPoints = 100, int damage = 10);
        virtual ~Rogue();

        virtual void attack(Unit* enemy, bool isAttack = true);
};

std::ostream& operator<<(std::ostream& out, const Rogue& unit);

#endif // ROGUE_H