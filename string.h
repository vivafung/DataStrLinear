#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <cstdlib>
#include <iostream>

namespace cs61003
{
class string
{
  friend ostream &operator<<(ostream &output, const string&);
//  friend istream &operator>>(istream &input, const string&);

  public:
    string();
    string(const string&);
    ~string();    
    string(const char* cptr)
          :_size(strlen(cptr)),
           _capacity(_size),
           _data(new char [strlen(cptr)])
    {
      //_data = new char [strlen(cptr)]; 
      strncpy(_data, cptr, strlen(cptr));
      
      if(_size==0)
        _data = 0;
    }
  
    string(int n,char c);
    char* c_str();
    bool operator==(const string&);
    bool operator!=(const string&);
    bool operator<(const string&);
    bool operator<=(const string&);
    bool operator>(const string&);
    bool operator>=(const string&);
    
    
    int size() const {return _size;}
    int capacity() const {return _capacity;}
    string substr(int, int);

    string& operator=(const string&);
    string& operator+=(const char);
    string& operator+=(const string);
    string operator+(const char);
    string operator+(const string&);

    void clear() {_size = 0;}
    void swap(string&);
    void resize(int);
    char& operator[](int i)  {return _data[i];}
    char operator[](int i) const {return _data[i];}
    //int find(const string&);


  private:
    void increase_capacity(int);
    int _size;
    int _capacity;
    char *_data;
};

}

#endif
