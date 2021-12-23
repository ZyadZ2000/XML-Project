#ifndef USERS_ON_SOCIAL_NETWORK_H
#define USERS_ON_SOCIAL_NETWORK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Users_On_Social_Network; }
QT_END_NAMESPACE

class Users_On_Social_Network : public QMainWindow
{
    Q_OBJECT

public:
    Users_On_Social_Network(QWidget *parent = nullptr);
    ~Users_On_Social_Network();



private slots:


    void on_pushButton_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_compressed_file_triggered();

private:
    Ui::Users_On_Social_Network *ui;
    QString file_path;
    QString Original;
};
#endif // USERS_ON_SOCIAL_NETWORK_H
