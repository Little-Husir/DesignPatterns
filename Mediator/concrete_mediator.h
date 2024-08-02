#ifndef CONCRETE_MEDIATOR_H
#define CONCRETE_MEDIATOR_H

#include "mediator.h"

// �����н���-�����н��ߵ�ְ���Ǳ������еĲ����ߣ��������ߵ���Ϣ֪ͨ��ÿһ����
class ConcreteMediator : public IMediator
{
public:
	// �������ߵ���Ϣ���͸����в����ߣ����������������Լ���
	virtual void distributeMessage(const IColleague* sender, const std::string& message) const override {
        for (const IColleague* c : getColleagues()) // �������еĲ�����
            if (c != sender)  // ������ƣ���Ҫ����Ϣ���͸��Լ�
                c->receiveMessage(sender, message);// ����Ϣ���͸�������
	}
};

#endif // CONCRETE_MEDIATOR_H
