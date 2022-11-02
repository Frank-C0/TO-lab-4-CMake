#ifndef Stack_h
#define Stack_h

template <typename T>
class Stack
{
    // int data;
public:
    // virtual Stack() {}
    // virtual ~Stack() {}
    virtual void push(T) ;
    virtual void pop() ;
    virtual T top() ;
    virtual bool empty() ;
};

#endif