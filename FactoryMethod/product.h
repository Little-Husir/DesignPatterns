﻿#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

// 创建抽象产品--汽车接口
class ICar
{
public:
    virtual string Name() = 0;  // 汽车名称
};

#endif // PRODUCT_H
