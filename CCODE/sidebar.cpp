#include "sidebar.h"

SideBar::SideBar(QWidget *parent) : QWidget(parent)
{
    m_sizePolicy = QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_sizePolicy.setHorizontalStretch(1);
    setSizePolicy(m_sizePolicy);
    m_layout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    m_openDocuments = OpenDocuments::instance();

    m_layout->addWidget(m_openDocuments);
    setColor();
}

SideBar* SideBar::m_instance = 0;

SideBar* SideBar::instance(QWidget *parent) {
    if (!m_instance) {
        m_instance = new SideBar(parent);
    }

    return m_instance;
}

void SideBar::setColor()
{
    QPalette p = this->palette();

    p.setColor(QPalette::Active, QPalette::Base, QColor(227, 242, 255));
    p.setColor(QPalette::Inactive, QPalette::Base, QColor(185, 185, 190));

    this->setPalette(p);
}
