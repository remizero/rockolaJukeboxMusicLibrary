#ifndef CONFIGDATA_H
#define CONFIGDATA_H

#include <QObject>

class ConfigDataMDL : public QObject {

    Q_OBJECT

  public:
    explicit ConfigDataMDL ( QObject *parent = nullptr );

            int getHeaderMinimumSectionSize () const;
     QByteArray getHeaderState ();
           bool getHeaderStretchLastSection () const;
            int getHeaderTooltipDuration () const;
            int getId () const;
            int getLanguage ();
            int getLibraryView () const;
           bool isModified () const;
           void setId ( int value );
           void setLanguage ( int language );
           void setLibraryView ( int value );
           void setHeaderMinimumSectionSize ( int value );
           void setHeaderState ( QByteArray headerState );
           void setHeaderStretchLastSection ( bool value );
           void setHeaderTooltipDuration ( int value );

  signals:

  public slots:

  private :
           int headerMinimumSectionSize = 0;
    QByteArray headerState = "";
          bool headerStretchLastSection = false;
           int headerTooltipDuration = 0;
           int id;
           int language = 0;
           int libraryView = 0;
          bool modified = false;
           //int modifiedCounter = 0;

          void setModified ();
};

#endif // CONFIGDATA_H
