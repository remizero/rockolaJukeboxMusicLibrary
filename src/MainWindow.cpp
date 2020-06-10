/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "MainWindow.h"

MainWindow::MainWindow ( QWidget *parent ) : QMainWindow ( parent ), ui ( new Ui::MainWindow ) {

  //
  // TODO Hay que desacoplar la data de los headers que vienen de la base de datos de la clase TreeModel.
  // TODO Hay que redefinir la clase treemodel para que solo reciba el modelo en bruto de la base de datos.
  // TODO Hay que desacoplar el método setupModelData de la clase TreeModel para poder asignar el valor del modelo a los delegados correspondientes.
  // TODO Revisar estos enlaces que hablan y muestran información relevante a lo arriba planteado
  // https://www.qtcentre.org/threads/22782-QTreeView-and-custom-model-from-QAbstractItemModel
  // https://www.qtcentre.org/threads/16031-Updating-QTreeView-with-custom-model
  // https://www.qtcentre.org/threads/7060-Treeview-and-custom-model
  // Este es muy interesante
  // https://www.qtcentre.org/threads/10646-How-to-activate-delegated-item-in-qtreeview-by-custom-shotcut
  // Este para un menú contextual personalizado
  // https://www.qtcentre.org/threads/19919-Custom-context-menu-in-QTreeView

  // no escribir no leer ni hablar                        Escuchar historias interactivas
  // no estudiar gramática                                Hacer preguntas de las historias interactivas
  //                                                      repetir las historias

  this->ui->setupUi ( this );

  this->rockolaDbConnection = new RockolaDbManager ();
  this->configData = RockolaUtils::loadSettings ( rockolaDbConnection->getConnection () );
  qInfo () << "DATA DE CONFIGURACIÓN INICIAL DEL OBJETO CONFIGDATA";
  qInfo () << this->configData->getId ();
  qInfo () << this->configData->getLanguage ();
  qInfo () << this->configData->getHeaderState ();

  // TODO Este QSortFilterProxyModel es para poder realizar la ordenación de la columnas de manera eficiente
  // Y permita mantener la estructura definida por la vista activa de visualización de la biblioteca.
  proxyModel = new QSortFilterProxyModel;

  // TODO Redefinir los nombres de las cabeceras por nombres mas representativos e intuitivos
  // (LISTO)TODO La asignación del lenguaje para esta línea de código debe venir desde la lectura de la base de datos, es decir,
  // crear un método en la clase RockolaDbManager que permita generar una tira SQL que permita traer toda la data de la tabla
  // settings en una sola consulta, con las relaciones con otras tablas según el caso que corresponda.
  QList<RockolaHeaderData> headersDataList = RockolaUtils::loadHeaders ( this->rockolaDbConnection->getConnection (), this->configData->getLanguage () );
  QFile file ( ":/RockolaResources/resources/default.txt" );
  file.open ( QIODevice::ReadOnly );
  RockolaTreeMDL *rockolaTreeMDL = new RockolaTreeMDL ( headersDataList, file.readAll () );
  file.close ();
  proxyModel->setSourceModel ( rockolaTreeMDL );
  this->ui->view->setModel ( proxyModel );
  // TODO hacer un tooltip personalizado con transparencia, colores personalizados
  // y esquinas redondeadas o como el logo del qt
  // https://contingencycoder.wordpress.com/2013/07/04/quick-tip-customize-qt-tooltips-with-style-sheets/
  this->ui->view->setToolTipDuration ( 5 );

  // TODO La carga de esta información debe hacerse desde una base de datos.
  /*
  QFile file ( ":/default.txt" );
  file.open ( QIODevice::ReadOnly );
  TreeModel *model = new TreeModel ( headers, file.readAll () );
  file.close ();
  */

  // TODO Como asignar estas columnas de forma automática
  // Identificar las columnas que llevarán delegados para hacer la asignación correspondiente de todos los delegados
  // de forma conjunta, ordenada y automática.
//view->setItemDelegateForColumn ( 69 , new StarDelegate );
  // Como asignar el valor definido en la base de datos para que se muestre el valor correspondiente al combo
//QList<ComboBoxItemModel> moodsDataModel = RockolaUtils::getMoodsData ( this->rockolaDbConnection->getConnection (), this->configData->getLanguage () );
//view->setItemDelegateForColumn ( 29 , new ComboBoxDelegate ( moodsDataModel, view ) );
  // TODO Se asigna el spinbox a la columna de tracks
//view->setItemDelegateForColumn ( 24 , new SpinBoxDelegate ( view ) );
  // Ver que tan importante es hacer uso de esta instrucción.
//view->openPersistentEditor ( model->index ( 0, 29 ) );

  // TODO Definir cuales seran todas las columnas a mostrar
  // TODO Optimizar esta sección de una manera mas automática

  // Esta sección es solo momentánea, al tener definidas las columnas y guardar el primer valor de las columnas
  // solo queda cargar ese valor desde la base de datos y restaurar los valores del QHeaderView.
  /*QList<int> colummList = { 0, 1, 3, 7, 22, 24, 29, 40, 66, 68, 69 };
  for ( int i = 0; i < headers.size (); ++i ) {

    if ( !colummList.contains ( i ) ) {

      view->hideColumn ( i );
    }
  }*/
/*
  view->hideColumn ( 0 );
  //view->hideColumn ( 1 );
  view->hideColumn ( 2 );
  //view->hideColumn ( 3 );
  view->hideColumn ( 4 );
  view->hideColumn ( 5 );
  view->hideColumn ( 6 );
  //view->hideColumn ( 7 );
  view->hideColumn ( 8 );
  view->hideColumn ( 9 );
  view->hideColumn ( 10 );
  view->hideColumn ( 11 );
  view->hideColumn ( 12 );
  view->hideColumn ( 13 );
  view->hideColumn ( 14 );
  view->hideColumn ( 15 );
  view->hideColumn ( 16 );
  view->hideColumn ( 17 );
  view->hideColumn ( 18 );
  view->hideColumn ( 19 );
  view->hideColumn ( 20 );
  view->hideColumn ( 21 );
  //view->hideColumn ( 22 );
  view->hideColumn ( 23 );
  //view->hideColumn ( 24 );
  view->hideColumn ( 25 );
  view->hideColumn ( 26 );
  view->hideColumn ( 27 );
  view->hideColumn ( 28 );
  //view->hideColumn ( 29 );
  view->hideColumn ( 30 );
  view->hideColumn ( 31 );
  view->hideColumn ( 32 );
  view->hideColumn ( 33 );
  view->hideColumn ( 34 );
  view->hideColumn ( 35 );
  view->hideColumn ( 36 );
  view->hideColumn ( 37 );
  view->hideColumn ( 38 );
  view->hideColumn ( 39 );
  //view->hideColumn ( 40 );
  view->hideColumn ( 41 );
  view->hideColumn ( 42 );
  view->hideColumn ( 43 );
  view->hideColumn ( 44 );
  view->hideColumn ( 45 );
  view->hideColumn ( 46 );
  view->hideColumn ( 47 );
  view->hideColumn ( 48 );
  view->hideColumn ( 49 );
  view->hideColumn ( 50 );
  view->hideColumn ( 51 );
  view->hideColumn ( 52 );
  view->hideColumn ( 53 );
  view->hideColumn ( 54 );
  view->hideColumn ( 55 );
  view->hideColumn ( 56 );
  view->hideColumn ( 57 );
  view->hideColumn ( 58 );
  view->hideColumn ( 59 );
  view->hideColumn ( 60 );
  view->hideColumn ( 61 );
  view->hideColumn ( 62 );
  view->hideColumn ( 63 );
  view->hideColumn ( 64 );
  view->hideColumn ( 65 );
  //view->hideColumn ( 66 );
  view->hideColumn ( 67 );
  //view->hideColumn ( 68 );
  //view->hideColumn ( 69 );
  view->hideColumn ( 70 );
  view->hideColumn ( 71 );
  view->hideColumn ( 72 );
  view->hideColumn ( 73 );
  view->hideColumn ( 74 );
  view->hideColumn ( 75 );
  view->hideColumn ( 76 );
  view->hideColumn ( 77 );
  view->hideColumn ( 78 );
  view->hideColumn ( 79 );
  view->hideColumn ( 80 );
  view->hideColumn ( 81 );
  view->hideColumn ( 82 );
  view->hideColumn ( 83 );
*/
  QHeaderView *header = this->ui->view->header ();
  // Se define que el QTreeView permitirá un menú contextual personalizado en las cabeceras del mismo.
  header->setContextMenuPolicy ( Qt::CustomContextMenu );
  // Se define el tamaño mínimo permitido para cada columna del QTreeView.
  // Se pudiera guardar en base de datos para que el usuario pueda jugar con este valor a gusto
  header->setMinimumSectionSize ( 50 );

//connect ( exitAction, &QAction::triggered, qApp, &QCoreApplication::quit );
//connect ( this->ui->view->selectionModel (), &QItemSelectionModel::selectionChanged, this, &MainWindow::updateActions );
//connect ( actionsMenu, &QMenu::aboutToShow, this, &MainWindow::updateActions );
//connect ( insertRowAction, &QAction::triggered, this, &MainWindow::insertRow );
  //connect ( insertColumnAction, &QAction::triggered, this, &MainWindow::insertColumn );
//connect ( removeRowAction, &QAction::triggered, this, &MainWindow::removeRow );
//connect ( removeColumnAction, &QAction::triggered, this, &MainWindow::removeColumn );
  //connect ( insertChildAction, &QAction::triggered, this, &MainWindow::insertChild );
//connect ( header, &QTreeView::customContextMenuRequested, this, &MainWindow::setHeaderContextualMenu );



  /**
   * Y con la funcion que ya hice para obtener la columna estamos listos
   * isColumnHidden ( int column )
   * hideColumn (int column )
   * showColumn (int column )
   *
   * Crear todas las columnas,
   * luego ocultar las que no se van a ver,
   * y colocar checkable en true todas las que se ven
   * y colocar checkable en false todas las que se ven
   * para saber cuales se deben mostrar hay que guardar toda esa info en un archivo o base de datos.
   * hacer uso de sqlite o xml para esta tarea.
   */
  // TODO Redefinir la creación de estas acciones de forma mas automática y mas clara.
  /*contextualMenu = new QMenu ( this );
  QAction *action_1 = new QAction ( "Album", this ); // EN QUE CASO USARLO
  action_1->setCheckable ( true );
  action_1->setData ( "0" );
  connect ( action_1, &QAction::triggered, this, [=](){ this->showHideColumn ( action_1->data () ); } );
  contextualMenu->addAction ( action_1 );
  QAction *action_2 = new QAction ( "Movie", this ); // EN QUE CASO USARLO
  action_2->setCheckable ( true );
  action_2->setData ( "1" );
  connect ( action_2, &QAction::triggered, this, [=](){ this->showHideColumn ( action_2->data () ); } );
  contextualMenu->addAction ( action_2 );
  QAction *action_3 = new QAction ( "Show title", this ); // EN QUE CASO USARLO
  action_3->setCheckable ( true );
  action_3->setData ( "2" );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  contextualMenu->addAction ( action_3 );
  QAction *action_4 = new QAction ( "BPM", this );
  action_4->setCheckable ( true );
  action_4->setData ( "3" );
  connect ( action_4, &QAction::triggered, this, [=](){ this->showHideColumn ( action_4->data () ); } );
  contextualMenu->addAction ( action_4 );
  QAction *action_5 = new QAction ( "Composer", this );
  action_5->setCheckable ( true );
  action_5->setData ( "4" );
  connect ( action_5, &QAction::triggered, this, [=](){ this->showHideColumn ( action_5->data () ); } );
  contextualMenu->addAction ( action_5 );
  QAction *action_6 = new QAction ( "Content type", this );
  action_6->setCheckable ( true );
  action_6->setData ( "5" );
  connect ( action_6, &QAction::triggered, this, [=](){ this->showHideColumn ( action_6->data () ); } );
  contextualMenu->addAction ( action_6 );
  QAction *action_7 = new QAction ( "Copyright message", this );
  action_7->setCheckable ( true );
  action_7->setData ( "6" );
  connect ( action_7, &QAction::triggered, this, [=](){ this->showHideColumn ( action_7->data () ); } );
  contextualMenu->addAction ( action_7 );
  QAction *action_8 = new QAction ( "Date of recording", this );
  action_8->setCheckable ( true );
  action_8->setData ( "7" );
  connect ( action_8, &QAction::triggered, this, [=](){ this->showHideColumn ( action_8->data () ); } );
  contextualMenu->addAction ( action_8 );
  QAction *action_9 = new QAction ( "Playlist delay", this );
  action_9->setCheckable ( true );
  action_9->setData ( "8" );
  connect ( action_9, &QAction::triggered, this, [=](){ this->showHideColumn ( action_9->data () ); } );
  contextualMenu->addAction ( action_9 );
  /*QAction *action_1 = new QAction ( "Encoded by", this );
  action_1->setCheckable ( true );
  connect ( action_1, &QAction::triggered, this, [=](){ this->showHideColumn ( action_1->data () ); } );
  contextualMenu->addAction ( action_1 );
  QAction *action_2 = new QAction ( "Lyricist", this ); // EN QUE CASO USARLO
  action_2->setCheckable ( true );
  connect ( action_2, &QAction::triggered, this, [=](){ this->showHideColumn ( action_2->data () ); } );
  contextualMenu->addAction ( action_2 );
  QAction *action_3 = new QAction ( "Text writer", this ); // EN QUE CASO USARLO
  action_3->setCheckable ( true );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  contextualMenu->addAction ( action_3 );
  QAction *action_1 = new QAction ( "File type", this );
  action_1->setCheckable ( true );
  connect ( action_1, &QAction::triggered, this, [=](){ this->showHideColumn ( action_1->data () ); } );
  contextualMenu->addAction ( action_1 );
  QAction *action_2 = new QAction ( "Action", this );
  action_2->setCheckable ( true );
  connect ( action_2, &QAction::triggered, this, [=](){ this->showHideColumn ( action_2->data () ); } );
  contextualMenu->addAction ( action_2 );
  QAction *action_3 = new QAction ( "Time of recording", this );
  action_3->setCheckable ( true );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  contextualMenu->addAction ( action_3 );
  QAction *action_1 = new QAction ( "Content group description", this );
  action_1->setCheckable ( true );
  connect ( action_1, &QAction::triggered, this, [=](){ this->showHideColumn ( action_1->data () ); } );
  contextualMenu->addAction ( action_1 );
  QAction *action_2 = new QAction ( "Title", this ); // EN QUE CASO USARLO
  action_2->setCheckable ( true );
  connect ( action_2, &QAction::triggered, this, [=](){ this->showHideColumn ( action_2->data () ); } );
  contextualMenu->addAction ( action_2 );
  QAction *action_3 = new QAction ( "songname", this ); // EN QUE CASO USARLO
  action_3->setCheckable ( true );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  contextualMenu->addAction ( action_3 );
  QAction *action_1 = new QAction ( "content description", this ); // EN QUE CASO USARLO
  action_1->setCheckable ( true );
  connect ( action_1, &QAction::triggered, this, [=](){ this->showHideColumn ( action_1->data () ); } );
  contextualMenu->addAction ( action_1 );
  QAction *action_2 = new QAction ( "Subtitle", this ); // EN QUE CASO USARLO
  action_2->setCheckable ( true );
  connect ( action_2, &QAction::triggered, this, [=](){ this->showHideColumn ( action_2->data () ); } );
  contextualMenu->addAction ( action_2 );
  QAction *action_3 = new QAction ( "Description refinement", this ); // EN QUE CASO USARLO
  action_3->setCheckable ( true );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  contextualMenu->addAction ( action_3 );
  QAction *action_1 = new QAction ( "Initial key", this );
  action_1->setCheckable ( true );
  connect ( action_1, &QAction::triggered, this, [=](){ this->showHideColumn ( action_1->data () ); } );
  contextualMenu->addAction ( action_1 );
  QAction *action_2 = new QAction ( "Language(s) used in the audio", this );
  action_2->setCheckable ( true );
  connect ( action_2, &QAction::triggered, this, [=](){ this->showHideColumn ( action_2->data () ); } );
  contextualMenu->addAction ( action_2 );
  QAction *action_3 = new QAction ( "Length", this );
  action_3->setCheckable ( true );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  contextualMenu->addAction ( action_3 );
  QAction *action_1 = new QAction ( "Media type of audio original", this );
  action_1->setCheckable ( true );
  connect ( action_1, &QAction::triggered, this, [=](){ this->showHideColumn ( action_1->data () ); } );
  contextualMenu->addAction ( action_1 );
  QAction *action_2 = new QAction ( "Original album", this );// EN QUE CASO USARLO
  action_2->setCheckable ( true );
  connect ( action_2, &QAction::triggered, this, [=](){ this->showHideColumn ( action_2->data () ); } );
  contextualMenu->addAction ( action_2 );
  QAction *action_3 = new QAction ( "movie", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  contextualMenu->addAction ( action_3 );
  QAction *action_1 = new QAction ( "show title", this );// EN QUE CASO USARLO
  action_1->setCheckable ( true );
  connect ( action_1, &QAction::triggered, this, [=](){ this->showHideColumn ( action_1->data () ); } );
  contextualMenu->addAction ( action_1 );
  QAction *action_2 = new QAction ( "Original filename", this );
  action_2->setCheckable ( true );
  connect ( action_2, &QAction::triggered, this, [=](){ this->showHideColumn ( action_2->data () ); } );
  contextualMenu->addAction ( action_2 );
  QAction *action_3 = new QAction ( "Original lyricist(s)", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  contextualMenu->addAction ( action_3 );
  QAction *action_1 = new QAction ( "text writer(s)", this );// EN QUE CASO USARLO
  action_1->setCheckable ( true );
  connect ( action_1, &QAction::triggered, this, [=](){ this->showHideColumn ( action_1->data () ); } );
  contextualMenu->addAction ( action_1 );
  QAction *action_2 = new QAction ( "Original artist(s)", this );// EN QUE CASO USARLO
  action_2->setCheckable ( true );
  connect ( action_2, &QAction::triggered, this, [=](){ this->showHideColumn ( action_2->data () ); } );
  contextualMenu->addAction ( action_2 );
  QAction *action_3 = new QAction ( "performer(s)", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Original release year", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "File owner", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "licensee", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Lead performer(s)", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Soloist(s)", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Band", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "orchestra", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "accompaniment", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Conductor", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "performer refinement", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Interpreted", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "remixed", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "otherwise modified by", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Part of a set", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Publisher", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Track number", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Position in set", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Recording dates", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Internet radio station name", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Internet radio station owner", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Size", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "ISRC", this );
  action_3->setToolTip ( "international standard recording code" ); //==================================================
  // ESTE TOOLTIPS ES PARA UTILIZARLO EN LA CABECERA DE CADA COLUMNA DEL QTREEVIEW
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Software", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Hardware and settings used for encoding", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Year of the recording", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "User defined text information", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Commercial information", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Copyright", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Legal information", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Official audio file webpage", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Official artist", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "performer webpage", this );// EN QUE CASO USARLO
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Official audio source webpage", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Official internet radio station homepage", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Payment", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "Publishers official webpage", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );
  QAction *action_3 = new QAction ( "User defined URL link", this );
  action_3->setCheckable ( true );
  contextualMenu->addAction ( action_3 );
  connect ( action_3, &QAction::triggered, this, [=](){ this->showHideColumn ( action_3->data () ); } );*/

  /*if ( header->restoreState ( configData->getHeaderState () ) ) {

    qInfo () << "Aparentemente se restauró el estado anterior de las cabeceras";

  } else {

    qInfo () << "Aparentemente NO se restauró el estado anterior de las cabeceras";
  }*/

  this->ui->view->setAnimated ( true );
  this->ui->view->setSortingEnabled ( true );
  //view->resizeColumnToContents ( 0 );
  // Se ajusta el tamaño de la columna al contenido de las celdas.
  /*for ( int column = 0; column < model->columnCount (); ++column ) {

    this->ui->view->resizeColumnToContents ( column );
  }*/
  // TODO Esto es para que la última columna de reduzca al tamaño mínimo ajustado por el ancho del texto
  this->ui->view->header ()->setStretchLastSection ( true );
  //table->horizontalHeader ()->setStretchLastSection ( true );
  //this->ui->view->setModel ( proxyModel );

  //updateActions ();
}

