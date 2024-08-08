// context.h
#ifndef CONTEXT_H
#define CONTEXT_H

#include "concrete_state.h"

// 交通信号灯--上下文由 TrafficLights 表示，该类有一个 IState 变量，在构造中被初始化为 RedLight（红灯）

//注意：在上下文提供的方法中，实际上使用的是IState的相应方法
class TrafficLights
{
public:
    //该类有一个 IState 变量，在构造中被初始化为 RedLight（红灯）
    TrafficLights() { m_pState = new RedLight(this); }
    //这个方法允许外部代码更改交通信号灯的状态。它通过传入一个新的 IState 对象来改变 m_pState 的值
    void SetState(IState* state) { m_pState = state; }

    //每当调用 Request() 方法时，TrafficLights 会委托当前状态来处理行为，即调用当前状态对象的 Handle() 方法
    void Request() { m_pState->Handle(); }

private:
    IState* m_pState;//指向 IState 接口的指针
};

#endif // CONTEXT_H
