#ifndef ELEMENT_H
#define ELEMENT_H

class IVisitor;

// 景点中定义了一个 Accept() 接口，用于接受访问者的访问
class IPlace
{
public:
	virtual ~IPlace() {}
	virtual void Accept(IVisitor *visitor) = 0;
};

#endif // ELEMENT_H
