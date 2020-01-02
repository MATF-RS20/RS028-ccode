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
#include "semantic.hpp"


class Editor : public QPlainTextEdit, public QListWidgetItem
{
    Q_OBJECT

public:
    Editor(std::string path = "", QWidget *parent = 0);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
    std::string name() const;

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);
    void parser();

private:
    QWidget *m_lineNumberArea;
    std::string m_path;
    std::string m_name;
};

#endif
