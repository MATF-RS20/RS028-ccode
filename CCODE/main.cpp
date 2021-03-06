#include "mainwindow.h"

#include <QApplication>
#include <QBoxLayout>
#include <QSizePolicy>


#include "editor.h"
#include "sidebar.h"
#include "codeeditor.h"
#include "parsererror.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("CCODE");
    const QIcon icon = QIcon(":/images/CCODE.png");
    w.setWindowIcon(icon);

    CodeEditor* codeEditor = CodeEditor::instance();
    Editor* editor = new Editor();

    codeEditor->pe=new ParserError();
    codeEditor->addEditor(editor);


    SideBar* sideBar = SideBar::instance();

    QBoxLayout layaout(QBoxLayout::LeftToRight, w.centralWidget());

    layaout.addWidget(sideBar);

    layaout.addLayout(codeEditor, 5);

    w.setStatusBar(codeEditor->pe->status);
    w.show();

    return a.exec();
}
