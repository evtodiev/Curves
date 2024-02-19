#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Point {
	double x, y, z;
};

struct Derivative {
	Point point; // точка на кривой, в которой вычисляется производная
	Point cos;	 // направляющие косинусы
};
 

class Curve
{
public:
	virtual Point Getpoint(double t) const = 0;
	virtual Derivative Getder(double t) const = 0;
	virtual void Print(double t) const = 0;
	
	// печать точки
	void Printpoint(Point p) const {
		cout << "(" << p.x << ", " << p.y << ", " << p.z << ")";
	}

	// печать производной
	void Printder(Derivative der) const {
		Printpoint(der.point);
		cout << "(" << der.cos.x << ", " << der.cos.y << ", " << der.cos.z << ")";
	}

};

