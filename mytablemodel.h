#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>

const int MyTableModelColumnCount = 5;

class MyTableModel : public QAbstractTableModel
{
    Q_OBJECT

    struct CepriInfo {
        QString name;
        int value;
        bool state;
        int progress;
        QString detailInfo;
    };

public:
    MyTableModel();
    void insertData(const QString &name, int value, bool state, int progress, const QString &detailInfo);

protected:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    QList<CepriInfo> m_cepriInfoList;
};

#endif // MYTABLEMODEL_H
