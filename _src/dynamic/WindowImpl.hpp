//
// Author: Omer Zelig
//

#ifndef dynamic_WindowImpl_HPP
#define dynamic_WindowImpl_HPP

#include "WindowInterface.hpp"

namespace dynamic_ {


class WindowImpl : public WindowInterface
{
public:
    WindowImpl(const char* a_name,
               const int a_height,
               const int a_width);
    virtual ~WindowImpl() override final;

    WindowImpl(const WindowImpl&)             = delete;
    WindowImpl & operator=(const WindowImpl&) = delete;


    const std::string& getName() const noexcept override final;

    int getHeight() const noexcept override final;

    int getWidth() const noexcept override final;

    void doNothing() const noexcept override final;

private:
    const std::string m_name;
    const int m_height;
    const int m_width;
};


}

#endif
