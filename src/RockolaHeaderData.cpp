#include "RockolaHeaderData.h"

RockolaHeaderData::RockolaHeaderData () {}

int RockolaHeaderData::getId () const {

  return this->id;
}

void RockolaHeaderData::setId ( int value ) {

  this->id = value;
}

QString RockolaHeaderData::getCodFrame () const {

  return this->codFrame;
}

void RockolaHeaderData::setCodFrame ( const QString &value ) {

  this->codFrame = value;
}

QString RockolaHeaderData::getHeader () const {

  return this->header;
}

void RockolaHeaderData::setHeader ( const QString &value ) {

  this->header = value;
}

QString RockolaHeaderData::getDescription () const {

  return this->description;
}

void RockolaHeaderData::setDescription ( const QString &value ) {

  this->description = value;
}
