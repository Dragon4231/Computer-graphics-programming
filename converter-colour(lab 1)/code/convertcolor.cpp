#include "convertcolor.h"
#include <QDebug>
#include <QtCore/qmath.h>


ConvertColor::ConvertColor()
{

}

QString ConvertColor::getColorString(QString model)
{
    if(model == "RGB"){
        return QString(QString::number(*r)+" "+QString::number(*g)+" "+QString::number(*b));
    }
    if(model == "CMYK"){
        QVector<double> vec = {1-((double)*r/255),1-((double)*g/255),1-((double)*b/255)};
        std::sort(vec.begin(),vec.end());
        double k = vec[0];
        if(qIsNaN(k)) k = 0;
        double c = (1-(*r/255)-k)/(1-k);
        if(qIsNaN(c)) c = 0;
        double m = (1-(*g/255)-k)/(1-k);
        if(qIsNaN(m)) m = 0;
        double y = (1-(*b/255)-k)/(1-k);
        if(qIsNaN(y)) y = 0;
        return QString(QString::number(c)+" "+QString::number(m)+" "+QString::number(y)+" "+QString::number(k));
    }
    if(model == "HSV" || model == "HLS"){
        double h = 0;
        double s = 0;
        double v = 0;
        double max = 0;
        double min = 0;
        double R = (double)*r/255;
        double G = (double)*g/255;
        double B = (double)*b/255;
        max = retmax(R,G,B);
        min = retmin(R,G,B);
        double delt = max-min;

        if(max == 0){
            s = 0;
        }else{
            s = (int) (delt/max)*100;
        }

        if(model == "HSV"){
            v = (int) (max*100);
        }else{
            v = (int) (((max+min)/2)*100);
        }

        if(delt == 0){
            h = 0;
        }
        else if(max == R && G>=B){
            h = (int) (60 * ((int)((G-B)/delt)%6));
        }else if(max == R && G < B){
            h = (int) ((60 * ((int)((G-B)/delt)%6))+360);
        }else if(max == G){
            h = (int) (60 * (((B-R)/delt)+2));
        }else if(max == B){
           h = (int) (60 * (((R-G)/delt)+4));
        }
        return QString(QString::number(h)+" "+QString::number(s)+" "+QString::number(v));
    }
    if(model == "XYZ" || model == "LAB"){
        double var_R = ( (double)*r/255 );
        double var_G = ( (double)*g/255 );
        double var_B = ( (double)*b/255 );

        if ( var_R > 0.04045 ) var_R = qPow((( var_R + 0.055 ) / 1.055),2.4);
        else                   var_R = var_R / 12.92;
        if ( var_G > 0.04045 ) var_G = qPow((( var_G + 0.055 ) / 1.055 ),2.4);
        else                   var_G = var_G / 12.92;
        if ( var_B > 0.04045 ) var_B = qPow((( var_B + 0.055 ) / 1.055 ),2.4);
        else                   var_B = var_B / 12.92;

        var_R = var_R * 100;
        var_G = var_G * 100;
        var_B = var_B * 100;

        double X = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
        double Y = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
        double Z = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;
        if(model == "LAB"){
            double var_X = X / 95.047;
            double var_Y = Y / 100;
            double var_Z = Z / 108.883;

            if ( var_X >= 0.008856 ) var_X = qPow(var_X,(0.334));
            else                    var_X = (7.787 * var_X) + (0.1379311);
            if ( var_Y >= 0.008856 ) var_Y = qPow(var_Y,(0.334));
            else                    var_Y = (7.787 * var_Y) + (0.1379311);
            if ( var_Z >= 0.008856 ) var_Z = qPow(var_Z,(0.334));
            else                    var_Z = (7.787*var_Z) + (0.1379311);

            double L = ( 116 * var_Y ) - 16;
            double A = 500 * ( var_X - var_Y );
            double B = 200 * ( var_Y - var_Z );
            QString str = QString("%1 %2 %3").arg(L, 0, 'f', 2).arg(A, 0, 'f', 2).arg(B, 0, 'f', 2);
            return str;
        }else{
            QString str = QString("%1 %2 %3").arg(X, 0, 'f', 3).arg(Y, 0, 'f', 3).arg(Z, 0, 'f', 3);
            return str;
        }
    }
    return QString();
}

double ConvertColor::retmax(double r, double g, double b)
{
    double max = r;
    if(max < g) max = g;
    if(max < b) max = b;
    return max;
}

double ConvertColor::retmin(double r, double g, double b)
{
    double min = r;
    if(min > g) min = g;
    if(min > b) min = b;
    return min;
}

double ConvertColor::absF(double func)
{
    if(func < 0) return func*(-1);
    return func;
}
