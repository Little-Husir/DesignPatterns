#ifndef CONCRETE_VISITOR_H
#define CONCRETE_VISITOR_H

#include "visitor.h"
#include "concrete_element.h"

//具体访问者有两种 - 游客、清洁工，它们分别实现了不同的访问操作（游客只管吃喝玩乐，清洁工负责清理垃圾）

// 游客
class Tourist : public IVisitor
{
public:
	virtual void Visit(BellTower *) override {
		std::cout << "I'm visiting the Bell Tower!" << std::endl;
	}

	virtual void Visit(TerracottaWarriors *) override {
		std::cout << "I'm visiting the Terracotta Warriors!" << std::endl;
	}
};

// 清洁工
class Cleaner : public IVisitor
{
public:
	virtual void Visit(BellTower *) override {
		std::cout << "I'm cleaning up the garbage of Bell Tower!" << std::endl;
	}

	virtual void Visit(TerracottaWarriors *) override {
		std::cout << "I'm cleaning up the garbage of Terracotta Warriors!" << std::endl;
	}
};

#endif // CONCRETE_VISITOR_H
