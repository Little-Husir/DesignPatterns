#include "widget.h"
#include <QButtonGroup>
#include <QRadioButton>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      calculator(20, 10),
      command(nullptr),
      addCmd(&calculator),
      subCmd(&calculator),
      mulCmd(&calculator),
      divCmd(&calculator)
{
    setWindowTitle("Calculator");
    setWindowIcon(QIcon(":/logo.png"));

    // 按钮组
    QButtonGroup *pButtonGroup = new QButtonGroup(this);
    QRadioButton *pAddButton = new QRadioButton("+", this);
    QRadioButton *pSubButton = new QRadioButton("-", this);
    QRadioButton *pMulButton = new QRadioButton("*", this);
    QRadioButton *pDivButton = new QRadioButton("/", this);
    QLabel *pLabel = new QLabel("x = 20, y = 10", this);
    m_pResultEdit = new QLineEdit(this);
    QPushButton *pCalButton = new QPushButton("Calculate", this);

    m_pResultEdit->setReadOnly(true);

    pButtonGroup->addButton(pAddButton, 0);
    pButtonGroup->addButton(pSubButton, 1);
    pButtonGroup->addButton(pMulButton, 2);
    pButtonGroup->addButton(pDivButton, 3);
    pButtonGroup->setExclusive(true);  // 互斥

    QHBoxLayout *pHLayout = new QHBoxLayout();
    pHLayout->addWidget(pAddButton);
    pHLayout->addWidget(pSubButton);
    pHLayout->addWidget(pMulButton);
    pHLayout->addWidget(pDivButton);
    pHLayout->setContentsMargins(0, 0, 0, 0);
    pHLayout->setSpacing(10);

    QVBoxLayout *pLayout = new QVBoxLayout(this);
    pLayout->addWidget(pLabel);
    pLayout->addWidget(m_pResultEdit);
    pLayout->addLayout(pHLayout);
    pLayout->addWidget(pCalButton);
    pLayout->setSpacing(10);
    pLayout->setContentsMargins(10, 10, 10, 10);

    // 连接信号槽
    connect(pButtonGroup, static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, &Widget::onButtonClicked);
    connect(pCalButton, &QPushButton::clicked, this, &Widget::onCalculate);

    // 默认选择加法
    pButtonGroup->button(0)->click();
}

Widget::~Widget()
{

}

// 设置当前命令
void Widget::onButtonClicked(int id)
{
    if (id == 0) {
        command = &addCmd;
    } else if (id == 1) {
        command = &subCmd;
    } else if (id == 2) {
        command = &mulCmd;
    } else if (id == 3) {
        command = &divCmd;
    }
}

// 计算结果
void Widget::onCalculate()
{
    int nResult = command->execute();
    m_pResultEdit->setText(QString::number(nResult));
}
