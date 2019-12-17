#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QBoxLayout>

class SideBar : public QWidget
{
    Q_OBJECT
public:
    static SideBar* instance(QWidget *parent = nullptr);

signals:
private:
    explicit SideBar(QWidget *parent = nullptr);
    static SideBar* m_instance;
    QSizePolicy m_sizePolicy;
    QBoxLayout* m_layout;
};

#endif // SIDEBAR_H
