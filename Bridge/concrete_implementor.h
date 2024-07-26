#ifndef CONCRETE_IMPLEMENTOR_H
#define CONCRETE_IMPLEMENTOR_H

#include "implementor.h"
#include <iostream>

//��������ʵ���࣬�̳в�ʵ��IEquipment�ӿ�

// ���
class Light : public IEquipment
{
public:
	// ����
	void PowerOn() override {
		std::cout << "Light is on." << std::endl;
	}

	// �ص�
	void PowerOff() override {
		std::cout << "Light is off." << std::endl;
	}
};

// ����
class Fan : public IEquipment
{
public:
	// �򿪷���
	void PowerOn() override {
		std::cout << "Fan is on." << std::endl;
	}

	// �رշ���
	void PowerOff() override {
		std::cout << "Fan is off." << std::endl;
	}
};

#endif // CONCRETE_IMPLEMENTOR_H
