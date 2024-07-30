#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <iostream>
#include <string>

//创建抽象享元类：在享元类中，要将内部状态和外部状态分开处理。通常将内部状态作为享元类的成员变量，而外部状态通过注入的方式添加到享元类中

// 玩家 - 有武器和使命
class IPlayer
{
public:
	virtual ~IPlayer() {}

	// 分配武器
	virtual void assignWeapon(std::string weapon) = 0;

	// 使命
	virtual void mission() = 0;

protected:
    std::string m_task; // 内部状态-不会随环境改变而改变的共享部分
    std::string m_weapon; // 外部状态-随环境改变而改变的、不可以共享的状态
};

#endif // FLYWEIGHT_H
