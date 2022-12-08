#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPainter>
#include <QMainWindow>
#include <QColorDialog>
#include <QDebug>
#include <convertcolor.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QColor color;
    ConvertColor converColor;
    void refreshLineEdit();
    void fromHSVtoRGB(double h, double s, double v,int* r, int* g, int* b);
    void fromHSLtoRGB(double h, double s, double l,int* r, int* g, int* b);
    void fromXYZtoRGB(double h, double s, double l,int* r, int* g, int* b);
    double Hue_2_RGB(double first, double second, double third);

private slots:
    void on_pushButton_clicked();
    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_3_activated(const QString &arg1);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_horizontalSlider_3_sliderMoved(int position);

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

protected:
    void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
