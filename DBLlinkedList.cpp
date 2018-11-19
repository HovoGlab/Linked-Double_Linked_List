#include <iostream>
using namespace std;


template <typename T>
class DblList 
{
 public:
    class node
    {
     public:   
        T value;
        node * next;
        node * prev;
        node():next(nullptr),
               prev(nullptr)
               
        {}       
    };
 public:
    void  m_insert(int pos,const T& val);
    void  m_print();
    void  m_isertionSort();
    DblList();
 protected:    
    node * m_head;
    node * m_tail;
    int count;
    
 
   
};

template <typename T>
DblList <T>::DblList ()
{
    count = 0;
    m_head = nullptr;
}

template <typename T>
void DblList <T>::m_insert(int pos,const T& val)
{
    if(0 == pos)
    { 
      count++;
      node * TMPnext = m_head;  
      m_head = new node;
      if(1 == count)
      {
        m_tail = m_head;    
      }
      m_head->prev = nullptr;
      m_head->next = TMPnext;
      m_head->value = val;
      if(count > 1)
      {
        TMPnext->prev = m_head;
      }  
     }
    else
    {
      node * TMPPtr = m_head;
      node * cur;
      for(int i = 0;i < pos;i++)
      {
        cur = TMPPtr->next;
        if(cur!=nullptr)
        {TMPPtr = cur;}
      }
      cur = TMPPtr->next;
      TMPPtr->next = new node;
      TMPPtr->next->next = cur;
      TMPPtr->next->prev = TMPPtr;
      TMPPtr->next->value = val;
      if(cur!=nullptr)
      {
        cur->prev = TMPPtr->next;
      }
      count++;
     }    

}

template <typename T>
void DblList <T>::m_print()
{  
     node * print = m_head; 
     while(print!=nullptr)
     {
         cout << print->value << " ";
         print = print->next;
     }    

}
template <typename T>
void DblList <T>::m_isertionSort()
{
    node * cur = m_head;
    for(int i = 0; i < count - 1; i++)
    {    
        if(cur->next->value < cur->value)
        {
            node *TMP = cur;
            while(cur->next->value < cur->value && cur != nullptr)
            {
                T tmp = cur->next->value;
                cur->next->value = cur->value;
                cur->value = tmp;
                cur = cur->prev;
            }
            cur = TMP;
        }
        cur = cur->next;
    }

}

int main()
{
    DblList <int> list; 
    list.m_insert(0,7);
    list.m_insert(0,15);
    list.m_insert(3,25);
    list.m_print();
    list.m_isertionSort();
   
}
