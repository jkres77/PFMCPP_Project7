#include "Paladin.h"

#include "Utility.h"

Paladin::Paladin(std::string name_, int hp_, int armor_, int attackDamage_ ) :
Character(hp_, armor_, attackDamage_),
name(name_)
{
    helpfulItems = makeHelpfulItems(1);
    defensiveItems = makeDefensiveItems(5);
}

const std::string& Paladin::getName()
{

}

std::string Paladin::getStats()
{

}
