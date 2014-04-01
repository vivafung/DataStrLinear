#include <iostream>
#include <iomanip>
#include "list.h"

using std::cout;

namespace cs61003
{

list::list(const list& xx)
  :_head(0),_tail(0)
{
  std::cout << "copy constructor called" << "\n";
  //if copying list is empty then we are done 
  if(xx._head == 0)
    {return;}
  //there are 1 or more nodes in xx
  //do the first node 
  _head = new Node((*xx._head)._data,0,0);
  _tail = _head;

  //if there's only one node in existing we're done
  if((*xx._head)._next == 0)
    return;

  //more than 1 node
  Node *eptr = (*xx._head)._next;
  Node *prevptr = _head;
  Node *nptr;

  while(eptr != 0)
  {
    //allocate, init next node in this object
    nptr = new Node((*eptr)._data,0,0);

    //make the previous node point to the new one
    prevptr->_next = nptr;

    //set up our list pointers for the next iteration
    prevptr = nptr;
    eptr = eptr->_next;
  }

  //init tail
  _tail = nptr;
}


list::~list()
{
  //std::cout << "destructor called" << "\n";
  while (!empty())
    pop_front();
}

list& list::operator=(const list& xx)
{
  //make a copy of the right operand of the assignment
  list tmp(xx);

  //swap
  swap(tmp);

  return *this;
}

void list::swap(list& other)
{
  std::swap(_head, other._head);
  std::swap(_tail, other._tail);
}

void list::insert(iterator it, const T& x)
{
  Node *nptr = new Node(x, it.node->_prev->_next, it.node->_prev);

  if(it.node->_prev == 0)
  push_front(x);

  else
  {
    it.node->_prev->_next = nptr->_prev;
    it.node->_prev = nptr->_next;

  }
}

/*
void list::splice(iterator pos, list& src, iterator srcBegin, iterator srcEnd)
{

}
*/

void list::push_front(const T& x)
{
  //allocate a node(init by the node constructor)
  Node *nptr = new Node(x,0,_head);
  if(_head)
  {
    //list is not empty
    _head->_prev = nptr->_next;
    _head = nptr;
  }
  else
  {
    //list is empty
    _head = nptr;
    _tail = nptr;
  }

}

void list::pop_front()
{
  //get a pointer to the first node
  Node *nptr = _head;
  if(_head->_next == 0)
    {
      //list has only one element
      _head = _tail = 0;
    }
  else
    {
      //list has more than one element
      _head = _head->_next;
      _head->_prev = 0;

    }
  //free the memory
  delete nptr;

}
 
int list::size() const
{
  int i=0;
  Node *nptr = _head;
  while(nptr != 0)
    {
      ++i;
      nptr = nptr->_next; 
      //why not "nptr = _head->_next;"
    }
    return i;
}

void list::push_back(const T& x)
{
  //get the new node
  Node *nptr = new Node(x,0,0);
  if(_head)
  {
    //list is not empty
    _tail->_next = nptr;
    nptr->_prev = _tail;
    _tail = nptr;

  }
  else
  {
    //list is empty
    _head = _tail = nptr;
  }

}

void list::pop_back()
{
  //get a pointer to the last node
  Node *nptr = _tail;
  if(_head->_next == 0)
  {
    //list has one element
    _head = _tail = 0;
  }
  else
  {
    //list has more than one element
    //fine the next-to-last node in the list
    Node *ptr = _head;
    while(ptr->_next->_next != 0)
    {
      ptr = ptr->_next;
    }
    ptr->_next = 0;
    _tail = ptr;
  }
  //
  delete nptr;

}


list_iterator& list_iterator::operator++()
{
  node = node->_next;
  return *this;
}

list_iterator& list_iterator::operator--()
{
  node = node->_prev;
  return *this;
}


bool list_iterator::operator!=(const list_iterator& x) 
{
  return node != x.node;
}

//---------------------------------------------------------------------------
// Assumes a 0 in _next member of last node
// Requires: #include<iomanip>

void list::output() const
{
    const int FIELD_WIDTH = 9;

    // Output header info
    std::cerr << "==========================================================\n";
    std::cerr << "_head = " << _head   << '\n';
    std::cerr << "_tail = " << _tail   << '\n';
  //std::cerr << " size = " <<  size() << '\n';

    // Pointers to current node and previous node
    Node* nptr = _head;
    Node* pptr = 0;
    int ctr = 0;
    while( nptr != 0)
    {
      std::cerr               << std::setw(3)           << ctr         << "  ";
      std::cerr << "addr = "  << std::setw(FIELD_WIDTH) << nptr        << "   ";
      std::cerr << "_prev = " << std::setw(FIELD_WIDTH) << nptr->_prev << "   ";
      std::cerr << "_next = " << std::setw(FIELD_WIDTH) << nptr->_next << "   ";
      std::cerr << "_data = " <<                           nptr->_data << "   ";
 
      // Check back from here and previous node to current node
      if (pptr && nptr->_prev != pptr)
          std::cerr << "  _prev bad";
      if (pptr && nptr->_prev->_next != nptr)
          std::cerr << "  _prev->_next bad";

      std::cerr << "\n";

      // Move pointers along
      pptr = nptr;
      nptr = nptr->_next;
      ++ctr;
    }
    std::cerr << '\n';
}


}
