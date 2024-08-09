#ifndef HANDLER_H
#define HANDLER_H

#include <iostream>

// 抽象处理者
//抽象处理者除了提供一个处理请假的接口之外，还有一个很关键的地方就是定义后继者，这样便可以构建一条链
class IHandler
{
public:
	virtual ~IHandler() {}
	void SetSuccessor(IHandler *successor) { 
		m_pSuccessor = successor;
	}
	virtual void HandleRequest(int days) = 0;

protected:
	IHandler *m_pSuccessor = nullptr;  // 后继者
};

#endif // HANDLER_H
