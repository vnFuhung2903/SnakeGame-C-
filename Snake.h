#ifndef SNAKE_H
#define SNAKE_H
#include <windows.h>
#include <deque>

using std::deque;


class Snake
{
    public:
        Snake(COORD pos, int level);
        void changeDirection(int dir);
        COORD getPosition();
        void Move();
        bool Eaten(COORD food_pos);
        void Grow();
        deque <COORD> BodyCheck();
        bool Boom();

    protected:

    private:
        COORD pos;
        deque <COORD> body;
        int SnakeLength;
        int level;
        int Direction;
};

#endif // SNAKE_H
