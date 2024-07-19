#include <QCoreApplication>
#include "concrete_factory.h"
#include "product.h"
#include <iostream>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif
/*
 工厂方法模式设计前导条件，工厂方法模式里这两个原则都有体现

    依赖倒转/依赖倒置原则：抽象不应该依赖细节，细节应该依赖于抽象即要针对接口编程，不要对实现编程

    *高层模块不应该依赖于低层模块。两个都应该依赖于抽象
    * 抽象不应该依赖于细节，细节应该依赖于抽象--即软件应该以接口开发为主

    说起依赖倒置原则这就要提到另一个原则了---里氏代换原则：即子类型必须必须能够替换掉它们的父类型
        *正是因为有了这个原则，使得继承复用成为了可能，只有当子类可以替换掉父类，软件单位的功能不受到影响时
         父类才能真正被复用，而子类也能够在父类的基础上增加新的行为

        *正是由于子类型的可替换性才使得使用父类类型的模块在无需修改的情况下就可以扩展，不然还谈什么扩展开放，修改关闭呢

     总结：依赖倒置其实可以说是面向对象设计的标志，如果编写时考虑的都是如何针对抽象编程，而不是针对细节编程
          即程序中所有的依赖关系都是终止于抽象类或者接口，那就是面向对象的设计，反之那就是过程化的设计了


工厂方法模式：（Factory Method Pattern）是一种常用的对象创建型设计模式，此模式的核心思想是封装类中不变的部分，
提取其中个性化善变的部分为独立类，通过依赖注入以达到解耦、复用以及方便后期维护拓展的目的。

Factory（抽象工厂）：是工厂方法模式的核心，与应用程序无关。任何在模式中创建的对象的工厂类必须实现这个接口。
ConcreteFactory（具体工厂）：实现抽象工厂接口的具体工厂类，包含与应用程序密切相关的逻辑，并且被应用程序调用以创建产品对象。
Product（抽象产品）：所创建对象的基类，也就是具体产品的共同父类或共同拥有的接口。
ConcreteProduct（具体产品）：实现了抽象产品角色所定义的接口。某具体产品有专门的具体工厂创建，它们之间往往一一对应。

优点：
    克服了简单工厂模式违背开放-封闭原则的缺点，又保留了封装对象创建过程的优点，降低客户端和工厂的耦合性。
    所以说，“工厂方法模式”是“简单工厂模式”的进一步抽象和推广。
缺点：
    每增加一个产品，相应的也要增加一个子工厂，加大了额外的开发量。

*/

//客户端的实现
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 奔驰
    AFactory *pFactory = new BenzFactory();//AFactory：父类指针指向子类对象--多态
    ICar *pCar = pFactory->CreateCar();//调用奔驰工厂的CreateCar()，返回一个奔驰汽车产品，ICar：父类指针指向子类对象再次多态
    cout << "Benz factory: " << pCar->Name() << endl;//pCar 多态调用BenzCar()类重载的Name()成员方法

    SAFE_DELETE(pCar);
    SAFE_DELETE(pFactory);

    // 宝马
    pFactory = new BmwFactory();
    pCar = pFactory->CreateCar();
    cout << "Bmw factory: " << pCar->Name() << endl;

    SAFE_DELETE(pCar);
    SAFE_DELETE(pFactory);

    // 奥迪
    pFactory = new AudiFactory();
    pCar = pFactory->CreateCar();
    cout << "Audi factory: " << pCar->Name() << endl;

    SAFE_DELETE(pCar);
    SAFE_DELETE(pFactory);

    getchar();

    return 0;//结束程序

    return a.exec();
}
