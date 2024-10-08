#ifndef OBJECT_STRUCTURE_H
#define OBJECT_STRUCTURE_H

#include "element.h"
#include <list>

//添加景点，并为每一个景点添加访问者

// 城市（西安）
class City
{
public:
    //添加
	void Attach(IPlace *place) {
		m_places.push_back(place);
	}

    //移除
	void Detach(IPlace *place) {
		m_places.remove(place);
	}

	void Accept(IVisitor *visitor) {
		// 为每一个 element 设置 visitor，进行对应的操作
		for (std::list<IPlace*>::iterator it = m_places.begin(); it != m_places.end(); ++it) {
			(*it)->Accept(visitor);
		}
	}

private:
	std::list<IPlace *> m_places;
};

#endif // OBJECT_STRUCTURE_H
