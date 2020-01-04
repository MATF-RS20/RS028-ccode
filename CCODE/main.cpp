#include "mainwindow.h"

#include <QApplication>
#include <QBoxLayout>
#include <QSizePolicy>

#include "editor.h"
#include "sidebar.h"
#include "codeeditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("CCODE");

    CodeEditor* codeEditor = CodeEditor::instance();
    Editor* editor = new Editor();

    codeEditor->addEditor(editor);
    codeEditor->addEditor(new Editor());

    SideBar* sideBar = SideBar::instance();

    QBoxLayout layaout(QBoxLayout::LeftToRight, w.centralWidget());

    layaout.addWidget(sideBar);

    layaout.addLayout(codeEditor, 5);
    w.show();

    return a.exec();
}
