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

QWidget* MainWindow::centralWidget()
{
    return ui->centralwidget;
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    if(CodeEditor::instance()->maybeSave()){
        event->accept();
    } else {
        event->ignore();
    }
}


void MainWindow::on_actionExit_triggered()
{
    if(CodeEditor::instance()->maybeSave()){
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

void MainWindow::on_actionsave_All_triggered()
{
    CodeEditor::instance()->saveAll();
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]",10), this);
    if(ok){
        CodeEditor::instance()->changeFont(font);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    Editor* editor = new Editor(fileName.toUtf8().constData());
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file: "+file.errorString());
        return;
    }
    CodeEditor::instance()->addEditor(editor);
    OpenDocuments::instance()->addItem(editor);
    QTextStream in(&file);
    QString text = in.readAll();
    CodeEditor::instance()->active()->setPlainText(text);
    file.close();

}

void MainWindow::on_actionUndo_triggered()
{
    CodeEditor::instance()->active()->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    CodeEditor::instance()->active()->redo();
}

void MainWindow::on_actionCopy_triggered()
{
    CodeEditor::instance()->active()->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    CodeEditor::instance()->active()->paste();
}

void MainWindow::on_actionCut_triggered()
{
    CodeEditor::instance()->active()->cut();
}
