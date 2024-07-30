#ifndef ABSTRACT_CLASS_H
#define ABSTRACT_CLASS_H

#include <iostream>
//创建抽象类-抽象类由 Company 表示，它提供了一套固定的模板方法 Recruit()，用于标准化算法的骨架：
// 注意： 相同的行为 CareerTalk() 和 ReceiveResume() 有默认实现，不同的行为 Interview() 和 Offer() 采用“占位符”方式，需要由具体公司来实现。
class Company
{
public:
	virtual ~Company() {}

	// 校园招聘
	void Recruit() {
		std::cout << "---------- Begin ----------" << std::endl;
		CareerTalk();
		ReceiveResume();
		Interview();
		Offer();
		std::cout << "---------- End ----------" << std::endl;
	}

	// 宣讲会
	void CareerTalk() {
		std::cout << "Delivery" << std::endl;
	}

	// 接收简历
	void ReceiveResume() {
		std::cout << "Receive Resume" << std::endl;
	}

	// 面试
	virtual void Interview() = 0;

	// 发放 Offer
	virtual void Offer() = 0;
};

#endif // ABSTRACT_CLASS_H
