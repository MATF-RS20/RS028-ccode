#include "semantic.hpp"
#include <iostream>
#include <string>

void Include_declaration::ispis(int d) const{
    std::cout << "#include ";
    if(_c == '<') std::cout << '<' << _s << '>'<<std::endl;
    else std::cout << '"' << _s << '"'<<std::endl;
}

void Other_declaration::ispis(int d) const{
    for (int j = 0; j < d; j++)
    std::cout << "\t";
<<<<<<< HEAD
    for(unsigned i=0; i<_v.size(); i++){
=======
    for(int i=0; i<_v.size(); i++){
>>>>>>> 58c8080627ad54ad116b0d5fcd0fb4d71ebe44b5
        _v[i]->ispis(d);
    }
}


Other_declaration::~Other_declaration(){
<<<<<<< HEAD
    for(unsigned i=0; i<_v.size(); i++){
=======
    for(int i=0; i<_v.size(); i++){
>>>>>>> 58c8080627ad54ad116b0d5fcd0fb4d71ebe44b5
        delete _v[i];
    }
}

void Function_declaration::ispis(int d) const{
    for (int j = 0; j < d; j++)
    std::cout << "\t";
    _f->ispis(d);
    std::cout << '(';
    if (_v.size() !=0){
<<<<<<< HEAD
        unsigned i=0;
=======
        int i=0;
>>>>>>> 58c8080627ad54ad116b0d5fcd0fb4d71ebe44b5
        for(i=0; i<_v.size()-1; i++){
            _v[i]->ispis(d);
            std::cout << ", ";
        }
        _v[i]->ispis(d);
    }
    std::cout << ')';
    _d->ispis(d);
}

void Declaration_specifiers::ispis(int d) const{
    if(_type_qualifier==""){
        std::cout <<_type_specifier << " "; 
    }
    else
        std::cout << _type_qualifier << " " << _type_specifier << " "; 
    
}


void Function_name::ispis(int d) const{
    for(int i =0; i<_num_pointer; i++)
        std::cout << '*';
    std::cout << _s;
}


void Function_variable::ispis(int d) const{
    _d1->ispis(d);
    _d2->ispis(d);
}


void Variable::ispis(int d) const{
    _d1->ispis(d);
    _d2->ispis(d); 
}


void Init_declarator::ispis(int d) const{
    _d1->ispis(d);
    if(_d2){
        std::cout << " = ";
        _d2->ispis(d);
    }
    
}

void Declaration::ispis(int d) const{
    for (int j = 0; j < d; j++)
    std::cout << "\t";
    _d->ispis(d);
    if (_v.size() !=0){
<<<<<<< HEAD
        unsigned i;
=======
        int i;
>>>>>>> 58c8080627ad54ad116b0d5fcd0fb4d71ebe44b5
        for(i=0; i<_v.size()-1; i++){
            _v[i]->ispis(d);
            std::cout << ", ";
        }
        _v[i]->ispis(d);
    }
    std::cout << ";\n";
}


void Block_item_list::ispis(int d) const{
    std::cout << '{' << std::endl;              //TODO razlicite notacije
<<<<<<< HEAD
    for(unsigned i=0; i<_v.size(); i++){
=======
    for(int i=0; i<_v.size(); i++){
>>>>>>> 58c8080627ad54ad116b0d5fcd0fb4d71ebe44b5
        _v[i]->ispis(d+1);
    }                             //TODO ako je _d prazno?
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    std::cout << '}' << std::endl;
}


void Case::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    std::cout << "case ";
    _d1->ispis(d);
<<<<<<< HEAD
    std::cout << ":";
=======
    std::cout << ":\n";
>>>>>>> 58c8080627ad54ad116b0d5fcd0fb4d71ebe44b5
    _d2->ispis(d+1);
}

void Default::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    std::cout << "default:\n";
    _d1->ispis(d+1);
}

void Switch::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    std::cout << "switch(";
    _d1->ispis(d);
    std::cout << ")";
    _d2->ispis(d);
}

void If_else::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    std::cout << "if(";
    _d1->ispis(d);
    std::cout << ")";
    _d2->ispis(d);
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    std::cout << "else";
    _d3->ispis(d);
}


void If_statement::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    std::cout << "if(";
    _d1->ispis(d);
    std::cout << ")";
    _d2->ispis(d);
}


void While::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    std::cout << "while(";
    _d1->ispis(d);
    std::cout << ")";
    _d2->ispis(d);
}


void Do_while::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    std::cout << "do";
    _d1->ispis(d);
    std::cout << "while(";
    _d2->ispis(d);
    std::cout << ");\n";
}

void For_statement_2::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    std::cout << "for(";
    _d1->ispis(d);
    _d2->ispis(d);
    std::cout << ")";
    _d3->ispis(d);
}

void For_statement_3::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    std::cout << "for(";
    _d1->ispis(d);
    _d2->ispis(d);
    _d3->ispis(d);
    std::cout << ")";
    _d4->ispis(d);
}

void For_expression::ispis(int d) const{
    if(_d)
        _d->ispis(d);
    std::cout << "; ";
}




