#include <QCoreApplication>
#include "concrete_subject.h"
#include "concrete_observer.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif


/*
    观察者模式（Observer Pattern），定义了对象间的一对多的依赖关系，让多个观察者对象同时监听某一个主题对象（被观察者）。当主题对象的状态发生更改时，会通知所有观察者，让它们能够自动更新。

     背景：
       很多时候，在应用程序的一部分发生更改时，需要同时更新应用程序的其他部分。有一种方法是：让接收者反复检查发送者来进行更新，但是这种方法存在两个主要问题
            1.占用大量的CPU时间来检查新的状态
            2.依赖于检测更新的时间间隔，可能不会立即 获得更新
     对于这个问题，有一个简单的解决方案-观察者模式

     模式结构：
       Subject（抽象主题）：跟踪所有观察者，并提供添加和删除观察者的接口。
       Observer（抽象观察者）：为所有的具体观察者定义一个接口，在得到主题的通知时进行自我更新。
       ConcreteSubject（具体主题）：将有关状态存入各 ConcreteObserver 对象。当具体主题的状态发生任何更改时，通知所有观察者。
       ConcreteObserver（具体观察者）：实现 Observer 所要求的更新接口，以便使本身的状态与主题的状态相协调。

     优点：
          1.观察者和被观察者是抽象耦合的   2.建立一套触发机制
     缺点：
          1.如果一个被观察者对象有很多的直接和间接的观察者，将所有的观察者都通知到会花费很多时间。
          2.如果在观察者和观察目标之间有循环依赖的话，观察目标会触发它们之间进行循环调用，可能导致系统崩溃。
          3.观察者模式没有相应的机制让观察者知道所观察的目标对象是怎么发生变化的，而仅仅只是知道观察目标发生了变化。

     适用场景：
          1.有多个子类共有的方法，且逻辑相同    2.重要的、复杂的方法，可以考虑作为模板方法

     场景解释：
          开始，我们创建了一个主题（滴滴）以及两个观察者（Jack Ma &amp; Pony），通过 attach() 将他们加入至司机行列。调用 setPrice(12.5)，通知他们起步价为 12.5 元。
          后来呢，司机 Pony 由于种种原因（大家都懂得）离职了 - detach() 注销。。。价格再次上调，涨、涨、涨 setPrice(15.0)。。。

     什么时候使用委托？
          当一个对象的改变需要同时改变其他对象的时候，而且它不知道具体有多少对象有待改变时，应该考虑使用观察者模式。
          当一个抽象模型有两个方面，其中一方面依赖于另一方面，这时用观察者模式可以将这两者封装在独立的对象中使它们各自独立地改变和复用。
          总的来讲，观察者模式所做的工作其实就是在解除耦合。让耦合的双方都依赖于抽象而不是依赖于具体。从而使得各自的变化都不会影响另一边的变化。

     界面的热插拔是否可以用到委托？


*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 创建主题、观察者
    ConcreteSubject *pSubject = new ConcreteSubject();
    IObserver *pObserver1 = new ConcreteObserver("Jack Ma");
    IObserver *pObserver2 = new ConcreteObserver("Pony");

    // 注册观察者
    pSubject->Attach(pObserver1);
    pSubject->Attach(pObserver2);

    // 更改价格，并通知观察者
    pSubject->SetPrice(12.5);
    pSubject->Notify();

    // 注销观察者
    pSubject->Detach(pObserver2);
    // 再次更改状态，并通知观察者
    pSubject->SetPrice(15.0);
    pSubject->Notify();

    SAFE_DELETE(pObserver1);
    SAFE_DELETE(pObserver2);
    SAFE_DELETE(pSubject);

    getchar();

    return 0;


    return a.exec();
}
