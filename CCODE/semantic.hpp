#ifndef __SEMANTIC_HPP__
#define __SEMANTIC_HPP__ 

#include <string>
#include <vector>
#include <iostream>

class Function_variable;
class Function_declaration;
class Declaration_specifiers;
class Variable;
class Init_declarator;
class Value;

extern int loop_activ;
extern int swith_active;

class AllDeclaration {
public:
    AllDeclaration();
    virtual ~AllDeclaration()
    {}
    virtual void ispis(int d = 0) const = 0;
};

class Include_declaration : public AllDeclaration{
public:
    Include_declaration(char c, std::string s)
        :_s(s),_c(c)
    {}
    void ispis(int d = 0) const;
private:
    std::string _s;
    char _c;

};

class Other_declaration : public AllDeclaration{
public:
    Other_declaration(std::vector<AllDeclaration*> v)
        : _v(v)
    {}
    ~Other_declaration();
    void ispis(int d=0) const;
private:
    Other_declaration(const Other_declaration &o);
    Other_declaration& operator=(const Other_declaration &o);
    std::vector<AllDeclaration*> _v;
};


class Declaration_specifiers : public AllDeclaration{
public:
    Declaration_specifiers(std::string type_specifier, std::string type_qualifier="")
        :_type_specifier(type_specifier),_type_qualifier(type_qualifier)
    {}
    void ispis(int d=0) const;
private:
    std::string _type_specifier,_type_qualifier;
};

class Declarator : public AllDeclaration{
public:
    Declarator(AllDeclaration *d,int num_pointer)
        : _d(d),_num_pointer(num_pointer)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d;
    int _num_pointer;
};





// class Function_inicialization : public AllDeclaration{
// public:
//     Function_inicialization(std::string s, std::vector<std::string*> v=std::vector<std::string*>())
//         :_s(s),_v(v)
//     {}
//     void ispis(int d=0) const;
// private:
//     std::string _s;
//     std::vector<std::string*> _v;
// };

class Array : public AllDeclaration{
public:
    Array(std::string s)
        :_s(s)
    {}
    void ispis(int d=0) const;
private:
    std::string _s;
};



class Function_variable : public AllDeclaration{
public:
    Function_variable(AllDeclaration* d1, AllDeclaration *d2)
        : _d1(d1), _d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration* _d1,*_d2;
};

class Function_name : public AllDeclaration{
public:
    Function_name(std::string s,int num_pointer)
        : _s(s),_num_pointer(num_pointer)
    {}
    void ispis(int d=0) const;
private:
    std::string _s;
    int _num_pointer;
};


class Function_declaration : public AllDeclaration{
public:
    Function_declaration (Function_variable *f, std::vector<AllDeclaration*> v, AllDeclaration* d)
        : _f(f), _v(v), _d(d)
    {}
    void ispis(int d=0) const;
private:
    Function_variable *_f;
    std::vector<AllDeclaration*> _v;
    AllDeclaration* _d;
};



class Variable : public AllDeclaration{
public:
    Variable(AllDeclaration *d1, AllDeclaration *d2)
        : _d1(d1), _d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1,*_d2;
};


