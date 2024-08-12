#include <QCoreApplication>
#include "concrete_visitor.h"
#include "object_structure.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

/*
   访问者模式 （Visitor Pattern）表示一个作用于某对象结构中的各元素的操作，它使你可以在不改变各元素类的前提下定义作用于这些元素的新操作。
       Vistor（访问者）：为对象结构中每一个 ConcreteElement 声明一个 visit() 操作，从这个操作的名称或参数类型可以清楚知道需要访问的具体元素的类型。
       ConcreteVisitor（具体访问者）：实现每个由 Visitor 声明的操作。
       Element（元素）：定义一个 accept() 操作，它通常以一个 Vistor 作为参数。
       ConcreteElement（具体元素）：实现 accept() 操作，通过调用 Visitor 的 visit() 方法来实现对元素的访问。
       ObjectStructure（对象结构）：能够枚举它的元素，同时提供一个高层的接口，以允许访问者访问它的元素。

   优点：
       1.增加新的访问操作很方便。使用访问者模式，增加新的访问操作就意味着增加一个新的具体访问者类，实现简单，无须修改源代码，符合“开闭原则”。
       2.将有关元素对象的访问行为集中到一个访问者对象中，而不是分散在一个个的元素类中。类的职责更加清晰，有利于对象结构中元素对象的复用，相同的对象结构可以供多个不同的访问者访问。
       3.让用户能够在不修改现有元素类层次结构的情况下，定义作用于该层次结构的操作。
   缺点：
       1.增加新的元素类困难。每增加一个新的元素类都意味着要在访问者中增加一个新的操作，并在每一个具体访问者类中增加相应的具体操作，这违背了“开闭原则”的要求。
       2.破坏封装。访问者模式要求访问者对象访问并调用每一个元素对象的操作，这意味着元素对象有时候必须暴露一些自己的内部操作和内部状态，否则无法供访问者访问。

   适用场景：
       1.一个对象结构包含多个类型的对象，希望对这些对象实施一些依赖其具体类型的操作。在访问者中针对每一种具体的类型都提供了一个访问操作，不同类型的对象可以有不同的访问操作。
       2.需要对一个对象结构中的对象进行很多不同的并且不相关的操作，而需要避免让这些操作“污染”这些对象的类，也不希望在增加新操作时修改这些类。
         访问者模式使得我们可以将相关的访问操作集中起来定义在访问者类中，对象结构可以被多个不同的访问者类所使用，将对象本身与对象的访问操作分离。
       3.对象结构中对象对应的类很少改变，但经常需要在此对象结构上定义新的操作。

   案例分析：
       在访问西安时，访问者会参观各个景点。对于景点来说，无论访问者是谁，它们都是不变的。而作为访问者，不同角色的访问方式也不尽相同，
       游客只负责旅游 - 吃喝玩乐，而清洁工则需要打扫卫生、清理垃圾。

       这里，游客和清洁工是具体访问者，兵马俑、钟楼等景点是具体元素，西安这座城市是结构对象。

   大话设计模式：
       访问者模式的目的是要把处理从数据结构分离出来。很多系统可以按照算法和数据结构分开，如果这样的系统有比较稳定的数据结构，又有易于变化的算法的话，使用访问者模式就是比较合适的
       因为访问者模式使得算法操作的增加变得容易。反之，如果这样的系统的数据结构对象易于变化，经常要有新的数据对象增加进来，就不适合使用访问者模式。
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    City *city = new City();

    // 景点 - 钟楼、兵马俑
    IPlace *bellTower = new BellTower();
    IPlace *warriors = new TerracottaWarriors();

    // 访问者 - 游客、清洁工
    IVisitor *tourist = new Tourist();
    IVisitor *cleaner = new Cleaner();

    // 添加景点
    city->Attach(bellTower);
    city->Attach(warriors);

    // 接受访问
    city->Accept(tourist);
    city->Accept(cleaner);

    SAFE_DELETE(cleaner);
    SAFE_DELETE(tourist);
    SAFE_DELETE(warriors);
    SAFE_DELETE(bellTower);
    SAFE_DELETE(city);

    getchar();

    return 0;


    return a.exec();
}
