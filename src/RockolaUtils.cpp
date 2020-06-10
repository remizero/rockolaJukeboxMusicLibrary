#include "RockolaUtils.h"

RockolaUtils::RockolaUtils ( QObject *parent ) : QObject ( parent ) {}

QList<ComboBoxItemModel> RockolaUtils::getMoodsData ( QSqlDatabase connection, int language ) {

  QList<ComboBoxItemModel> comboBoxItemModelList;
  QSqlQuery query ( connection );
  query.exec ( "SELECT iso_369_1 FROM languages WHERE id = \"" + QString::number ( language ) + "\";" );
  while ( query.next () ) {

    QString str = query.value ( "iso_369_1" ).toString ();
    str.truncate ( 2 );
    query.exec ( "SELECT id, mood" + str.toUpper () + " FROM moods;" );
    while ( query.next () ) {

      ComboBoxItemModel comboBoxItemModel;
      comboBoxItemModel.setId ( query.value ( "id" ).toInt () );
      comboBoxItemModel.setValue ( query.value ( "mood" + str.toUpper () ).toString () );
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

QStringList RockolaUtils::getStringListEnum () {

  QMetaEnum metaEnum = QMetaEnum::fromType<RockolaUtils::enumExtensions> ();
  QStringList enumList;

  int keyCount = metaEnum.keyCount ();
  for ( int i = 0; i < keyCount; ++i ) {

    enumList += metaEnum.valueToKey ( i );
  }
  return enumList;
}

QList<RockolaHeaderData> RockolaUtils::loadHeaders ( QSqlDatabase connection, int language ) {

  //QStringList headers;
  RockolaHeaderData rockolaHeaderModel;
  QList<RockolaHeaderData> headersList;
  QSqlQuery query ( connection );
  query.exec ( "SELECT iso_369_1 FROM languages WHERE id = \"" + QString::number ( language ) + "\";" );
  while ( query.next () ) {

    QString str = query.value ( "iso_369_1" ).toString ();
    str.truncate ( 2 );
    query.exec ( "SELECT id, codFrame, header" + str.toUpper () + ", description" + str.toUpper () + " FROM headers;" );
    while ( query.next () ) {

      //headers << query.value ( "header" + str.toUpper () ).toString ();
      rockolaHeaderModel.setId ( query.value ( "id" ).toInt () );
      rockolaHeaderModel.setCodFrame ( query.value ( "codFrame" ).toString () );
      rockolaHeaderModel.setHeader ( query.value ( "header" + str.toUpper () ).toString () );
      rockolaHeaderModel.setDescription ( query.value ( "description" + str.toUpper () ).toString () );
      headersList.append ( rockolaHeaderModel );
    }
  }
  return headersList;
}

ConfigData *RockolaUtils::loadSettings ( QSqlDatabase connection ) {

  ConfigData *configData = new ConfigData ();
  QSqlQuery query ( connection );
  query.exec ( "SELECT * FROM settings;" );
  while ( query.next () ) {

    configData->setId ( query.value ( "id" ).toInt () );
    configData->setLanguage ( query.value ( "language" ).toInt () );
    configData->setHeaderState ( query.value ( "headerState" ).toByteArray () );
  }
  return configData;
}

void RockolaUtils::saveSettings ( QSqlDatabase connection ,ConfigData *configData ) {

  if ( configData->isModified () ) {

    QSqlQuery query ( connection );
    query.prepare ( "UPDATE settings SET language=:language, headerState=:headerState WHERE id=:id;" );
    query.bindValue ( ":language", QString::number ( configData->getLanguage () ) );
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

