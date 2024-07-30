#ifndef PROXY_H
#define PROXY_H

#include "subject.h"
#include "real_subject.h"
#include <iostream>

//注意： 代理类也是抽象主题类的子类，调用时可以在原有业务方法的基础上附加一些新的方法，来对功能进行扩充或约束。
// 代理点
class Proxy : public ITelco
{
public:
	Proxy() : m_pCMCC(NULL) {}
	~Proxy() { delete m_pCMCC; }

	// 低于 50 不充
	void Recharge(int money) override {
		if (money >= 50) {
			if (m_pCMCC == NULL)
				m_pCMCC = new CMCC();
			m_pCMCC->Recharge(money);
		}
		else {
			std::cout << "Sorry, too little money" << std::endl;
		}
	}

private:
	CMCC *m_pCMCC;
};

#endif // PROXY_H
