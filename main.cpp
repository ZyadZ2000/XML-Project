#include "users_on_social_network.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Users_On_Social_Network w;
    w.show();
    return a.exec();
}
