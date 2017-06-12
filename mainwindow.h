#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "listjsadaptor.h"
#include <QMainWindow>
#include <QWebEngineView>
#include <QWebChannel>
#include "address.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void addStringToList(QString);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void user_enteredAddress(Address data);
private:
    Ui::MainWindow *ui;
    QWebEngineView *mapView;
    QWebChannel webchannel;
    ListJSAdaptor *adaptor;
    void createMapView();
    void createWebChannel();
};

#endif // MAINWINDOW_H
