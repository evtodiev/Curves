#pragma once
#include "Curve.h"
class Circle :
    public Curve
{
public:
    Circle(double r) : _r(r), _name("Circle") {};

    void Print(double t) const override {
        Point p;
        p.x = _r * cos(t);
        p.y = _r * sin(t);
        p.z = 0.0;

        cout << fixed << setprecision(2);

        cout << _name << " " << "radius = " << _r << " ";
        Printder(Getder(t));
        cout << endl;
    }
    
    Point Getpoint(double t) const override {
        Point point;
        point.x = _r * cos(t);
        point.y = _r * sin(t);
        point.z = 0.0;
        return point;
    }

    Derivative Getder(double t) const override {
        Derivative der;
        der.point = Getpoint(t);
        der.cos.x = -_r * sin(t);
        der.cos.y =  _r * cos(t);
        der.cos.z = 0.0;
        return der;
    }
    
    double Get_r() const { return _r; };

private:
    const string _name;
    double _r; // радиус
 
};

