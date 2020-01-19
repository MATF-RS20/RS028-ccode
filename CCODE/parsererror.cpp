#include "parsererror.h"

ParserError::ParserError()
{
//    a = new QDialog();
//    a->show();

}


void ParserError::add(std::string err){
    std::cout << err << " ";
}

void ParserError::good(std::string msg){
    std::cout << msg << " ";
}
