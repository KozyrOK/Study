#include "Warlock.h"

Warlock::Warlock(int unitType, std::string name, int hitPoints, int damage, int mana):
    SpellCaster::SpellCaster(unitType, name, hitPoints, damage, mana) {
        this->demon = NULL;
    }

Warlock::~Warlock() {
    if ( this->demon != NULL )
        delete demon;
}

void Warlock::attack(Unit* enemy, bool isAttack) {
    this->warlockAttack = new Attack(this, enemy, isAttack);
    delete warlockAttack;
}

void Warlock::cast(Unit* enemy) {
    this->warlockCast = new Spell(this, enemy);
    delete warlockCast;
}

void Warlock::heal(Unit* unit) {
    this->warlockHeal = new Helper(this, unit);
    delete warlockHeal;
}

Demon* Warlock::callDemon() {
    if ( this->demon == NULL )
        this->demon = new Demon(this);
    return this->demon;
}

void Warlock::killDemon() {
    if ( this->demon != NULL )
        delete demon;
}

void Warlock::subtractHitPoints(int hitPoints) {
    Unit::subtractHitPoints(hitPoints);

    if ( this->getHitPoints() <= 0 )
        delete this->demon;
}

std::ostream& operator<<(std::ostream& out, const Warlock& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage()
    << " MANA: " << unit.getMana() << "|" << unit.getManaLimit();
    return out;
}