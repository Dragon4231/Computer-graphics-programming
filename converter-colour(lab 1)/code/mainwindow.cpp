#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtCore/qmath.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(255);
    ui->horizontalSlider_2->setMinimum(0);
    ui->horizontalSlider_2->setMaximum(255);
    ui->horizontalSlider_3->setMinimum(0);
    ui->horizontalSlider_3->setMaximum(255);
    color = Qt::black;
    QFile *file = new QFile();
    QList<QString> list_colors{"RGB","CMYK","HSV","HLS","XYZ","LAB"};
   for(int i = 0; i < list_colors.size(); i++){
       ui->comboBox->addItem(list_colors[i]);
       ui->comboBox_2->addItem(list_colors[i]);
       ui->comboBox_3->addItem(list_colors[i]);
   }
   refreshLineEdit();
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::refreshLineEdit()
{
    ui->lineEdit->setText(converColor.getColorString(ui->comboBox->currentText()));
    ui->lineEdit_2->setText(converColor.getColorString(ui->comboBox_2->currentText()));
    ui->lineEdit_3->setText(converColor.getColorString(ui->comboBox_3->currentText()));
}

void MainWindow::fromHSVtoRGB(double h, double s, double v, int *r, int *g, int *b)
{
    if ( s == 0 )
    {
       *r = v * 255;
       *g = v * 255;
       *b = v * 255;
    }
    else
    {
       double var_h = h * 6;
       if ( var_h == 6 ) var_h = 0;
       int var_i = int( var_h );
       double var_1 = v * ( 1 - s );
       double var_2 = v * ( 1 - s * ( var_h - var_i ) );
       double var_3 = v * ( 1 - s * ( 1 - ( var_h - var_i ) ) );
       double var_r;
       double var_g;
       double var_b;
       if( var_i == 0 ){
           var_r = v;
           var_g = var_3 ;
           var_b = var_1;
       }
       else if(var_i == 1) {
           var_r = var_2;
           var_g = v;
           var_b = var_1;
       }
       else if(var_i == 2){
           var_r = var_1;
           var_g = v;
           var_b = var_3;
       }
       else if(var_i == 3){
           var_r = var_1;
           var_g = var_2;
           var_b = v;
       }
       else if(var_i == 4){
           var_r = var_3;
           var_g = var_1;
           var_b = v;     }
       else{
           var_r = v;
           var_g = var_1;
           var_b = var_2;
       }

       *r = var_r * 255;
       *g = var_g * 255;
       *b = var_b * 255;
    }
}

void MainWindow::fromHSLtoRGB(double h, double s, double l, int* r, int* g, int* b)
{
    double var_2;
    if ( s == 0 )
    {

        *r = l * 255.0;
        *g = l * 255.0;
        *b = l * 255.0;
    }
    else
    {
       if ( l < 0.5 ){
           var_2 = l * (1+s);
       }
       else{
           var_2 = (l+s)-(s*l);
       }

       double var_1 = 2.0 * l - var_2;

       *r = 255.0 * Hue_2_RGB( var_1, var_2, h + (0.3334));
       *g = 255.0 * Hue_2_RGB( var_1, var_2, h );
       *b = 255.0 * Hue_2_RGB( var_1, var_2, h - (0.3334));
    }
    if(*r > 255.0) *r = 255.0;
    if(*g > 255.0) *g = 255.0;
    if(*b > 255.0) *b = 255.0;
}

void MainWindow::fromXYZtoRGB(double h, double s, double l, int *r, int *g, int *b)
{
    double var_R = ( (double)*r/255 );
    double var_G = ( (double)*g/255 );
    double var_B = ( (double)*b/255 );

    var_R = var_R * 100;
    var_G = var_G * 100;
    var_B = var_B * 100;

    double X = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
    double Y = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
    double Z = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;


}

