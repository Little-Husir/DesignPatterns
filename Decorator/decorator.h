#ifndef DECORATOR_H
#define DECORATOR_H

#include "component.h"

// 调味品--装饰IBeverage抽象类而不改变它，CondimentDecorator类的改变不影响IBeverage类
class CondimentDecorator : public IBeverage
{
public :
    CondimentDecorator(IBeverage *beverage) : m_pBeverage(beverage) {}

    string Name() {
        return m_pBeverage->Name();
    }

    double Cost() {
        return m_pBeverage->Cost();
    }

protected :
    IBeverage *m_pBeverage;
} ;

#endif // DECORATOR_H
