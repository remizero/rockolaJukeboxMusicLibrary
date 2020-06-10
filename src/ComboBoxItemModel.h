#ifndef COMBOBOXMODEL_H
#define COMBOBOXMODEL_H

#include <QMetaType>
#include <QObject>

class ComboBoxItemModel {

  public:
    ComboBoxItemModel ();
    ~ComboBoxItemModel ();

    QString getDescription () const;
        int getId () const;
    QString getValue () const;
       void setDescription ( const QString &value );
       void setId ( int value );
       void setValue ( const QString &value );

  private:
        int id;
    QString value;
    QString description;
};
Q_DECLARE_METATYPE ( ComboBoxItemModel )

#endif // COMBOBOXMODEL_H
