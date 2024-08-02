#pragma once

#include "colleague.h"
#include <list>

class IColleague;

// 抽象中介者-由于中介需要和所有参与者打交道，所以它除了注册参与者之外，还需要将发送者的消息传递出去
class IMediator
{
public:
	// 注册参与者
	virtual void registerColleague(IColleague* colleague) { m_colleagues.emplace_back(colleague); }
	const std::list<IColleague*>& getColleagues() const { return m_colleagues; }

	// 将发送者的消息发送给所有参与者
	virtual void distributeMessage(const IColleague* sender, const std::string& message) const = 0;

private:
	std::list<IColleague*> m_colleagues;
};
