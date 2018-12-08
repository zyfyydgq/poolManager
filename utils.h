#ifndef UTILS_H
#define UTILS_H

#include <iostream>
using namespace std;
#include <math.h>
#include <QString>
#include <rectangle.h>
#include <circular.h>
#include <trapezium.h>

#define tree_price 35
#define grass_price 1000
#define shop_price 85
#define locker_price 45
#define poor_price 25
#define fence_price 15
#define reat_price 55

QString search(double area, double budget, double square_side, double count, double tree_budget, double &use_budget, double &side, bool grass){
    Rectangle square_shop, rectangle_locker;
    Circular circular_poor;
    Trapezium trapezoid_rest;
    QString result;
    double shop_area, locker_area, poor_area, fence_length, reat_area;
    double shop_budget, locker_budget, poor_budget, fence_budget, reat_budget;

    square_side -= 3;
    for(; (use_budget < budget) && (side < square_side / 2); side += count){
        square_shop.set_attribute(side, side);
        rectangle_locker.set_attribute(side, side * 0.75);
        circular_poor.set_radius(side / 2);
        trapezoid_rest.set_attribute(side);

        shop_area = square_shop.area();
        locker_area = rectangle_locker.area();
        poor_area = circular_poor.area();
        fence_length = circular_poor.get_perimeter();
        reat_area = trapezoid_rest.area();

        shop_budget = shop_area * shop_price;
        locker_budget = locker_area * locker_price;
        poor_budget = poor_area * poor_price;
        fence_budget = (fence_length + 4 * square_side)* fence_price;
        reat_budget = reat_area * reat_price;

        use_budget = tree_budget + shop_budget + locker_budget + poor_budget + fence_budget + reat_budget;
    }
    side -= count;
    if(side < square_side / 4){
        result = "预算过少,合理方案场地利用率不足50%,无法建设\n";
        return result;
    }

    result.append("设计方案总预算");
    if(grass)
        use_budget += grass_price;
    result.append(QString("%1").arg(use_budget));
    result.append("元。\n其中，外围场地利用（种树）花费");
    result.append(QString("%1").arg(tree_budget));
    result.append("元;\n泳池建设花费");
    result.append(QString("%1").arg(poor_budget));
    result.append("元;\n过道花费");
    result.append(QString("%1").arg(fence_budget));
    result.append("元;\n商店建设花费");
    result.append(QString("%1").arg(shop_budget));
    result.append("元;\n更衣室建设花费");
    result.append(QString("%1").arg(locker_budget));
    result.append("元;\n休息区建设花费");
    result.append(QString("%1").arg(reat_budget));
    result.append("元;\n");
    return result;
}



#endif // UTILS_H
