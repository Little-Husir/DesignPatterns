#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>
#include <string>

//��Խ��ĳһʱ�̣����ʱ��ָ���������ʱ�䣬�� DateTime ��ʾ����Ϊ���ṩ��Ӧ�� setter �� getter ����
// ����ʱ��-��Ҫ����¼���࣬������ʱ��

//����ʱ���ǽ�Ҫ�����ϸ�ڸ���װ��memento����¼���У���һ��Ҫ���ı����ϸ��Ҳ��Ӱ��ͻ�����--����Ŀ��˵���԰�������ҳ���滻���Ĳ������߲������ݵȱ����������Ա��´�ʹ����ʾ
class DateTime
{
public:
	DateTime(std::string dt) : m_dateTime(dt) {}
	~DateTime() {}

	void SetDateTime(std::string dt) {
		m_dateTime = dt;
	}

	std::string GetDateTime() {
		return m_dateTime;
	}

private:
	std::string m_dateTime;
};

#endif // MEMENTO_H
