#include <QtWidgets>

#include "progressdelegate.h"

QRect ProgressDelegate::CheckBoxRect(const QStyleOptionViewItem &viewItemStyleOptions)const
{
    QStyleOptionButton checkBoxStyleOption;
    QRect checkBoxRect = QApplication::style()->subElementRect( QStyle::SE_CheckBoxIndicator, &checkBoxStyleOption);
    QPoint checkBoxPoint(viewItemStyleOptions.rect.x() + viewItemStyleOptions.rect.width() / 2 - checkBoxRect.width() / 2,
                         viewItemStyleOptions.rect.y() + viewItemStyleOptions.rect.height() / 2 - checkBoxRect.height() / 2);
    return QRect(checkBoxPoint, checkBoxRect.size());
}

void ProgressDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 3)
    {
        int progress = index.data().toInt();

        QStyleOptionProgressBar  progressBarOption ;
        progressBarOption.rect = option.rect;
        progressBarOption.minimum = 0;
        progressBarOption.maximum = 100;
        progressBarOption.progress = progress;
        progressBarOption.text = QString::number(progress) + "%";
        progressBarOption.textAlignment = Qt::AlignCenter;
        progressBarOption.textVisible = true;

        QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);
    }
    else if (index.column() == 2)
    {
        bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
        QStyleOptionButton *checkBoxOption = new QStyleOptionButton();
        checkBoxOption->state |= QStyle::State_Enabled;
        if(checked)
        {
            checkBoxOption->state |= QStyle::State_On;
        }
        else
        {
            checkBoxOption->state |= QStyle::State_Off;
        }
        checkBoxOption->rect = CheckBoxRect(option);
        QApplication::style()->drawControl(QStyle::CE_CheckBox,checkBoxOption,painter);

    }
    else
    {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QWidget *ProgressDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
//    int column = index.column();
//    if(column == 2)
//    {
//        QCheckBox *checkBox = new QCheckBox(parent);
//        bool state = index.data().toBool();
//        checkBox->setChecked(state);
//        return checkBox;
//    }
//    else
    {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
}

void ProgressDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
//    int column = index.column();
//    if(column == 2)
//    {
//        QCheckBox *checkBox = qobject_cast<QCheckBox *>(editor);
//        bool state = index.data().toBool();
//        checkBox->setChecked(state);
//    }
//    else
    {
        return QStyledItemDelegate::setEditorData(editor, index);
    }
}

void ProgressDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
//    int column = index.column();
//    if(column == 2)
//    {
//        QCheckBox *checkBox = qobject_cast<QCheckBox *>(editor);
//        bool state = checkBox->isChecked();
//        model->setData(index, QVariant(state));
//    }
//    else
    {
        return QStyledItemDelegate::setModelData(editor, model, index);
    }
}

QSize ProgressDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}
