/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

/*
    RockolaTreeItem.cpp

    A container for items of data supplied by the simple tree model.
*/

#include "RockolaTreeItem.h"

#include <QStringList>

//! [0]
RockolaTreeItem::RockolaTreeItem ( const QVector<RockolaHeaderData> &data, RockolaTreeItem *parent ) {

  this->parentItem = parent;
  this->itemData = data;
}
//! [0]

//! [1]
RockolaTreeItem::~RockolaTreeItem () {

  qDeleteAll ( this->childItems );
}
//! [1]

//! [2]
RockolaTreeItem *RockolaTreeItem::child ( int number ) {

  return this->childItems.value ( number );
}
//! [2]

//! [3]
int RockolaTreeItem::childCount () const {

  return this->childItems.count ();
}
//! [3]

//! [4]
int RockolaTreeItem::childNumber () const {

  if ( this->parentItem ) {

    return this->parentItem->childItems.indexOf ( const_cast<RockolaTreeItem *> ( this ) );
  }
  return 0;
}
//! [4]

//! [5]
int RockolaTreeItem::columnCount () const {

  return this->itemData.count ();
}
//! [5]

//! [6]
QVariant RockolaTreeItem::data ( int column , int role ) const {

  if ( role == Qt::DisplayRole ) {

    return QVariant::fromValue ( ( this->itemData.value ( column ) ).getHeader () );

  } else if ( role == Qt::ToolTipRole ) {

    return QVariant::fromValue ( ( this->itemData.value ( column ) ).getDescription () );
  }
  return QVariant::fromValue ( ( this->itemData.value ( column ) ).getHeader () );
}
//! [6]

//! [7]
bool RockolaTreeItem::insertChildren ( int position, int count, int columns ) {

  if ( position < 0 || position > this->childItems.size () ) {

    return false;
  }
  for ( int row = 0; row < count; ++row ) {

    QVector<RockolaHeaderData> data ( columns );
    RockolaTreeItem *item = new RockolaTreeItem ( data, this );
    this->childItems.insert ( position, item );
  }
  return true;
}
//! [7]

//! [8]
bool RockolaTreeItem::insertColumns ( int position, int columns ) {

  if ( position < 0 || position > this->itemData.size () ) {

    return false;
  }
  for ( int column = 0; column < columns; ++column ) {

    this->itemData.insert ( position, RockolaHeaderData () );
  }
  foreach ( RockolaTreeItem *child, this->childItems ) {

    child->insertColumns ( position, columns );
  }
  return true;
}
//! [8]

//! [9]
RockolaTreeItem *RockolaTreeItem::parent () {

  return this->parentItem;
}
//! [9]

//! [10]
bool RockolaTreeItem::removeChildren ( int position, int count ) {

  if ( position < 0 || position + count > this->childItems.size () ) {

    return false;
  }
  for ( int row = 0; row < count; ++row ) {

    delete this->childItems.takeAt ( position );
  }
  return true;
}
//! [10]

bool RockolaTreeItem::removeColumns ( int position, int columns ) {

  if ( position < 0 || position + columns > this->itemData.size () ) {

    return false;
  }
  for ( int column = 0; column < columns; ++column ) {

    this->itemData.remove ( position );
  }
  foreach ( RockolaTreeItem *child, this->childItems ) {

    child->removeColumns ( position, columns );
  }
  return true;
}

//! [11]
bool RockolaTreeItem::setData ( int column, const QVariant &value ) {

  if ( column < 0 || column >= this->itemData.size () ) {

    return false;
  }
  this->itemData.replace ( column, qvariant_cast<RockolaHeaderData> ( value ) );
  return true;
}
//! [11]
