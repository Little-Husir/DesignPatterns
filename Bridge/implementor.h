#ifndef IMPLEMENTOR_H
#define IMPLEMENTOR_H

//创建实现类接口-所有电器都有一些共性，可以被打开和关闭
class IEquipment
{
public:
	virtual ~IEquipment() {}

	// 打开
	virtual void PowerOn() = 0;

	// 关闭
	virtual void PowerOff() = 0;
};

#endif // IMPLEMENTOR_H
