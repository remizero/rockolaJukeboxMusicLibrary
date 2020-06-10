#ifndef ROCKOLATREEMDL_H
#define ROCKOLATREEMDL_H

#include <QAbstractItemModel>
#include <QDebug>
#include <QList>
#include <QObject>
#include <QString>

#include "RockolaHeaderData.h"
#include "RockolaTreeItem.h"
#include "StarRating.h"

//class RockolaTreeItem;

class RockolaTreeMDL : public QAbstractItemModel {

    Q_OBJECT

  public:
    explicit RockolaTreeMDL ( const QList<RockolaHeaderData> &headers, const QString &data = "", QObject *parent = nullptr );
    ~RockolaTreeMDL () override;

       QVariant data ( const QModelIndex &index, int role ) const override;
       QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const override;
    QModelIndex index ( int row, int column, const QModelIndex &parent = QModelIndex () ) const override;
    QModelIndex parent ( const QModelIndex &index ) const override;
            int rowCount ( const QModelIndex &parent = QModelIndex () ) const override;
            int columnCount ( const QModelIndex &parent = QModelIndex () ) const override;

    Qt::ItemFlags flags ( const QModelIndex &index ) const override;
             bool setData ( const QModelIndex &index, const QVariant &value, int role = Qt::EditRole ) override;
             bool setHeaderData ( int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole ) override;
             bool insertColumns ( int position, int columns, const QModelIndex &parent = QModelIndex () ) override;
             bool removeColumns ( int position, int columns, const QModelIndex &parent = QModelIndex () ) override;
             bool insertRows ( int position, int rows, const QModelIndex &parent = QModelIndex () ) override;
             bool removeRows ( int position, int rows, const QModelIndex &parent = QModelIndex () ) override;

  private:
               void setupModelData ( const QStringList &lines, RockolaTreeItem *parent );
    RockolaTreeItem *getItem ( const QModelIndex &index ) const;
    RockolaTreeItem *rootItem;
};

#endif // ROCKOLATREEMDL_H
