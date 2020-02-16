//
// Author: Omer Zelig
//

#ifndef WindowImpl_HPP
#define WindowImpl_HPP

#include "WindowInterface.hpp"

namespace static_ {


class WindowImpl : public WindowInterface<WindowImpl>
{
public:
    WindowImpl(const char* a_name,
               const int a_height,
               const int a_width);
    ~WindowImpl();

    WindowImpl(const WindowImpl&)             = delete;
    WindowImpl & operator=(const WindowImpl&) = delete;


    const std::string& getName() const noexcept;

    int getHeight() const noexcept;

    int getWidth() const noexcept;

    void doNothing() const noexcept;

private:
    const std::string m_name;
    const int m_height;
    const int m_width;
};


}

#endif
