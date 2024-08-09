#include <QCoreApplication>
#include "context.h"
#include "concrete_strategy.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete p; p=nullptr;} }
#endif

/*
   策略模式（Strategy Pattern）定义一系列算法，把它们一个个封装起来，并且使它们可以互相替换。Strategy 可以使算法独立于使用算法的客户端。
       Context（环境角色）：持有一个对 Strategy 的引用，最终给客户端调用。
       Strategy（抽象策略）：定义了一个公共接口，让不同的算法以不同的方式来实现。通过这个接口，Context 可以调用不同的算法。
       ConcreteStrategy（具体策略）：实现 Strategy 定义的接口，提供具体算法的实现。

   优点：
       1.各自使用封装的算法，可以很容易地引入新的算法来满足相同的接口。
       2.由于实现的是同一个接口，所以策略之间可以自由切换。
       3.Strategy 使客户端能够选择所需的算法，而无需使用switch/case或if/else语句。
       4.算法的细节完全封装在 Strategy 类中，因此，可以在不影响 Context 类的情况下更改算法的实现。

   缺点：
       1.客户端必须知道所有的策略，了解它们之间的区别，以便适时选择恰当的算法。
       2.策略模式将造成产生很多策略类，可以通过使用享元模式在一定程度上减少对象的数量。

   适用场景：
       1.多个类有不同的表现形式，每种表现形式可以独立成单独的算法。
       2.需要在不同情况下使用不同的算法，以后算法可能还会增加。
       3.对客户端隐藏具体算法的实现细节，彼此完全独立。

   案例分析：
       要出去玩，有很多种出行方式，自行车、公交车、自驾、地铁、火车、飞机。。。如何选择最合适的呢？
           1.如果离家近，又怕堵车，可以骑自行车。
           2.如果离家远，但想省钱，早点出发，可以乘公交车。
           3.如果有车，并且不介意支付停车费，可以选择自驾。
           4.如果没有车，但赶时间，可以乘出租车。
       这里的每一种出行方式都是一种具体的策略。如何选择，需要基于成本、便利和时间之间的权衡。

   大话设计模式：
       1.策略模式是一种定义一系列算法的方法，从概念上来看，所有这些算法完成的都是相同的工作，只是实现不同，它可以以相同的方式调用所有的算法，减少了各种算法类与使用算法类之间的耦合

       2.策略模式的 Strategy 类层次为 Context 定义了一系列的可供重用的算法或行为。继承有助于析取出这些算法中的公共功能
       3.当不同的行为堆砌在一个类中时，就很难避免使用条件语句来选择合适的行为。将这些行为封装在一个个独立的 Strategy 类中，可以在使用这些行为的类中消除条件语句
       4.策略模式就是用来封装算法的，但在实践中，我们发现可以用它来封装几乎任何类型的规则，只要在分析过程中听到需要在不同时间应用不同的业务规则，
         就可以考虑使用策略模式处理这种变化的可能性
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ITransport *bike = new Bike();
    ITransport *car = new Car();
    ITransport *train = new Train();

    // 张三骑自行车、李四开车、王五坐火车
    Tourists *zhangsan = new Tourists(bike);
    Tourists *lisi = new Tourists(car);
    Tourists *wangwu = new Tourists(train);

    zhangsan->Travel();
    lisi->Travel();
    wangwu->Travel();

    SAFE_DELETE(bike);
    SAFE_DELETE(car);
    SAFE_DELETE(train);

    SAFE_DELETE(zhangsan);
    SAFE_DELETE(lisi);
    SAFE_DELETE(wangwu);

    getchar();

    return 0;


    return a.exec();
}
