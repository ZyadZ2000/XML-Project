#include "users_on_social_network.h"
#include "ui_users_on_social_network.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include"XML.h"
#include <iostream>
#include <sstream>
#include <QPixmap>
#include <QDir>


bool f=false;
QString path;
bool Saved=false;
Users_On_Social_Network::Users_On_Social_Network(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Users_On_Social_Network)
{
    ui->setupUi(this);

    //this->setCentralWidget(ui->plainTextEdit);
    ui->comboBox->addItem("Check Consistency!");
    ui->comboBox->addItem("Formatting XML!");
    ui->comboBox->addItem("Convert to JSON!");
    ui->comboBox->addItem("Compressing the file!");
    ui->comboBox->addItem("VISUALIZE!");
}

Users_On_Social_Network::~Users_On_Social_Network()
{
    delete ui;
}







void Users_On_Social_Network::on_pushButton_clicked()
{
    QString chosen = ui->comboBox->currentText();
    if(chosen == "VISUALIZE!"){
        //Check Consistency first
        //We Must call the parsing function
        //Save the return string as .dot file and tell user to name it as "test.dot"
          QString r = ui->plainTextEdit->toPlainText();
          string r_s =r.toStdString();
          r_s=XML_Consistency(r_s);
          string vis=visual(r_s);







        dot_path = QFileDialog::getSaveFileName(this,"Please save your file and name it (test.dot)");
        QFile file(dot_path);
        if(!file.open(QFile::WriteOnly|QFile::Text)){
            QMessageBox::warning(this,"Not Found","Your File is not find");
        }
        QTextStream out(&file);
        QString text =QString::fromStdString(vis) ;
         //QString text = ui->plainTextEdit->toPlainText();
        out<<text;
        file.flush();
        file.close();

        G = new GraphWindow(dot_path,this);
        G->show();
    }
    if(chosen == "Check Consistency!"){
        QString current;
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Choose File","If you want to operate on the current text press YES, press NO for operating on the original file",QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes){
            current = ui->plainTextEdit->toPlainText();
        }
        if(reply == QMessageBox::No){
            current = Original;
        ui->plainTextEdit->setPlainText(current);

        }
        string ss=current.toStdString();
        ss =XML_Consistency(ss);
        QString current_new = QString::fromStdString(ss);
        current=current_new;
        f=true;
        ui->plainTextEdit->setPlainText(current);


    }
    if(chosen == "Formatting XML!"){
        QString current;
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Choose File","If you want to operate on the current text press YES, press NO for operating on the original file",QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes){
            current = ui->plainTextEdit->toPlainText();
        }
        bool NO=false;
        if(reply == QMessageBox::No){
            current = Original;
        ui->plainTextEdit->setPlainText(current);
        NO=true;

        }
        if(!Saved && !NO){
             QMessageBox::warning(this,"Not Saved","Save it First then Try again");
        }
        if(Saved || NO){
            QFile file(path);
            if(!file.open(QFile::WriteOnly|QFile::Text)){
                QMessageBox::warning(this,"Not Found","Your File is not find");
            }
            QTextStream out(&file);
            QString text = ui->plainTextEdit->toPlainText();
            out<<text;
            file.flush();
            file.close();
            Saved=false;


        if(f){

            string path_ss=path.toStdString();
           string ss=read(path_ss);
            ss =XML_Format(ss);
            QString current_new = QString::fromStdString(ss);
            current=current_new;
             ui->plainTextEdit->setPlainText(current);

        }
        else{
            string path_ss=path.toStdString();
            string ss=read(path_ss);
            ss =XML_Consistency(ss);
            ss =XML_Format(ss);
            QString current_new = QString::fromStdString(ss);
            current=current_new;
             ui->plainTextEdit->setPlainText(current);

        }
        }


    }
    if(chosen == "Convert to JSON!"){
        QString current;
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Choose File","If you want to operate on the current text press YES, press NO for operating on the original file",QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes){
            current = ui->plainTextEdit->toPlainText();
        } bool NO=false;
        if(reply == QMessageBox::No){
            current = Original;
        ui->plainTextEdit->setPlainText(current);
        NO=true;

        }
        if(!Saved && !NO){
             QMessageBox::warning(this,"Not Saved","Save it First then Try again");
        }
        if(Saved || NO){
            QFile file(path);
            if(!file.open(QFile::WriteOnly|QFile::Text)){
                QMessageBox::warning(this,"Not Found","Your File is not find");
            }
            QTextStream out(&file);
            QString text = ui->plainTextEdit->toPlainText();
            out<<text;
            file.flush();
            file.close();
             Saved=false;

        if(f){
            string ss=current.toStdString();
            ss =XML_TO_JSON(ss);
            QString current_new = QString::fromStdString(ss);


            QString file_name = QFileDialog::getSaveFileName(this,"Choose a place to Save");
            QFile file(file_name);
            if(!file.open(QFile::WriteOnly|QFile::Text)){
                QMessageBox::warning(this,"Not Found","Your File is not find");
            }
            QTextStream out(&file);
            QString text = current_new;
            out<<text;
            file.flush();
            file.close();


        }
        else{
            string ss=current.toStdString();
            ss =XML_Consistency(ss);
            ss =XML_TO_JSON(ss);
            QString current_new = QString::fromStdString(ss);



            QString file_name = QFileDialog::getSaveFileName(this,"Choose a place to Save");
            QFile file(file_name);
            if(!file.open(QFile::WriteOnly|QFile::Text)){
                QMessageBox::warning(this,"Not Found","Your File is not find");
            }
            QTextStream out(&file);
             QString text = current_new;
            out<<text;
            file.flush();
            file.close();


        }
        }



    }
    if(chosen == "Compressing the file!"){
        QString current;
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Choose File","If you want to operate on the current text press YES, press NO for operating on the original file",QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes){
            current = ui->plainTextEdit->toPlainText();
        }
        if(reply == QMessageBox::No){
            current = Original;
        ui->plainTextEdit->setPlainText(current);

        }
       /* if(!Saved){
            QFile file(path);
            if(!file.open(QFile::WriteOnly|QFile::Text)){
                QMessageBox::warning(this,"Not Found","Your File is not find");
            }
            QTextStream out(&file);
            QString text = ui->plainTextEdit->toPlainText();
            out<<text;
            file.flush();
            file.close();
             Saved=false;}*/
        string current_s=current.toStdString();
        current_s=XML_Consistency(current_s);
        vector<int> v  = encoding(current.toStdString());
       stringstream ss_ss;
        copy( v.begin(), v.end(), ostream_iterator<int>(ss_ss, " "));
        string compressed = ss_ss.str();
        QString file_name = QFileDialog::getSaveFileName(this,"Choose a place to Save");
        QFile file(file_name);
        if(!file.open(QFile::WriteOnly|QFile::Text)){
            QMessageBox::warning(this,"Not Found","Your File is not find");
        }
        QTextStream out(&file);
        QString text =QString::fromStdString(compressed) ;
        out<<text;
        file.flush();
        file.close();

    }
}


