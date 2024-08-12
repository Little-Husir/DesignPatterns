#ifndef CONCRETE_ELEMENT_H
#define CONCRETE_ELEMENT_H

#include "element.h"
#include "visitor.h"
#include <iostream>

//����Ԫ�������� - ��¥������ٸ������ʵ���� Accept() ����
//ע�⣺ �� Accept() �����У�ͨ������ Visitor �� visit() �������Ե�ǰ����Ϊ��������ʵ�ֶԾ���ķ��ʡ�

// ��¥
class BellTower : public IPlace
{
public:
	virtual void Accept(IVisitor *visitor) override {
		std::cout << "Bell Tower is accepting visitor." << std::endl;
		visitor->Visit(this);
	}
};

// ����ٸ
class TerracottaWarriors : public IPlace
{
public:
	virtual void Accept(IVisitor *visitor) override {
		std::cout << "Terracotta Warriors is accepting visitor." << std::endl;
		visitor->Visit(this);
	}
};

#endif // CONCRETE_ELEMENT_H
