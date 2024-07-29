#include <QCoreApplication>
#include "composite.h"
#include "leaf.h"

/*
     组合模式（Composite Pattern）组合多个对象形成树形结构以表示具有“整体-部分”关系的层次结构。
     组合模式对单个对象（即：叶子构件）和组合对象（即：容器构件）的使用具有一致性，组合模式又被称为“整体-部分”（Part-Whole）模式，属于对象结构型模式。

     1.Component（抽象构件）：为叶子构件和容器构件对象定义接口，可以包含所有子类共有行为的声明和实现。
     在抽象构件中，声明了访问及管理子构件的接口（例如：Add()、Remove()、GetChild() 等）。
     2.Leaf（叶子构件）：叶子节点没有子节点。它实现了 Component 中定义的行为，对于访问及管理子构件的接口，可以通过异常等方式进行处理。
     3.Composite（容器构件）：容器节点包含子节点（可以是叶子构件，也可以是容器构件）。它提供了一个集合用于存储子节点，实现了 Component 中定义的行为，
     包括访问及管理子构件的接口，在其业务方法中可以递归调用其子节点的业务方法。

     组合模式又分为透明组合模式和安全组合模式
       透明组合模式特点：
         1.在 Component 中定义了用于访问和管理子构建的接口，这样做的好处是确保所有的构件类都有相同的接口。
         2.在 Client 看来，Leaf 与 Composite 所提供的接口一致，Client 可以相同地对待所有的对象。
       安全组合模式特点：
         1.在 Component 中不定义任何用于访问和管理子构建的接口，而在 Composite 中声明并实现。
         2.这种做法是安全的，因为不需要向 Leaf 提供这些管理成员对象的接口，对于 Leaf 来说，Client 不可能调用到这些接口。

     透明组合模式的缺点是不够安全，因为 Leaf 和 Composite 在本质上是有区别的。Leaf 不可能有下一个层级，
     因此为其提供 Add()、Remove()、GetChild() 等接口没有意义。这在编译阶段不会出错，但在运行阶段如果调用这些接口可能会出错（如果没有提供相应的异常处理）。

     安全组合模式的缺点是不够透明，因为 Leaf 和 Composite 具有不同的接口，且 Composite 中那些用于访问和管理子构建的接口没有在 Component 中定义，
     因此 Client 不能完全针对抽象编程，必须有区别地对待 Leaf 和 Composite。

     透明组合模式是组合模式的标准形式，但在实际应用中，安全组合模式的使用频率也非常高。

     优点：
        1.组合模式可以清楚地定义分层次的复杂对象，表示对象的全部或部分层次，它让 Client 忽略了层次的差异，方便对整个层次结构进行控制。
        2.Client 可以一致地使用一个组合结构或其中单个对象，不必关心处理的是单个对象还是整个组合结构，简化了 Client 的代码。
        3.在组合模式中，增加新的叶子构件和容器构件很方便，无须对现有类进行任何修改，符合“开闭原则”。
        4.为树形结构提供了一种灵活的解决方案，通过递归组合容器对象和叶子对象，可以形成复杂的树形结构，但对树形结构的控制却非常简单。

     缺点：
        1.使设计变得更加抽象，对象的业务规则如果很复杂，则实现组合模式具有很大挑战性，而且不是所有的方法都与叶子对象子类都有关联。

     适用场景：
        1.表示对象的“整体-部分”层次结构（树形结构）
        2.希望用户忽略组合对象与单个对象的不同，统一地使用组合结构中的所有对象。
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 创建一个树形结构
    // 创建根节点
    Component *pRoot = new Composite("江湖公司（任我行）");

    // 创建分支
    Component *pDepart1 = new Composite("日月神教（东方不败）");
    pDepart1->Add(new Leaf("光明左使（向问天）"));
    pDepart1->Add(new Leaf("光明右使（曲洋）"));
    pRoot->Add(pDepart1);

    Component *pDepart2 = new Composite("五岳剑派（左冷蝉）");
    pDepart2->Add(new Leaf("嵩山（左冷蝉）"));
    pDepart2->Add(new Leaf("衡山（莫大）"));
    pDepart2->Add(new Leaf("华山（岳不群）"));
    pDepart2->Add(new Leaf("泰山（天门道长）"));
    pDepart2->Add(new Leaf("恒山（定闲师太）"));
    pRoot->Add(pDepart2);

    // 添加和删除叶子
    pRoot->Add(new Leaf("少林（方证大师）"));
    pRoot->Add(new Leaf("武当（冲虚道长）"));
    Component *pLeaf = new Leaf("青城（余沧海）");
    pRoot->Add(pLeaf);

    // 小丑，直接裁掉
    pRoot->Remove(pLeaf);

    // 递归地显示组织架构
    pRoot->Operation(1);

    // 删除分配的内存
    SAFE_DELETE(pRoot);

    getchar();

    return 0;


    return a.exec();
}
