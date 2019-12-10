#ifndef PROGRESSDELEGATE_H
#define PROGRESSDELEGATE_H

#include <QStyledItemDelegate>

class ProgressDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    ProgressDelegate(QWidget *parent = nullptr) : QStyledItemDelegate(parent) {}

protected:
    QRect CheckBoxRect(const QStyleOptionViewItem &viewItemStyleOptions) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif
