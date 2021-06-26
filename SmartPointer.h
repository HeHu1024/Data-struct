#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include "Object.h"


namespace DTLib
{

template <typename T>

class SmartPointer : public Object
{
private:
    T* m_pointer;
public :
    // construct function initialize param
    SmartPointer<T>(T* p = NULL)
    {
        m_pointer = p;
    }
    // copy construct function
    // can not make two pointer to one memery
    SmartPointer(const SmartPointer<T> &obj)
    {
        m_pointer = obj.m_pointer;
        // ͬһ��ѿռ�ֻ����һ��ָ��
        // const_cast��������ת����ȥ�������const����
        const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
    }
    // �������캯��
    SmartPointer<T>& operator= (const SmartPointer<T>& obj)
    {
        // judge oneself copy
        if( this != obj )
        {
            delete m_pointer;
            m_pointer = obj.m_pointer;
            // ͬһ��ѿռ�ֻ����һ��ָ��
            // const_castǿ������ת����ȥ�������const����
            const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
        }
        return *this;
    }
    T* operator ->()
    {
        return m_pointer;
    }
    T& operator *()
    {
        return *m_pointer;
    }
    bool isNull()
    {
        return (m_pointer == NULL);
    }
    T* get()
    {
        return m_pointer;
    }
    ~SmartPointer()
    {
        delete m_pointer;
    }

};



}


#endif // SMARTPOINTER_H
