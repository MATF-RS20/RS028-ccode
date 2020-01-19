#ifndef PARSERERROR_H
#define PARSERERROR_H

#include <iostream>
#include <QLineEdit>
class ParserError
{
public:
    ParserError();
    void add(std::string err);
    void good(std::string msg);
    QDialog *a;
};

#endif // PARSERERROR_H
