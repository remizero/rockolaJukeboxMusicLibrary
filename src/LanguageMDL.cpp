#include "LanguageMDL.h"

LanguageMDL::LanguageMDL ( QObject *parent ) : QObject ( parent ) {

}

QString LanguageMDL::getDescription () const {

  return this->description;
}

int LanguageMDL::getId () const {

  return this->id;
}

QString LanguageMDL::getIso_369_1 () const {

  return this->iso_369_1;
}

QString LanguageMDL::getIso_369_2 () const {

  return this->iso_369_2;
}

void LanguageMDL::setDescription ( const QString &value ) {

  this->description = value;
}

void LanguageMDL::setId ( int value ) {

  this->id = value;
}

void LanguageMDL::setIso_369_1 ( const QString &value ) {

  this->iso_369_1 = value;
}

void LanguageMDL::setIso_369_2 ( const QString &value ) {

  this->iso_369_2 = value;
}
