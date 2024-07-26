#ifndef REFINED_ABSTRACTION_H
#define REFINED_ABSTRACTION_H

#include "abstraction.h"
#include <iostream>

//�������������-�ض����͵Ŀ��غܶ࣬��������ʽ���ء���λ����

// ����ʽ����
class PullChainSwitch : public ISwitch
{
public:
	PullChainSwitch(IEquipment *equipment) 
		: ISwitch(equipment) {}

	// ������ʽ���ش򿪵���
	void On() override {
		std::cout << "Switch on the equipment with a pull chain switch." << std::endl;

		if (nullptr != m_pEquipment)
			m_pEquipment->PowerOn();
	}

	// ������ʽ���عرյ���
	void Off() override {
		std::cout << "Switch off the equipment with a pull chain switch." << std::endl;

		if (nullptr != m_pEquipment)
			m_pEquipment->PowerOff();
	}
};

// ��λ����
class TwoPositionSwitch : public ISwitch
{
public:
	TwoPositionSwitch(IEquipment *equipment)
		: ISwitch(equipment) {}

	// ����λ���ش򿪵���
	void On() override {
		std::cout << "Switch on the equipment with a two-position switch." << std::endl;

		if (nullptr != m_pEquipment)
			m_pEquipment->PowerOn();
	}

	// ����λ���عرյ���
	void Off() override {
		std::cout << "Switch off the equipment with a two-position switch." << std::endl;

		if (nullptr != m_pEquipment)
			m_pEquipment->PowerOff();
	}
};

#endif // REFINED_ABSTRACTION_H