MainWindow::~MainWindow () {

  delete this->ui;
}

void MainWindow::closeEvent ( QCloseEvent *event ) {
/*
  QByteArray headerView = view->header ()->saveState ();
  qInfo () << headerView;
  this->configData->setLanguage ( 2 );
  this->configData->setHeaderState ( view->header ()->saveState () );
  RockolaUtils::saveSettings ( this->rockolaDbConnection->getConnection (), this->configData );
*/
  event->accept ();
  //qInfo () << headerView.toStdString ();
  //this->mainWindowEvents->closeEvent ( event );
}

void MainWindow::setHeaderContextualMenu ( QPoint pos ) {
/*
  columnIndex = pos;
  contextualMenu->popup ( this->view->header ()->mapToGlobal ( pos ) );
*/
}

void MainWindow::checkedUncheked ( bool signal, QAction *action ) {
/*
  action->setCheckable ( !signal );
*/
}

RockolaDbManager *MainWindow::getRockolaDbConnection () const {

  return this->rockolaDbConnection;
}

void MainWindow::setRockolaDbConnection ( RockolaDbManager *value ) {

  this->rockolaDbConnection = value;
}

void MainWindow::insertChild () {
/*
  QModelIndex index = view->selectionModel ()->currentIndex ();
  QAbstractItemModel *model = view->model ();

  if ( model->columnCount ( index ) == 0 ) {

    if ( !model->insertColumn ( 0, index ) ) {

      return;
    }
  }
  if ( !model->insertRow ( 0, index ) ) {

    return;
  }
  for ( int column = 0; column < model->columnCount ( index ); ++column ) {

    QModelIndex child = model->index ( 0, column, index );
    model->setData ( child, QVariant ( "[No data]" ), Qt::EditRole );
    if ( !model->headerData ( column, Qt::Horizontal ).isValid () ) {

      model->setHeaderData ( column, Qt::Horizontal, QVariant ( "[No header]" ), Qt::EditRole );
    }
  }
  view->selectionModel ()->setCurrentIndex ( model->index ( 0, 0, index ), QItemSelectionModel::ClearAndSelect );
  updateActions ();
*/
}

