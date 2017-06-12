#ifndef UIMAINWINJSADAPTOR_H
#define UIMAINWINJSADAPTOR_H

#include "jscallable.h"
#include <QListWidget>

class ListJSAdaptor : public JSCallable
{
private:
    QListWidget *ui;
public:

    ListJSAdaptor(QListWidget*);
    void call(QString);
};

#endif // UIMAINWINJSADAPTOR_H
