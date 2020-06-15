#include "ConfigDataMDL.h"

ConfigDataMDL::ConfigDataMDL ( QObject *parent ) : QObject ( parent ) {

  this->modified = false;
  //this->modifiedCounter = 0;
}

int ConfigDataMDL::getHeaderMinimumSectionSize () const {

  return this->headerMinimumSectionSize;
}

QByteArray ConfigDataMDL::getHeaderState () {

  return this->headerState;
}

bool ConfigDataMDL::getHeaderStretchLastSection () const {

  return this->headerStretchLastSection;
}

int ConfigDataMDL::getHeaderTooltipDuration () const {

  return this->headerTooltipDuration;
}

int ConfigDataMDL::getId () const {

  return this->id;
}

int ConfigDataMDL::getLanguage () {

  return this->language;
}

int ConfigDataMDL::getLibraryView () const {

  return this->libraryView;
}

bool ConfigDataMDL::isModified () const {

  return this->modified;
}

void ConfigDataMDL::setHeaderMinimumSectionSize ( int value ) {

  if ( ( this->headerMinimumSectionSize != 0 ) && ( !this->modified ) ) {

    this->modified = !this->modified;
  }
  this->headerMinimumSectionSize = value;
}

void ConfigDataMDL::setHeaderState ( QByteArray headerState ) {

  if ( ( !this->headerState.isEmpty () ) && ( !this->modified ) ) {

    this->modified = !this->modified;
  }
  this->headerState = headerState;
}

void ConfigDataMDL::setHeaderStretchLastSection ( bool value ) {

  if ( ( !this->headerStretchLastSection ) && ( !this->modified ) ) {

    this->modified = !this->modified;
  }
  this->headerStretchLastSection = value;
}

void ConfigDataMDL::setHeaderTooltipDuration ( int value ) {

  if ( ( this->headerTooltipDuration != 0 ) && ( !this->modified ) ) {

    this->modified = !this->modified;
  }
  this->headerTooltipDuration = value;
}

void ConfigDataMDL::setId ( int value ) {

  this->id = value;
}

void ConfigDataMDL::setLanguage ( int language ) {

  if ( ( this->language != 0 ) && ( !this->modified ) ) {

    this->modified = !this->modified;
  }
  this->language = language;
}

void ConfigDataMDL::setLibraryView ( int value ) {

  if ( ( this->libraryView != 0 ) && ( !this->modified ) ) {

    this->modified = !this->modified;
  }
  this->libraryView = value;
}

/*void ConfigData::setModified () {

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
}*/
