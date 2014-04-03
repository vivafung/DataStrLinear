#include<iostream>
#include<cstdlib>

using namespace std;

typedef int T;

class Node
{
        friend class queue;
        public:
          Node(const T& data, Node* next)
            :_data(data),
             _next(next)
             {}

        private:
          T _data;
          Node* _next;
};

class queue
{
        public:
        queue()
          :_head(0),_tail(0)
           {}
        queue(const queue&);
        ~queue();

        void push_back(const T&);
        void pop_front();
        bool empty() const {return !_head;}
        int size() const;
 
        private:
          Node* _head;
          Node* _tail;

};
