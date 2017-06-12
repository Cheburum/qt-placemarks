#ifndef JSCALLABLE_H
#define JSCALLABLE_H
#include <QObject>
#include <QString>
class JSCallable : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE virtual void call(QString);
    explicit JSCallable(QObject *parent = 0);
signals:

public slots:
};

#endif // JSCALLABLE_H
