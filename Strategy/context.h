#ifndef CONTEXT_H
#define CONTEXT_H

#include "strategy.h"

// 旅行者
//环境角色对外提供了一个 Travel() 接口，最终由客户端调用。在内部，它最终调用的是 ITransport 的相应方法,用来维护一个对ITransport对象的引用
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
