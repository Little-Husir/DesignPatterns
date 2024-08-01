#ifndef COMMAND_H
#define COMMAND_H

class IReciever;

// 提供执行命令的接口
class Command
{
public:
    Command(IReciever *reciever);
    virtual int execute() = 0;  // 执行命令
protected:
    IReciever *m_pReciever;
};

// 加法
class AddCommand : public Command
{
public:
    AddCommand(IReciever *reciever);
    int execute();
};

// 减法
class SubtractCommand : public Command
{
public:
    SubtractCommand(IReciever *reciever);
    int execute();
};

// 乘法
class MultiplyCommand : public Command
{
public:
    MultiplyCommand(IReciever *reciever);
    int execute();
};

// 除法
class DivideCommand : public Command
{
public:
    DivideCommand(IReciever *reciever);
    int execute();
};

#endif // COMMAND_H
