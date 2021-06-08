#include "DragonSlayer.h"
#include "Dragon.h"

#include "Utility.h"
#include "AttackItem.h"

DragonSlayer::DragonSlayer(std::string name_, int hp_, int armor_, int attackDamage_ ) :
Character(hp_, armor_, attackDamage_),
name(name_)
{
    helpfulItems = makeHelpfulItems(4);
    defensiveItems = makeDefensiveItems(3);
}

const std::string& DragonSlayer::getName()
{
    return name;
}

void DragonSlayer::attack(Character& other)
{
    std::cout << name << " is attacking " << other.getName() << " !!" << std::endl;
    if( auto* dragon = dynamic_cast<Dragon*>(&other) )
    {
        // assert(false);
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.
        //so they should USE their attack item before attacking the dragon... 
        //note that items are single-use only, so you need to reset it after use.  
        //look in the Character class for how the other item types are reset after use.
        for( auto& item : attackItems )
        {
            if( auto* attackItem = dynamic_cast<AttackItem*>(item.get()) )
            {
                attackItem->use(this);
                item.reset(); //can only be used once!
                break;
            }
        }

        while( dragon->getHP() > 0 )
        {
          dragon->takeDamage(attackDamage);
        }
    }
        
    Character::attack(other);
        
}

std::string DragonSlayer::getStats()
{
    return getCharacterStats(this);
}
