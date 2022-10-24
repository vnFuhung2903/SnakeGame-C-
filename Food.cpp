#include "Food.h"
#define HEIGHT 25
#define WIDTH 50

Food::Food()
{
    CreatFood();
}

void Food::CreatFood()
{
    pos.X = rand() % (WIDTH - 3) + 1;
    pos.Y = rand() % (HEIGHT - 3) + 1;
}

COORD Food::getPosition()
{
    return pos;
}
