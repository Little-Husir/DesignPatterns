#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#include "memento.h"
#include <iostream>
#include <string>

// 一生-Life 用于创建 DateTime，以记录当前的日期时间，并可以使用 DateTime 进行恢复
class Life
{
public:
	Life() {}
	~Life() {}

	void SetDateTime(std::string dt) {
		std::cout << "Set date time to " << dt << std::endl;
		m_dateTime = dt;
	}

	// 仅用于打印
	std::string GetDateTime() {
		return m_dateTime;
	}

    // 恢复日期时间-恢复备忘录
	void SetMemento(DateTime *dt) {
		if (nullptr != dt)
			m_dateTime = dt->GetDateTime();
	}

    // 创建日期时间-创建备忘录
	DateTime *CreateMemento() {
		return new DateTime(m_dateTime);
	}

private:
	std::string m_dateTime;
};

#endif // ORIGINATOR_H