void Users_On_Social_Network::on_actionOpen_triggered()
{
    QString filter = "All Files (*.*) ;; XML File (*.xml)";
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file","C://",filter);
    path=file_name;
    file_path = file_name;
    //Read the file after the opening
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"Not Found","Your File is not find");
        return;
    }
    QTextStream in(&file);
    Original = in.readAll();
    ui->plainTextEdit->setPlainText(Original);
    file.close();

}


void Users_On_Social_Network::on_actionSave_As_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Choose a place to Save");
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"Not Found","Your File is not find");
    }
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void Users_On_Social_Network::on_actionSave_triggered()
{

    QFile file(path);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"Not Found","Your File is not find");
    }
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
    Saved=true;
}


void Users_On_Social_Network::on_actionOpen_compressed_file_triggered()
{
    QString filter = "All Files (*.*) ;; XML File (*.xml)";
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file","C://",filter);
    path=file_name;
    file_path = file_name;
    //Read the file after the opening
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"Not Found","Your File is not find");
        return;
    }
    QTextStream in(&file);
    QString com = in.readAll();
    string com_s=com.toStdString();
    stringstream iss( com_s );
    int number;
    std::vector<int> myNumbers;
    while ( iss >> number )
      {myNumbers.push_back( number );}
    string decom= decoding(myNumbers);
     ui->plainTextEdit->setPlainText(QString::fromStdString(decom));
}

