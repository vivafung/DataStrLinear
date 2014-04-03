#include <iostream>
#include <iomanip>
#include "queue.h"

using std::cout;

queue::queue(const queue& xx)
  :_head(0),_tail(0)
{
  _head = new Node((*xx._head)._data,0);
  _tail = _head;
  //one node only
  if((*xx._head)._next == 0)
    return;

  //more than one node
  Node *eptr = (*xx._head)._next;
  Node *nptr;

  while(eptr != 0)
    {
    nptr = new Node(const (*eptr)._data,0);
    (*xx._head)._next = nptr;
    _head = nptr;
    }
    _tail = NULL;
}


queue::~queue()
{
  while(!empty())
    pop_front();

}

void queue::push_back(const T& xx)
{
  //get a new node
  Node *nptr = new Node(xx,0);
  if(_head)
    {
      //queue is not empty
      _tail->_next = nptr;
      //_tail = nptr;
      _tail = NULL;
    }
  else
    {
      //queue is empty
      _head = _tail = nptr;
    }
}


void queue::pop_front()
{
  //get a pointer to the first node
  Node *nptr = _head;
  if(_head->_next == 0)
    {
    //queue only has one element
    _head = _tail = 0;
    }
  else
    {
    //queue has more than one element
    _head = _head->_next;
    }
  //free memory
  //delete *nptr;
}


int queue::size() const
{
  int i=0;
  Node *nptr = _head;
  while(nptr != 0)
    {
      ++i;
      nptr = nptr->_next;
    }
}

