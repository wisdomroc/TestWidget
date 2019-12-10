#include "widget.h"
#include "ui_widget.h"
#include "progressdelegate.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),m_tableModel(nullptr)
{
    ui->setupUi(this);

    initData();
    initUi();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initData()
{
    if(m_tableModel == nullptr)
        m_tableModel = new MyTableModel();
    m_tableModel->insertData("TestInfoOne", 11, true, 90, "TestDetailInfoOne");
    m_tableModel->insertData("TestInfoTwo", 22, false, 80, "TestDetailInfoTwo");
    m_tableModel->insertData("TestInfoThree", 33, true, 50, "TestDetailInfoThree");
    m_tableModel->insertData("TestInfoFour", 44, false, 20, "TestDetailInfoFour");
    m_tableModel->insertData("TestInfoFive", 55, true, 70, "TestDetailInfoFive");
    m_tableModel->insertData("TestInfoSix", 66, false, 60, "TestDetailInfoSix");
}

void Widget::initUi()
{
    ui->tableView->setModel(m_tableModel);
    ui->tableView->setItemDelegate(new ProgressDelegate());
    ui->tableView->setMouseTracking(true);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}
