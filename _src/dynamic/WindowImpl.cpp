//
// Author: Omer Zelig
//


#include "WindowImpl.hpp"


using WindowImpl = dynamic_::WindowImpl;


WindowImpl::WindowImpl(const char* a_name,
                       const int a_height,
                       const int a_width):
    m_name(std::string(a_name)),
    m_height(a_height),
    m_width(a_width)
{

}


WindowImpl::~WindowImpl()
{

}


const std::string& WindowImpl::getName() const noexcept
{
    return m_name;
}



int WindowImpl::getHeight() const noexcept
{
    return m_height;
}


int WindowImpl::getWidth() const noexcept
{
    return m_width;
}


void WindowImpl::doNothing() const noexcept
{
    return;
}
