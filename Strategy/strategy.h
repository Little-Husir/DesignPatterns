#ifndef STRATEGY_H
#define STRATEGY_H

// 出行策略-抽象策略由 ITransport 表示，它提供了一个 Run接口，用于提供出行方式
class ITransport
{
public:
	virtual ~ITransport() {}
	virtual void Run() = 0;
};

#endif // STRATEGY_H
