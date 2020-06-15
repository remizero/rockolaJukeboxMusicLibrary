#ifndef ROCKOLAUTILS_H
#define ROCKOLAUTILS_H

#include <QDebug>
#include <QDir>
#include <QList>
#include <QMetaEnum>
#include <QObject>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include "ComboBoxItemModel.h"
#include "ConfigDataMDL.h"
#include "LanguageMDL.h"
#include "LibraryViewMDL.h"
#include "RockolaHeaderData.h"

class RockolaUtils : public QObject {

    Q_OBJECT

  public:
    explicit RockolaUtils ( QObject *parent = nullptr );

    enum enumExtensions {

      AAC = 0,
      AIFF,
      APE,
      ASF,
      AU,
      FLAC,
      M4A,
      M4B,
      M4P,
      MIDI,
      MOD,
      MP2,
      MP3,
      MP4,
      MPC,
      OGA,
      OGG,
      OPUS,
      RAW,
      WAV,
      WEBM,
      WMA
    };
    Q_ENUM ( enumExtensions )

    enum enumHeaders {

      UFID = 0,
      TALB,
      TIT1,
      TIT2,
      TIT3,
      TOAL,
      TPOS,
      TRCK,
      TSRC,
      TSST,
      TCOM,
      TENC,
      TEXT,
      TIPL,
      TMCL,
      TOLY,
      TOPE,
      TPE1,
      TPE2,
      TPE3,
      TPE4,
      TXXX,
      TBPM,
      TCON,
      TFLT,
      TKEY,
      TLAN,
      TLEN,
      TMED,
      TMOO,
      TCOP,
      TOWN,
      TPRO,
      TPUB,
      TRSN,
      TRSO,
      TDEN,
      TDLY,
      TDOR,
      TDRC,
      TDRL,
      TDTG,
      TOFN,
      TSOA,
      TSOP,
      TSOT,
      TSSE,
      WCOM,
      WCOP,
      WOAF,
      WOAR,
      WOAS,
      WORS,
      WPAY,
      WPUB,
      WXXX,
      MCDI,
      ETCO,
      MLLT,
      SYTC,
      USLT,
      SYLT,
      COMM,
      RVA2,
      EQU2,
      RVRB,
      APIC,
      GEOB,
      PCNT,
      POPM,
      RBUF,
      AENC,
      LINK,
      POSS,
      USER,
      OWNE,
      COMR,
      ENCR,
      GRID,
      PRIV,
      SIGN,
      SEEK,
      ASPI
    };
    Q_ENUM ( enumHeaders )

    static QList<ComboBoxItemModel> getMoodsData ( QSqlDatabase connection, QString language );
                 static QStringList getStringListEnum ();
                         static int getEnumHeadersValue ( const char *key, bool *ok = nullptr );
                 static LanguageMDL *loadCurrentLanguage ( QSqlDatabase connection, int language );
    static QList<RockolaHeaderData> loadHeaders ( QSqlDatabase connection, QString language );
          static QList<LanguageMDL> loadLanguages ( QSqlDatabase connection, QString language );
              static LibraryViewMDL *loadLibraryView ( QSqlDatabase connection, int libraryViewID, QString language );
               static ConfigDataMDL *loadSettings ( QSqlDatabase connection );
                        static void saveSettings ( QSqlDatabase connection, ConfigDataMDL *configData );

  signals:

  public slots:
};

#endif // ROCKOLAUTILS_H
