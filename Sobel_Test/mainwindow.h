#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sobel_tsv.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(char *file1, char *file2);
    ~MainWindow();

private:
    QImage *image_input  = nullptr;

    void    Sobel_Test();

    int*    rgb_to_gray(QImage image);
    QImage  gray_to_rgb(int *gray_image, int width, int height);


};
#endif // MAINWINDOW_H
