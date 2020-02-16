//
// Author: Omer Zelig
//


#include "WindowInterface.hpp"

//
// for explicit template instantiation
//
#include "WindowImpl.hpp"


template<class T>
static_::WindowInterface<T>::WindowInterface()
{

}


template<class T>
static_::WindowInterface<T>::~WindowInterface()
{

}


template<class T>
const std::string& static_::WindowInterface<T>::getName() const noexcept
{
    return static_cast<T const&>(*this).getName();
}


template<class T>
int static_::WindowInterface<T>::getHeight() const noexcept
{
    return static_cast<const T&>(*this).getHeight();
}


template<class T>
int static_::WindowInterface<T>::getWidth() const noexcept
{
    return static_cast<const T&>(*this).getWidth();
}


template<class T>
void static_::WindowInterface<T>::doNothing() const noexcept
{
    return static_cast<const T&>(*this).doNothing();
}


template class static_::WindowInterface<static_::WindowImpl>;
