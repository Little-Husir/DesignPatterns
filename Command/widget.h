#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "reciever.h"
#include "command.h"

class QLineEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private Q_SLOTS:
    void onButtonClicked(int id);  // 设置当前命令
    void onCalculate();  // 计算结果

private:
    QLineEdit *m_pResultEdit;

    Calculator calculator;
    Command *command;  // 用于调用命令
    AddCommand addCmd;  // 加法
    SubtractCommand subCmd;  // 减法
    MultiplyCommand mulCmd;  // 乘法
    DivideCommand divCmd;  // 除法
};

#endif // WIDGET_H
