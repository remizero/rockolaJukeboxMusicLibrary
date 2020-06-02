#ifndef DBUTILS_H
#define DBUTILS_H

#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class RockolaDbManager {

  public :
    RockolaDbManager ();

              void closeConnection ();
              void createDb ();
              bool deleteDb ();
              void executeSqlFile ();
      QSqlDatabase getConnection ();
              bool isConnected ();
    static QString normalizePath ( QString pathname );
              void openConnection ();
        static int parseSqlScriptFile ( QSqlDatabase &connection, const QString &fileName );
       static void restoreRockolaDb ();

    // TODO Hacer uso de la clase Logger del sistema qtrcp para llevar un registro de errores

  private :
    QSqlDatabase connection;
         QString path;
};

#endif // DBUTILS_H
