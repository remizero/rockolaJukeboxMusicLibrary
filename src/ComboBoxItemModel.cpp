#include "ComboBoxItemModel.h"

ComboBoxItemModel::ComboBoxItemModel () {}

ComboBoxItemModel::~ComboBoxItemModel () {}

QString ComboBoxItemModel::getDescription () const {

  return this->description;
}

int ComboBoxItemModel::getId () const {

  return this->id;
}

QString ComboBoxItemModel::getValue () const {

  return this->value;
}

void ComboBoxItemModel::setDescription ( const QString &value ) {

  this->description = value;
}

void ComboBoxItemModel::setId ( int value ) {

  this->id = value;
}

void ComboBoxItemModel::setValue ( const QString &value ) {

  this->value = value;
}
