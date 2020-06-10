#include "ConfigData.h"

ConfigData::ConfigData ( QObject *parent ) : QObject ( parent ) {

  this->modified = false;
  this->modifiedCounter = 0;
}

int ConfigData::getHeaderMinimumSectionSize () const {

  return this->headerMinimumSectionSize;
}

QByteArray ConfigData::getHeaderState () {

  return this->headerState;
}

bool ConfigData::getHeaderStretchLastSection () const {

  return this->headerStretchLastSection;
}

int ConfigData::getHeaderTooltipDuration () const {

  return this->headerTooltipDuration;
}

int ConfigData::getId () const {

  return this->id;
}

int ConfigData::getLanguage () {

  return this->language;
}

bool ConfigData::isModified () const {

  return this->modified;
}

void ConfigData::setId ( int value ) {

  this->id = value;
}

void ConfigData::setLanguage ( int language ) {

  this->setModified ();
  this->language = language;
}

void ConfigData::setModified () {

  if ( this->modifiedCounter <= 1 ) {

    if ( this->modifiedCounter == 1 ) {

      if ( !this->modified ) {

        this->modified = !this->modified;
        this->modifiedCounter++;
      }
    } else {

      this->modifiedCounter++;
    }
  }
}

void ConfigData::setHeaderMinimumSectionSize ( int value ) {

  this->headerMinimumSectionSize = value;
}

void ConfigData::setHeaderState ( QByteArray headerState ) {

  this->setModified ();
  this->headerState = headerState;
}

void ConfigData::setHeaderStretchLastSection ( bool value ) {

  this->headerStretchLastSection = value;
}

void ConfigData::setHeaderTooltipDuration ( int value ) {

  this->headerTooltipDuration = value;
}
