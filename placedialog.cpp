#include "placedialog.h"
#include "ui_placedialog.h"
#include <QPushButton>
PlaceDialog::PlaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlaceDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->City,&QLineEdit::textChanged,
                     this,&PlaceDialog::onTextChanged);
    QObject::connect(ui->Street,&QLineEdit::textChanged,
                     this,&PlaceDialog::onTextChanged);
    QObject::connect(ui->House,&QLineEdit::textChanged,
                     this,&PlaceDialog::onTextChanged);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

PlaceDialog::~PlaceDialog()
{
    delete ui;
}
void PlaceDialog::onTextChanged(const QString &str){
    if(ui->City->text().isEmpty()
            ||ui->House->text().isEmpty()
            ||ui->Street->text().isEmpty())
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    else
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}

void PlaceDialog::on_buttonBox_accepted()
{

    emit enteredAddress(Address(ui->City->text(),
                                      ui->Street->text(),
                                      ui->House->text(),
                                      ui->Corpus->text()));
}
