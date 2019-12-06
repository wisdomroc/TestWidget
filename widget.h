#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mytablemodel.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void initData();
    void initUi();

private:
    Ui::Widget *ui;
    MyTableModel *m_tableModel;
};

#endif // WIDGET_H
