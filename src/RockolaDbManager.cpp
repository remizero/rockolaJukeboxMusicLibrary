#include "RockolaDbManager.h"

RockolaDbManager::RockolaDbManager () {

  this->path = QDir::home ().path ();
  this->path.append ( QDir::separator () ).append ( ".rockola" ).append ( QDir::separator () ).append ( "rockola.db" );
  this->path = RockolaDbManager::normalizePath ( this->path );
  this->openConnection ();
}

void RockolaDbManager::closeConnection () {

  if ( this->isConnected () ) {

    this->connection.close ();
  }
}

void RockolaDbManager::createDb () {

}

bool RockolaDbManager::deleteDb () {

  return QFile::remove ( this->path );
}

void RockolaDbManager::executeSqlFile () {

  QSqlQuery sqlQuery;
  //sqlQuery.
}

QSqlDatabase RockolaDbManager::getConnection () {

  return this->connection;
}

bool RockolaDbManager::isConnected () {

  return this->connection.isOpen () && this->connection.isValid ();
}

QString RockolaDbManager::normalizePath ( QString pathname ) {

  return QDir::toNativeSeparators ( pathname );
}

void RockolaDbManager::openConnection () {

  this->connection = QSqlDatabase::addDatabase ( "QSQLITE" );
  this->connection.setDatabaseName ( path );
  this->connection.open ();
}

int RockolaDbManager::parseSqlScriptFile ( QSqlDatabase &connection, const QString &fileName ) {

  // Código tomado de https://www.qtcentre.org/threads/27167-How-can-i-execute-a-database-script-within-Qt
  // 14th January 2010, 08:37 USUARIO: numbat
  QFile file ( fileName );
  if ( !file.open ( QIODevice::ReadOnly | QIODevice::Text ) ) {

    return 0;
  }
  QTextStream in ( &file );
  QString sql = in.readAll ();
  if ( sql.length () == 0 ) {

    return 0;
  }
  QList<int> splitPoints;
  enum { IN_STR, IN_ESC, NORMAL } state = NORMAL;
  int successCount = 0;

  for ( int i = 0; i < sql.length (); i++ ) {

    const int character = sql.at ( i ).unicode ();
    switch ( state ) {

      case IN_STR:

        switch ( character ) {

          case '\"':

            state = NORMAL;
            break;

          case '\\':

            state = IN_ESC;
            break;
        }
        break;

      case IN_ESC:

        state = IN_STR;
        break;

      case NORMAL:

        switch ( character ) {

          case ';':

            splitPoints.push_back ( i );
            break;

          case '\"':

            state = IN_STR;
            break;
        }
    }
  }
  splitPoints.push_back ( sql.length () - 1 );
  for ( int i = 0, j = 0; i < splitPoints.length (); i++ ) {

    QString statement = sql.mid ( j, splitPoints.at ( i ) - j + 1 );
    j = splitPoints.at ( i ) + 1;
    if ( statement.trimmed ().length () > 0 ) {

      QSqlQuery query ( connection );
      if ( query.exec ( statement ) ) {

        successCount++;

      } else {

        // TODO Hacer uso de la clase Logger del sistema qtrcp para llevar un registro de errores
        qDebug () << "Failed:" << statement << "\nReason:" << query.lastError ();
      }
    }
  }
  return successCount;
}

void RockolaDbManager::restoreRockolaDb () {

  // TODO Al terminar de ejecutarse este código debe restablecerse la conexión a la base de datos.
  // TODO Recargar lo que haya que recargar.
  // TODO Tomar toda la información cargada disponible y guardar la data que haya que guardar.
  QSqlDatabase connection = QSqlDatabase::addDatabase ( "QSQLITE" );
  QString path = QDir::home ().path ();
  path.append ( QDir::separator () ).append ( ".rockola" ).append ( QDir::separator () ).append ( "rockola.db" );
  path = RockolaDbManager::normalizePath ( path );
  connection.setDatabaseName ( path );
  connection.open ();

  if ( connection.isOpen () && connection.isValid () ) {

    QDirIterator it ( ":/resources", QDirIterator::Subdirectories );
    while ( it.hasNext () ) {

      QFileInfo f ( it.next () );
      if ( f.isFile () ) {

        if ( f.suffix ().compare ( "sql" ) == 0 ) {

          RockolaDbManager::parseSqlScriptFile ( connection, f.filePath () );
        }
      }
    }
  } else {

    // TODO Hacer uso de la clase Logger del sistema qtrcp para llevar un registro de errores
    qInfo () << "Por alguna razón no se conectó, verificar que pasó";
  }
  connection.close ();
}
