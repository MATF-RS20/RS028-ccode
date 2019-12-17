#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class CodeEditorData;

class CodeEditor : public QObject
{
    Q_OBJECT
public:
    explicit CodeEditor(QObject *parent = nullptr);
    CodeEditor(const CodeEditor &);
    CodeEditor &operator=(const CodeEditor &);
    ~CodeEditor();

signals:


private:
    QSharedDataPointer<CodeEditorData> data;
};

#endif // CODEEDITOR_H
