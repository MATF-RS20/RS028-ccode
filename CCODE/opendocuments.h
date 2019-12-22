#ifndef OPENDOCUMENTS_H
#define OPENDOCUMENTS_H

#include <QWidget>
#include <QListView>
#include <QBoxLayout>
#include <QLabel>
#include <QListWidget>
#include "codeeditor.h"

class OpenDocuments : public QWidget
{
    Q_OBJECT
public:

    static OpenDocuments* instance(QWidget *parent = nullptr);

signals:

private:
    explicit OpenDocuments(QWidget *parent = nullptr);
    static OpenDocuments* m_instance;

    QBoxLayout* m_documents;
    QListView* m_list;
};

#endif // OPENDOCUMENTS_H
