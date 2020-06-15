#ifndef LIBRARYVIEWMDL_H
#define LIBRARYVIEWMDL_H

#include <QObject>

class LibraryViewMDL : public QObject {

    Q_OBJECT

  public:
    explicit LibraryViewMDL ( QObject *parent = nullptr );

    QString getDataView () const;
    QString getDescription () const;
        int getId () const;
    QString getLibraryView () const;
       void setDataView ( const QString &value );
       void setDescription ( const QString &value );
       void setId ( int value );
       void setLibraryView ( const QString &value );

  private:
    QString dataView;
    QString description;
        int id;
    QString libraryView;
};

#endif // LIBRARYVIEWMDL_H
