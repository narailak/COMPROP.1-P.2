#include <iostream>
using namespace std;

struct Rect
{
	double x, y, w, h;
};

double overlap(Rect *R1, Rect *R2)
{
	double result, xl, xr, yt, yb;
	if (R1->y < R2->y)
		yt = R1->y;
	else
		yt = R2->y;
	if (R1->y - R1->h < R2->y - R2->h)
		yb = R2->y - R2->h;
	else
		yb = R1->y - R1->h;
	if (R1->x > R2->x)
		xl = R1->x;
	else
		xl = R2->x;
	if (R1->x + R1->w < R2->x + R2->w)
		xr = R1->x + R1->w;
	else
		xr = R2->x + R2->w;
	result = (yt - yb) * (xr - xl);
	if (result >= 0)
		return result;
	else
		return 0;
}