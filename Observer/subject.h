#ifndef SUBJECT_H
#define SUBJECT_H

class IObserver;

// 抽象主题-提供关于注册、注销、通知观察者的接口
class ISubject
{
public:
    virtual void Attach(IObserver *) = 0;  // 注册观察者
    virtual void Detach(IObserver *) = 0;  // 注销观察者
    virtual void Notify() = 0;  // 通知观察者
};

#endif // SUBJECT_H
