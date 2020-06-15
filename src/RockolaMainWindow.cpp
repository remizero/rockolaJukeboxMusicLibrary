#include "RockolaMainWindow.h"

RockolaMainWindow::RockolaMainWindow ( RockolaDbManager *dbConnection, QWidget *parent ) : QMainWindow ( parent ), ui ( new Ui::MainWindow ) {

  // Se instancia la vista del QTreeView desde el formulario ui.
  this->ui->setupUi ( this );
  // Se asigna la base de datos a ser utilizada por la aplicación.
  this->rockolaDbConnection = dbConnection;
  // Se carga la data de configuración de la aplicación.
  this->configData = RockolaUtils::loadSettings ( this->rockolaDbConnection->getConnection () );
  this->languageMDL = RockolaUtils::loadCurrentLanguage ( this->rockolaDbConnection->getConnection (), this->configData->getLanguage () );
  // Se asigna un filtro para ordenar correctamente la vista de acuerdo al modelo establecido para la misma.
  proxyModel = new QSortFilterProxyModel;
  // Se configuran las cabeceras de la vista.
  this->setUpHeaders ();
  // Se asigna el modelo del arbol QTreeView al Proxy Model para el ordenamiento correcto de la misma.
  this->proxyModel->setSourceModel ( this->rockolaTreeMDL );
  // Se asigna el modelo al arbol QTreeView
  this->ui->view->setModel ( this->proxyModel );
  // TODO hacer un tooltip personalizado con transparencia : colores personalizados
  // y esquinas redondeadas o como el logo del qt
  // https://contingencycoder.wordpress.com/2013/07/04/quick-tip-customize-qt-tooltips-with-style-sheets/


  // Se asignan los delegados a las columnas correspondientes.
  this->setUpDelegates ( this->headersDataList );







  this->ui->view->setAnimated ( true );
  this->ui->view->setSortingEnabled ( true );
}

RockolaMainWindow::~RockolaMainWindow () {

  delete this->ui;
}

void RockolaMainWindow::closeEvent ( QCloseEvent *event ) {

  QByteArray headerView = this->ui->view->header ()->saveState ();
  //qInfo () << headerView;
  //this->configData->setLanguage ( 2 );
  this->configData->setHeaderState ( this->ui->view->header ()->saveState () );
  RockolaUtils::saveSettings ( this->rockolaDbConnection->getConnection (), this->configData );
  event->accept ();
}

RockolaDbManager *RockolaMainWindow::getRockolaDbConnection () const {

  return this->rockolaDbConnection;
}

void RockolaMainWindow::setRockolaDbConnection ( RockolaDbManager *value ) {

  this->rockolaDbConnection = value;
}

