#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QTreeView>
#include <QFileSystemModel>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QScreen>
#include <QDateTime>
#include <QListView>
#include <QDebug>
#include <QImageWriter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui-> tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setColumnWidth(0,130);
    ui->tableWidget->setColumnWidth(1,70);
    ui->tableWidget->setColumnWidth(2,145);
    ui->tableWidget->setColumnWidth(3,120);
    ui->tableWidget->setColumnWidth(4,70);
    ui->tableWidget->setColumnWidth(5,120);
    ui->tableWidget->setColumnWidth(6,120);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    QStringList sListHeader;
    sListHeader << "Name" << "Size" << "Create" << "Permission" << "Depth" << "Extension" << "Compression";
    ui->tableWidget_2->setColumnCount(7);
    ui->tableWidget_2->setColumnWidth(0,130);
    ui->tableWidget_2->setColumnWidth(1,70);
    ui->tableWidget_2->setColumnWidth(2,145);
    ui->tableWidget_2->setColumnWidth(3,120);
    ui->tableWidget_2->setColumnWidth(4,70);
    ui->tableWidget_2->setColumnWidth(5,120);
    ui->tableWidget_2->setColumnWidth(6,120);
    ui->tableWidget_2->horizontalHeader()->setVisible(false);
    ui->tableWidget_2->verticalHeader()->setVisible(false);
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("Name"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("Size"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("Create"));
    ui->tableWidget->setItem(0,3,new QTableWidgetItem("Permission"));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem("Depth"));
    ui->tableWidget->setItem(0,5,new QTableWidgetItem("Extension"));
    ui->tableWidget->setItem(0,6,new QTableWidgetItem("Compression"));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshLineEdit()
{
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setColumnCount(7);
    ui->tableWidget_2->setRowCount(fileInfos->size());
    for(int i = 0 ; i < fileInfos->size(); i++){
        QImage img;
        QImageWriter imgWr;
        imgWr.write(img);
        img.load(fileInfos->at(i).filePath());
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(fileInfos->at(i).completeBaseName()));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::number(fileInfos->at(i).size())));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(fileInfos->at(i).birthTime().toString()));
        ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(QString::number(img.height())+"x"+QString::number(img.width())));
        ui->tableWidget_2->setItem(i,4,new QTableWidgetItem(QString::number(img.depth())));
        ui->tableWidget_2->setItem(i,5,new QTableWidgetItem(fileInfos->at(i).suffix()));
        ui->tableWidget_2->setItem(i,6,new QTableWidgetItem(QString::number(imgWr.compression())));
    }
}

void MainWindow::on_action_triggered()
{
    QFileDialog w;
    w.setFileMode(QFileDialog::DirectoryOnly);
    w.setOption(QFileDialog::DontUseNativeDialog,true);
    QListView *lView = w.findChild<QListView*>("listView");
    if (lView)
        lView->setSelectionMode(QAbstractItemView::MultiSelection);
    QTreeView *tView = w.findChild<QTreeView*>();
    if (tView)
        tView->setSelectionMode(QAbstractItemView::MultiSelection);
    w.exec();
    dirs.clear();
    dirs = w.selectedFiles();
    refreshInfo();
}

