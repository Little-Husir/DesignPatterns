#include <QCoreApplication>
#include "singleton.h"
#include <iostream>

using namespace std;
//在程序运行结束时，系统会调用Singleton的静态成员GC的析构函数，该析构函数会进行资源的释放
//这种方式最大的优点就是在不知不觉中对资源进行释放，使用起来尤为方便

//程序生命周期：单例实例的生命周期通常与程序的生命周期相同。一旦程序结束，所有分配的内存（包括单例实例）都会被操作系统回收。
Singleton::GC Singleton::GC::gc; // 重要
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //Singleton single = Singleton::GetInstance();

       //Singleton *pSingleton1 = Singleton::GetInstance();
       //Singleton *pSingleton2 = Singleton::GetInstance();

       //cout << (pSingleton1 == pSingleton2) << endl;

       //Singleton::GetInstance().doSomething();  // OK
       //Singleton single = Singleton::GetInstance();  // Error 不能编译通过

       Singleton::GetInstance();
       //Singleton::GetInstance()->DestoryInstance();  // 手动释放

       return 0;//代表程序运行结束，单例类的资源进行回收，GC类的析构函数对单例类的资源回收进行处理

    return a.exec();
}
