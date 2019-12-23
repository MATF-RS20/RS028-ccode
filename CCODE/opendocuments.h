#ifndef OPENDOCUMENTS_H
#define OPENDOCUMENTS_H

#include <QWidget>
#include <QListView>
#include <QBoxLayout>
#include <QLabel>
#include <QListWidget>
#include "codeeditor.h"

class OpenDocuments : public QListWidget
{
    Q_OBJECT
public:

    static OpenDocuments* instance(QListWidget *parent = nullptr);

signals:

private slots:
    void changeActiveEditor(QListWidgetItem *item);

private:
    explicit OpenDocuments(QListWidget *parent = nullptr);
    static OpenDocuments* m_instance;

    QBoxLayout* m_documents;
    QListView* m_list;
};

#endif // OPENDOCUMENTS_H
