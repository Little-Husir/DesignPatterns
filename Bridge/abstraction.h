#ifndef ABSTRACTION_H
#define ABSTRACTION_H

#include "implementor.h"

//����������-���ڿ�����˵��������֪����ƺͷ��ȵĴ��ڣ�ֻ֪���Լ����Կ��ƣ���/�رգ�ĳ��������Ҳ����˵
//ÿ�� ISwitch Ӧ�ó���һ�� IElectricalEquipment ����

// ����
class ISwitch
{
public:
    //�������ж�����һ�� IEquipment����ISwitch��IEquipment���ڹ�����ϵ
	ISwitch(IEquipment *equipment) { m_pEquipment = equipment; }
	virtual ~ISwitch() {}

	// �򿪵���
	virtual void On() = 0;

	// �رյ���
	virtual void Off() = 0;

protected:
	IEquipment *m_pEquipment = nullptr;
};

#endif // ABSTRACTION_H