bool MainWindow::insertColumn ( QString header ) {
/*
  QAbstractItemModel *model = view->model ();
  int column = view->indexAt ( columnIndex ).column ();
  // Insert a column in the parent item.
  bool changed = model->insertColumn ( column + 1 );
  if ( changed ) {

    model->setHeaderData ( column + 1, Qt::Horizontal, QVariant ( header ), Qt::EditRole );
  }
  updateActions ();
  return changed;
*/
}

void MainWindow::showHideColumn ( QVariant header ) {
/*
  if ( view->isColumnHidden ( header.toInt () ) ) {

    view->showColumn ( header.toInt () );

  } else {

    view->hideColumn ( header.toInt () );
  }
*/
}

void MainWindow::insertRow () {
/*
  QModelIndex index = view->selectionModel ()->currentIndex ();
  QAbstractItemModel *model = view->model ();

  if ( !model->insertRow ( index.row () + 1, index.parent () ) ) {

    return;
  }
  updateActions ();
  for ( int column = 0; column < model->columnCount ( index.parent () ); ++column ) {

    QModelIndex child = model->index ( index.row () + 1, column, index.parent () );
    model->setData ( child, QVariant ( "[No data]" ), Qt::EditRole );
  }
*/
}

bool MainWindow::removeColumn () {
/*
  QAbstractItemModel *model = view->model ();
  int column = view->selectionModel ()->currentIndex ().column ();

  // Insert columns in each child of the parent item.
  bool changed = model->removeColumn ( column );
  if ( changed ) {

    updateActions ();
  }
  return changed;
*/
}

