#include <QCoreApplication>
#include "concrete_prototype.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete p; p=nullptr;} }
#endif

/*

   原型模式（Prototype Pattern）是一种创建型设计模式，允许一个对象再创建另外一个可定制的对象，而无需知道任何创建的细节。
       Prototype（抽象原型）：定义了克隆自身的接口。
       ConcretePrototype（具体原型）：被复制的对象，需要实现 Prototype 定义的接口。

   优点：
       1.如果创建新的对象比较复杂，可以利用原型模式简化对象的创建过程，同时也能够提高效率
       2.简化对象的创建，无需理会创建过程
       3.可以在程序运行时（对象属性发生了变化）获得一份内容相同的实例，他们之间不会相互干扰

   缺点：
       1.在实现深拷贝时可能需要比较复杂的代码（*理解深拷贝与浅拷贝）
       2.需要为每一个类配备一个克隆方法，而且该克隆方法需要对类的功能进行通盘考虑，这对全新的类来说不是很难，
       但对已有的类进行改造时，不一定是件容易的事，必须修改其源代码，违背了“开闭原则”。

   适用场景：
       1.如果创建新对象成本较大，可以利用已有的对象进行复制来获得
       2.如果系统要保存对象的状态，而对象的状态变化很小，或者对象本身占内存不大的时候，也可以使用原型模式配合备忘录模式来应用。
         相反，如果对象的状态变化很大，或者对象占用的内存很大，那么采用状态模式会比原型模式更好。
       3.需要避免使用分层次的工厂类来创建分层次的对象，并且类的实例对象只有一个或很少的几个组合状态，
         通过复制原型对象得到新实例可能比使用构造函数创建一个新实例更加方便。
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 孙悟空
    Monkey *swk = new SunWuKong("Qi Tian Da Sheng");

    // 克隆猴子猴孙
    Monkey *swk1 = swk->Clone();    //只需要调用clone方法就可以实现新猴子的生成，如果猴子类里提供setxxx方法则可以修改新猴子的细节
    Monkey *swk2 = swk1->Clone();   //即不用重新初始化对象，而是动态的获得对象运行时的状态，从而获得一个新的猴子实例

    swk1->Play();
    swk2->Play();

    SAFE_DELETE(swk2);
    SAFE_DELETE(swk1);
    SAFE_DELETE(swk);

    getchar();

    return 0;


    return a.exec();
}
