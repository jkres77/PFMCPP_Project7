#include "Dwarf.h"

#include "Utility.h"

Dwarf::Dwarf(std::string name_, int hp_, int armor_, int attackDamage_ ) :
Character(hp_, armor_, attackDamage_),
name(name_)
{
    helpfulItems = makeHelpfulItems(3);
    defensiveItems = makeDefensiveItems(6);
}

const std::string& Dwarf::getName()
{
    return name;
}

std::string Dwarf::getStats()
{
    return getCharacterStats(this);
}