class Init_declarator : public AllDeclaration{
public:
    Init_declarator(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1,*_d2;
};


class Declaration : public AllDeclaration{
public:
    Declaration(AllDeclaration *d, std::vector<AllDeclaration*> v)
        :_d(d),_v(v)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d; 
    std::vector<AllDeclaration*> _v;    
};


class Block_item_list : public AllDeclaration{
public:
    Block_item_list(std::vector<AllDeclaration*> v=std::vector<AllDeclaration*>())
        :_v(v)
    {}
    void ispis(int d=0) const;
private:
    std::vector<AllDeclaration*> _v;
};


class Case : public AllDeclaration{
public:
    Case(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Default : public AllDeclaration{
public:
    Default(AllDeclaration *d1)
        :_d1(d1)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1;
};

class Switch : public AllDeclaration{
public:
    Switch(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {
        swith_active++;
    }
    ~Switch(){
        swith_active--;
        if(swith_active<0)
            std::cout << "greeeeeeska";
    }
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class If_else : public AllDeclaration{
public:
    If_else(AllDeclaration *d1, AllDeclaration *d2, AllDeclaration *d3)
        :_d1(d1),_d2(d2),_d3(d3)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2, *_d3;
};

class If_statement : public AllDeclaration{
public:
    If_statement(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};


class While : public AllDeclaration{
public:
    While(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {
        loop_activ++;
    }
    ~While(){
        loop_activ--;
        if(loop_activ<0)
            std::cout << "greeeeeeska";
    }
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Do_while : public AllDeclaration{
public:
    Do_while(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {
        loop_activ++;
    }
    ~Do_while(){
        loop_activ--;
        if(loop_activ<0)
            std::cout << "greeeeeeska";
    }
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};


class For_statement_3 : public AllDeclaration{
public:
    For_statement_3(AllDeclaration *d1, AllDeclaration *d2, AllDeclaration *d3, AllDeclaration *d4)
        :_d1(d1),_d2(d2),_d3(d3),_d4(d4)
    {
        loop_activ++;
    }
    ~For_statement_3(){
        loop_activ--;
        if(loop_activ<0)
            std::cout << "greeeeeeska";
    }
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2, *_d3, *_d4;
};

class For_statement_2 : public AllDeclaration{
public:
    For_statement_2(AllDeclaration *d1, AllDeclaration *d2, AllDeclaration *d3)
        :_d1(d1),_d2(d2),_d3(d3)
    {
        loop_activ++;
    }
    ~For_statement_2(){
        loop_activ--;
        if(loop_activ<0)
            std::cout << "greeeeeeska";
    }
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2, *_d3;
};

class For_expression : public AllDeclaration{
public:
    For_expression(AllDeclaration *d)
        :_d(d)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d;
}; 


class For_declaration : public AllDeclaration{
public:
    For_declaration(AllDeclaration *d, std::vector<AllDeclaration*> v)
        :_d(d),_v(v)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d; 
    std::vector<AllDeclaration*> _v;    
};


class Continue : public AllDeclaration{
public:
    Continue(){
        is_correct=1;
        if(loop_activ<=0)
            is_correct=0;
    }
    void ispis(int d=0) const;
private:
    int is_correct;
};

class Break : public AllDeclaration{
public:
    Break(){
        is_correct=1;
        if(loop_activ<=0)
            is_correct=0;
    }
    void ispis(int d=0) const;
private:
    int is_correct;
};

class Return : public AllDeclaration{
public:
    Return(AllDeclaration *d)
        :_d(d)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d;
};

class Expression : public AllDeclaration{
public:
    Expression(AllDeclaration *d)
        :_d(d)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d;
};

class Ternary_conditional : public AllDeclaration{
public:
    Ternary_conditional(AllDeclaration *d1, AllDeclaration *d2, AllDeclaration *d3)
        :_d1(d1),_d2(d2),_d3(d3)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2, *_d3;
};


class Comma : public AllDeclaration{
public:
    Comma(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Assigment : public AllDeclaration{
public:
    Assigment(std::string s, std::string operand, AllDeclaration *d)
        :_s(s),_operand(operand),_d(d)
    {}
    void ispis(int d=0) const;
private:
    std::string _s,_operand;
    AllDeclaration *_d;
};

class Logical_OR : public AllDeclaration{
public:
    Logical_OR(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Logical_AND : public AllDeclaration{
public:
    Logical_AND(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Bitwise_OR : public AllDeclaration{
public:
    Bitwise_OR(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Bitwise_XOR : public AllDeclaration{
public:
    Bitwise_XOR(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Bitwise_AND : public AllDeclaration{
public:
    Bitwise_AND(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Not_equal : public AllDeclaration{
public:
    Not_equal(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Equal : public AllDeclaration{
public:
    Equal(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Less : public AllDeclaration{
public:
    Less(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Greater : public AllDeclaration{
public:
    Greater(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Less_or_equal : public AllDeclaration{
public:
    Less_or_equal(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Greater_or_equal : public AllDeclaration{
public:
    Greater_or_equal(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Bitwise_left_shift : public AllDeclaration{
public:
    Bitwise_left_shift(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Bitwise_right_shift : public AllDeclaration{
public:
    Bitwise_right_shift(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Addition : public AllDeclaration{
public:
    Addition(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Subtraction : public AllDeclaration{
public:
    Subtraction(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Multiplication : public AllDeclaration{
public:
    Multiplication(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Division : public AllDeclaration{
public:
    Division(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Remainder : public AllDeclaration{
public:
    Remainder(AllDeclaration *d1, AllDeclaration *d2)
        :_d1(d1),_d2(d2)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d1, *_d2;
};

class Cast_expression : public AllDeclaration{
public:
    Cast_expression(std::string s, AllDeclaration *d)
        :_s(s),_d(d)
    {}
    void ispis(int d=0) const;
private:
    std::string _s;
    AllDeclaration *_d;
};

class Prefix_decrement : public AllDeclaration{
public:
    Prefix_decrement(std::string s)
        :_s(s)
    {}
    void ispis(int d=0) const;
private:
    std::string _s;
};

class Prefix_increment : public AllDeclaration{
public:
    Prefix_increment(std::string s)
        :_s(s)
    {}
    void ispis(int d=0) const;
private:
    std::string _s;
};


class Unary_operator : public AllDeclaration{
public:
    Unary_operator(std::string s, AllDeclaration *d)
        :_s(s),_d(d)
    {}
    void ispis(int d=0) const;
private:
    std::string _s;
    AllDeclaration *_d;
};

class Sizeof : public AllDeclaration{
public:
    Sizeof(AllDeclaration *d)
        :_d(d)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d;
};

class Sizeof_type : public AllDeclaration{
public:
    Sizeof_type(std::string s)
        :_s(s)
    {}
    void ispis(int d=0) const;
private:
    std::string _s;
};

class Function_caller : public AllDeclaration{
public:
    Function_caller(std::string s, std::vector<AllDeclaration*> v=std::vector<AllDeclaration*>())
        :_s(s),_v(v)
    {}
    void ispis(int d=0) const;
private:
    std::string _s;
    std::vector<AllDeclaration*> _v;
};

class Postfix_decrement : public AllDeclaration{
public:
    Postfix_decrement(std::string s)
        :_s(s)
    {}
    void ispis(int d=0) const;
private:
    std::string _s;
};

class Postfix_increment : public AllDeclaration{
public:
    Postfix_increment(std::string s)
        :_s(s)
    {}
    void ispis(int d=0) const;
private:
    std::string _s;
};


class Id : public AllDeclaration{
public:
    Id(std::string s)
        :_s(s)
    {}
    void ispis(int d=0) const;
private:
    std::string _s;
};

class Integer : public AllDeclaration{
public:
    Integer(int i)
        :_i(i)
    {}
    void ispis(int d=0) const;
private:
    int _i;
};

class Float : public AllDeclaration{
public:
    Float(float f)
        :_f(f)
    {}
    void ispis(int d=0) const;
private:
    float _f;
};

class String_literal : public AllDeclaration{
public:
    String_literal(std::string s)
        :_s(s)
    {}
    void ispis(int d=0) const;
private:
    std::string _s;
};

class Brackets : public AllDeclaration{
public:
    Brackets(AllDeclaration *d)
        :_d(d)
    {}
    void ispis(int d=0) const;
private:
    AllDeclaration *_d;
};

class Union_access : public AllDeclaration{
public:
    Union_access(std::string s1, std::string s2)
        :_s1(s1),_s2(s2)
    {}
    void ispis(int d=0) const;
private:
    std::string _s1,_s2;
};

class Pointer_access : public AllDeclaration{
public:
    Pointer_access(std::string s1, std::string s2)
        :_s1(s1),_s2(s2)
    {}
    void ispis(int d=0) const;
private:
    std::string _s1,_s2;
};



class Array_subscripting : public AllDeclaration{
public:
    Array_subscripting(std::string s1, AllDeclaration *d)
        :_s1(s1),_d(d)
    {}
    void ispis(int d=0) const;
private:
    std::string _s1;
    AllDeclaration *_d;
};

// class Function{
// public:
//     Function{type_specifier, type_qualifier, std::map<std::string,Type_value>, pointer}
// }
// 
// class Type_value{
// public:
//     Type_value(type_specifier, type_qualifier, value, pointer, array)
// }




#endif
