#ifndef FOOD_H
#define FOOD_H
#include <windows.h>
#include <cstdlib>


class Food
{
    public:
        Food();
        void CreatFood();
        COORD getPosition();

    protected:

    private:
        COORD pos;
};

#endif // FOOD_H
