#ifndef CARE_TAKER_H
#define CARE_TAKER_H

#include "originator.h"
#include <vector>

// �¹ⱦ��-����ʱ�⵹���Ĺؼ���ͨ�� PandoraBox�����𱦲ſ����ֲ��ź�
class PandoraBox
{
public:
	PandoraBox(Life *life) : m_pLife(life) {}
	~PandoraBox() {
		for (auto itr = m_history.begin(); itr != m_history.end(); ++itr) {
			delete *itr;
		}
		m_history.clear();
	}

	// ���汸��
	void Save() {
		m_history.push_back(m_pLife->CreateMemento());
	}

	// ��Խ��ĳһʱ�̣����ȡʱ�䣩
	void Undo() {
		int index = rand() % m_history.size();
		m_pLife->SetMemento(m_history[index]);
	}

private:
	Life *m_pLife;
	std::vector<DateTime *> m_history;
};

#endif // CARE_TAKER_H
