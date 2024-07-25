#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "builder.h"

// 构造指挥官：在Create方法里接受一个IBuilder，然后在内部调用相应的组装函数
class Direcror
{
public:
    void Create(IBuilder *builder) {
        builder->BuildCpu();
        builder->BuildMainboard();
        builder->BuildRam();
        builder->BuildVideoCard();
    }
};

#endif // DIRECTOR_H
