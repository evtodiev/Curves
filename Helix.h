#pragma once
#include "Curve.h"
class Helix :
    public Curve
{
public:
    Helix(double r, double h) : _name("Helix"), _r(r), _h(h) {}

    Point Getpoint(double t) const override {
        Point p;
        p.x = _r * cos(t);
        p.y = _r * sin(t);
        p.z = _h * t;
        return p;
    }
    void Print(double t) const override {
        cout << fixed << setprecision(2);

        cout << _name << " " 
             << "radius = " << _r << ", " 
             << "step = "   << _h << ", ";
          // Printpoint( Getpoint(t) );
            Printder(Getder(t));
        cout << endl;
    }

    Derivative Getder(double t) const override {
        Derivative der;
        der.point = Getpoint(t);
        double val = sqrt(_r * _r + _h * _h);
        der.cos.x = (-_r * sin(t)) / val;
        der.cos.y = ( _r * cos(t)) / val;
        der.cos.z =            _h / val;

        return der;
    }


 private:
    const string _name;
    double _r, _h;
};

