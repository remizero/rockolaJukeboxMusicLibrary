#ifndef CONFIGDATA_H
#define CONFIGDATA_H

#include <QObject>

class ConfigData : public QObject {

    Q_OBJECT

  public:
    explicit ConfigData ( QObject *parent = nullptr );

            int getHeaderMinimumSectionSize () const;
     QByteArray getHeaderState ();
           bool getHeaderStretchLastSection () const;
            int getHeaderTooltipDuration () const;
            int getId () const;
            int getLanguage ();
           bool isModified () const;
           void setId ( int value );
           void setLanguage ( int language );
           void setHeaderMinimumSectionSize ( int value );
           void setHeaderState ( QByteArray headerState );
           void setHeaderStretchLastSection ( bool value );
           void setHeaderTooltipDuration ( int value );

  signals:

  public slots:

  private :
           int headerMinimumSectionSize;
    QByteArray headerState;
          bool headerStretchLastSection;
           int headerTooltipDuration;
           int id;
           int language;
          bool modified;
           int modifiedCounter;

          void setModified ();
};

#endif // CONFIGDATA_H
