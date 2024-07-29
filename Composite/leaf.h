// ͸�����ģʽ
#ifndef LEAF_H
#define LEAF_H

#include "component.h"
//��Ϊ Component �����࣬Leaf ��Ҫʵ�� Component �ж�������нӿڣ����� Leaf ���ܰ����ӹ�������ˣ�
//�� Leaf ��ʵ�ַ��ʺ͹����ӹ����ĺ���ʱ����Ҫ�����쳣����������ʾ,��Ȼ�������ɻ��leaf��ʵ�ִ����鷳
class Leaf : public Component
{
public:
	Leaf(string name) : Component(name) {}
	virtual ~Leaf() {}
	void Add(Component *cmpt) {
		cout << "Can't add to a Leaf" << endl;
	}
	void Remove(Component *cmpt) {
		cout << "Can't remove from a Leaf" << endl;
	}
	Component* GetChild(int index) {
		cout << "Can't get child from a Leaf" << endl;
		return NULL;
	}
	void Operation(int indent) {
		string newStr(indent, '-');
		cout << newStr << " " << m_strName << endl;
	}

private:
	Leaf();  // ������
};

#endif // LEAF_H
