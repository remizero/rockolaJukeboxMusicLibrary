
// Librerías Qt
#include <QApplication>

// Librerías de la Aplicación
//#include "MainWindow.h"
#include "RockolaMainWindow.h"

// Librerías Externas

int main ( int argc, char *argv [] ) {

  // Se inicializan los recursos internos de la aplicación
  Q_INIT_RESOURCE ( RockolaResources );

  QApplication a ( argc, argv );

  // Se carga el controlador de base de datos
  RockolaDbManager *rockolaDbConnection = new RockolaDbManager ();

  RockolaMainWindow rockolaMainWindow ( rockolaDbConnection );
  rockolaMainWindow.show ();
  return a.exec ();
}
