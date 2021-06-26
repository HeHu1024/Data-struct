#ifndef LINKLIST_H
#define LINKLIST_H

#include "List.h"
#include "Exception.h"

namespace DTLib
{


template <typename T>
class Linklist : public List<T>
{
protected:

    struct Node : public Object
    {
        T value;
        Node* next;
    };
    // mutable 声明，是为了修改const成员变量
    mutable Node m_header;
    int m_length;

public:
    Linklist()
    {
        m_header.next = NULL;
        m_length = 0;
    }

    virtual bool insert(const T& e)
    {
        return insert(m_length,e);
    }

    virtual bool insert(int i,const T& e)
    {
        bool ret = (0 <= i) && (i <= m_length);
        if( ret )
        {
            Node* node = new Node();
            if( node != NULL )
            {
                Node *current = &m_header;
                for(int p=0; p<i; p++ )
                {
                    current = current->next;
                }
                node->value = e;
                node->next = current->next;
                current->next = node;

                m_length ++;
            }else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to insert new element  !!!!!");
            }
        }
        return ret;
    }

    virtual bool remove(int i)
    {
        bool ret = (0 <= i) && (i <= m_length);
        if( ret )
        {
            Node* current = &m_header;
            for( int p=0; p < i; p++ )
            {
                current = current->next;
            }
            Node* toDel = current->next;
            current->next = toDel->next;

            delete toDel;
            m_length--;
        }
        return ret;
    }

    virtual bool set(int i,const T& e)
    {
        bool ret = (0 <= i) && (i <= m_length);
        if( ret )
        {
            Node* current = &m_header;
            for( int p=0; p < i; p++ )
            {
                current = current->next;
            }
            current->next->value = e;
        }
        return ret;
    }

    T get(int i)
    {
        T ret;
        if( get(i,ret) )
        {
            return ret;
        }else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"invalid paramer i to get element  !!!!!");
        }

        return ret;
    }

    virtual bool get(int i, T& e)const
    {

        bool ret = (0 <= i) && (i <= m_length);
        if( ret )
        {
            Node* current = &m_header;
            for( int p=0; p < i; p++ )
            {
                current = current->next;
            }
            e = current->next->value;
        }
        return ret;
    }

    virtual int length() const
    {
        return m_length;
    }
    virtual void clear()
    {
        while( m_header.next != NULL )
        {
            Node *toDel = m_header.next;
            m_header.next = toDel->next;
            delete toDel;
        }
        m_length = 0;
    }

    ~Linklist()
    {
        clear();
    }


};















}



#endif // LINKLIST_H