double MainWindow::Hue_2_RGB(double v1,double v2, double vH)
{
       if ( vH < 0 ) vH += 1.0;
       if( vH > 1 ) vH -= 1.0;
       if ( ( 6.0 * vH ) < 1.0 ) return ( v1 + ( v2 - v1 ) * 6.0 * vH );
       if ( ( 2.0 * vH ) < 1.0 ) return ( v2 );
       if ( ( 3.0 * vH ) < 2.0 ) return ( v1 + ( v2 - v1 ) * ( ( 2.0 / 3.0 ) - vH ) * 6.0 );
       return ( v1 );
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(QPen(color, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(brush);
    painter.drawEllipse(300, 200, 150, 150);
}

void MainWindow::on_pushButton_clicked()
{
    color = QColorDialog::getColor();
    color.getRgb(converColor.r, converColor.g, converColor.b);
    refreshLineEdit();
    repaint();
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    refreshLineEdit();
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    refreshLineEdit();
}

void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    refreshLineEdit();
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    ui->label->clear();
    QStringList list = arg1.split(" ");
    if(ui->comboBox->currentText() == "RGB"){
        if(list.size() < 3 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double R = list.at(0).toDouble();
        double G = list.at(1).toDouble();
        double B = list.at(2).toDouble();    
        if((R < 0 || R > 255) || (G < 0 || G > 255) || (B < 0 || B > 255)){
            ui->label->setText("Неверное значение");
        }else{
            *converColor.r = R;
            *converColor.g = G;
            *converColor.b = B;
            color.setRgb(R,G,B);
        }
      }
    }

    if(ui->comboBox->currentText() == "CMYK"){
        if(list.size() < 4 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double C = list.at(0).toDouble();
        double M = list.at(1).toDouble();
        double Y = list.at(2).toDouble();
        double K = list.at(3).toDouble();
        if((C < 0 || C > 1) || (M < 0 || M > 1) || (Y < 0 || Y > 1) || (K < 0 || K > 1)){
            ui->label->setText("Неверное значение");
        }else{
            *converColor.r = 255*(1-C)*(1-K);
            *converColor.g = 255*(1-M)*(1-K);
            *converColor.b = 255*(1-Y)*(1-K);
            color.setRgb(*converColor.r,*converColor.g,*converColor.b);
        }
      }
    }

    if(ui->comboBox->currentText() == "HSV"){
        if(list.size() < 3 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double H = list.at(0).toDouble();
        double S = list.at(1).toDouble();
        double V = list.at(2).toDouble();
        if((H < 0 || H > 1) || (S < 0 || S > 1) || (V < 0 || V > 1)){
            ui->label->setText("Неверное значение");
        }else{
            fromHSVtoRGB(H,S,V,converColor.r,converColor.g,converColor.b);
            color.setRgb(*converColor.r,*converColor.g,*converColor.b);
        }
      }
    }

    if(ui->comboBox->currentText() == "HLS"){
        if(list.size() < 3 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double H = list.at(0).toDouble();
        double S = list.at(1).toDouble();
        double L = list.at(2).toDouble();
        if((H < 0 || H > 1) || (S < 0 || S > 1) || (L < 0 || L > 1)){
            ui->label->setText("Неверное значение");
        }else{
            fromHSLtoRGB(H,S,L,converColor.r,converColor.g,converColor.b);
            color.setRgb(*converColor.r,*converColor.g,*converColor.b);
        }
      }
    }
    repaint();
    ui->lineEdit_2->setText(converColor.getColorString(ui->comboBox_2->currentText()));
    ui->lineEdit_3->setText(converColor.getColorString(ui->comboBox_3->currentText()));
}

void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{
    ui->label->clear();
    QStringList list = arg1.split(" ");
    if(ui->comboBox_2->currentText() == "RGB"){
        if(list.size() < 3 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double R = list.at(0).toDouble();
        double G = list.at(1).toDouble();
        double B = list.at(2).toDouble();
        if((R < 0 || R > 255) || (G < 0 || G > 255) || (B < 0 || B > 255)){
            ui->label->setText("Неверное значение");
        }else{
            *converColor.r = R;
            *converColor.g = G;
            *converColor.b = B;
            color.setRgb(R,G,B);
        }
      }
    }

    if(ui->comboBox_2->currentText() == "CMYK"){
        if(list.size() < 4 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double C = list.at(0).toDouble();
        double M = list.at(1).toDouble();
        double Y = list.at(2).toDouble();
        double K = list.at(3).toDouble();
        if((C < 0 || C > 1) || (M < 0 || M > 1) || (Y < 0 || Y > 1) || (K < 0 || K > 1)){
            ui->label->setText("Неверное значение");
        }else{
            *converColor.r = 255*(1-C)*(1-K);
            *converColor.g = 255*(1-M)*(1-K);
            *converColor.b = 255*(1-Y)*(1-K);
            color.setRgb(*converColor.r,*converColor.g,*converColor.b);
        }
      }
    }

    if(ui->comboBox_2->currentText() == "HSV"){
        if(list.size() < 3 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double H = list.at(0).toDouble();
        double S = list.at(1).toDouble();
        double V = list.at(2).toDouble();
        if((H < 0 || H > 1) || (S < 0 || S > 1) || (V < 0 || V > 1)){
            ui->label->setText("Неверное значение");
        }else{
            fromHSVtoRGB(H,S,V,converColor.r,converColor.g,converColor.b);
            color.setRgb(*converColor.r,*converColor.g,*converColor.b);
        }
      }
    }

    if(ui->comboBox_2->currentText() == "HLS"){
        if(list.size() < 3 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double H = list.at(0).toDouble();
        double S = list.at(1).toDouble();
        double L = list.at(2).toDouble();
        if((H < 0 || H > 1) || (S < 0 || S > 1) || (L < 0 || L > 1)){
            ui->label->setText("Неверное значение");
        }else{
            fromHSLtoRGB(H,S,L,converColor.r,converColor.g,converColor.b);
            color.setRgb(*converColor.r,*converColor.g,*converColor.b);
        }
      }
    }
    if(ui->comboBox_2->currentText() == "XYZ"){
        if(list.size() < 3 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double X = list.at(0).toDouble();
        double Y = list.at(1).toDouble();
        double Z = list.at(2).toDouble();
        qDebug() << X;
        qDebug() << Y;
        qDebug() << Z;
        if((X < 0 || X > 1) || (Y < 0 || Y > 1) || (Z < 0 || Z > 1)){
            ui->label->setText("Неверное значение");
        }else{
            fromXYZtoRGB(X,Y,Z,converColor.r,converColor.g,converColor.b);
            color.setRgb(*converColor.r,*converColor.g,*converColor.b);
        }
      }
    }

    repaint();
    ui->lineEdit->setText(converColor.getColorString(ui->comboBox->currentText()));
    ui->lineEdit_3->setText(converColor.getColorString(ui->comboBox_3->currentText()));
}

void MainWindow::on_lineEdit_3_textEdited(const QString &arg1)
{
    ui->label->clear();
    QStringList list = arg1.split(" ");
    if(ui->comboBox_3->currentText() == "RGB"){
        if(list.size() < 3 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double R = list.at(0).toDouble();
        double G = list.at(1).toDouble();
        double B = list.at(2).toDouble();
        if((R < 0 || R > 255) || (G < 0 || G > 255) || (B < 0 || B > 255)){
            ui->label->setText("Неверное значение");
        }else{
            *converColor.r = R;
            *converColor.g = G;
            *converColor.b = B;
            color.setRgb(R,G,B);
        }
      }
    }

    if(ui->comboBox_3->currentText() == "CMYK"){
        if(list.size() < 4 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double C = list.at(0).toDouble();
        double M = list.at(1).toDouble();
        double Y = list.at(2).toDouble();
        double K = list.at(3).toDouble();
        if((C < 0 || C > 1) || (M < 0 || M > 1) || (Y < 0 || Y > 1) || (K < 0 || K > 1)){
            ui->label->setText("Неверное значение");
        }else{
            *converColor.r = 255*(1-C)*(1-K);
            *converColor.g = 255*(1-M)*(1-K);
            *converColor.b = 255*(1-Y)*(1-K);
            color.setRgb(*converColor.r,*converColor.g,*converColor.b);
        }
      }
    }

    if(ui->comboBox_3->currentText() == "HSV"){
        if(list.size() < 3 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double H = list.at(0).toDouble();
        double S = list.at(1).toDouble();
        double V = list.at(2).toDouble();
        if((H < 0 || H > 1) || (S < 0 || S > 1) || (V < 0 || V > 1)){
            ui->label->setText("Неверное значение");
        }else{
            fromHSVtoRGB(H,S,V,converColor.r,converColor.g,converColor.b);
            color.setRgb(*converColor.r,*converColor.g,*converColor.b);
        }
      }
    }

    if(ui->comboBox_3->currentText() == "HLS"){
        if(list.size() < 3 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double H = list.at(0).toDouble();
        double S = list.at(1).toDouble();
        double L = list.at(2).toDouble();
        if((H < 0 || H > 1) || (S < 0 || S > 1) || (L < 0 || L > 1)){
            ui->label->setText("Неверное значение");
        }else{
            fromHSLtoRGB(H,S,L,converColor.r,converColor.g,converColor.b);
            color.setRgb(*converColor.r,*converColor.g,*converColor.b);
        }
      }
    }
    if(ui->comboBox_3->currentText() == "XYZ"){
        if(list.size() < 3 || list.contains("")){
            ui->label->setText("Не хватает данных.");
        }else{
        double X = list.at(0).toDouble();
        double Y = list.at(1).toDouble();
        double Z = list.at(2).toDouble();
        qDebug() << X;
        qDebug() << Y;
        qDebug() << Z;
        if((X < 0 || X > 1) || (Y < 0 || Y > 1) || (Z < 0 || Z > 1)){
            ui->label->setText("Неверное значение");
        }else{
            fromXYZtoRGB(X,Y,Z,converColor.r,converColor.g,converColor.b);
            color.setRgb(*converColor.r,*converColor.g,*converColor.b);
        }
      }
    }

    repaint();
    ui->lineEdit_2->setText(converColor.getColorString(ui->comboBox_2->currentText()));
    ui->lineEdit->setText(converColor.getColorString(ui->comboBox->currentText()));
}



void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    *converColor.r = position;
    color.setRgb(position,*converColor.g, *converColor.b);
    repaint();
    refreshLineEdit();
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    *converColor.g = position;
    color.setRgb(*converColor.r, position, *converColor.b);
    repaint();
    refreshLineEdit();
}

void MainWindow::on_horizontalSlider_3_sliderMoved(int position)
{
    *converColor.b = position;
    color.setRgb(*converColor.r, *converColor.g, position);
    repaint();
    refreshLineEdit();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->lineEdit->setReadOnly(false);
    if(ui->comboBox->currentText() == "XYZ" || ui->comboBox->currentText() == "LAB"){
        ui->lineEdit->setReadOnly(true);
    }
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    ui->lineEdit_2->setReadOnly(false);
    if(ui->comboBox->currentText() == "XYZ"  || ui->comboBox->currentText() == "LAB"){
        ui->lineEdit_2->setReadOnly(true);
    }
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    ui->lineEdit_3->setReadOnly(false);
    if(ui->comboBox->currentText() == "XYZ" || ui->comboBox->currentText() == "LAB"){
        ui->lineEdit_3->setReadOnly(true);
    }
}
