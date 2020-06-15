#include "LibraryViewMDL.h"

LibraryViewMDL::LibraryViewMDL ( QObject *parent ) : QObject ( parent ) {

}

QString LibraryViewMDL::getDataView () const {

  return this->dataView;
}

QString LibraryViewMDL::getDescription () const {

  return this->description;
}

int LibraryViewMDL::getId () const {

  return this->id;
}

QString LibraryViewMDL::getLibraryView () const {

  return this->libraryView;
}

void LibraryViewMDL::setDataView ( const QString &value ) {

  this->dataView = value;
}

void LibraryViewMDL::setDescription ( const QString &value ) {

  this->description = value;
}

void LibraryViewMDL::setId ( int value ) {

  this->id = value;
}

void LibraryViewMDL::setLibraryView ( const QString &value ) {

  this->libraryView = value;
}
