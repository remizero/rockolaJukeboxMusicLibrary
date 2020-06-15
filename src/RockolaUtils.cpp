#include "RockolaUtils.h"

RockolaUtils::RockolaUtils ( QObject *parent ) : QObject ( parent ) {}

QList<ComboBoxItemModel> RockolaUtils::getMoodsData ( QSqlDatabase connection, QString language ) {

  QList<ComboBoxItemModel> comboBoxItemModelList;
  QSqlQuery query ( connection );
  language.truncate ( 2 );
  while ( query.next () ) {

    query.exec ( "SELECT id, mood" + language.toUpper () + " FROM moods;" );
    while ( query.next () ) {

      ComboBoxItemModel comboBoxItemModel;
      comboBoxItemModel.setId ( query.value ( "id" ).toInt () );
      comboBoxItemModel.setValue ( query.value ( "mood" + language.toUpper () ).toString () );
      comboBoxItemModel.setDescription ( "" );
      comboBoxItemModelList.append ( comboBoxItemModel );
    }
  }
  return comboBoxItemModelList;
}

int RockolaUtils::getEnumHeadersValue ( const char *key, bool *ok ) {

  QMetaEnum metaEnum = QMetaEnum::fromType<RockolaUtils::enumHeaders> ();
  int enumValue;
  enumValue = metaEnum.keyToValue ( key, ok );
  return enumValue;
}

LanguageMDL *RockolaUtils::loadCurrentLanguage ( QSqlDatabase connection, int language ) {

  LanguageMDL *languageDataMDL = new LanguageMDL ();
  QSqlQuery query ( connection );
  query.exec ( "SELECT * FROM languages WHERE id = \"" + QString::number ( language ) + "\";" );
  while ( query.next () ) {

    QString str = query.value ( "iso_369_1" ).toString ();
    str.truncate ( 2 );
    languageDataMDL->setDescription ( query.value ( "description" + str.toUpper () ).toByteArray () );
    languageDataMDL->setId ( query.value ( "id" ).toInt () );
    languageDataMDL->setIso_369_1 ( query.value ( "iso_369_1" ).toByteArray () );
    languageDataMDL->setIso_369_2 ( query.value ( "iso_369_2" ).toByteArray () );
  }
  return languageDataMDL;
}

QStringList RockolaUtils::getStringListEnum () {

  QMetaEnum metaEnum = QMetaEnum::fromType<RockolaUtils::enumExtensions> ();
  QStringList enumList;

  int keyCount = metaEnum.keyCount ();
  for ( int i = 0; i < keyCount; ++i ) {

    enumList += metaEnum.valueToKey ( i );
  }
  return enumList;
}

QList<RockolaHeaderData> RockolaUtils::loadHeaders ( QSqlDatabase connection, QString language ) {

  RockolaHeaderData rockolaHeaderModel;
  QList<RockolaHeaderData> headersList;
  QSqlQuery query ( connection );
  language.truncate ( 2 );
  while ( query.next () ) {

    query.exec ( "SELECT id, codFrame, header" + language.toUpper () + ", description" + language.toUpper () + " FROM headers;" );
    while ( query.next () ) {

      rockolaHeaderModel.setId ( query.value ( "id" ).toInt () );
      rockolaHeaderModel.setCodFrame ( query.value ( "codFrame" ).toString () );
      rockolaHeaderModel.setHeader ( query.value ( "header" + language.toUpper () ).toString () );
      rockolaHeaderModel.setDescription ( query.value ( "description" + language.toUpper () ).toString () );
      headersList.append ( rockolaHeaderModel );
    }
  }
  return headersList;
}

QList<LanguageMDL> RockolaUtils::loadLanguages ( QSqlDatabase connection, QString language ) {

  LanguageMDL languageDataMDL;
  QList<LanguageMDL> languageList;
  QSqlQuery query ( connection );
  language.truncate ( 2 );
  query.exec ( "SELECT * FROM languages;" );
  while ( query.next () ) {

    languageDataMDL.setDescription ( query.value ( "description" + language.toUpper () ).toByteArray () );
    languageDataMDL.setId ( query.value ( "id" ).toInt () );
    languageDataMDL.setIso_369_1 ( query.value ( "iso_369_1" ).toByteArray () );
    languageDataMDL.setIso_369_2 ( query.value ( "iso_369_2" ).toByteArray () );
    languageList.append ( languageDataMDL );
  }
  return languageList;
}

LibraryViewMDL *RockolaUtils::loadLibraryView ( QSqlDatabase connection, int libraryViewID, QString language ) {

  LibraryViewMDL *libraryViewData = new LibraryViewMDL ();
  QSqlQuery query ( connection );
  language.truncate ( 2 );
  while ( query.next () ) {

    query.exec ( "SELECT id, libraryView, dataView, description" + language.toUpper () + " FROM LibraryViews WHERE id = \"" + QString::number ( libraryViewID ) + "\";" );
    while ( query.next () ) {

      libraryViewData->setDataView ( query.value ( "dataView" ).toByteArray () );
      libraryViewData->setDescription ( query.value ( "description" ).toByteArray () );
      libraryViewData->setId ( query.value ( "id" ).toInt () );
      libraryViewData->setLibraryView ( query.value ( "libraryView" ).toByteArray () );
    }
  }
  return libraryViewData;
}

ConfigDataMDL *RockolaUtils::loadSettings ( QSqlDatabase connection ) {

  ConfigDataMDL *configData = new ConfigDataMDL ();
  QSqlQuery query ( connection );
  query.exec ( "SELECT * FROM settings;" );
  while ( query.next () ) {

    configData->setHeaderMinimumSectionSize ( query.value ( "headerMinimumSectionSize" ).toInt () );
    configData->setHeaderState ( query.value ( "headerState" ).toByteArray () );
    configData->setHeaderStretchLastSection ( query.value ( "headerStretchLastSection" ).toInt () );
    configData->setHeaderTooltipDuration ( query.value ( "headerTooltipDuration" ).toInt () );
    configData->setId ( query.value ( "id" ).toInt () );
    configData->setLanguage ( query.value ( "language" ).toInt () );
    configData->setLibraryView ( query.value ( "libraryView" ).toInt () );
  }
  return configData;
}

void RockolaUtils::saveSettings ( QSqlDatabase connection ,ConfigDataMDL *configData ) {

  if ( configData->isModified () ) {

    QSqlQuery query ( connection );
    //query.prepare ( "UPDATE settings SET language=:language, headerState=:headerState WHERE id=:id;" );
    query.prepare ( "UPDATE settings SET headerState=:headerState WHERE id=:id;" );
    //query.bindValue ( ":language", QString::number ( configData->getLanguage () ) );
    query.bindValue ( ":headerState", configData->getHeaderState () );
    query.bindValue ( ":id", QString::number ( configData->getId () ) );
    if ( query.exec () ) {

      // TODO Hacer uso de la clase Logger del sistema qtrcp para llevar un registro de errores
      qInfo () << "Si se ejecutó correctamente";

    } else {

      // TODO Hacer uso de la clase Logger del sistema qtrcp para llevar un registro de errores
      qInfo () << "No se ejecutó correctamente : " << query.lastError ();
    }
  } else {

    // TODO Hacer uso de la clase Logger del sistema qtrcp para llevar un registro de errores
    qInfo () << "NO se modificó el objeto configData.";
  }
}
