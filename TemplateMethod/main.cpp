﻿#include <QCoreApplication>
#include "concrete_class.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

/*
     模版方法模式（Template Method Pattern）定义一个操作中算法的骨架，而将一些步骤延迟到子类中。模板方法使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。
         抽象类（AbstractClass）：定义抽象的原语操作，具体的子类将重定义它们以实现一个算法的各步骤。主要是实现一个模板方法，定义一个算法的骨架。该模板方法不仅调用原语操作
                                也调用定义在 AbstractClass 或其他对象中的操作。
         具体类（ConcreteClass）：实现原语操作以完成算法中与特定子类相关的步骤。

     优点：
         1.在父类中形式化地定义一个算法，而由其子类实现细节的处理，在子类实现详细的处理算法时并不会改变算法中步骤的执行次序。
         2.模板方法模式是一种代码复用技术，在类库设计中尤为重要，它提取了类库中的公共行为，将公共行为放在父类中，而通过其子类来实现不同的行为，它鼓励我们恰当使用继承来实现代码复用。
         3.可实现一种反向控制结构，通过子类覆盖父类的钩子方法来决定某一特定步骤是否需要执行。
         4.在模板方法模式中，可以通过子类来覆盖父类的基本方法，不同的子类可以提供基本方法的不同实现，更换和增加新的子类很方便，符合单一职责原则和开闭原则。

     缺点：
         1.需要为每一个基本方法的不同实现提供一个子类，如果父类中可变的基本方法太多，将会导致类的个数增加，系统更加庞大，设计也更加抽象，此时，可结合桥接模式来进行设计。

     适用场景：
         1.对一些复杂的算法进行分割，将算法中固定不变的部分设计为模板方法和父类具体方法，而一些可变的细节由子类实现。
         2.各子类中公共的行为应被提取出来并集中到一个公共父类中，以避免代码重复。
         3.需要通过子类来决定父类算法中某个步骤是否执行，实现子类对父类的反向控制。

     案例分析：
         无论什么公司，在校招时一般都会采用“宣讲会 -&gt; 接收简历 -&gt; 面试 -&gt; 发放 Offer”这样一套固定流程。其中，各公司宣讲会（宣传企业文化、福利待遇）和接收简历（自带简历）的形式几乎是一样的
         不同的是面试和发放 Offer 环节。阿里需要经过一面、二面、三面，并提供30W/年的薪酬；而腾讯则需要一面、二面，并提供25W/年的薪酬。

         这里，公司是抽象类，“宣讲会 ->接收简历 ->面试 ->发放 Offer”则是一套固定的模板方法（招聘流程）。具体类由阿里和腾讯表示，不同之处在于面试和发放 Offer 环节，需要它们分别实现。

     模板方法特点：
        模板方法模式是通过把不变行为搬移到超类，去除子类中的重复代码来体现它的优势。模板方法模式就是提供了一个很好的代码复用平台。因为有时候，我们会遇到由一系列步骤构成的过程需要执行。
        这个过程从高层次上看是相同的，但有些步骤的实现可能不同。这时候，我们通常就应该要考虑用模板方法模式了。也就是说，碰到这个情况，当不变的和可变的行为在方法的子类实现中混合在一起的时候，
        不变的行为就会在子类中重复出现。我们通过模板方法模式把这些行为搬移到单一的地方，这样就帮助子类摆脱重复的不变行为的纠缠。
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 阿里校招
    Company *alibaba = new Alibaba();
    alibaba->Recruit();

    // 腾讯校招
    Company *tencent = new Tencent();
    tencent->Recruit();

    SAFE_DELETE(tencent);
    SAFE_DELETE(alibaba);

    getchar();

    return 0;


    return a.exec();
}
