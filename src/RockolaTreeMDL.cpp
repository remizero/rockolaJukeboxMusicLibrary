#include "RockolaTreeMDL.h"

RockolaTreeMDL::RockolaTreeMDL ( const QList<RockolaHeaderData> &headers, const QString &data, QObject *parent ) : QAbstractItemModel ( parent ) {

  QVector<RockolaHeaderData> rootData;
  foreach ( RockolaHeaderData header, headers ) {

    rootData << header;
  }
  this->rootItem = new RockolaTreeItem ( rootData );
  this->setupModelData ( data.split ( QString ( "\n" ) ), this->rootItem );
}

RockolaTreeMDL::~RockolaTreeMDL () {}
//! [1]

//! [2]
int RockolaTreeMDL::columnCount ( const QModelIndex & /* parent */ ) const {

  return this->rootItem->columnCount ();
}
//! [2]

QVariant RockolaTreeMDL::data ( const QModelIndex &index, int role ) const {

  if ( !index.isValid () ) {

    return QVariant ();
  }
  if ( role != Qt::DisplayRole && role != Qt::EditRole ) {

    return QVariant ();
  }
  RockolaTreeItem *item = this->getItem ( index );
  return QVariant::fromValue ( item->data ( index.column () ) );
}

//! [3]
Qt::ItemFlags RockolaTreeMDL::flags ( const QModelIndex &index ) const {

  if ( !index.isValid () ) {

    return nullptr;
  }
  return Qt::ItemIsEditable | QAbstractItemModel::flags ( index );
}
//! [3]

//! [4]
RockolaTreeItem *RockolaTreeMDL::getItem ( const QModelIndex &index ) const {

  if ( index.isValid () ) {

    RockolaTreeItem *item = static_cast<RockolaTreeItem*> ( index.internalPointer () );
    if ( item ) {

      return item;
    }
  }
  return this->rootItem;
}
//! [4]

QVariant RockolaTreeMDL::headerData ( int section, Qt::Orientation orientation, int role ) const {

  if ( orientation == Qt::Horizontal && role == Qt::DisplayRole ) {

    return QVariant::fromValue ( this->rootItem->data ( section ) );

  } else if ( role == Qt::ToolTipRole ) {

    return QVariant::fromValue ( this->rootItem->data ( section, role ) );
  }
  return QVariant ();
}

//! [5]
QModelIndex RockolaTreeMDL::index ( int row, int column, const QModelIndex &parent ) const {

  if ( parent.isValid () && parent.column () != 0 ) {

    return QModelIndex ();
  }
//! [5]

//! [6]
  RockolaTreeItem *parentItem = this->getItem ( parent );
  RockolaTreeItem *childItem = parentItem->child ( row );
  if ( childItem ) {

    return createIndex ( row, column, childItem );

  } else {

    return QModelIndex ();
  }
}
//! [6]

bool RockolaTreeMDL::insertColumns ( int position, int columns, const QModelIndex &parent ) {

  bool success;
  this->beginInsertColumns ( parent, position, position + columns - 1 );
  success = this->rootItem->insertColumns ( position, columns );
  this->endInsertColumns ();
  return success;
}

bool RockolaTreeMDL::insertRows ( int position, int rows, const QModelIndex &parent ) {

  RockolaTreeItem *parentItem = this->getItem ( parent );
  bool success;
  this->beginInsertRows ( parent, position, position + rows - 1 );
  success = parentItem->insertChildren ( position, rows, this->rootItem->columnCount () );
  this->endInsertRows ();
  return success;
}

//! [7]
QModelIndex RockolaTreeMDL::parent ( const QModelIndex &index ) const {

  if ( !index.isValid () ) {

    return QModelIndex ();
  }
  RockolaTreeItem *childItem = this->getItem ( index );
  RockolaTreeItem *parentItem = childItem->parent ();
  if ( parentItem == this->rootItem ) {

    return QModelIndex ();
  }
  return this->createIndex ( parentItem->childNumber (), 0, parentItem );
}
//! [7]

bool RockolaTreeMDL::removeColumns ( int position, int columns, const QModelIndex &parent ) {

  bool success;
  this->beginRemoveColumns ( parent, position, position + columns - 1 );
  success = this->rootItem->removeColumns ( position, columns );
  this->endRemoveColumns ();
  if ( this->rootItem->columnCount () == 0 ) {

    this->removeRows ( 0, rowCount () );
  }
  return success;
}

bool RockolaTreeMDL::removeRows ( int position, int rows, const QModelIndex &parent ) {

  RockolaTreeItem *parentItem = this->getItem ( parent );
  bool success = true;
  this->beginRemoveRows ( parent, position, position + rows - 1 );
  success = parentItem->removeChildren ( position, rows );
  this->endRemoveRows ();
  return success;
}

