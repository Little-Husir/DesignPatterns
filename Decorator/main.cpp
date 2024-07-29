#include <QCoreApplication>
#include "concrete_component.h"
#include "concrete_decorator.h"
#include <iostream>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

/*

   装饰者模式（Decorator Pattern）是在不必改变原类文件和使用继承的情况下，动态地扩展一个对象的功能。它是通过创建一个包装对象，也就是装饰来包裹真实的对象。
       Component（抽象构件）：给出一个抽象接口，以规范准备接收附加责任的对象。
       ConcreteComponent（具体构件）：定义一个将要接收附加责任的类。
       Decorator（抽象装饰类）：持有一个构件（Component）对象的实例，并实现一个与抽象构件接口一致的接口。
       ConcreteDecorator（具体装饰类）：负责给构件对象添加上附加的责任。

   优点：
       1.Decorator 模式与继承关系的目的都是要扩展对象的功能，但是 Decorator 可以提供比继承更多的灵活性。
       2.通过使用不同的具体装饰类以及这些装饰类的排列组合，可以创造出很多不同行为的组合。

   缺点：
       1.这种比继承更加灵活机动的特性，也同时意味着更加多的复杂性。
       2.装饰模式会导致设计中出现许多小类，如果过度使用，会使程序变得很复杂。
       3.装饰模式是针对抽象构建（Component）类型编程。但是，如果要针对具体构件（ConcreteComponent）编程，
         应该重新思考应用架构，以及装饰者是否合适。当然也可改变 Component 接口，增加新的公开的行为，
         实现“半透明”的装饰者模式。在实际项目中要做出最佳选择。

   适用场景：
       1.需要扩展一个类的功能，或给一个类添加附加职责。
       2.需要动态的给一个对象添加功能，这些功能可以再动态的撤销。
       3.需要增加由一些基本功能的排列组合而产生的非常大量的功能，从而使继承关系变的不现实。
       4.当不能采用生成子类的方法进行扩充时。一种情况是，可能有大量独立的扩展，为支持每一种组合将产生大量的子类，
         使得子类数目呈爆炸性增长。另一种情况可能是因为类定义被隐藏，或类定义不能用于生成子类。

   案例分析：
       在星巴克购买咖啡时，可以要求在其中加入各种调味品（辅料）。调味品很多，有些不收费（例如：白砂糖、香草粉等），
       有些则需要额外收费（例如：奶油、摩卡、糖浆等），所以充分利用起来吧！倘若咖啡不带劲，我们想要添加奶油、摩卡和糖浆，
       这时，就可以利用装饰者模式思想来实现。

       简单理解就是买咖啡时添加辅料，辅料在代码里就可以理解为扩展，也就是保持原接口不变，对接口增加扩展

   大话设计模式知识点：
       Component是定义一个对象接口，可以给这些对象动态的添加职责，ConcreteComponent是定义了一个具体的对象，也可以给这个对象添加一些职责，
       Decorator装饰抽象类，继承了Component从外类来扩展Component类的功能，但对于Component来说，是无需知道Decorator的存在的，
       至于ConcreteDecorator就是具体的装饰对象，起到给Component添加职责的功能

       装饰模式是为已有功能动态的添加更多功能的一种方式，但什么时候使用呢？
       在初始的设计中，当系统需要增加新功能的时候，是向旧的类中添加新的代码，这些新加的代码通常装饰了原有类的核心职责或主要行为，
       但这种做法的问题在于，它们在主类中加入了新的字段，新的方法和新的逻辑，从而增加了主类的复杂度，而这些新加入的东西仅仅是为了
       满足一些只在某种特定情况下才会执行的特殊行为的需要，而装饰模式却提供了一个非常好的解决方案，它把每个要装饰的功能放在单独的类中
       并让这个类包装它所要装饰的对象，因此当需要执行特殊行为时，用户代码就可以在运行时根据需要有选择地、按顺序地使用装饰功能包装对象了

       装饰模式的优点总结下来就是，把类中的装饰功能从类中搬移去除，这样可以简化原有的类，更大的好处是，有效的把类的核心职责和装饰功能区分开了，
       而且可以去除相关类中重复的装饰逻辑，最理想的情况是保证装饰类之间彼此独立，这样它们就可以任意的顺序组合了
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /********** 黑咖啡 **********/
    IBeverage *pHouseBlend = new HouseBlend();
    cout << pHouseBlend->Name() << " : " << pHouseBlend->Cost() << endl;

    // 黑咖啡 + 奶牛，奶牛类中对黑咖啡进行扩展
    CondimentDecorator *pCream = new Cream(pHouseBlend);
    cout << pCream->Name() << " : " << pCream->Cost() << endl;

    // 黑咖啡 + 摩卡
    //在 Mocha 的构造函数中，myBeverage 传递给 CondimentDecorator 的构造函数，并存储在 m_pBeverage 成员中。
    //这样，Mocha 对象可以通过 m_pBeverage 访问基础 IBeverage 对象，并在其 Name() 和 Cost() 方法中进行扩展。
    CondimentDecorator *pMocha = new Mocha(pHouseBlend);
    cout << pMocha->Name() << " : " << pMocha->Cost() << endl;

    // 黑咖啡 + 糖浆
    CondimentDecorator *pSyrup = new Syrup(pHouseBlend);
    cout << pSyrup->Name() << " : " << pSyrup->Cost() << endl;

    /********** 深度烘培咖啡豆 **********/
    IBeverage *pDarkRoast = new DarkRoast();
    cout << pDarkRoast->Name() << " : " << pDarkRoast->Cost() << endl;

    // 深度烘培咖啡豆 + 奶油
    CondimentDecorator *pCreamDR = new Cream(pDarkRoast);
    cout << pCreamDR->Name() << " : " << pCreamDR->Cost() << endl;

    // 深度烘培咖啡豆 + 奶油 + 摩卡
    CondimentDecorator *pCreamMocha = new Mocha(pCreamDR);
    cout << pCreamMocha->Name() << " : " << pCreamMocha->Cost() << endl;

    // 深度烘培咖啡豆 + 奶油 + 摩卡 + 糖浆
    CondimentDecorator *pCreamMochaSyrup = new Syrup(pCreamMocha);
    cout << pCreamMochaSyrup->Name() << " : " << pCreamMochaSyrup->Cost() << endl;

    SAFE_DELETE(pSyrup);
    SAFE_DELETE(pMocha);
    SAFE_DELETE(pCream);
    SAFE_DELETE(pHouseBlend);

    SAFE_DELETE(pCreamMochaSyrup);
    SAFE_DELETE(pCreamMocha);
    SAFE_DELETE(pCreamDR);
    SAFE_DELETE(pDarkRoast);

    getchar();

    return 0;

    return a.exec();
}
