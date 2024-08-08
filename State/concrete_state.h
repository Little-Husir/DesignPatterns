// concrete_state.h
#ifndef CONCRETE_STATE_H
#define CONCRETE_STATE_H

#include "state.h"

//它们所提供的方法有对上下文对象的引用，并且能够改变它的状态
class TrafficLights;

// 红灯
class RedLight : public IState
{
public:
    //构造函数-提供一个TrafficLights上下文
    RedLight(TrafficLights* context);
    virtual void Handle() override;

private:
    TrafficLights* m_pContext;
};

// 绿灯
class GreenLight : public IState
{
public:
    GreenLight(TrafficLights* context);
    virtual void Handle() override;

private:
    TrafficLights* m_pContext;
};

// 黄灯
class YellowLight : public IState
{
public:
    YellowLight(TrafficLights* context);
    virtual void Handle() override;

private:
    TrafficLights* m_pContext;
};

#endif // CONCRETE_STATE_H
