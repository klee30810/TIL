#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)
{
    if (num == 1)
    {
        printf("Move plate 1 from %c to %c \n", from, to);
    }
    else
    {
        HanoiTowerMove(num - 1, from, to, by);
        printf("Move plate %d from %c to %c \n", num, from, to);
        HanoiTowerMove(num - 1, by, to, from);
    }
}

int main()
{
    HanoiTowerMove(5, 'A', 'B', 'C');

    return 0;
}