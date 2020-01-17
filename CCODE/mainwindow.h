#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QWidget>
#include <codeeditor.h>
#include <opendocuments.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget* centralWidget();
private slots:
    void on_actionExit_triggered();

    void on_actionSave_triggered();

    void on_actionNew_2_triggered();

    void on_actionSave_As_triggered();

private:
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *event) override;

};
#endif // MAINWINDOW_H
