#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <vector>
#include <algorithm>
#include <QWidget>
#include <QBoxLayout>
#include <QStringListModel>
#include <QGuiApplication>
#include "editor.h"
#include "highlighter.h"


class CodeEditor : public QBoxLayout
{
    Q_OBJECT
public:
    static CodeEditor* instance(QWidget *parent = nullptr);
    ~CodeEditor();

    void addEditor(Editor *editor);
    std::vector<Editor*> editors();
    void setActive(Editor *editor);
    Editor* active();
    bool maybeSave();
    void saveAll();

signals:
private:
    explicit CodeEditor(QBoxLayout::Direction dir, QWidget *parent = nullptr);
    static CodeEditor* m_instance;
    std::vector<Editor*> m_editors;
    Editor *m_active = nullptr;
    Highlighter *highlighter;

    QCompleter *completer =nullptr;
    QAbstractItemModel *modelFromFile(const QString& fileName);

};

#endif // CODEEDITOR_H
