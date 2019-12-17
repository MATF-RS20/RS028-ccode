#include "sidebar.h"

SideBar::SideBar(QWidget *parent) : QWidget(parent)
{
    m_sizePolicy = QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_sizePolicy.setHorizontalStretch(1);
    setSizePolicy(m_sizePolicy);
    m_layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    auto w1 = new QWidget();
    auto w2 = new QWidget();
    w1->setStyleSheet("background-color: 'red';");
    w2->setStyleSheet("background-color: 'red'");
    m_layout->addWidget(w1);
    m_layout->addWidget(w2);
}
