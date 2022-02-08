#include "graphwindow.h"
#include "ui_graphwindow.h"
#include <QPixmap>
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QString>
GraphWindow::GraphWindow(const QString& dot_path,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphWindow)
{
    ui->setupUi(this);
   QString now = dot_path;
   QString ed = now.replace("/test.dot","");

    QDir::setCurrent(ed);
    system("dot -Tpng -O test.dot");
   QString t = QString("%1.png").arg(dot_path);
    //qInfo() << t;
    //qInfo() << ed;
    QPixmap graph(t);
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(graph.scaled(w,h,Qt::KeepAspectRatio));
    //ui->label->setPixmap(graph);
}

GraphWindow::~GraphWindow()
{
    delete ui;
}
