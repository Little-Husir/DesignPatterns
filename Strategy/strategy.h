#ifndef STRATEGY_H
#define STRATEGY_H

// ���в���-��������� ITransport ��ʾ�����ṩ��һ�� Run�ӿڣ������ṩ���з�ʽ
class ITransport
{
public:
	virtual ~ITransport() {}
	virtual void Run() = 0;
};

#endif // STRATEGY_H
