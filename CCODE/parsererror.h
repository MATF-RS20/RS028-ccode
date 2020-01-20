#ifndef PARSERERROR_H
#define PARSERERROR_H

#include <iostream>
#include <QStatusBar>
#include <QLabel>
class ParserError
{
public:
    ParserError();
    ParserError(ParserError &p){
        status=p.status;
        label=p.label;
    }
    void message(std::string msg, bool correct);
    QStatusBar *status=nullptr;

private:
    QLabel *label;
};

#endif // PARSERERROR_H
