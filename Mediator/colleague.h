#pragma once

#include "mediator.h"
#include <string>

class IMediator;

// 抽象同事类-由于房东和租客均由同事类表示，所以既需要（房东）发送消息，又需要（租客）接收消息
class IColleague
{
public:
	IColleague(const std::string& name) : m_strName(name) {}
	std::string getName() const { return m_strName; }

	// 通过中介者，将自己的消息发布出去
	virtual void sendMessage(const IMediator& mediator, const std::string& message) const = 0;
	// 接收来自发送者的消息
	virtual void receiveMessage(const IColleague* sender, const std::string& message) const = 0;

private:
	std::string m_strName;
};