void For_declaration::ispis(int d) const{
    _d->ispis(d);
    if (_v.size() !=0){
<<<<<<< HEAD
        unsigned i;
=======
        int i;
>>>>>>> 58c8080627ad54ad116b0d5fcd0fb4d71ebe44b5
        for(i=0; i<_v.size()-1; i++){
            _v[i]->ispis(d);
            std::cout << ", ";
        }
        _v[i]->ispis(d);
    }
    std::cout << "; ";
}


void Continue::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    if(!is_correct){
        std::cout << "continue;";
        std::cout << "_\t_continue nije u petlji\n";
    }else
        std::cout << "continue;\n";
}

void Break::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    if(!is_correct){
        std::cout << "break;";
        std::cout << "_\t_break nije u petlji\n";
    }else
        std::cout << "break;\n";
}

void Return::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    std::cout << "return";
    if(_d){
        std::cout << " ";
        _d->ispis(d);
    }
    std::cout << ";\n";
}


void Expression::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "\t";
    if(_d)
        _d->ispis(d);
    std::cout << ";\n";
}

void Comma::ispis(int d) const{
    _d1->ispis(d);
    std::cout << ", ";
    _d2->ispis(d);
}

void Assigment::ispis(int d) const{
    std::cout << _s << ' ' << _operand << ' ';
    _d->ispis(d);
}

void Ternary_conditional::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " ? ";
    _d2->ispis(d);
    std::cout << " : ";
}

void Logical_OR::ispis(int d) const{
    for (int j = 0; j < d; j++)
        std::cout << "_";
    _d1->ispis(d);
    std::cout << " || ";
    _d2->ispis(d);
}

void Logical_AND::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " && ";
    _d2->ispis(d);
}

void Bitwise_OR::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " | ";
    _d2->ispis(d);
}

void Bitwise_XOR::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " ^ ";
    _d2->ispis(d);
}

void Bitwise_AND::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " & ";
    _d2->ispis(d);
}

void Not_equal::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " != ";
    _d2->ispis(d);
}

void Equal::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " == ";
    _d2->ispis(d);
}

void Less::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " < ";
    _d2->ispis(d);
}

void Greater::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " > ";
    _d2->ispis(d);
}

void Less_or_equal::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " <= ";
    _d2->ispis(d);
}

void Greater_or_equal::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " >= ";
    _d2->ispis(d);
}

void Bitwise_left_shift::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " << ";
    _d2->ispis(d);
}

void Bitwise_right_shift::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " >> ";
    _d2->ispis(d);
}

void Addition::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " + ";
    _d2->ispis(d);
}

void Subtraction::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " - ";
    _d2->ispis(d);
}

void Multiplication::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " * ";
    _d2->ispis(d);
}

void Division::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " / ";
    _d2->ispis(d);
}

void Remainder::ispis(int d) const{
    _d1->ispis(d);
    std::cout << " % ";
    _d2->ispis(d);
}

void Cast_expression::ispis(int d) const{
    std::cout << "(" << _s << ")";
    _d->ispis(d);
}


void Prefix_decrement::ispis(int d) const{
    std::cout << "--" << _s;
}

void Prefix_increment::ispis(int d) const{
    std::cout << "++" << _s;
}

void Unary_operator::ispis(int d) const{
    std::cout << _s;
    _d->ispis(d);
}

void Sizeof::ispis(int d) const{
    std::cout << "sizeof ";
    _d->ispis(d);
}

void Sizeof_type::ispis(int d) const{
    std::cout << "sizeof (" << _s << ")";
}


void Function_caller::ispis(int d) const{
    std::cout << _s << "(";
    if (_v.size() !=0){
<<<<<<< HEAD
        unsigned i;
=======
        int i;
>>>>>>> 58c8080627ad54ad116b0d5fcd0fb4d71ebe44b5
        for(i=0; i<_v.size()-1; i++){
            _v[i]->ispis(d);
            std::cout << ", ";
        }                             //TODO ako je _d prazno?
        _v[i]->ispis(d);
    }
    std::cout << ")";
}

void Postfix_increment::ispis(int d) const{
    std::cout << _s << "++";
}

void Postfix_decrement::ispis(int d) const{
    std::cout << _s << "++";
}

void Id::ispis(int d) const{
    std::cout << _s;
}

void Integer::ispis(int d) const{
    std::cout << _i;
}

void Float::ispis(int d) const{
    std::cout << _f;
}

void String_literal::ispis(int d) const{
    std::cout << "\"" <<_s << "\"";
}

void Brackets::ispis(int d) const{
    std::cout << "(";
    _d->ispis();
    std::cout << ")";
}


void Union_access::ispis(int d) const{
    std::cout << _s1 << "." << _s2;
}


void Pointer_access::ispis(int d) const{
    std::cout << _s1 << "->" << _s2;
}

// void Function_inicialization::ispis(int d) const{
//     std::cout << _s << "(";
//     if(_v.size()){
//         int i;
//         for(i = 0; i < _v.size()-1; i++){
//             std::cout << _v[i];
//             std::cout << ", ";
//         }
//         std::cout << _v[i];
//     }
//     std::cout << ")";
//         
// }

void Array::ispis(int d) const{
    std::cout << _s << "[]";
}


void Array_subscripting::ispis(int d) const{
    std::cout << _s1 << "[";
    _d->ispis(d);
    std::cout << "]";
}

void Declarator::ispis(int d) const{
    for(int i =0; i<_num_pointer; i++)
        std::cout << '*';
    _d->ispis(d);
}

