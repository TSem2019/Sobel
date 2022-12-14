#include "mainwindow.h"


MainWindow::MainWindow(char *file1, char *file2)
{
    image_input = new QImage(3,3,QImage::Format_BGR888);

    Sobel_Test();
}

MainWindow::~MainWindow()
{
}

void MainWindow::Sobel_Test()
{

    image_input->load("../examples/Lena_test.png","PNG");

    QImage w(image_input->convertToFormat(QImage::Format_BGR888));

int *G;
int *gray;
QImage q;

    gray = rgb_to_gray(w);

    G = sobel_tsv(gray, w.width(), w.height());

    q = gray_to_rgb(G, w.width(), w.height());

    q.save("../examples/sobel.png");
}



int* MainWindow::rgb_to_gray(QImage image)
{
    int *im_gray;

    im_gray = new int [image.width()*image.height()];

    int *ptr = im_gray;

    QRgb value;

    for (int row = 0; row < image.height(); row++)
        {
            for (int col = 0; col < image.width(); col++)
                {
                    value = image.pixel(col,row);
                    *ptr = qGray(value);
                    ptr++;
                }
        }
    return im_gray;
}


QImage MainWindow::gray_to_rgb(int *gray_image, int width, int height)
{
    QImage out(width, height, QImage::Format_Grayscale8);

        int gray;
        QRgb value;

        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col < width; col++)
            {
                gray = gray_image[row*width+col];
                value = qRgb(gray, gray, gray);
                out.setPixel(col,row,value);
            }
        }

    return out;
}
