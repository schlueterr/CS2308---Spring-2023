#ifndef MONSTER_H
#define MONSTER_H
#include <string>

using namespace std;

class Monster{
    private:
        string nickname;
        int health;
    public:
        Monster(string n, int h);
        void setNickname(string n);
        void setHealth(int h);
        string getNickname();
        int getHealth();
        double damage();
};

#endif