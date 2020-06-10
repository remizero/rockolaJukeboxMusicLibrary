#ifndef ROCKOLAHEADERTOOLTIPDLG_H
#define ROCKOLAHEADERTOOLTIPDLG_H

#include <QAbstractItemView>
#include <QHelpEvent>
#include <QModelIndex>
#include <QString>
#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>
#include <QToolTip>

class RockolaHeaderTooltipDLG : public QStyledItemDelegate {

    Q_OBJECT

  public:
    RockolaHeaderTooltipDLG ( QObject* parent );
    ~RockolaHeaderTooltipDLG ();

  public slots:
      bool helpEvent ( QHelpEvent *e, QAbstractItemView *view, const QStyleOptionViewItem &option, const QModelIndex &index );
};

#endif // ROCKOLAHEADERTOOLTIPDLG_H
