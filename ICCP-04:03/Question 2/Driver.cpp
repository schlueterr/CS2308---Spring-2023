#include <iostream>
#include <string>
#include "Monster.h"
using namespace std;

int main() {
    Monster m("Goblin", 75);
    cout << "Nickname: " << m.getNickname() << std::endl;
    cout << "Health: " << m.getHealth() << std::endl;
    cout << "Damage: " << m.damage() << std::endl;
    m.setHealth(50);
    cout << "New health: " << m.getHealth() << std::endl;
    cout << "New damage: " << m.damage() << std::endl;
    return 0;
}
