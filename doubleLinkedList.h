#include <iostream>
#ifndef LIST_H
#define LIST_H

using std::cout;

typedef int T;

namespace cs61003
{

class Node
{
  friend class list;
  friend class list_iterator;

  public:  
    Node(const T& data, Node* prev, Node* next)
     :_data(data),
      _prev(prev),
      _next(next)
     { }
    
  private:
      T    _data;
      Node* _prev;
      Node* _next;
};

class list_iterator
{
  public:
    //constructor
    list_iterator(Node *n)
      :node(n)
    {}

    list_iterator& operator++();
    list_iterator& operator--();
    bool operator!=(const list_iterator&);
    T& operator*() const
    {return (*node)._data;}

    Node* node;

};

class list
{
  public:
    typedef list_iterator iterator;

    list()
      :_head(0),_tail(0)
      {}
    list(const list&);
    ~list();
    
    void push_front(const T&);
    void pop_front();
    void push_back(const T&);
    void pop_back();
    bool empty() const {return !_head;}
    int size() const;
    void swap(list&);    
    list& operator=(const list&);
    
    void insert(iterator, const T&);
    //void splice(iterator, list&, iterator, iterator);

    iterator begin() const 
     {
    // iterator *p1=new iterator(_head);
    // return *p1;
       return iterator(_head);
     }
    
    iterator end() const 
    {
      //iterator *p2=new iterator(_tail->_next);
      return iterator(_tail->_next);
    }

    T& front()
      {return _head->_data;}
    T front() const 
      {return _head->_data;}
    T& back()
      {return _tail->_data;}
    T back() const
      {return _tail->_data;}
   

    void output() const;
  private:
    Node *_head;
    Node *_tail;

};


}

#endif
