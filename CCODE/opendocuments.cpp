#include "opendocuments.h"
#include <iostream>

OpenDocuments* OpenDocuments::m_instance = 0;

OpenDocuments::OpenDocuments(QListWidget *parent) : QListWidget(parent)
{
    auto codeEditor = CodeEditor::instance();
    auto editors = codeEditor->editors();

    std::for_each(editors.begin(), editors.end(), [this](Editor* ed) {
        addItem(ed);
    });

    codeEditor->active()->setSelected(true);
    connect(this, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(changeActiveEditor(QListWidgetItem*)));
}

OpenDocuments* OpenDocuments::instance(QListWidget *parent)
{
    if (!m_instance) {
        m_instance = new OpenDocuments(parent);
    }

    return m_instance;
}

void OpenDocuments::changeActiveEditor(QListWidgetItem *item) {
    Editor* e = (Editor*) item;
    CodeEditor::instance()->setActive(e);
}
