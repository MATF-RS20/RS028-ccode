#include "mainwindow.h"

#include <QApplication>
#include <QBoxLayout>
#include <QSizePolicy>


#include "editor.h"
#include "sidebar.h"
#include "codeeditor.h"
#include <QFileSystemModel>
#include <QTreeView>
#include <QDirModel>
#include <QSplitter>
#include <QStringListModel>
#include <QStringList>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("CCODE");
    const QIcon icon = QIcon(":/images/CCODE.png");
    w.setWindowIcon(icon);

    CodeEditor* codeEditor = CodeEditor::instance();
    Editor* editor = new Editor();


    codeEditor->addEditor(editor);
    codeEditor->addEditor(new Editor());


    SideBar* sideBar = SideBar::instance();

    QBoxLayout layaout(QBoxLayout::LeftToRight, w.centralWidget());

    QDirModel* model = new QDirModel();

    auto index = model->index("/Users");
    auto path = model->filePath(index);
    std::cout << path.toUtf8().constData() << std::endl;
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);


    layaout.addWidget(sideBar);

    layaout.addLayout(codeEditor, 5);



    w.show();

    return a.exec();
}
