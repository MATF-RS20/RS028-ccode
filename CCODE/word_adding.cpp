#include "word_adding.h"

word_adding::word_adding()
{

}

void word_adding::add_word(std::string s){
    std::cout << s << std::endl;
}

void word_adding::word_checking(std::map<std::string,int> map){
    for (auto word : map)
        add_word(word.first);
}
