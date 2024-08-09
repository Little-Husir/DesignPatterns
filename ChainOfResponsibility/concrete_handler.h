#ifndef CONCRETE_HANDLER_H
#define CONCRETE_HANDLER_H

#include "handler.h"

//���崦���߰��� Manager��Director��CEO�����ǵ�ʵ�ֻ�����ͬ��ֻ����׼��������һ��

// ����
class Manager : public IHandler
{
public:
	void HandleRequest(int days) override {
		if (days <= 1) {
			std::cout << "Manager ��׼�� " << days << " ���" << std::endl;
		} else {
			if (nullptr != m_pSuccessor)
				m_pSuccessor->HandleRequest(days);
		}
	}
};

// �ܼ�
class Director : public IHandler
{
public:
	void HandleRequest(int days) override {
		if (days <= 3) {
			std::cout << "Director ��׼�� " << days << " ���" << std::endl;
		} else {
			if (nullptr != m_pSuccessor)
				m_pSuccessor->HandleRequest(days);
		}
	}
};

// �ܲ�-ע�⣺ ���� CEO λ����߲㣨��������ĩβ�����������󵽴˽���������������´��ݡ�
class CEO : public IHandler
{
public:
	void HandleRequest(int days) override {
		if (days <= 7) {
			std::cout << "CEO ��׼�� " << days << " ���" << std::endl;
		} else {
			std::cout << "����ų��٣��Ժ������ϰ�����" << std::endl;
		}
	}
};

#endif // CONCRETE_HANDLER_H
