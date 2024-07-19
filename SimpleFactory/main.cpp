#include <QCoreApplication>
#include "factory.h"
#include "product.h"
#include <iostream>

//用于安全地删除指针对象并将指针置为 nullptr。它的作用是防止重复删除和悬空指针（dangling pointer）的问题
#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=nullptr;} }
#endif

//多态满足条件：
//1、有继承关系
//2、子类重写父类中的虚函数
//多态使用：
//父类指针或引用指向子类对象

//学习简单工厂方法之前应提前了解动态多态的使用-即虚函数或纯虚函数的使用
//推荐博客：https://blog.csdn.net/amoscykl/article/details/85796850

//如果想通过父类指针删除子类对象时，应使用虚析构函数，
//析构函数一般定义成虚函数，原因：
//析构函数定义成虚函数是为了防止内存泄漏，因为当基类的指针或者引用指向或绑定到派生类的对
//象时，如果未将基类的析构函数定义成虚函数，会调用基类的析构函数，那么只能将基类的成员所
//占的空间释放掉，派生类中特有的就会无法释放内存空间导致内存泄漏。

//简单工厂模式最大的优点在于工厂类中包含了必要的逻辑判断，根据客户端的选择条件动态实例化相关的类
//对于客户端来说，去除了与具体产品的依赖--就以该例子来说，让客户端不用管那个类的实例，只需要把CAR_TYPE::BENZ
//枚举变量给工厂，工厂就自动给出了相应的实例，客户端只需要去生成汽车就好了，不同的实例生产不同品牌的汽车
//但问题也就在这里，如果要生产"比亚迪"的汽车，我们是一定要给汽车工厂类里添加'case'条件分支的，
//修改原有的类，这可不是好方法，这就等于说，我们不但对扩展开放了，对修改也开放了，这就违背了"开放-封闭"原则
//针对这个问题所以延伸出了另一种设计模式--工厂方法模式

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 工厂
    Factory *pFactory = new Factory();

    // 生产奔驰、宝马、奥迪
    ICar *pBenzCar = pFactory->CreateCar(CAR_TYPE::BENZ);
    ICar* pBmwCar = pFactory->CreateCar(CAR_TYPE::BMW);
    ICar* pAudiCar = pFactory->CreateCar(CAR_TYPE::AUDI);

    cout << pBenzCar->Name() << endl;
    cout << pBmwCar->Name() << endl;
    cout << pAudiCar->Name() << endl;

    SAFE_DELETE(pBenzCar);
    SAFE_DELETE(pBmwCar);
    SAFE_DELETE(pAudiCar);
    SAFE_DELETE(pFactory);

    getchar();

    return 0;
    return a.exec();
}
