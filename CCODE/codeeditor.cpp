#include "codeeditor.h"

CodeEditor::CodeEditor(QBoxLayout::Direction dir, QWidget *parent) : QBoxLayout(dir, parent)
{

}

CodeEditor* CodeEditor::m_instance = 0;

CodeEditor* CodeEditor::rade(QWidget *parent)
{
    if (!m_instance)
    {
        m_instance = new CodeEditor(QBoxLayout::TopToBottom, parent);
    }

    return m_instance;
}

void CodeEditor::addEditor(Editor *editor)
{
    if (m_active) {
        m_active->setVisible(false);
    }
    m_editors.push_back(editor);
    addWidget(editor);
    m_active = editor;
}

std::vector<Editor*> CodeEditor::editors() {
    return m_editors;
}

void CodeEditor::setActive(Editor *editor) {
    m_active->setVisible(false);
    m_active = editor;
    editor->setVisible(true);
}
