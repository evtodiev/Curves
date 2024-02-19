#pragma once
#include "Curve.h"
class Ellipse :
    public Curve
{
public:
    Ellipse(double a, double b) : _name("Ellipse"), _a(a), _b(b) {};
    
    void Print(double t) const override {
        Point p;
        p.x = _a * cos(t);
        p.y = _b * sin(t);
        p.z = 0.0;


        cout << fixed << setprecision(2);

        cout << _name << " " << "radii = " << _a << ", " << _b << " ";
        Printder(Getder(t));
        cout << endl;

    }
    
    Point Getpoint(double t) const override {
        Point point;
        point.x = _a * cos(t);
        point.y = _b * sin(t);
        point.z = 0.0;
        return point;
    }

    Derivative Getder(double t) const override {
        Derivative der;
        der.point = Getpoint(t);
        double sint = sin(t), cost = cos(t);

        double val = sqrt(_a * _a * sint*sint + _b * _b * cost*cost);
        der.cos.x = (-_a * sint) / val;
        der.cos.y = ( _b * cost) / val;
        der.cos.z = 0.0;

        return der;
    }

private:
    double _a, _b;
    const string _name;
};

