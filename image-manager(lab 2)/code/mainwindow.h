#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QTableWidgetItem>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void refreshLineEdit();
    void refreshInfo();

private slots:
    void on_action_triggered();

    void on_comboBox_currentIndexChanged(int index);

    static bool compareFileInfoForString(const QFileInfo& first, const QFileInfo& second);
    static bool compareFileInfoForSize(const QFileInfo& first, const QFileInfo& second);
    static bool compareFileInfoForTime(const QFileInfo& first, const QFileInfo& second);

    void on_listWidget_currentRowChanged(int currentRow);

    void on_tableWidget_cellClicked(int row, int column);


private:
    Ui::MainWindow *ui;
    QStringList dirs;
    //QFileInfoList *fileInfos = new QFileInfoList();
    QVector<QFileInfo> *fileInfos = new QVector<QFileInfo>();
};
#endif // MAINWINDOW_H
