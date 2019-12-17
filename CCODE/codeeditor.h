#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <vector>
#include <algorithm>
#include <QWidget>
#include <QBoxLayout>
#include "editor.h"

class CodeEditor : public QBoxLayout
{
    Q_OBJECT
public:
    static CodeEditor* rade(QWidget *parent = nullptr);

    void addEditor(Editor* editor);
    std::vector<Editor*> editors();
    void setActive(Editor* editor);

signals:
private:
    explicit CodeEditor(QBoxLayout::Direction dir, QWidget *parent = nullptr);
    static CodeEditor* m_instance;
    std::vector<Editor*> m_editors;
    Editor* m_active;

};

#endif // CODEEDITOR_H
