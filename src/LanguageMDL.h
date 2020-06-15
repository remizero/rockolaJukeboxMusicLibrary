#ifndef LANGUAGEMDL_H
#define LANGUAGEMDL_H

#include <QObject>

class LanguageMDL : public QObject {

    Q_OBJECT

  public:
    explicit LanguageMDL ( QObject *parent = nullptr );

    QString getDescription  () const;
    int getId () const;
    QString getIso_369_1 () const;
    QString getIso_369_2 () const;
    void setDescription ( const QString &value );
    void setId ( int value );
    void setIso_369_1 ( const QString &value );
    void setIso_369_2 ( const QString &value );

  signals:

  public slots:

  private:
    QString description;
    int id;
    QString iso_369_1;
    QString iso_369_2;
};

#endif // LANGUAGEMDL_H
