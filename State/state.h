// state.h
#ifndef STATE_H
#define STATE_H

// 信号灯的状态
class IState
{
public:
    //纯虚函数--用于改变状态
    //状态类的 Handle() 方法可能会更改信号灯的状态（例如从红灯变为绿灯），并通过 SetState() 方法更新 TrafficLights 的状态。
    virtual void Handle() = 0;
};

#endif // STATE_H
