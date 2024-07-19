#include <QCoreApplication>
#include "factory.h"
#include "product.h"
#include <iostream>

using namespace std;

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

/*
  抽象工厂模式：（Abstract Factory Pattern）是所有形态的工厂模式中最为抽象和最具一般性的一种形态。抽象工厂模式是指当有多个抽象角色时，使用的一种工厂模式。
  抽象工厂模式可以向客户端提供一个接口，使客户端在不必指定产品的具体的情况下，创建多个产品族中的产品对象。

  优点：
       *封装了产品的创建，使得不需要知道具体是那种产品，只需要知道是那个工厂即可
       * 可以支持不同类型的产品，使得模式灵活性更强
       * 可以非常方便的使用一族中不同类型的产品

  缺点：
       *结构过于臃肿，如果产品类型较多或产品族较多，会非常难于管理
       *每次如果添加一组产品，那么所有的工厂类都必须添加一个方法，这样违背了开放-封闭原则。所以一般适用于产品组合产品族变化不大的情况。
  适用场景：在不必指定具体产品的情况下，创建多个产品族中的产品对象

   工厂方法模式要求产品必须为同一类型，也就是说，BBA 只能生产汽车，要生产其他产品（例如：自行车）是不行的，这显然限制了产品的扩展。
   为了解决这个问题，抽象工厂模式出现了 - 将产品归类分组，然后将好几组产品构成一族。每个工厂负责生产一族产品，而工厂中的每个方法负责生产一种类型的产品。
   这样，客户端只需要创建具体工厂的实例，然后调用工厂对象的工厂方法就可以得到所需要的产品对象--具体代码见factory 类

   一个程序员如果从来没有熬夜写程序的经历，不能算是一个好程序员，因为他没有痴迷过，所以他不会有大成就

 */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // 奔驰
    AFactory *pFactory = AFactory::CreateFactory(AFactory::FACTORY_TYPE::BENZ_FACTORY);
    ICar *pCar = pFactory->CreateCar();
    IBike *pBike = pFactory->CreateBike();

    cout << "Benz factory - Car: " << pCar->Name() << endl;
    cout << "Benz factory - Bike: " << pBike->Name() << endl;

    SAFE_DELETE(pCar);
    SAFE_DELETE(pBike);
    SAFE_DELETE(pFactory);

    // 宝马
    pFactory = AFactory::CreateFactory(AFactory::FACTORY_TYPE::BMW_FACTORY);
    pCar = pFactory->CreateCar();
    pBike = pFactory->CreateBike();
    cout << "Bmw factory - Car: " << pCar->Name() << endl;
    cout << "Bmw factory - Bike: " << pBike->Name() << endl;

    SAFE_DELETE(pCar);
    SAFE_DELETE(pBike);
    SAFE_DELETE(pFactory);

    // 奥迪
    pFactory = AFactory::CreateFactory(AFactory::FACTORY_TYPE::AUDI_FACTORY);
    pCar = pFactory->CreateCar();
    pBike = pFactory->CreateBike();
    cout << "Audi factory - Car: " << pCar->Name() << endl;
    cout << "Audi factory - Bike: " << pBike->Name() << endl;

    SAFE_DELETE(pCar);
    SAFE_DELETE(pBike);
    SAFE_DELETE(pFactory);

    getchar();

    return 0;

    return a.exec();
}
