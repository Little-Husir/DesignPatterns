#pragma once

#include "colleague.h"
#include <list>

class IColleague;

// �����н���-�����н���Ҫ�����в����ߴ򽻵�������������ע�������֮�⣬����Ҫ�������ߵ���Ϣ���ݳ�ȥ
class IMediator
{
public:
	// ע�������
	virtual void registerColleague(IColleague* colleague) { m_colleagues.emplace_back(colleague); }
	const std::list<IColleague*>& getColleagues() const { return m_colleagues; }

	// �������ߵ���Ϣ���͸����в�����
	virtual void distributeMessage(const IColleague* sender, const std::string& message) const = 0;

private:
	std::list<IColleague*> m_colleagues;
};
