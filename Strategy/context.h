#ifndef CONTEXT_H
#define CONTEXT_H

#include "strategy.h"

// ������
//������ɫ�����ṩ��һ�� Travel() �ӿڣ������ɿͻ��˵��á����ڲ��������յ��õ��� ITransport ����Ӧ����,����ά��һ����ITransport���������
class Tourists
{
public:
	Tourists(ITransport *transport) { 
		m_pTransport = transport;
	}

	void Travel() {
		if (nullptr != m_pTransport)
			m_pTransport->Run(); 
	}

private:
	ITransport *m_pTransport = nullptr;
};

#endif // CONTEXT_H
