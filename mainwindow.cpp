#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include "placedialog.h"

void MainWindow::createMapView(){
    QFile htmlResourceFile(":/MapHTML.html");
    htmlResourceFile.open(QIODevice::ReadOnly|QIODevice::Text);
    auto html = QTextStream(&htmlResourceFile).readAll();
    mapView = new QWebEngineView();
    mapView->page()->setWebChannel(&webchannel);
    webchannel.registerObject(QStringLiteral("qtCallable"),adaptor);
    mapView->setHtml(html);
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    adaptor=new ListJSAdaptor(ui->listWidget);
    createMapView();
    ui->gridLayout->addWidget(mapView,2,1);
    mapView->show();
}

MainWindow::~MainWindow()
{
    delete adaptor;
    delete mapView;
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    PlaceDialog* dial = new PlaceDialog();
    dial->setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(dial,&PlaceDialog::enteredAddress,
                     this,&MainWindow::user_enteredAddress);
    dial->show();
}

QString createAddressName(const Address& data){
    auto newItem = QString("г. ")+data.getCity()+
            QString(", ул. ")+data.getStreet()+
            QString(", "+data.getHouse());
    const auto corpus = data.getCorpus();
    if(corpus.length()>0)
        newItem+=QString("к")+corpus;
    return newItem;
}

void MainWindow::user_enteredAddress(Address data){
    const auto newItem = createAddressName(data);
    mapView->page()->runJavaScript(
                QString("addPlacemark(\"")+
                newItem+QString("\");"));
}
