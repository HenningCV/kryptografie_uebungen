#include <iostream>
#include <tuple>

#include "ellipticCurve.h"
#include "gcd.h"


struct POINT ellipticCurve(int a, int b, int p, int x, int y, int d)
{

	POINT point;
	point.x = x;
	point.y = y;

	POINT pointH;
	pointH.x = x;
	pointH.y = y;

	POINT pointNew;
	pointNew.x = 0;
	pointNew.y = 0;


	return pointH;
}