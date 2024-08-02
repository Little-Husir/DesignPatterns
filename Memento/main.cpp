#include <QCoreApplication>
#include "originator.h"
#include "care_taker.h"
#include <time.h>
#include <sstream>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif


/*
   备忘录模式（Memento Pattern）在不破坏封装的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，这样可以在以后将对象恢复到原先保存的状态。
      Originator（发起人）：负责创建一个 Memento，以记录当前时刻自身的内部状态，并可以使用 Memento 恢复内部状态。Originator 可以根据需要决定 Memento 储存自己的哪些内部状态。
      Memento（备忘录）：负责存储 Originator 对象的内部状态，并可以防止 Originator 以外的其他对象访问备忘录。
      Caretaker（管理者）：负责管理 Memento，但不能对 Memento 的内容进行访问或者操作。

   优点：
      1.提供了一种状态恢复机制，使用户能够方便的回到某个历史的状态  2.实现了信息的封装，使得用户不需要关心状态的保存细节
   缺点：
      如果 Originator 对象很大，那么 Memento 对象也会很大，这势必会占用较大的存储空间，而且每保存一次都需要消耗一定的系统资源。

   适用场景：
      保存一个对象在某一个时刻的全部（或部分）状态，这样在以后需要时便能够恢复到先前的状态，实现撤销操作。
      防止外界对象破坏一个对象历史状态的封装性，避免将对象历史状态的实现细节暴露给外界对象。

   案例分析：
      月光宝盒-让时光倒流
      和“月光宝盒”一样，备忘录模式也提供了时光倒流的机制，将一个对象某个时刻的状态进行备份，当用户后悔（需要返回之前的状态）时，可以把备份调用出来！

   大话设计模式笔记：
      Memento 模式比较适用于功能比较复杂的，但需要维护或记录属性历史的类，或者需要保存的属性只是众多属性中的一小部分时，
      Originator 可以根据保存的 Memento 信息还原到前一状态。

      如果在某个系统中使用命令模式时，需要实现命令的撤销功能，那么命令模式可以使用备忘录模式来存储可撤销操作的状态。有时一些对象的内部信息必须保存在对象以外的地方，
      但是必须要由对象自己读取，这时，使用备忘录可以把复杂的对象内部信息对其他的对象屏蔽起来，从而可以恰当地保持封装的边界。

*/


//简单来说就是保存一个类的状态，以便后续恢复到之前保存的那个状态
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    srand((unsigned)time(0));

    Life *life = new Life();
    PandoraBox *box = new PandoraBox(life);

    // 设置并保存一些历史时间
    for (int i = 0; i < 5; i++) {
        std::ostringstream buffer;
        buffer << "200" << i << "/10/01 00:00:00";
        std::string dt = buffer.str();

        life->SetDateTime(dt);
        box->Save();
    }

    // 穿越多次
    for (int i = 0; i < 2; i++) {
        box->Undo();
        std::cout << "Current date time is " << life->GetDateTime() << std::endl;
    }

    SAFE_DELETE(life);
    SAFE_DELETE(box);

    getchar();

    return 0;


    return a.exec();
}
