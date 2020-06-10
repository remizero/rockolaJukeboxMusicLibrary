#ifndef COMBOBOXITEMDELEGATE_H
#define COMBOBOXITEMDELEGATE_H

#include <QComboBox>
#include <QList>
#include <QStyledItemDelegate>

#include "ComboBoxItemModel.h"

//! [0]
class ComboBoxDelegate : public QStyledItemDelegate {

    Q_OBJECT

  public:
    ComboBoxDelegate ( QList<ComboBoxItemModel> comboBoxItemModelList, QWidget *parent = nullptr );
    ~ComboBoxDelegate () override;

    QWidget *createEditor ( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const override;
       void setEditorData ( QWidget *editor, const QModelIndex &index ) const override;
       void setModelData ( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const override;
      //QSize sizeHint ( const QStyleOptionViewItem &option, const QModelIndex &index ) const override;
       //void paint ( QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index ) const override;

  private slots:
    //void commitAndCloseEditor ();

  private:
    QList<ComboBoxItemModel> comboBoxItemModelList;
};
//! [0]

#endif // COMBOBOXITEMDELEGATE_H
