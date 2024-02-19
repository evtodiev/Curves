#include <iostream>
#include <vector>
#include <random>

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

const double PI = 3.141592653589793238463;

int main()
{
    vector <unique_ptr<Curve>> curves;
    
    std::default_random_engine gen;
    std::uniform_int_distribution<int>      int_distr   (1, 3);
    std::uniform_real_distribution<double>  double_distr(0.0, 30.0);


    // заполняем массив
    for (int i = 0; i < 20; ++i) {
        int int_rand = int_distr(gen);
        double r, a, b, h;
        switch (int_rand) {
        case 1:
            r = double_distr(gen);
            curves.emplace_back(new Circle(r));
            break;
        case 2:
            a = double_distr(gen);
            b = double_distr(gen);
            curves.emplace_back(new Ellipse(a, b));
            break;
        case 3:
            r = double_distr(gen);
            h = double_distr(gen);
            curves.emplace_back(new Helix(r, h));
            break;
        }
    }

    // выводим значения точки и производной
    for (auto &curve : curves) {
        curve->Print(PI / 4.0);
    }

    cout << "--------------------" << endl;

    // выделяем круги
    vector <Curve *> circles;

    for (auto& curve : curves) {
        if (typeid(*curve) == typeid (Circle))
            circles.push_back(&(*curve));
    }
    
    //for (auto& circle : circles) {
    //    circle->Print(PI / 2.0);
    //}
    //cout << "--------------------" << endl;


    // сортируем
    sort(circles.begin(), circles.end(),
        [](Curve *const a, Curve *const b) {
            const Circle* a1 = dynamic_cast<const Circle*>(a);
            const Circle* b1 = dynamic_cast<const Circle*>(b);
            return a1->Get_r() < b1->Get_r();
        });
    

    // сумма радиусов всех кругов
    double r_sum = 0.0;
    for (auto& circle : circles) {
        const Circle* c = dynamic_cast<const Circle*>(circle);
        r_sum += c->Get_r();
    }
    cout << "R sum = " << r_sum << endl;
}