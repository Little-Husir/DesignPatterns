#include <QCoreApplication>
#include "invoker.h"
#include "reciever.h"
#include "command.h"

/*
    根据命令模式，实现一个命令队列，形成一个命令链。
    以打车为例，又是滴滴，用户发起一个“打车”命令，司机接单，到达终点时，用户再次发起一个“付款”命令，司机收款。
    和上述示例类似， Command 是一个抽象类，将被用作执行命令的接口。其他的 ConcreteCommand 类派生自它，提供了具体的命令（打车/付款）。

    开始，我们创建了两个命令（打车 &amp; 付款），通过 Invoker 的 addCmd() 将他们加入至命令队列，然后 notify() 通知执行命令，这样，就形成了一个命令链。

    兴趣点：
       要降低发送者和接收者之间的耦合度，命令模式是一种非常好的方式。在实现命令模式时，要记住，最重要的事情是：命令只是发送者和接收者之间的链接。
       它应该只告诉接收者发送者期望的是什么，而不应该以任何方式改变发送者和接收者的逻辑。
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Reciever *rev = new Reciever();
    Command *cmd1 = new TakeCommand(rev);
    PayCommand *cmd2 = new PayCommand(rev);
    Invoker inv;

    inv.addCmd(cmd1);
    inv.addCmd(cmd2);
    inv.notify();

    delete cmd1;
    delete cmd2;
    delete rev;

    return 0;

    return a.exec();
}
