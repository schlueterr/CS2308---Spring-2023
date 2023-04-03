#include "Monster.h"
#include <string>
using namespace std;

Monster::Monster(string n, int h){
    nickname = n;
    health = h;
}

void Monster::setNickname(string n){
    nickname = n;
}

void Monster::setHealth(int h){
    if (health < 0){
        health = 0;
    }
    else if (health > 100)
    {
        health = 100;
    }
    else
    {
        health = h;
    }
}

string Monster::getNickname(){
    return nickname;
}

int Monster::getHealth(){
    return health;
}

double Monster::damage(){
    return static_cast<double>(health) / 10.0 + 3.0;
}