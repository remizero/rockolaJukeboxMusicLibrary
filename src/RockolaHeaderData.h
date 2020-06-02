#ifndef ROCKOLAHEADERMODEL_H
#define ROCKOLAHEADERMODEL_H

#include <QMetaType>
#include <QString>

class RockolaHeaderData {

  public:
    RockolaHeaderData ();

    QString getCodFrame () const;
    QString getDescription () const;
    QString getHeader () const;
    int getId () const;
    void setCodFrame ( const QString &value );
    void setDescription ( const QString &value );
    void setHeader ( const QString &value );
    void setId ( int value );

  private:
    int id;
    QString codFrame;
    QString header;
    QString description;
};
Q_DECLARE_METATYPE ( RockolaHeaderData )

#endif // ROCKOLAHEADERMODEL_H
