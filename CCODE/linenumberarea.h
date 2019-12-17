#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H

#include "editor.h"
class Editor;

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(Editor *editor);

protected:
    void paintEvent(QPaintEvent *event);
    QSize sizeHint() const;
private:
    Editor *m_editor;
};

#endif // LINENUMBERAREA_H
