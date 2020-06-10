#ifndef ROCKOLAMAINWINDOW_H
#define ROCKOLAMAINWINDOW_H


#include <QCloseEvent>
#include <QMainWindow>
#include <QMenu>
#include <QPoint>
#include <QSortFilterProxyModel>

#include "ComboBoxDelegate.h"
#include "ConfigData.h"
#include "RockolaDbManager.h"
#include "RockolaTreeMDL.h"
#include "RockolaUtils.h"
#include "SpinBoxDelegate.h"
#include "StarDelegate.h"
#include "ui_MainWindow.h"

namespace Ui {

  class MainWindow;
}

class RockolaMainWindow : public QMainWindow {

    Q_OBJECT

  public:
    explicit RockolaMainWindow ( RockolaDbManager *dbConnection, QWidget *parent = nullptr );
    ~RockolaMainWindow () override;

    RockolaDbManager *getRockolaDbConnection () const;
                void setRockolaDbConnection ( RockolaDbManager *value );

  signals:

  public slots:

  private:
                  ConfigData *configData;
                       QMenu *contextualMenu;
                      QPoint columnIndex;
    QList<RockolaHeaderData> headersDataList;
       QSortFilterProxyModel *proxyModel; // PARA ORDENAR LAS COLUMNAS DE LA BIBLIOTECA MUSICAL
            RockolaDbManager *rockolaDbConnection;
              RockolaTreeMDL *rockolaTreeMDL;
              Ui::MainWindow *ui;

                     void setUpDelegates ( QList<RockolaHeaderData> headersDataList );
                     void setUpHeaders ();

  protected:
    void closeEvent ( QCloseEvent *event ) override;
};

#endif // ROCKOLAMAINWINDOW_H
