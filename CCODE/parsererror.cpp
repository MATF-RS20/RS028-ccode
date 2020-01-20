#include "parsererror.h"

ParserError::ParserError()
{
    status = new QStatusBar();
    label = new QLabel();
    status->addPermanentWidget(label);
    status->insertPermanentWidget(0,label);

}


void ParserError::message(std::string msg, bool correct){
    if(correct)
        label->setStyleSheet("QLabel {background-color : green;}");
    else
        label->setStyleSheet("QLabel {background-color : red;}");

    label->setText(QString::fromStdString(msg));


}


