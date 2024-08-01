#include "command.h"
#include "reciever.h"

Command::Command(IReciever *reciever)
    : m_pReciever(reciever)
{

}

// 加法
AddCommand::AddCommand(IReciever *reciever)
    : Command(reciever)
{

}

int AddCommand::execute()
{
    m_pReciever->setAction(TYPES::ACTION::ADD);
    return m_pReciever->getResult();
}

// 减法
SubtractCommand::SubtractCommand(IReciever *reciever)
    : Command(reciever)
{

}

int SubtractCommand::execute()
{
    m_pReciever->setAction(TYPES::ACTION::SUBTRACT);
    return m_pReciever->getResult();
}

// 乘法
MultiplyCommand::MultiplyCommand(IReciever *reciever)
    : Command(reciever)
{

}

int MultiplyCommand::execute()
{
    m_pReciever->setAction(TYPES::ACTION::MULTIPLY);
    return m_pReciever->getResult();
}

// 除法
DivideCommand::DivideCommand(IReciever *reciever)
    : Command(reciever)
{

}

int DivideCommand::execute()
{
    m_pReciever->setAction(TYPES::ACTION::DIVIDE);
    return m_pReciever->getResult();
}
