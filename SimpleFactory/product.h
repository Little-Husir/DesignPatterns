#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

//**抽象类特点**：

//- 无法实例化对象
//- 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

// 汽车接口
class ICar
{
public:
    virtual string Name() = 0;  // 汽车名称-纯虚函数为抽象类也就是接口
};

#endif // PRODUCT_H
