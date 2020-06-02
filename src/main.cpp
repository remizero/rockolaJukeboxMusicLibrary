
// Librerías Qt
#include <QApplication>

// Librerías de la Aplicación
#include "MainWindow.h"

// Librerías Externas

int main ( int argc, char *argv [] ) {

  // Se inicializan los recursos internos de la aplicación
  Q_INIT_RESOURCE ( rockolaresources );

  QApplication a ( argc, argv );

  // Se carga el controlador de base de datos
  RockolaDbManager *rockolaDbConnection = new RockolaDbManager ();

  MainWindow w;
  w.show ();
  return a.exec ();
}
