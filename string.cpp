#include <iostream>
#include <cassert>
#include <cstring>
#include "string.h"

using std::cin;
using std::cout;
using std::cerr;

namespace cs61003
{

string::string()
      :_size(0),_capacity(0),_data(0)
      {}

string::string(const string& xx)
      :_size(xx._size),
       _capacity(xx._size),
       _data(0)
{
  if(!xx._capacity)
    return;
  _data = new char [xx._size];
  strncpy(_data, xx._data, _size);

}

string::~string()
{
  if(_data)
    delete [] _data;
}

string::string(int n,char c)
      :_size(n),
       _capacity(_size),
       _data(new char [_size])
{
  for(int i=0; i < _size; ++i)
    *(_data + i) = c;
}

char* string::c_str()
{
  //determine the new capacity
  if(_size == _capacity)
    {if(_capacity != 0)
      _capacity *= 2;
     else
       _capacity = 1;
    }

  //get new memory 
  char* ptr = new char [_capacity];

  //copy old data to new memory
  memcpy(ptr,_data,_size);

  //delete old memory
  if(_data)
    delete [] _data;
  
  //make pointer pointed to new memory
  _data = ptr;
  assert (ptr != NULL);
  //push back
  _data[_size] = '\0';

  return ptr;
}


bool string::operator==(const string& xx)
{
  // Can't be equal if the lengths are different
  if (_size != xx._size)
      return false;

  if(_size == xx._size)
  {
  int a = strncmp(_data,xx._data,_size);
  if(a==0)
    return true;
  else
    return false;
  }
}

void string::swap(string& xx)
{
  std::swap(_size, xx._size);
  std::swap(_capacity, xx._capacity);
  std::swap(_data, xx._data);
}

string& string::operator=(const string& xx)
{
  //delete old memory
  if(_data)
    delete [] _data;
  
  //init 
  _size = xx._size;
  _capacity = xx._capacity;

  //allocate new memory
  _data = new char [_capacity];

  //assign
  for(int i = 0; i < _size; ++i)
    _data[i] = xx._data[i];

  return *this;
}

string& string::operator+=(const char c)
{
  if(_size == _capacity) 
    {if(_capacity == 0)
  
    _capacity = 1;
  else
    _capacity *= 2;
   }
    
  int need = _size + 1;
  increase_capacity(need);
  _data[_size] = c;
  ++_size;
  return *this;
}
    
void string::increase_capacity(int need)
{
/*
  if(_capacity == 0)
    _capacity = 1;
  else
    _capacity *= 2;
*/
  //get new memory
  char* ptr = new char [need];
  _capacity = need;

  //copy data to new memory
  memcpy(ptr,_data,_size);
  
  //delete old memory
  if(_data)
    delete [] _data;

  //make pointer pointed to new memory
  _data = ptr;
 
}

string string::operator+(const char c)
{ 
  string xx(*this);
  xx += c;
  return xx;
}

string& string::operator+=(const string xx)
{
  //function call
  int need = _size + xx._size;
  while(need > _capacity) 
    {increase_capacity(need);}
     
  //add string
  for(int i = _size; i < need; ++i)
    {
      _data[i] = xx._data[i-_size];
    }
  _size += xx._size;  
  return *this;
}


string string::operator+(const string& xx)
{
  string a(*this);
  a += xx;
  return a;
}


void string::resize(int x)
{
  string a(*this);
  if(_capacity < x)
    increase_capacity(x);

  (*this)._size = x;
  

}

bool string::operator<(const string& xx)
{ 
  if(_size == 0 && xx._size != 0)
  {return true;}
    
  if(_size == 0 && xx._size == 0)
    {return false;}
  if(_size != 0 && xx._size == 0)
    {return false;}
  int a = strncmp(_data,xx._data,_size);
  
  if(a < 0)
        {return true;}
  if(a == 0 && (_size < xx._size))
    {return true;}
  else
    return false;
  

}

bool string::operator<=(const string& xx)
{
  if((*this) == xx || (*this) < xx)
    return true;
  else 
    return false;
}

bool string::operator>(const string& xx)
{

  if((*this) == xx || (*this) < xx)
    return false;
  else 
    return true;
}


bool string::operator>=(const string& xx)
{

  if((*this) < xx)
    return false;
  else 
    return true;

}

bool string::operator!=(const string& xx)
{
  if((*this) == xx)
    return false;
  else
    return true;
}

string string::substr(int POS, int LEN)
{
  string xx(*this);
  string zz;
  zz._size = LEN;
  zz._capacity = LEN;
  zz._data = new char [LEN];

  for(int i = 0; i < LEN; ++i)
    zz._data[i] = xx._data[POS + i];
  
  return zz;
}


std::ostream& operator<<(std::ostream& out_stream, string& x)
{
  string x;
  oout_stream << x;
  return out_stream;

}

/*
std::istream& operator>>(std::istream& in_stream, string& x)
{



}
*/


/*
int string::find(const string& str)
{
  string xx(*this);
  for(int i = 0; i < str._size; ++i)
    {
    int j = 0;
    if(str._data[i] == _data[i+j])
    {
    for(int j; j < _size - str._size + 1; ++j)
         return i;
    }
     else
         return -1;
    }  
}



int string::find(const string& str, int start_index)
{
  string xx(*this);
  int i,j;
  i=j=0;
  for(int i; i < str._size; ++i)
    {
   
      if(str._data[i] == _data[i+j])
        {
         for(int j; j < _size; ++j)          
         {
         start_index = i;
         return start_index;
         }
        }
       else
         return -1;
      }
  
}
*/


}
