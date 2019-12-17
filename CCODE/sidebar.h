#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QBoxLayout>

class SideBar : public QWidget
{
    Q_OBJECT
public:
    explicit SideBar(QWidget *parent = nullptr);

signals:
private:
    QSizePolicy m_sizePolicy;
    QBoxLayout* m_layout;
};

#endif // SIDEBAR_H
