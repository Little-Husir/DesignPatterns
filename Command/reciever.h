#ifndef RECIEVER_H
#define RECIEVER_H

namespace TYPES
{
    enum ACTION
    {
        ADD,  // 加法
        SUBTRACT,  // 减法
        MULTIPLY,  // 乘法
        DIVIDE   // 除法
    };
}

// 命令接收者
class IReciever
{
public:
    virtual void setAction(TYPES::ACTION action) = 0;  // 设置具体命令
    virtual int getResult() = 0;  // 获取命令结果
};

// 命令接收者具体实现
class Calculator : public IReciever
{
public:
    Calculator(int x, int y);
    void setAction(TYPES::ACTION action);
    int getResult();

private:
    int m_nX;
    int m_nY;
    TYPES::ACTION m_currentAction;
};

#endif // RECIEVER_H
