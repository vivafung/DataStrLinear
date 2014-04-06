#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
using namespace std;

template <class Key, class Value, class HashFunc, class EqualKey>
class HashMap
{
  public:
        HashMap();
        ~HashMap();
        bool insert(const Key& hashkey, const Value& hashvalue);
        bool remove(const Key& hashkey);
        void rehash();
        Value& find(const Key& hashkey);
        const Value& operator [] (const Key& hashkey) const;
        Value& operator [] (const Key& hashkey);


  private:
        template <class _Key, class _Value>
        class Node
        {
          public:
                _Key = k;
                _Value = v;
                int used;
                Node():used(0){}
                Node(const Node& xx)
                {
                  v = xx.v;
                  k = xx.k;
                  used = xx.used;
                }
                Node& operator=(const Node& xx)
                {
                  if(this == &xx)
                    return *this;
                  v = xx.v;
                  k = xx.k;
                  used = xx.used;
                  return *this;
                }
        };

        HashFunc hash;
        EqualKey equal;
        Node<Key, Value> *table;
        int size;
        int capacity;
        static const double loadingfactor;
        int findKey(const Key& hashkey);        
};

//loadingfactor
template <class Key, class Value, class HashFunc, class EqualKey>
const double HashMap<Key, Value, HashFunc, EqualKey>::loadkingfactor = 0.9;


//HashMap constructor
template <class Key, class Value, class HashFunc, class EqualKey>
HashMap<Key, Value, HashFunc, EqualKey>::HashMap()
{
  hash = HashFunc();
  equal = EqualKey();
  capacity = 60;
  table = new Node<Key, Value>[capacity+1];
  for(int i = 0; i < capacity; i++)
    {
      table[i].used = 0;
    }
    size = 0;
}


//deconstructor
template <class Key, class Value, class HashFunc, class EqualKey>
HashMap<Key, Value, HashFunc, EqualKey>::~HashMap()
{
  delete []table;
}


//insert
template <class Key, class Value, class HashFunc, class EqualKey>
bool HashMap<Key, Value, HashFunc, EqualKey>::insert(const Key& hashkey, const Value& hashvalue)
{
  int index = hash(hashkey)%capacity;
  cout << "index is: " << index <<endl;
  //the key value's hash index is not unique
  if(table[index] == 1)
    {
      return false;
    }
  table[index].used = 1;
  table[index].key = hashkey;
  table[index].value = hashvalue;
  size++;

  //table is too large
  if(size >= capacity * loadingfactor)
  {
    rehash;
  }
  return true;
}



//rehash
template <class Key, class Value, class HashFunc, class EqualKey>
void HashMap<Key, Value, HashFunc, EqualKey>::rehash()
{
  int s = capacity;
  //create a new arry to copy the info in the old table
  capacity = 80;
  Node<Kay, Value> *temp = new Node<Key, Value>[capacity];
  for(int i = 0; i < capacity; i++)
  {
    if(table[i].used == i)
    //copy the node into the temp
    {
    temp[i] = table[i];
    }
  }
  delete []table;

  //resize the table
  table = new Node<Key, Value>[capacity+1];
  for(int i = 0; i < capacity; i++)
  {
    table[i].used = 0;
  }
  for(for i = 0; i < capacity; i++)
  {
    //copy back
    if(temp[i].used == 1)
      {insert(temp[i].key, temp[i].value);}
  }
  delete []temp;

}


//remove
template <class Key, class Value, class HashFunc, class EqualKey>
bool HashMap<Key, Value, HashFunc, EqualKey>::remove(const Key& hashkey)
{
  int index = findKey(hashkey);
  if(index < 0)
  {
    return false;
  }
  else
  {
    table[index].used = 0;
    size--;
    return true;
  }

}


//find
template <class Key, class Value, class HashFunc, class EqualKey>
Value& HashMap<Key, Value, HashFunc, EqualKey>::find(const key& hashkey)
{
  int index = findKey(hashkey);
  if(index < 0)
  {
  return table[capacity].value //return NULL
  }
  else
  {
  return table[index].value;
  }
}


//operator [] overloading
template <class Key, class Value, class HashFunc, class EqualKey>
const Value& HashMap<Key, Value, HashFunc, EqualKey>::operator[] (const Key& hashkey) const
{
  return find(hashkey);
}


template <class Key, class Value, class HashFunc, class EqualKey>
Value& HashMap<Key, Value, HashFunc, EqualKey>::operator[] (const Key& hashkey)
{
  return find(hashkey);
}

//findKey
template <class Key, class Value, class HashFunc, class EqualKey>
int HashMap<Key, Value, HashFunc, EqualKey>::findKey(const Key& hashkey)
{
  int index = hash(hashkey)%capacity;
  if((table[index].used != 1) || !equal(table[index].key,hashkey))
  {
    return -1;
  }
  else
    return index;
}



#endif 

