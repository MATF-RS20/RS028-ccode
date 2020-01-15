#ifndef EDITOR_H
#define EDITOR_H

#include <QPlainTextEdit>
#include <QWidget>
#include <QPainter>
#include <QTextBlock>
#include <QListWidgetItem>
#include "linenumberarea.h"
#include "parser.h"
#include "lexer.h"
#include <QCompleter>
#include <QScrollBar>


class Editor : public QPlainTextEdit, public QListWidgetItem
{
    Q_OBJECT

public:
    Editor(std::string path = "", QWidget *parent = 0);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
    std::string name() const;
    void setCompleter(QCompleter *c);
    QCompleter *completer() const;


protected:
    void resizeEvent(QResizeEvent *event);
    void keyPressEvent(QKeyEvent *e);
    void focusInEvent(QFocusEvent *e);

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);
    void parser();
    void insertCompletion(const QString &completion);

private:
    QWidget *m_lineNumberArea;
    std::string m_path;
    std::string m_name;
    QString textUnderCursor() const;
    QCompleter *c = nullptr;
};

#endif
