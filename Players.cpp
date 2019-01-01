#include "BoardAndPawns.cpp"
class Player{
public:
    void make_move();
    char color;

};

class RandomPlayer: public Player{
public:
    void make_move(){}
};

//tworze graczy i ich ruchy

