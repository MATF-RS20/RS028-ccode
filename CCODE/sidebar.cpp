#include "sidebar.h"

SideBar::SideBar(QWidget *parent) : QWidget(parent)
{
    m_sizePolicy = QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_sizePolicy.setHorizontalStretch(1);
    setSizePolicy(m_sizePolicy);
    m_layout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    m_openDocuments = OpenDocuments::instance(this);

    m_layout->addWidget(m_openDocuments);
}

SideBar* SideBar::m_instance = 0;

SideBar* SideBar::instance(QWidget *parent) {
    if (!m_instance) {
        m_instance = new SideBar(parent);
    }

    return m_instance;
}
