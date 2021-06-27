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

    /********************************varaible********************/
    struct Node : public Object
    {
        T value;
        Node* next;
    };
    // mutable ��������Ϊ���޸�const��Ա����
    // mutable Node m_header ��ֹ�����ʱ�����T���ͳ���;
    // Ϊʲôstruct��Ҫ�̳�Object ==> ��ֹstruct m_header ���ڴ�����Node��ͬ������crash
    mutable struct : public Object
    {
        char reserved[sizeof(T)];
        Node* next;
    } m_header;
    int m_length;

    Node* m_crrent;     // �α�ָ�룬����Ԫ��ʹ��
    int m_step;         // ����Ԫ���ƶ��Ĳ���



    /***************************** function *******************/
    Node* position(int i) const
    {
        Node *ret = reinterpret_cast<Node*> (&m_header);
        for( int p=0; p<i; p++ )
        {
            ret = ret->next;
        }
        return ret;
    }

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
            Node* node = Create();
            if( node != NULL )
            {
                Node *current = position(i);
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
            Node* current = position(i);
            Node* toDel = current->next;
            current->next = toDel->next;

            destory(toDel);
            m_length--;
        }
        return ret;
    }

    virtual bool set(int i,const T& e)
    {
        bool ret = (0 <= i) && (i <= m_length);
        if( ret )
        {
            position(i)->next->value = e;
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
            e = position(i)->next->value;
        }
        return ret;
    }

    virtual int find(const T& e) const
    {
        int ret = -1;
        // ָ���0��Ԫ��
        Node* node = m_header.next;
        int i = 0;
        while( node )
        {
            if( node->value == e )
            {
                ret = i;
                break;
            }else
            {
                node = node->next;
                i++;
            }
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
            destory(toDel);
        }
        m_length = 0;
    }

    // ʵ������Ԫ�ر������Ч�ʣ��α�m_currenʵ��


    // funtion ʵ���α����Ԫ���ƶ��Ĺ���
    // parma i ָ���ƶ���λ��Ŀ��. step ָ��ÿ���ƶ��Ĳ���
    bool move(int i,int step = 1)
    {
        bool ret = ( (0 <= i) && (i <= m_length) && (step > 0) );
        {
            if( ret )
            {
                m_crrent = position(i)->next;  // ��header ��ʼ�ƶ�
                m_step = step;
            }
        }
        return ret;
    }
    // �ж�m_current�Ƿ��ƶ������
    bool end()
    {
        return (m_crrent == NULL);
    }
    // ��ȡ��ǰm_current ָ��Ľڵ�Ԫ�ص�
    T current()
    {
        // ���û�н���,���ص�ǰcurrentָ��ڵ��ֵ
        if( !end() )
        {
            return m_crrent->value;
        }else       // ����Ѿ������ˣ�ȴ��Ҫ����,�׳��쳣
        {
            THROW_EXCEPTION(InvalidOperationException,"No value at current position......");
        }
    }
    // �ƶ��α�function
    bool next()
    {
        int i = 0;
        // why i < m_step ?  ===>ÿ���ƶ��Ĳ�����eg move(0,3)
        // ��0��ʼ������ÿ�α����Ĳ���3
        while( !end() && (i < m_step) )
        {
            m_crrent = m_crrent->next;
            i++;
        }
        return (i == m_step);
    }
    // ���� Node
    virtual Node* Create()
    {
        return new Node();
    }
    virtual void destory(Node* pn)
    {
        delete pn;
    }

    ~Linklist()
    {
        clear();
    }


};















}



#endif // LINKLIST_H
