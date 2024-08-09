#ifndef HANDLER_H
#define HANDLER_H

#include <iostream>

// ��������
//�������߳����ṩһ��������ٵĽӿ�֮�⣬����һ���ܹؼ��ĵط����Ƕ������ߣ���������Թ���һ����
class IHandler
{
public:
	virtual ~IHandler() {}
	void SetSuccessor(IHandler *successor) { 
		m_pSuccessor = successor;
	}
	virtual void HandleRequest(int days) = 0;

protected:
	IHandler *m_pSuccessor = nullptr;  // �����
};

#endif // HANDLER_H
