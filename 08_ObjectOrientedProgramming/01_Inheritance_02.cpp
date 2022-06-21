#include <iostream>
/*
Activity 23: Creating Game Characters
We want to write a new game, and in that game, create two types of characters 
– a hero and enemies. 
Enemies can swing their swords, and the hero can cast a spell.
*/

struct Position {
    std::string positionIdentifier;
};

class Character{

    public:
        void moveTo(Position *P){
            Pos = P;
            std::cout << "Moved to position " << Pos->positionIdentifier 
                << " " << Pos << std::endl;
        }
    private:
        Position * Pos;
};

class Spell {
    public:
        Spell(std::string name) : d_name(name) {}

        std::string name() const {
            return d_name;
        }
    private:
        std::string d_name;
};

class Hero : public Character {
    
    public:
        void castSpell(Spell sp){
            std::cout << "Casting spell " << sp.name() << std::endl;
        }
};


class Enemy : public Character {
    
    public:
        void Swinging(){
            std::cout << "Swinging sword" << std::endl;
        }
};



int main(){

    Position position{"Enemy castle"};
    Hero hero;
    Enemy enemy;

    hero.moveTo(&position);
    enemy.moveTo(&position);
    
    hero.castSpell(Spell("fireball"));
    enemy.Swinging();
    return 0;
}
/* ////! The output should be:
Moved to position Enemy castle
Moved to position Enemy castle
Casting spell fireball
Swinging sword
*/