void MainWindow::removeRow () {
/*
  QModelIndex index = view->selectionModel ()->currentIndex ();
  QAbstractItemModel *model = view->model ();
  if ( model->removeRow ( index.row (), index.parent () ) ) {

    updateActions ();
  }
*/
}

void MainWindow::updateActions () {
/*
  bool hasSelection = !view->selectionModel ()->selection ().isEmpty ();
  removeRowAction->setEnabled ( hasSelection );
  removeColumnAction->setEnabled ( hasSelection );

  bool hasCurrent = view->selectionModel ()->currentIndex ().isValid ();
  insertRowAction->setEnabled ( hasCurrent );
  insertColumnAction->setEnabled ( hasCurrent );

  if ( hasCurrent ) {

    view->closePersistentEditor ( view->selectionModel ()->currentIndex () );
    int row = view->selectionModel ()->currentIndex ().row ();
    int column = view->selectionModel ()->currentIndex ().column ();
    if ( view->selectionModel ()->currentIndex ().parent ().isValid () ) {

      statusBar ()->showMessage ( tr ( "Position: (%1,%2)" ).arg ( row ).arg ( column ) );

    } else {

      statusBar ()->showMessage ( tr ( "Position: (%1,%2) in top level" ).arg ( row ).arg ( column ) );
    }
  }
*/
}
