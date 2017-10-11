#include "Demon.h"

Demon::Demon(Warlock* master, int unitType, std::string name, int hitPoints, int damage):
    Unit::Unit(unitType, name, hitPoints, damage) {
        this->master = master;
        master->ensureIsAlive();
        master->subtractHitPoints(10);
        if ( master->getHitPoints() == 0 )
            master->killDemon();
    }

Demon::~Demon() {}

void Demon::attack(Unit* enemy, bool isAttack) {
    this->demonAttack = new Attack(this, enemy, isAttack);
    delete demonAttack;
}

void Demon::subtractHitPoints(int hitPoints) {
    this->state->subtractHitPoints(hitPoints);
    if ( this->getHitPoints() <= 0 )
        master->killDemon();
}

std::ostream& operator<<(std::ostream& out, const Demon& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage();
    return out;
}