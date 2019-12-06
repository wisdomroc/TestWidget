#include "mytablemodel.h"

MyTableModel::MyTableModel()
{

}

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_cepriInfoList.count();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{

}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{

}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{

}

bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const
{

}
