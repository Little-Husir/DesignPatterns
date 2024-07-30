#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <iostream>
#include <string>

//����������Ԫ�ࣺ����Ԫ���У�Ҫ���ڲ�״̬���ⲿ״̬�ֿ�����ͨ�����ڲ�״̬��Ϊ��Ԫ��ĳ�Ա���������ⲿ״̬ͨ��ע��ķ�ʽ��ӵ���Ԫ����

// ��� - ��������ʹ��
class IPlayer
{
public:
	virtual ~IPlayer() {}

	// ��������
	virtual void assignWeapon(std::string weapon) = 0;

	// ʹ��
	virtual void mission() = 0;

protected:
    std::string m_task; // �ڲ�״̬-�����滷���ı���ı�Ĺ�����
    std::string m_weapon; // �ⲿ״̬-�滷���ı���ı�ġ������Թ����״̬
};

#endif // FLYWEIGHT_H
