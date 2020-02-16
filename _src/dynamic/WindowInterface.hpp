//
// Author: Omer Zelig
//

#ifndef dynamic_WindowInterface_HPP
#define dynamic_WindowInterface_HPP

// system
#include <string>

namespace dynamic_ {


class WindowInterface
{
public:
    WindowInterface();
    virtual ~WindowInterface();

    WindowInterface(const WindowInterface&)             = delete;
    WindowInterface & operator=(const WindowInterface&) = delete;

    //
    //
    //
    virtual const std::string& getName() const noexcept = 0;

    //
    //
    //
    virtual int getHeight() const noexcept = 0;

    //
    //
    //
    virtual int getWidth() const noexcept = 0;

    //
    //
    //
    virtual void doNothing() const noexcept = 0;


};


}

#endif
