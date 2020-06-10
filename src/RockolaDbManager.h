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
    // TODO Hacer de esta clase un singleton
    // https://www.google.com/search?client=opera&q=Qt+thread-safe+singleton&sourceid=opera&ie=UTF-8&oe=UTF-8
    // https://forum.qt.io/topic/58688/singleton-class-example/3
    // https://es.stackoverflow.com/questions/28532/qué-es-la-clase-singleton-en-qt-y-cuestiones-sobre-esta-clase
    // https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwiqxa_x_u7pAhWDg-AKHTTpC1wQwqsBMAN6BAgIEAQ&url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3Dyrc8qglmCyw&usg=AOvVaw2id3BDlRWCTSIvxPGjtp9H

  private :
    QSqlDatabase connection;
         QString path;
};

#endif // DBUTILS_H
