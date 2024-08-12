#ifndef VISITOR_H
#define VISITOR_H

class BellTower;
class TerracottaWarriors;

// ����������-��������ҪΪÿ�����㶼�ṩһ�����ʷ���
class IVisitor
{
public:
	virtual ~IVisitor() {}
    virtual void Visit(BellTower *) = 0;//��¥�����ṩһ�����ʷ���
    virtual void Visit(TerracottaWarriors *) = 0;//����ٸ�����ṩһ�����ʷ���
};

#endif // VISITOR_H
