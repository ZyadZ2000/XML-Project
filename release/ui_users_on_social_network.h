/********************************************************************************
** Form generated from reading UI file 'users_on_social_network.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERS_ON_SOCIAL_NETWORK_H
#define UI_USERS_ON_SOCIAL_NETWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Users_On_Social_Network
{
public:
    QAction *actionOpen;
    QAction *actionSave_As;
    QAction *actionSave;
    QAction *actionOpen_compressed_file;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Users_On_Social_Network)
    {
        if (Users_On_Social_Network->objectName().isEmpty())
            Users_On_Social_Network->setObjectName(QString::fromUtf8("Users_On_Social_Network"));
        Users_On_Social_Network->resize(544, 437);
        actionOpen = new QAction(Users_On_Social_Network);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pics/Resources/download (1).jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionSave_As = new QAction(Users_On_Social_Network);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pics/Resources/Custom-Icon-Design-Pretty-Office-7-Save-as.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon1);
        actionSave = new QAction(Users_On_Social_Network);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionOpen_compressed_file = new QAction(Users_On_Social_Network);
        actionOpen_compressed_file->setObjectName(QString::fromUtf8("actionOpen_compressed_file"));
        centralwidget = new QWidget(Users_On_Social_Network);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        Users_On_Social_Network->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Users_On_Social_Network);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 544, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        Users_On_Social_Network->setMenuBar(menubar);
        statusbar = new QStatusBar(Users_On_Social_Network);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Users_On_Social_Network->setStatusBar(statusbar);
        toolBar = new QToolBar(Users_On_Social_Network);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Users_On_Social_Network->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionOpen_compressed_file);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave_As);

        retranslateUi(Users_On_Social_Network);

        QMetaObject::connectSlotsByName(Users_On_Social_Network);
    } // setupUi

    void retranslateUi(QMainWindow *Users_On_Social_Network)
    {
        Users_On_Social_Network->setWindowTitle(QApplication::translate("Users_On_Social_Network", "Users_On_Social_Network", nullptr));
        actionOpen->setText(QApplication::translate("Users_On_Social_Network", "Open", nullptr));
        actionSave_As->setText(QApplication::translate("Users_On_Social_Network", "Save As", nullptr));
        actionSave->setText(QApplication::translate("Users_On_Social_Network", "Save", nullptr));
        actionOpen_compressed_file->setText(QApplication::translate("Users_On_Social_Network", "Open compressed file", nullptr));
        pushButton->setText(QApplication::translate("Users_On_Social_Network", "OK", nullptr));
        menuFile->setTitle(QApplication::translate("Users_On_Social_Network", "File", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Users_On_Social_Network", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Users_On_Social_Network: public Ui_Users_On_Social_Network {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_ON_SOCIAL_NETWORK_H
