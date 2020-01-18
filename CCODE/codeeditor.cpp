#include "codeeditor.h"

CodeEditor::CodeEditor(QBoxLayout::Direction dir, QWidget *parent)
    : QBoxLayout(dir, parent)
{
    highlighter=new Highlighter();
    completer = new QCompleter(this);
    completer->setModel(modelFromFile(":/resources/wordlist.txt"));
    completer->setModelSorting(QCompleter::CaseSensitivelySortedModel);
    completer->setCaseSensitivity(Qt::CaseInsensitive);


}

CodeEditor::~CodeEditor() {
    std::for_each(m_editors.begin(), m_editors.end(), [](Editor* e){ delete e; });
}

CodeEditor* CodeEditor::m_instance = 0;

CodeEditor* CodeEditor::instance(QWidget *parent)
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
    highlighter->setDocument(editor->document());
    m_active->setCompleter(completer);
}

std::vector<Editor*> CodeEditor::editors() {
    return m_editors;
}

void CodeEditor::setActive(Editor *editor) {
    m_active->setVisible(false);
    m_active = editor;
    editor->setVisible(true);
    highlighter->setDocument(editor->document());
    m_active->setCompleter(completer);
}

Editor* CodeEditor::active() {
    return m_active;
}

bool CodeEditor::maybeSave(){
    bool all_saved=true;
    for(unsigned i =0; i<m_editors.size();i++){
        all_saved=m_editors[i]->maybeSave();
        if(!all_saved)
            break;
    }
    return all_saved;
}

void CodeEditor::saveAll(){
    for(unsigned i =0; i<m_editors.size();i++){
        m_editors[i]->save();
    }
}

QAbstractItemModel *CodeEditor::modelFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        return new QStringListModel(completer);

#ifndef QT_NO_CURSOR
    QGuiApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
#endif
    QStringList words;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        if (!line.isEmpty())
            words << QString::fromUtf8(line.trimmed());
    }

#ifndef QT_NO_CURSOR
    QGuiApplication::restoreOverrideCursor();
#endif
    return new QStringListModel(words, completer);
}
