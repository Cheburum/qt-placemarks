#include "listjsadaptor.h"
#include <QDebug>
ListJSAdaptor::ListJSAdaptor(QListWidget* ui):ui(ui)
{

}
void ListJSAdaptor::call(QString str){
    qDebug()<<str;
    ui->addItem(str);
}
