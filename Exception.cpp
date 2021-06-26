#include "exception.h"
#include <cstring>
#include <cstdlib>
using namespace std;

namespace DTLib
{


void Exception::init(const char* message,const char* file,int line)
{
    // 将字符串复制一份，复制到堆空间
    m_message = strdup(message);
    if( file != NULL )
    {
        char sl[1] = {0};
        // 将line copy到sl
        itoa(line,sl,10);
        // + 2 的原因时 ':' 和 '\0'
        m_location = static_cast<char*>(malloc(strlen(file) + strlen(sl) + 2));
        if( m_location != NULL )
        {
            m_location = strcpy(m_location,file);
            m_location = strcat(m_location,":");
            m_location = strcat(m_location,sl);
        }
        // 是否可以抛出异常
        // THROW_EXCEPTION(NoEnoughMemoryException,"Exception::init");



    }else
    {
        m_location = NULL;
    }
}


Exception::Exception(const char* message)
{
    init(message,NULL,0);
}

Exception::Exception(const char* file, int line)
{
    init(NULL,file,line);
}

Exception::Exception(const char* message, const char *file, int line)
{
    init(message,file,line);
}


// 拷贝构造（深拷贝）
Exception::Exception(const Exception& e)
{
    m_message= strdup(e.m_message);
    m_location = strdup(e.m_location);
}


Exception& Exception::operator=(const Exception& e)
{
    if( this != &e )
    {
        free(m_message);
        free(m_location);

        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }
    return *this;
}


const char* Exception::message()const
{
    return m_message;
}
const char* Exception::location()const
{
    return m_location;
}


Exception::~Exception()
{
    free(m_message);
    free(m_location);
}
}
