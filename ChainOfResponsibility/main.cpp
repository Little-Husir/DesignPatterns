#include <QCoreApplication>
#include "concrete_handler.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete p; p=nullptr;} }
#endif

/*
   职责链模式 （Chain of Responsibility Pattern）使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。将这些对象连成一条链，
   并沿着这条链传递该请求，直到有一个对象处理它为止。

      Handler（抽象处理者）：定义了处理请求所需的接口。
      ConcreteHandler（具体处理者）：处理自己负责的请求，如果无法处理，则将请求传递给与之保持联系的后继者（即：successor）。
      Client（客户端）：请求的发起者，将访问 Handler 来处理它。

   优点：
      1.降低耦合度，将请求的发送者和接收者解耦。
      2.简化了对象，使得对象不需要知道链的结构。从另一方面来看消除了对 switch/case或if/else条件逻辑的依赖
      3.增强给对象指派职责的灵活性，通过改变链内的成员或者调整它们的次序来动态改变职责。
      4.增加新的具体处理者很方便，无须修改原有代码，只需要在客户端重新建链即可。

   缺点：
      1.由于没有明确的接收者，所以无法保证请求一定会被处理（可能直到链的末端都得不到处理，也可能因为链没有配置正确而得不到处理。）
      2.对于较长的职责链来说，请求可能涉及到多个处理对象，这将会使系统性能受到一定影响，而且不利于代码调试。
      3.如果建链不当，可能会造成循环调用，这将导致系统陷入死循环。

   适用场景：
      1.有多个对象可以处理同一请求，具体哪个对象处理由运行时刻自动确定。客户端只负责提交请求，而无须关心请求的处理对象是谁以及它是如何处理的。
      2.在不明确指定接受者的情况下，向多个对象中的一个提交一个请求。
      3.可动态指定一组对象处理请求，客户端可以动态创建职责链来处理请求，还可以改变链中处理者之间的先后次序。

   案例分析：
      当员工发出请假请求时，链中的处理者可以对请求作出响应或者将其传递给上级。每个处理者都有自己的一套规则，而这套规则是他们可以批准的。
      审批流程：经理（1 天及以下） --> 总监（3 天及以下） --> 总裁（7 天为界限）。
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    IHandler *manager = new Manager();
    IHandler *director = new Director();
    IHandler *ceo = new CEO();

    // 职责链：经理 -> 总监 -> 总裁-->先是经理审批然后总监然后总裁审批
    manager->SetSuccessor(director);//设置审批人
    director->SetSuccessor(ceo);

    manager->HandleRequest(1);
    manager->HandleRequest(2);
    manager->HandleRequest(5);
    manager->HandleRequest(10);

    SAFE_DELETE(manager);
    SAFE_DELETE(director);
    SAFE_DELETE(ceo);

    getchar();

    return 0;


    return a.exec();
}
