#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#include "memento.h"
#include <iostream>
#include <string>

// һ��-Life ���ڴ��� DateTime���Լ�¼��ǰ������ʱ�䣬������ʹ�� DateTime ���лָ�
class Life
{
public:
	Life() {}
	~Life() {}

	void SetDateTime(std::string dt) {
		std::cout << "Set date time to " << dt << std::endl;
		m_dateTime = dt;
	}

	// �����ڴ�ӡ
	std::string GetDateTime() {
		return m_dateTime;
	}

    // �ָ�����ʱ��-�ָ�����¼
	void SetMemento(DateTime *dt) {
		if (nullptr != dt)
			m_dateTime = dt->GetDateTime();
	}

    // ��������ʱ��-��������¼
	DateTime *CreateMemento() {
		return new DateTime(m_dateTime);
	}

private:
	std::string m_dateTime;
};

#endif // ORIGINATOR_H
