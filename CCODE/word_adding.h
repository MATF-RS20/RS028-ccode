#ifndef WORD_ADDING_H
#define WORD_ADDING_H

#include <iostream>
#include <map>
#include <vector>
class word_adding
{
public:
    word_adding();
    void word_checking(std::map<std::string,int> map);
private:
    void delete_word(std::string s);
    void add_word(std::string s);
    std::vector<std::string> words;
};

#endif // WORD_ADDING_H
