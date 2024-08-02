#include <QCoreApplication>
#include "concrete_colleague.h"
#include "concrete_mediator.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

/*
    中介者模式（Mediator Pattern）用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。
        Mediator（抽象中介者）：为 Colleague 对象之间的通信定义接口。
        ConcreteMediator（具体中介者）：实现 Mediator 接口，并需要了解和维护各个 Colleague 对象，负责协调他们之间的通信。
        Colleague（抽象同事类）：定义与其他 Colleague 通信的接口。
        ConcreteColleague （具体同事类）：实现 Colleague 接口，并通过 Mediator 与其他 Colleague 进行沟通。

    中介者是对象的通信中心。当一个对象需要与另一个对象通信时，它不会直接调用另一个对象。相反，它会调用中介者对象，其主要职责是将消息路由到目标对象。
    它允许开发人员不必管理对象之间的链接。

    优点：
        1.中介者模式简化了对象之间的交互，它用中介者和同事的一对多交互代替了原来同事之间的多对多交互，一对多关系更容易理解、维护和扩展，
          将原本难以理解的网状结构转换成相对简单的星型结构。
        2.中介者模式可将各同事对象解耦。中介者有利于各同事之间的松耦合，可以独立地改变和复用每一个同事和中介者，增加新的中介者和新的同事类都比较方便，更好地符合“开闭原则”。
        3.可以减少子类生成，中介者将原本分布于多个对象间的行为集中在一起，改变这些行为只需生成新的中介者子类即可，这使各个同事类可被重用，无须对同事类进行扩展。
    缺点：
        1.如果存在大量同事之间的交互，中介者将会变得非常复杂，使得系统难以维护

    适用场景：
        1.系统中对象之间存在比较复杂的引用关系，导致它们之间的依赖关系结构混乱而且难以复用该对象。
        2.想通过一个中间类来封装多个类中的行为，而又不想生成太多的子类。

    案例分析：
        奔波在一线城市的人，想必都经历过找房的辛酸（北漂的我默默地路过），不通过中介，想找到一个合适的小窝？不存在的。。。社区驻守、客户介绍、网络拓客、花钱买房源信息，
        对于中介来说，这些简直都是轻车熟路，房源哪里逃！更可怕的是，前一秒是独家，下一秒就是千百家。
        这里，中介是对象的通信中心。当房东需要与租客通信时，他们之间不会直接交互，而是通过中介将消息发送给目标对象。

    最好的例子就是Qt的事件处理机制，发送事件以及处理事件
*/


//找房啦！一旦房东将房子挂出去，中介便会通知所有需要租房的人
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 房东
    IColleague *landlord = new ConcreteColleague("Tom");

    // 租客
    IColleague *jerry = new ConcreteColleague("Jerry");
    IColleague *tuffy = new ConcreteColleague("Tuffy");

    // 中介者 - 添加租客
    ConcreteMediator mediator;
    mediator.registerColleague(jerry);//注册参与者，调用中介者父类的registerColleague虚函数
    mediator.registerColleague(tuffy);

    // 房东通过中介将消息发送出去-接收者接收到消息后将消息打印出来
    landlord->sendMessage(mediator, "Xi'erqi, two bedroom house, 6000/month.");

    SAFE_DELETE(jerry);
    SAFE_DELETE(tuffy);

    getchar();

    return 0;


    return a.exec();
}
