#include "codeeditor.h"

class CodeEditorData : public QSharedData
{
public:

};

CodeEditor::CodeEditor(QObject *parent) : QObject(parent), data(new CodeEditorData)
{

}

CodeEditor::CodeEditor(const CodeEditor &rhs) : data(rhs.data)
{

}

CodeEditor &CodeEditor::operator=(const CodeEditor &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

CodeEditor::~CodeEditor()
{

}
