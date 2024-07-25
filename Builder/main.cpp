#include <QCoreApplication>
#include "concrete_bulider.h"
#include "director.h"
#include <string>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

/*
  建造者模式：诣在将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示

    Builder（抽象建造者）：为创建一个产品对象的各个部件指定抽象接口。
    ConcreteBuilder（具体建造者）：实现 Builder 的接口以构造和装配该产品的各个部件，定义并明确它所创建的表示，并提供一个检索产品的接口。
    Director（指挥者）：构造一个使用 Builder 接口的对象。
    Product（产品）：表示被构造的复杂对象。ConcreteBuilder 创建该产品的内部表示并定义它的装配过程，包含定义组成部件的类，包括将这些部件装配成最终产品的接口。

  优点：                                缺点：
    建造者独立，易于扩展                    产品必须有共同点，范围有限制
    便于控制细节风险                       如果内部变化复杂，将会有很多的建造类

  适用场景：
    需要生成的对象有复杂的内部结构
    需要生成的对象内部属性本身相互依赖

  应用场景示例：
    联想旗下有众多系列的电脑，例如：ThinkPad 和 Yoga。。。在科技创新的大潮下，产品层出不穷。电脑虽多，但结构基本一致，
    都是由 CPU、主板、内存、显卡等组成。如果为每台电脑都单独设计一个组装流程，管理的成本太高。这时，建造者模式就出现了，
    为所有系列指定一个统一的组装流程，所有的电脑都按照这个流程来组装。
*/


//可以看出创建任何产品都非常干净
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Direcror *pDirecror = new Direcror();//创建指挥者
    ThinkPadBuilder *pTPBuilder = new ThinkPadBuilder();//创建具体产品
    YogaBuilder *pYogaBuilder = new YogaBuilder();

    // 组装 ThinkPad、Yoga
    pDirecror->Create(pTPBuilder);  //多态-IBuilder指向子类ThinkPadBuilder--传参也可以达到多态的效果
    pDirecror->Create(pYogaBuilder);

    // 获取组装后的电脑
    Computer *pThinkPadComputer = pTPBuilder->GetResult();
    Computer *pYogaComputer = pYogaBuilder->GetResult();

    // 测试输出
    cout << "-----ThinkPad-----" << endl;
    cout << "CPU: " << pThinkPadComputer->GetCPU() << endl;
    cout << "Mainboard: " << pThinkPadComputer->GetMainboard() << endl;
    cout << "Ram: " << pThinkPadComputer->GetRam() << endl;
    cout << "VideoCard: " << pThinkPadComputer->GetVideoCard() << endl;

    cout << "-----Yoga-----" << endl;
    cout << "CPU: " << pYogaComputer->GetCPU() << endl;
    cout << "Mainboard: " << pYogaComputer->GetMainboard() << endl;
    cout << "Ram: " << pYogaComputer->GetRam() << endl;
    cout << "VideoCard: " << pYogaComputer->GetVideoCard() << endl;

    SAFE_DELETE(pThinkPadComputer);
    SAFE_DELETE(pYogaComputer);
    SAFE_DELETE(pTPBuilder);
    SAFE_DELETE(pYogaBuilder);
    SAFE_DELETE(pDirecror);

    getchar();

    return 0;


    return a.exec();
}
