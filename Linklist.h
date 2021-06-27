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
    // mutable 声明，是为了修改const成员变量
    // mutable Node m_header 防止构造的时候调用T类型出错;
    // 为什么struct需要继承Object ==> 防止struct m_header 在内存上与Node不同，导致crash
    mutable struct : public Object
    {
        char reserved[sizeof(T)];
        Node* next;
    } m_header;
    int m_length;

    Node* m_crrent;     // 游标指针，便利元素使用
    int m_step;         // 遍历元素移动的步数



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
        // 指向第0个元素
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

    // 实现数据元素便利提高效率，游标m_curren实现


    // funtion 实现游标遍历元素移动的功能
    // parma i 指定移动的位置目标. step 指定每次移动的步数
    bool move(int i,int step = 1)
    {
        bool ret = ( (0 <= i) && (i <= m_length) && (step > 0) );
        {
            if( ret )
            {
                m_crrent = position(i)->next;  // 从header 开始移动
                m_step = step;
            }
        }
        return ret;
    }
    // 判断m_current是否移动到最后
    bool end()
    {
        return (m_crrent == NULL);
    }
    // 获取当前m_current 指向的节点元素的
    T current()
    {
        // 如果没有结束,返回当前current指向节点的值
        if( !end() )
        {
            return m_crrent->value;
        }else       // 如果已经结束了，却还要返回,抛出异常
        {
            THROW_EXCEPTION(InvalidOperationException,"No value at current position......");
        }
    }
    // 移动游标function
    bool next()
    {
        int i = 0;
        // why i < m_step ?  ===>每次移动的步数，eg move(0,3)
        // 从0开始遍历，每次遍历的步数3
        while( !end() && (i < m_step) )
        {
            m_crrent = m_crrent->next;
            i++;
        }
        return (i == m_step);
    }
    // 创建 Node
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
