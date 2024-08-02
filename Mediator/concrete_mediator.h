#ifndef CONCRETE_MEDIATOR_H
#define CONCRETE_MEDIATOR_H

#include "mediator.h"

// 具体中介者-具体中介者的职责是遍历所有的参与者，将发送者的消息通知到每一个人
class ConcreteMediator : public IMediator
{
public:
	// 将发送者的消息发送给所有参与者（但不包括发送者自己）
	virtual void distributeMessage(const IColleague* sender, const std::string& message) const override {
        for (const IColleague* c : getColleagues()) // 遍历所有的参与者
            if (c != sender)  // 添加限制，不要将消息发送给自己
                c->receiveMessage(sender, message);// 将消息发送给参与者
	}
};

#endif // CONCRETE_MEDIATOR_H
