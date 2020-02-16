//
// Author: Omer Zelig
//
// Notes:
// 1) read more https://www.fluentcpp.com/2017/05/12/curiously-recurring-template-pattern/
//    section"what can go wrong"
//

#ifndef static_WindowInterface_HPP
#define static_WindowInterface_HPP


// system
#include <string>


namespace static_ {

template <typename Impl>
class WindowInterface
{
public:
    WindowInterface(const WindowInterface&)             = delete;
    WindowInterface & operator=(const WindowInterface&) = delete;

    //
    //
    //
    const std::string& getName() const noexcept;

    //
    //
    //
    int getHeight() const noexcept;

    //
    //
    //
    int getWidth() const noexcept;

    //
    //
    //
    void doNothing() const noexcept;

    //
    // prevent misuse (Note 1)
    //
private:
    WindowInterface();
    ~WindowInterface();
    friend Impl;
};


}

#endif
