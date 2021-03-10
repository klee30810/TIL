#include <stdio.h>
#include "Point.h"

void SetPointPos(Point *ppos, int xpos, int ypos)
{
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

void ShowPointPos(Point *ppos)
{
	printf("[%d, %d] \n", ppos->xpos, ppos->ypos);
}

int PointComp(Point *pos1, Point *pos2)
{
	if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)
		return 0;
	else if (pos1->xpos == pos2->xpos)
		return 1;
	else if (pos1->ypos == pos2->ypos)
		return 2;
	else
		return -1;
}

// insert point sorting rule function
int PointPrecede(Point *d1, Point *d2)
{
	if (d1->xpos < d2->xpos) // ascending order
	{
		return 0;
	}
	else if (d1->xpos == d2->xpos) // same : ypos ascending
	{
		if (d1->ypos < d2->ypos)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}