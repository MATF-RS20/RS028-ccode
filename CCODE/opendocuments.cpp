#include "opendocuments.h"

OpenDocuments* OpenDocuments::m_instance = 0;

OpenDocuments::OpenDocuments(QWidget *parent) : QWidget(parent)
{
    auto rade = new QListWidget(this);
    auto editors = CodeEditor::instance()->editors();

    std::for_each(editors.begin(), editors.end(), [rade](Editor* ed) {
        rade->addItem(QString::fromStdString(ed->name()));
    });
}

OpenDocuments* OpenDocuments::instance(QWidget *parent)
{
    if (!m_instance) {
        m_instance = new OpenDocuments(parent);
    }

    return m_instance;
}
