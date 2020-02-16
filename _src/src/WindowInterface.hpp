//
// Author: Omer Zelig
//

#ifndef WindowInterface_HPP
#define WindowInterface_HPP


namespace Window {

class WindowInterface
{
public:
    WindowInterface();
    ~WindowInterface();

    WindowInterface(const WindowInterface&)             = delete;
    WindowInterface & operator=(const WindowInterface&) = delete;

};

}

#endif