//! [8]
int RockolaTreeMDL::rowCount ( const QModelIndex &parent ) const {

  RockolaTreeItem *parentItem = this->getItem ( parent );
  return parentItem->childCount ();
}
//! [8]

bool RockolaTreeMDL::setData ( const QModelIndex &index, const QVariant &value, int role ) {

  if ( role != Qt::EditRole ) {

    return false;
  }
  RockolaTreeItem *item = this->getItem ( index );
  bool result = item->setData ( index.column (), value );
  if ( result ) {

    emit this->dataChanged ( index, index );
  }
  return result;
}

bool RockolaTreeMDL::setHeaderData ( int section, Qt::Orientation orientation, const QVariant &value, int role ) {

  if ( role != Qt::EditRole || orientation != Qt::Horizontal ) {

    return false;
  }
  bool result = this->rootItem->setData ( section, value );
  if ( result ) {

    emit this->headerDataChanged ( orientation, section, section );
  }
  return result;
}

void RockolaTreeMDL::setupModelData ( const QStringList &lines, RockolaTreeItem *parent ) {

  // TODO este código ajustarlo al formato de base de datos
  QList<RockolaTreeItem*> parents;
  QList<int> indentations;
  parents << parent;
  indentations << 0;
  int number = 0;

  qInfo () << "Contador de líneas leidas desde el archivo: " << lines.count ();
  while ( number < lines.count () ) {

    // Este fragmento de código de 9 líneas es para determinar la identación y saber cuales son los hijos.
    // Al cambiar el modelo se puede subtituir por el código respectivo.
    int position = 0;
    //qInfo () << lines [ number ];
    while ( position < lines [ number ].length () ) {

      if ( lines [ number ].at ( position ) != ' ' ) {

        break;
      }
      ++position;
    }
    QString lineData = lines [ number ].mid ( position ).trimmed ();
    if ( !lineData.isEmpty () ) {

      // Read the column data from the rest of the line.
      QStringList columnStrings = lineData.split ( "\t", QString::SkipEmptyParts );
      QVector<QVariant> columnData;
      for ( int column = 0; column < columnStrings.count (); ++column ) {

        columnData << columnStrings [ column ];
        //qInfo () << columnStrings [ column ];
      }
      if ( position > indentations.last () ) {

        qInfo () << "La posición es mayor que la indentación";
        // The last child of the current parent is now the new parent unless the current parent has no children.
        // El último hijo del padre actual es ahora el nuevo padre a menos que el padre actual no tenga hijos.
        if ( parents.last ()->childCount () > 0 ) {

          parents << parents.last ()->child ( parents.last ()->childCount () - 1 );
          indentations << position;
        }
      } else {

        qInfo () << "La posición no es mayor que la indentación";
        while ( position < indentations.last () && parents.count () > 0 ) {

          parents.pop_back ();
          indentations.pop_back ();
        }
      }
      // Append a new item to the current parent's list of children.
      RockolaTreeItem *parent = parents.last ();
      qInfo () << "this->rootItem->columnCount (): " << this->rootItem->columnCount ();
      qInfo () << "parent->childCount (): " << parent->childCount ();
      //parent->data ();
      qInfo () << "columnData.size (); " << columnData.size ();
      parent->insertChildren ( parent->childCount (), 1, this->rootItem->columnCount () );
      for ( int column = 0; column < columnData.size (); ++column ) {

        // TODO Como saber cual es la columna Rating para asignar el delegado a esa columna
        // TODO Definir un tamaño fijo para la columna Rating
        if ( column == 2 ) {

          //parent->child ( parent->childCount () - 1 )->setData ( column, QVariant::fromValue ( StarRating ( columnData [ column ].toInt () ) ) );
          // Aquí validar cual es la columna para asignar correctamente el delegado correspondiente
          parent->child ( parent->childCount () - 1 )->setData ( 69, QVariant::fromValue ( StarRating ( columnData [ column ].toInt () ) ) );

        } else if ( ( parent->childCount () - 1 ) == 24 ) {

          // TODO Aquí hay que asignar el valor columnData [ column ] al SpinBoxDelegate. Como hacer esto?
          parent->child ( parent->childCount () - 1 )->setData ( column, columnData [ column ] );

        } else if ( ( parent->childCount () - 1 ) == 29 ) {

          // TODO Aquí hay que asignar el valor columnData [ column ] al ComboBoxDelegate. Como hacer esto?
          parent->child ( parent->childCount () - 1 )->setData ( column, columnData [ column ] );

        } else {

          parent->child ( parent->childCount () - 1 )->setData ( column, columnData [ column ] );
        }
      }
    }
    ++number;
  }
}
