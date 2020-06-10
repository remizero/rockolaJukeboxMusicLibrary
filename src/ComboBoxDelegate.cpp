#include "ComboBoxDelegate.h"

ComboBoxDelegate::ComboBoxDelegate ( QList<ComboBoxItemModel> comboBoxItemModelList, QWidget *parent ) : QStyledItemDelegate ( parent ) {

  this->comboBoxItemModelList = comboBoxItemModelList;
}

ComboBoxDelegate::~ComboBoxDelegate () {}

QWidget *ComboBoxDelegate::createEditor ( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const {

  // Create the combobox and populate it
  QComboBox *cb = new QComboBox ( parent );
  const int row = index.row ();
  for ( int i = 0; i < this->comboBoxItemModelList.size (); ++i ) {

    cb->addItem ( this->comboBoxItemModelList.at ( i ).getValue (), this->comboBoxItemModelList.at ( i ).getId () );
  }
  return cb;
}

void ComboBoxDelegate::setEditorData ( QWidget *editor, const QModelIndex &index ) const {

  QComboBox *cb = qobject_cast<QComboBox *> ( editor );
  Q_ASSERT ( cb );
  // get the index of the text in the combobox that matches the current value of the item
  const QString currentText = index.data ( Qt::EditRole ).toString ();
  const int cbIndex = cb->findText ( currentText );
  // if it is valid, adjust the combobox
  if ( cbIndex >= 0 ) {

    cb->setCurrentIndex ( cbIndex );
  }
}

void ComboBoxDelegate::setModelData ( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const {

  QComboBox *cb = qobject_cast<QComboBox *> ( editor );
  Q_ASSERT ( cb );
  model->setData ( index, cb->currentText (), Qt::EditRole );
}
