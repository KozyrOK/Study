#include <iostream>
#include <cstdlib>
#include "Vampire.h"
#include "Werewolf.h"
#include "Priest.h"
#include "Warlock.h"
#include "Demon.h"
#include "Necromancer.h"
#include "Rogue.h"

int main() {
    Vampire* unit1 = new Vampire();
    Werewolf* unit2 = new Werewolf();
    Rogue* unit3 = new Rogue();
    Warlock* unit4 = new Warlock();
    Necromancer* unit5 = new Necromancer();

    std::cout << *unit1 << std::endl;
    std::cout << *unit2 << std::endl;
    std::cout << *unit3 << std::endl;
    std::cout << *unit4 << std::endl;
    std::cout << *unit5 << std::endl;
    std::cout << std::endl;

    unit1->makeVampire(unit3);
    unit2->makeWerewolf(unit4);

    std::cout << *unit1 << std::endl;
    std::cout << *unit2 << std::endl;
    std::cout << *unit3 << std::endl;
    std::cout << *unit4 << std::endl;
    std::cout << *unit4 << std::endl;

    return 0;
}