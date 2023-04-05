#include <tuple> 
#include <iostream> 
#include <math.h>

int gcd(int a, int b)
{
	int rest = 0;
	
	/*
		Erstellen Sie eine Funktion, die den größten gemeinsamen Teiler der Zahlen a und b
		(gcd(a, b)) berechnet.
		Hinweis: Beim euklidischen Algorithmus wird in aufeinanderfolgenden Schritten jeweils
		eine Division mit Rest durchgeführt, wobei der Rest im nächsten Schritt zum neuen
		Divisor wird. Der Divisor, bei dem sich Rest 0 ergibt, ist der größte gemeinsame Teiler
		der Ausgangszahlen.
	*/
	
	do {
		rest = a % b;
		a = b;
		b = rest;
	} while (rest != 0);

	return a;
}

std::tuple<int, int, int> extendedEuclid(int aDecremented, int a)
{
	int xDecremented = 1;
	int xIncremented;
	int x = 0;

	int yDecremented = 0;
	int yIncremented;
	int y = 1;

	int aIncremented;
	int q;


	/*
		Implementieren Sie den erweiterten euklidischen Algorithmus.

		q_i = floor(a_{i-1}/a_i)
		a_{i+1} = a_{i-1} ? q_i*a_i
		x_{i+1} = x_{i-1} ? q_i*x_i
		y_{i+1} = y_{i-1} ? q_i*y_i
	*/

	do {
		q = floor(aDecremented / a);

		aIncremented = aDecremented - q * a;
		aDecremented = a;
		a = aIncremented;

		xIncremented = xDecremented - q * x;
		xDecremented = x;
		x = xIncremented;

		yIncremented = yDecremented - q * y;
		yDecremented = y;
		y = yIncremented;
	} while (a != 0);
	

	return std::make_tuple(aDecremented, xDecremented, yDecremented);
}