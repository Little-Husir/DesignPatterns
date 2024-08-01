#ifndef OBSERVER_H
#define OBSERVER_H

// 抽象观察者-提供一个update接口，用于更新价格
class IObserver
{
public:
    virtual void Update(float price) = 0;  // 更新价格
};

#endif // OBSERVER_H