void RockolaMainWindow::setUpDelegates ( QList<RockolaHeaderData> headersDataList ) {

  // TODO Leer este tutorial completo
  // https://doc.qt.io/qt-5/modelview.html




  // TODO Para realizar cambios dinámicos en el modelo del QTreeView
  // https://quabr.com/53405627/how-to-change-a-qtreeview-model-on-an-action-triggered-signal-in-pyqt5
  // https://stackoverflow.com/questions/53405627/how-to-change-a-qtreeview-model-on-an-action-triggered-signal-in-pyqt5
  // https://stackoverflow.com/questions/37972839/dynamic-qtreeview-with-custom-delegates
  // https://stackoverflow.com/questions/16530384/qt-qtreeview-not-updating-when-adding-to-model
  // https://www.qtcentre.org/threads/28082-QTreeView-own-model-dynamic-filling
  // https://forum.qt.io/topic/17409/solved-qt-4-7-qcombobox-custom-item-delegate-doesn-t-affect-the-current-item-displayed/2
  //
  //

  for ( int i = 0; i < headersDataList.size (); ++i ) {

    switch ( RockolaUtils::getEnumHeadersValue ( headersDataList.at ( i ).getCodFrame ().toUtf8 ().constData () ) ) {

      case RockolaUtils::enumHeaders::UFID : { // Identificador único del archivo.

        // this->ui->view->hideColumn ( i );
/*
        QList<ComboBoxItemModel> moodsDataModel = RockolaUtils::getMoodsData ( this->rockolaDbConnection->getConnection (), this->configData->getLanguage () );
        this->ui->view->setItemDelegateForColumn ( 29 , new ComboBoxDelegate ( moodsDataModel, this->ui->view ) );
        this->ui->view->setItemDelegateForColumn ( 24 , new SpinBoxDelegate ( this->ui->view ) );
        */
        break;
      }
      case RockolaUtils::enumHeaders::TALB : { // Título del disco.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TIT1 : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TIT2 : { // Título de la canción.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TIT3 : { // Complemento del título del disco.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TOAL : { // Título original, p.e. si pertenece originalmente a otro disco.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TPOS : { // Conjunto de varios CD p.e. 1/3.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TRCK : { // Posición de la pista dentro del disco.

        // =====================================================================
        this->ui->view->setItemDelegateForColumn ( i , new SpinBoxDelegate ( this->ui->view ) );
        break;
      }
      case RockolaUtils::enumHeaders::TSRC : { // ISRC International Standard Recording Code.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TSST : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TCOM : { // Compositor de la pista.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TENC : { // Nombre de la person u organización que codificó el archivo, puede contener copyright.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TEXT : { // Escritor de la canción.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TIPL : { // Lista de personas involucradas en la procucción de la grabación.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TMCL : { // Lista de músicos acreditados en la procucción de la grabación.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TOLY : { // Letrista original de la canción en el caso de ser una versión.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TOPE : { // Artista o interprete original de la canción en el caso de ser una versión.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TPE1 : { // Artista o grupo principal.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TPE2 : { // Banda/Orquesta/Acompañamiento.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TPE3 : { //

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TPE4 : { // Nombre de las personas involucradas en el remix de la canción.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TXXX : { // Etiqueta para información del usuario.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TBPM : { // Bits por minutos de la canción.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TCON : { // Género de las canciones.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TFLT : { // Tipo de archivo definido por el mimetype del tipo de archivo, similar a TMED.

        break;
      }
      case RockolaUtils::enumHeaders::TKEY : { // Clave musical de la pista p.e. Dbm o D#m.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TLAN : { // Idioma en el que está escrita la letra de la canción.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TLEN : { // Tamaño de la pista.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TMED : { // Medio desde el que se extrajo la pista.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TMOO : { // Estado anímico de la canción.

        // =====================================================================
        QList<ComboBoxItemModel> moodsDataModel = RockolaUtils::getMoodsData ( this->rockolaDbConnection->getConnection (), this->configData->getLanguage () );
        this->ui->view->setItemDelegateForColumn ( i , new ComboBoxDelegate ( moodsDataModel, this->ui->view ) );
        break;
      }
      case RockolaUtils::enumHeaders::TCOP : { // Copyright.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TOWN : { // Nombre del propietario o licencia de la pista.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TPRO : { // Información del productor.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TPUB : { // Publicista.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TRSN : { // Internet radio station name.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TRSO : { // Internet radio station owner.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TDEN : { // Fecha de codificación del archivo.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TDLY : { // milisegundos de silencio que deben ser insertados antes de la pista.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TDOR : { // Fecha de publicación original de la pista.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TDRC : { // Fecha de grabación de la pista.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TDRL : { // Fecha de la primera liberación de la pista.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TDTG : { // Fecha en que fue etiquetada la pista.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TOFN : { // Nombre original de la pista.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TSOA : { // Clasificación adicional para el tipo de disco p.e. Soundtrack.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::TSOP : { // Clasificación adicional para el interprete de la canción.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TSOT : { // Clasificación adicional para el título de la canción.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::TSSE : { // Software y hardware utilizado para la codificación de la pista.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::WCOM : { // URL con información comercial de la pista o album.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::WCOP : { // URL con información legal o copyright de la pista o album.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::WOAF : { // URL de la página oficial del archivo de audio.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::WOAR : { // URL de la página oficial del interprete o artista.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::WOAS : { // URL de la página oficial de la fuente del audio.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::WORS : { // Official Internet radio station homepage

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::WPAY : { // Página de pago del archivo o album.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::WPUB : { // Página oficial del publicista.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::WXXX : { // URL definido por el usuario.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::MCDI : { // Music CD identifier

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::ETCO : { // Event timing codes.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::MLLT : { // Referencias para calcular posiciones en el archivo.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::SYTC : { // Para describir mejor el tempo de la pieza.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::USLT : { // Contiene la letra de la canción.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::SYLT : { // Puede ser utilizado también pára la letra de la canción.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::COMM : { // Comentarios para agregar a la pista.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::RVA2 : { // Permite predefinir ajustes al volumen de la pista y otras cosas mas.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::EQU2 : { // Permite predefinir la ecualización de la pista.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::RVRB : { // Permite predefinir la reverb de la pista

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::APIC : { // Imágen a mostrar de la pista.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::GEOB : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::PCNT : { // Play counter.

        // =====================================================================
        break;
      }
      case RockolaUtils::enumHeaders::POPM : { // Popularímetro.

        this->ui->view->setItemDelegateForColumn ( i , new StarDelegate () );
        break;
      }
      case RockolaUtils::enumHeaders::RBUF : { // Permite predefinir el tamaño del buffer de reprodución de la pista.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::AENC : { // indica si el flujo de audio real está encriptado y por quién.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::LINK : { // Enlace externo a archivo o URL que contiene la información de la pista.

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::POSS : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::USER : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::OWNE : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::COMR : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::ENCR : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::GRID : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::PRIV : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::SIGN : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::SEEK : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      case RockolaUtils::enumHeaders::ASPI : {

        // this->ui->view->hideColumn ( i );
        break;
      }
      default:

        // this->ui->view->hideColumn ( i );
        break;
    }
  }
}

void RockolaMainWindow::setUpHeaders () {

  // TODO Como y donde hacer uso de esta información
  this->libraryViewMDL = RockolaUtils::loadLibraryView ( this->rockolaDbConnection->getConnection (), this->configData->getLibraryView (), this->configData->getLanguage () );

  // Se carga la información de las cabeceras de la vista de la biblioteca
  this->headersDataList = RockolaUtils::loadHeaders ( this->rockolaDbConnection->getConnection (), this->configData->getLanguage () );
  QFile file ( ":/RockolaResources/resources/default.txt" );
  file.open ( QIODevice::ReadOnly );
  // Se crea el modelo para el arbol QTreeView
  this->rockolaTreeMDL = new RockolaTreeMDL ( this->headersDataList, file.readAll () );
  file.close ();

  // Se asignan algunos parámetros de configuración para la correcta visualización de la vista del arbol QTreeView

  // Se define que las cabeceras del permitirá un menú contextual personalizado.
  this->ui->view->header ()->setContextMenuPolicy ( Qt::CustomContextMenu );
  // Se define el tamaño mínimo permitido para cada columna del QTreeView.
  this->ui->view->header ()->setMinimumSectionSize ( this->configData->getHeaderMinimumSectionSize () );
  this->ui->view->header ()->setStretchLastSection ( this->configData->getHeaderStretchLastSection () );
  // Se asignan algunos parámetros de configuración para la correcta visualización de la vista del arbol QTreeView
  this->ui->view->header ()->setToolTipDuration ( this->configData->getHeaderTooltipDuration () );

  if ( !this->configData->getHeaderState ().isEmpty () ) {

    if ( !this->ui->view->header ()->restoreState ( this->configData->getHeaderState () ) ) {

      // TODO Guardar un mensaje de error en el log de errores
      qInfo () << "Aparentemente NO se restauró el estado anterior de las cabeceras";
    }
  }
}
