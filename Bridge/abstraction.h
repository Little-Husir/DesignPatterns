#ifndef ABSTRACTION_H
#define ABSTRACTION_H

#include "implementor.h"

//创建抽象类-对于开关来说，它并不知道电灯和风扇的存在，只知道自己可以控制（打开/关闭）某个电器。也就是说
//每个 ISwitch 应该持有一个 IElectricalEquipment 对象：

// 开关
class ISwitch
{
public:
    //抽象类中定义了一个 IEquipment，即ISwitch与IEquipment存在关联关系
	ISwitch(IEquipment *equipment) { m_pEquipment = equipment; }
	virtual ~ISwitch() {}

	// 打开电器
	virtual void On() = 0;

	// 关闭电器
	virtual void Off() = 0;

protected:
	IEquipment *m_pEquipment = nullptr;
};

#endif // ABSTRACTION_H
