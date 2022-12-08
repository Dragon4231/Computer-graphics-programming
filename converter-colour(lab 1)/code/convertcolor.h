#ifndef CONVERTCOLOR_H
#define CONVERTCOLOR_H

#include <QString>
#include <QVector>


class ConvertColor
{
public:
    ConvertColor();
    int *r = new int();
    int *g = new int();
    int *b = new int();
    QString getColorString(QString model);
    double retmax(double r, double g, double b);
    double retmin(double r, double g, double b);
    double absF(double func);
};

#endif // CONVERTCOLOR_H
