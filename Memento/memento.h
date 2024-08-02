#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>
#include <string>

//穿越至某一时刻，这个时刻指具体的日期时间，用 DateTime 表示，并为其提供相应的 setter 和 getter 方法
// 日期时间-需要备忘录的类，这里是时间

//更多时候是将要保存的细节给封装在memento备忘录类中，那一天要更改保存的细节也不影响客户端了--拿项目来说可以把主功能页面替换掉的参数或者波形数据等备忘下来，以便下次使用显示
class DateTime
{
public:
	DateTime(std::string dt) : m_dateTime(dt) {}
	~DateTime() {}

	void SetDateTime(std::string dt) {
		m_dateTime = dt;
	}

	std::string GetDateTime() {
		return m_dateTime;
	}

private:
	std::string m_dateTime;
};

#endif // MEMENTO_H
