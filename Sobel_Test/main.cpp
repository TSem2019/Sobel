#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
//    if (argc < 3)
//    {
//        return 1;
//    }
        char *f1, *f2;
        f1 = argv[1];
        f2 = argv[2];

        QApplication a(argc, argv);
        MainWindow w(f1, f2);

    return 0;
}
