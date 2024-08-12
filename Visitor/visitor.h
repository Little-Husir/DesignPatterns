#ifndef VISITOR_H
#define VISITOR_H

class BellTower;
class TerracottaWarriors;

// 创建访问者-访问者需要为每个景点都提供一个访问方法
class IVisitor
{
public:
	virtual ~IVisitor() {}
    virtual void Visit(BellTower *) = 0;//钟楼景点提供一个访问方法
    virtual void Visit(TerracottaWarriors *) = 0;//兵马俑景点提供一个访问方法
};

#endif // VISITOR_H
