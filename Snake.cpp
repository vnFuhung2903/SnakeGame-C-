#include "Snake.h"
#include "Food.h"

#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define HEIGHT 25
#define WIDTH 50

Snake::Snake(COORD pos, int level)
{
    this->pos = pos;
    this->level = level;
    SnakeLength = 1;
    Direction = 0;
    body.push_front(pos);
}

void Snake::changeDirection(int dir)
{
    if(Direction != -dir)
        Direction = dir;
}

COORD Snake::getPosition()
{
    return pos;
}

void Snake::Move()
{
    switch(Direction)
    {
        case -2:
            pos.Y -= 1;
            break;
        case -1:
            pos.X -= 1;
            break;
        case 2:
            pos.Y += 1;
            break;
        case 1:
            pos.X += 1;
            break;
    }

    if(pos.X == 0)  pos.X = WIDTH - 2;
    if(pos.X == WIDTH - 1) pos.X = 1;
    if(pos.Y == 0)  pos.Y = HEIGHT - 2;
    if(pos.Y == HEIGHT - 1) pos.Y = 1;
    body.push_front(pos);
    if(body.size() > SnakeLength) body.pop_back();
}

deque <COORD> Snake::BodyCheck()
{
    return body;
}

void Snake::Grow()
{
    ++level;
    ++SnakeLength;
}

bool Snake::Eaten(COORD food_pos)
{
    if(food_pos.X == pos.X && food_pos.Y == pos.Y)
        return 1;
    return 0;
}

bool Snake::Boom()
{
    if(pos.X == 0 || pos.X == WIDTH - 1 || pos.Y == 0 || pos.Y == HEIGHT - 1)
        return 1;
    FOR(i,1,body.size() - 1)
        if(pos.X == body.at(i).X && pos.Y == body.at(i).Y)  return 1;
    return 0;
}
