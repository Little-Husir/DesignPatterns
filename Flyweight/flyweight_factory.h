#ifndef FLYWEIGHT_FACTORY_H
#define FLYWEIGHT_FACTORY_H

#include "concrete_flyweight.h"
#include <map>

//创建享元工厂：享元工厂的作用在于提供一个用于存储享元对象的享元池，当需要对象时，首先从享元池中获取，如果不存在，则创建一个新的享元对象，将其保存至享元池中并返回

// 用于获取玩家
class PlayerFactory
{
public:
    // 如果 T/CT 对象存在，则直接从享元池获取；否则，创建一个新对象并添加到享元池中，然后返回。-减少内存开销，如果共享的对象越多，存储节约越多
	static IPlayer* getPlayer(std::string type)
	{
		IPlayer *p = NULL;
		if (m_map.find(type) != m_map.end()) {
			p = m_map[type];
		}
		else {
			// 创建 T/CT 对象
			if (type == "T") {
				std::cout << "Terrorist Created" << std::endl;
				p = new Terrorist();
			}
			else if (type == "CT") {
				std::cout << "Counter Terrorist Created" << std::endl;
				p = new CounterTerrorist();
			}
			else {
				std::cout << "Unreachable code!" << std::endl;
			}
			// 一旦创建，将其插入到 map 中
			m_map.insert(std::make_pair(type, p));
		}
		return p;
	}

private:
	// 存储 T/CT 对象（享元池）
	static std::map<std::string, IPlayer*> m_map;
};

#endif // FLYWEIGHT_FACTORY_H
