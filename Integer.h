#pragma once
class Integer{

private:
    int Value;
    Integer* next;

public:

    Integer(int value);

    //getters
    int get_Value();
    Integer* get_next();

    //setters
    void set_Value(char value);
    void set_next(Integer* Next);


};