void MainWindow::refreshInfo()
{
    fileInfos->clear();
    ui->tableWidget_2->clear();
    QString path = "";
    for(int i = 0; i < dirs.size(); i++){
        path = dirs[i];
        QDir dir(path);
        QStringList nameFilters;
        nameFilters << "*.jpg" << "*.gif" << "*.tif" << "*.bmp" << "*.png" << "*.pcx";
        QFileInfoList fileInfo = dir.entryInfoList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
        for(QFileInfo tem : fileInfo){
            fileInfos->push_back(tem);
        }
    }
    refreshLineEdit();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    refreshInfo();
    if(index == 7){
        std::sort(fileInfos->begin(), fileInfos->end(), compareFileInfoForString);
    }
    if(index == 9){
        std::sort(fileInfos->begin(), fileInfos->end(), compareFileInfoForTime);
    }
    if(index == 8){
        std::sort(fileInfos->begin(), fileInfos->end(), compareFileInfoForSize);
    }
    if(index == 1){
        QVector<QFileInfo> *fileInfosTemp = new QVector<QFileInfo>();
        for(QFileInfo fl : *fileInfos){
            if(fl.suffix().toLower() == "bmp"){
                fileInfosTemp->push_back(fl);
            }
        }
        fileInfos->clear();
        fileInfos = fileInfosTemp;
    }
    if(index == 2){
        QVector<QFileInfo> *fileInfosTemp = new QVector<QFileInfo>();
        for(QFileInfo fl : *fileInfos){
            if(fl.suffix().toLower() == "png"){
                fileInfosTemp->push_back(fl);
            }
        }
        fileInfos->clear();
        fileInfos = fileInfosTemp;    }
    if(index == 3){
        QVector<QFileInfo> *fileInfosTemp = new QVector<QFileInfo>();
        for(QFileInfo fl : *fileInfos){
            if(fl.suffix().toLower() == "jpg"){
                fileInfosTemp->push_back(fl);
            }
        }
        fileInfos->clear();
        fileInfos = fileInfosTemp;    }
    if(index == 4){
        QVector<QFileInfo> *fileInfosTemp = new QVector<QFileInfo>();
        for(QFileInfo fl : *fileInfos){
            if(fl.suffix().toLower() == "pcx"){
                fileInfosTemp->push_back(fl);
            }
        }
        fileInfos->clear();
        fileInfos = fileInfosTemp;    }
    if(index == 5){
        QVector<QFileInfo> *fileInfosTemp = new QVector<QFileInfo>();
        for(QFileInfo fl : *fileInfos){
            if(fl.suffix().toLower() == "gif"){
                fileInfosTemp->push_back(fl);
            }
        }
        fileInfos->clear();
        fileInfos = fileInfosTemp;    }
    if(index == 6){
        QVector<QFileInfo> *fileInfosTemp = new QVector<QFileInfo>();
        for(QFileInfo fl : *fileInfos){
            if(fl.suffix().toLower() == "tif"){
                fileInfosTemp->push_back(fl);
            }
        }
        fileInfos->clear();
        fileInfos = fileInfosTemp;    }
    refreshLineEdit();
}

bool MainWindow::compareFileInfoForString(const QFileInfo &first, const QFileInfo &second)
{
    if(first.completeBaseName().compare(second.completeBaseName()) < 0) return true;
    return false;
}

bool MainWindow::compareFileInfoForSize(const QFileInfo &first, const QFileInfo &second)
{
    if(first.size() < second.size()) return true;
    return false;
}

bool MainWindow::compareFileInfoForTime(const QFileInfo &first, const QFileInfo &second)
{
    if(first.birthTime() < second.birthTime()) return true;
    return false;
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
   /* if(currentRow == -1) return;
    ui->listWidget_2->clear();
    QFileInfo resultInfo = fileInfos->at(currentRow);
    QImage img;
    QImageWriter imgWr;
    imgWr.write(img);
    img.load(resultInfo.filePath());
    ui->listWidget_2->addItem("Название : "+resultInfo.completeBaseName()+"\n"
                              +"Размер : "+QString::number(resultInfo.size())+"\n"
                              +"Создан : "+resultInfo.birthTime().toString()+"\n"
                              +"Разрешение : "+QString::number(img.height())+"x"+QString::number(img.width())+"\n"
                              +"Глубина цвета : "+QString::number(img.depth())+"\n"
                              +"Расширение файла : "+resultInfo.suffix()+"\n"+
                              "Сжатие : "+QString::number(imgWr.compression()));*/
}



void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if(column == 0){
        on_comboBox_currentIndexChanged(7);
    }else if(column == 1){
        on_comboBox_currentIndexChanged(8);
    }else if(column == 2){
        on_comboBox_currentIndexChanged(9);
    }
}
