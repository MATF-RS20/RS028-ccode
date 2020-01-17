#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}

QWidget* MainWindow::centralWidget() {
    return ui->centralwidget;
}


void MainWindow::closeEvent(QCloseEvent *event){
    if (CodeEditor::instance()->maybeSave()) {
            event->accept();
        } else {
            event->ignore();
        }
}


//void MainWindow::on_actionNew_triggered()
//{
//    currenFile.clear();
//    ui->textEdit->setText(QString());
//}

//void MainWindow::on_actionOpen_triggered()
//{
//    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
//    QFile file(filename);
//    currenFile = filename;
//    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
//        QMessageBox::warning(this, "Warning", "Cannot open file: "+file.errorString());
//        return;
//    }
//    setWindowTitle(filename);
//    QTextStream in(&file);
//    QString text = in.readAll();
//    ui->textEdit->setText(text);
//    file.close();
//}


//void MainWindow::on_actionSave_as_triggered()
//{
//    QString filename = QFileDialog::getSaveFileName(this, "Save as");
//     QFile file(filename);
//     if(!file.open(QFile::WriteOnly | QFile::Text)){
//         QMessageBox::warning(this, "Warning", "Cannot save file: "+file.errorString());
//         return;
//     }
//     currenFile = filename;
//     setWindowTitle(filename);
//     QTextStream out(&file);
//     QString text = ui->textEdit->toPlainText();
//     out<<text;
//     file.close();

//}

//void MainWindow::on_actionExit_triggered()
//{
//    QApplication::quit();
//}

//void MainWindow::on_actionCopy_triggered()
//{
//    ui->textEdit->copy();
//}

//void MainWindow::on_actionPaste_triggered()
//{
//    ui->textEdit->paste();
//}



//void MainWindow::on_actionCut_triggered()
//{
//    ui->textEdit->cut();
//}



//void MainWindow::on_textEdit_textChanged()
//{
//    QString text = ui->textEdit->toPlainText();
//    std::cout << text.toUtf8().constData() << std::endl;

//}

void MainWindow::on_actionExit_triggered()
{
    if (CodeEditor::instance()->maybeSave()) {
        QApplication::quit();
    }
}



void MainWindow::on_actionNew_2_triggered()
{
    CodeEditor* codeEditor = CodeEditor::instance();
    Editor* editor = new Editor();
    codeEditor->addEditor(editor);
    OpenDocuments::instance()->addItem(editor);
}

void MainWindow::on_actionSave_triggered()
{
    CodeEditor::instance()->active()->save();
}


void MainWindow::on_actionSave_As_triggered()
{
    CodeEditor::instance()->active()->save_as();
}
