#ifndef CONFIGDATA_H
#define CONFIGDATA_H

#include <QObject>

class ConfigData : public QObject {

    Q_OBJECT

  public:
    explicit ConfigData ( QObject *parent = nullptr );

            int getId () const;
            int getLanguage ();
     QByteArray getHeaderState ();
           bool isModified () const;
           void setId ( int value );
           void setLanguage ( int language );
           void setHeaderState ( QByteArray headerState );

  signals:

  public slots:

  private :
    QByteArray headerState;
           int id;
           int language;
          bool modified;
           int modifiedCounter;

          void setModified ();
};

#endif // CONFIGDATA_H
