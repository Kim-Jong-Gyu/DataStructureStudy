#include "mazestack.h"

int main()
{
    int mazearray[8][8] = {
        {0,0,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,1},
        {1,1,1,0,1,1,1,1},
        {1,1,1,0,1,1,1,1},
        {1,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,0}
    };

    LinkedStack *pStack;
    pStack = createLinkedStack();

    MapPosition start;
    MapPosition end;
    start.x = 0;
    start.y = 0;
    end.x = 7;
    end.y = 7;

    findPath(mazearray[8][8], start, end, pStack);
    
}