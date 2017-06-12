#ifndef PLACEDIALOG_H
#define PLACEDIALOG_H

#include <QDialog>
#include "address.h"
namespace Ui {
class PlaceDialog;
}

class PlaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlaceDialog(QWidget *parent = 0);
    ~PlaceDialog();

private slots:
    void on_buttonBox_accepted();
    void onTextChanged(const QString&);
signals:
    void enteredAddress(Address);

private:
    Ui::PlaceDialog *ui;
};

#endif // PLACEDIALOG_H
