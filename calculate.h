#ifndef CALCULATE_H
#define CALCULATE_H

#include <iostream>
#include <string.h>
#include <math.h>
#include <utils.h>
#include <QString>

#define tree_price 35
#define grass_price 1000
#define shop_price 85
#define locker_price 45
#define poor_price 25
#define fence_price 15
#define reat_price 55

QString calculate(double area, double budget, double &use_budget, double &side, bool with_grass){  //参数:场地面积,预算,(引用传回)使用金额
    double square_side, count, tree_budget;
    QString result, result_1;
    square_side = floor(sqrt(area));
    square_side = square_side - 1/20 * square_side;                       //切割不规则图形,以向下取整得到方形,因边缘不规则边长去5%以消误差
    tree_budget = tree_price *(area - square_side * square_side);         //剩余面积种树填满
    count = square_side / 1000;                                           //计数器,千分之一边长作为扩展最小单位
    if(with_grass){
        budget -= grass_price;
        result.append("草坪预计花费");
        result.append(QString("%1").arg(grass_price));
        result.append("元;\n");
        result_1 = search(area, budget, square_side, count, tree_budget, use_budget, side, with_grass);
        result.append(result_1);
    }
    else{
        result = search(area, budget, square_side, count, tree_budget, use_budget, side, with_grass);
    }
    return result;
}




#endif // CALCULATE_H
