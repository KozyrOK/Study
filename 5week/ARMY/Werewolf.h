#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include "Attack.h"
#include "SpellCaster.h"

class Werewolf : public Unit {
protected:
    Attack* werewolfAttack;
public:
    Werewolf(int unitType = 5, std::string name = "Human", int hitPoints = 100, int damage = 10,
        int unitType2 = 6, std::string name2 = "Wolf", int hitPoints2 = 150, int damage2 = 15);
    virtual ~Werewolf();

    virtual void attack(Unit* enemy, bool isAttack = true);
    void makeWerewolf(SpellCaster* unit, std::string newName = "Human");
    void makeWerewolf(Unit* unit, std::string newName = "Human");
};

std::ostream& operator<<(std::ostream& out, const Werewolf& unit);

#endif // WEREWOLF_H