﻿#include <QCoreApplication>
#include "facade.h"

/*
    外观模式（Facade Pattern）又称为门面模式，属于结构型模式。Façade 为子系统中的一组接口提供了一个统一的高层接口，该接口使得子系统更加容易使用。
        1.Facade（外观）：模式的核心，被 Client 调用，知晓相关子系统的功能和责任。在正常情况下，它将所有从 Client 发来的请求委派到相应的子系统去，让子系统处理。
        2.SubSystem（子系统）：可以同时有一个或者多个子系统，子系统可以是一个单独的类或类的集合。每个子系统都可以被 Client 直接调用，或者被 Facade 调用，
          它处理由 Facade 传过来的请求。子系统并不知道 Facade 的存在，对于子系统而言，Facade 仅仅是另外一个 Client 而已。

    优点：
        1.对 Client 屏蔽子系统组件，减少了 Client 处理的对象数目，并使得子系统使用起来更加容易。通过引入外观模式，Client 的代码将变得很简单，与之关联的对象也很少。
        2.实现了子系统与 Client 之间的松耦合关系，这使得子系统的组件变化不会影响到调用它的 Client，只需要调整 Facade 即可。
        3.降低了大型软件系统中的编译依赖性，并简化了系统在不同平台之间的移植过程，因为编译一个子系统一般不需要编译所有其他的子系统。
          一个子系统的修改对其他子系统没有任何影响，而且子系统内部变化也不会影响到外观对象。
        4.只是提供了一个访问子系统的统一入口，并不影响用户直接使用子系统类。

    缺点：
        1.不能很好地限制 Client 使用子系统类，如果对 Client 访问子系统类做太多的限制，则会减少可变性和灵活性。
        2.在不引入抽象外观类的情况下，增加新的子系统可能需要修改 Facade 或 Client 的源代码，违背了“开闭原则”。

    适用场景：
        1.当要为一个复杂子系统提供一个简单接口时。该接口可以满足大多数用户的需求，而且用户也可以越过外观类直接访问子系统。
        2.Client 与多个子系统之间存在很大的依赖性。引入外观类将子系统与 Client 以及其他子系统解耦，可以提高子系统的独立性和可移植性。
        3.在层次化结构中，可以使用外观模式定义系统中每一层的入口。层与层之间不直接产生联系，而通过外观类建立联系，降低层之间的耦合度。

    案例分析：
        像京东、淘宝、亚马逊这些电商平台，客户挑选好喜欢的宝贝，然后进行结算。在随后的过程中，我们并不清楚这些网站背后的情况，所关注的只不过是，
        下完订单后，将会在一段时间后收货。其实，在幕后，任务被分发给不同的子系统（订单团队、供应商、快递员）去完成，为了方便，可以进行订单跟踪：
             下订单 -->订单验证 --> 打包 --> 出货 --> 派送 --> 交付

    外观模式什么时候使用最好？
        “这要分三个阶段来说，首先，在设计初期阶段，应该要有意识的将不同的两个层分离，比如经典
        的三层架构，就需要考虑在数据访问层和业务逻辑层、业务逻辑层和表示层的层与层之间建立外观
        Facade，这样可以为复杂的子系统提供一个简单的接口，使得耦合大大降低。其次，在开发阶段，子系
        统往往因为不断的重构演化而变得越来越复杂，大多数的模式使用时也都会产生很多很小的类，这本是
        好事，但也给外部调用它们的用户程序带来了使用上的困难，增加外观Facade 可以提供一个简单的接
        口，减少它们之间的依赖。第三，在维护一个遗留的大型系统时，可能这个系统已经非常难以维护和扩
        展了，但因为它包含非常重要的功能，新的需求开发必须要依赖于它。此时用外观模式 Facade 也是非常
        合适的。你可以为新系统开发一个外观 Facade 类，来提供设计粗糙或高度复杂的遗留代码的比较清晰
        简单的接口，让新系统与 Facade 对象交互，Facade与遗留代码交互所有复杂的工作”


*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    OnlineShoppingFacade facade;

    // 提交订单
    facade.submitRequest();

    // 跟踪订单，直到订单完成
    while (!facade.checkStatus());

    std::cout << "********** 订单完成，跟踪次数：" << facade.followupNum() << " **********" << std::endl;

    getchar();

    return 0;

    return a.exec();
}
