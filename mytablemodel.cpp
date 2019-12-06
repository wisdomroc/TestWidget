#include "mytablemodel.h"

MyTableModel::MyTableModel()
{

}

void MyTableModel::insertData(const QString &name, int value, const QString &detailInfo)
{
    beginInsertRows(QModelIndex(), m_cepriInfoList.count(), m_cepriInfoList.count());
    CepriInfo cepriInfo;
    cepriInfo.name = name;
    cepriInfo.value = value;
    cepriInfo.detailInfo = detailInfo;
    m_cepriInfoList.append(cepriInfo);
    endInsertRows();
}

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_cepriInfoList.count();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return MyTableModelColumnCount;
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    int row = index.row();
    int column = index.column();
    CepriInfo curInfo = m_cepriInfoList.at(row);
    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (column) {
        case 0:
            return QVariant(curInfo.name);
            break;
        case 1:
            return QVariant(curInfo.value);
            break;
        case 2:
            return QVariant(curInfo.detailInfo);
            break;
        }
    }

    return QVariant();
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal)
    {
        if(role == Qt::DisplayRole)
        {
            QStringList headerList;
            headerList << QStringLiteral("名称") << QStringLiteral("值") << QStringLiteral("详细信息");
            return QVariant(headerList.at(section));
        }
    }
    else if(orientation == Qt::Vertical)
    {
        if(role == Qt::DisplayRole)
        {
            return QVariant(section + 1);
        }
    }

    return QVariant();
}

bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;

    if(role == Qt::EditRole)
    {
        int row = index.row();
        int column = index.column();
        CepriInfo curInfo = m_cepriInfoList.at(row);
        switch (column) {
        case 0:
            curInfo.name = value.toString();
            break;
        case 1:
            curInfo.value = value.toInt();
            break;
        case 2:
            curInfo.detailInfo = value.toString();
            break;
        }
        m_cepriInfoList.replace(row, curInfo);
        emit dataChanged(index, index);
        return true;
    }

    return false;
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const
{
    int column = index.column();
    if(column == 0)
        return Qt::ItemIsEnabled;
    else
        return Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
