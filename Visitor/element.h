#ifndef ELEMENT_H
#define ELEMENT_H

class IVisitor;

// �����ж�����һ�� Accept() �ӿڣ����ڽ��ܷ����ߵķ���
class IPlace
{
public:
	virtual ~IPlace() {}
	virtual void Accept(IVisitor *visitor) = 0;
};

#endif // ELEMENT_H
