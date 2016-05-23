#include "iterator.h"
#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include <stack>
using namespace std;

class Base;

Iterator::Iterator(Base* ptr) {this->self_ptr = ptr;}
OperatorIterator::OperatorIterator(Base* ptr): Iterator(ptr) {};
void OperatorIterator::first() {this->current_ptr = this->self_ptr->get_left();}
void OperatorIterator::next()
{
    if(this->current_ptr == this->self_ptr->get_left())
    {
        this->current_ptr = this->self_ptr->get_right();
    }
    else if(this->current_ptr == this->self_ptr->get_right())
    {
        this->current_ptr = NULL;
    }
}
bool OperatorIterator::is_done()
{
    if(this->current_ptr == NULL)
    {
        return true;
    }
    return false;
}
Base* OperatorIterator::current() {return this->current_ptr;}

UnaryIterator::UnaryIterator(Base* ptr) : Iterator(ptr) {};
void UnaryIterator::first() {this->current_ptr = this->self_ptr->get_left();}
void UnaryIterator::next()
{
    if(this->current_ptr == this->self_ptr->get_left())
    {
        this->current_ptr = NULL;
    }
}
bool UnaryIterator::is_done()
{
    if(this->current_ptr == NULL)
    {
        return true;
    }
    return false;
}
Base* UnaryIterator::current() {return this->current_ptr;}

NullIterator::NullIterator(Base* ptr) : Iterator(ptr) {};
void NullIterator::first() {return;}
void NullIterator::next() {return;}
bool NullIterator::is_done() {return true;}
Base* NullIterator::current() {return NULL;}

PreOrderIterator::PreOrderIterator(Base* ptr) : Iterator(ptr) {};
void PreOrderIterator::first()
{
   if(!iterators.empty())
   {
       while(!iterators.empty())
       {
          iterators.pop();
       }
   }
   Iterator* temp = this->self_ptr->create_iterator();
   temp->first();
   iterators.push(temp);
   return;
}
void PreOrderIterator::next()
{
    Iterator* p = this->iterators.top()->current()->create_iterator();
    p->first();
    this->iterators.push(p);
    while(this->iterators.size() > 0 && this->iterators.top()->is_done())
    {
       this-> iterators.pop();
        if(!iterators.empty())
        {
            this->iterators.top()->next();
        }
    }
}
bool PreOrderIterator::is_done()
{
   if(iterators.empty())
   {
       return true;
   } 
   return false;
}
Base* PreOrderIterator::current()
{
    if(this->iterators.size() > 0)
    {
     return iterators.top()->current();
    }
    else
    {
        return NULL;
    }
}








