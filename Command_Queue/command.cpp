#include "command.h"
#include "reciever.h"
#include <iostream>

Command::Command(Reciever *reciever)
    : m_pReciever(reciever)
{

}

// 打车
TakeCommand::TakeCommand(Reciever *reciever)
    : Command(reciever)
{

}

void TakeCommand::execute()
{
    std::cout << "Take command..." << std::endl;
    m_pReciever->takeOrder();
}

// 付款
PayCommand::PayCommand(Reciever *reciever)
    : Command(reciever)
{

}

void PayCommand::execute()
{
    std::cout << "Pay command..." << std::endl;
    m_pReciever->receipt();
}
