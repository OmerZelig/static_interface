
// system
#include <iostream>
#include <memory>
#include <chrono>

// project
#include "../src/WindowInterface.hpp"
#include "../src/WindowImpl.hpp"


template <typename T>
void getName(const static_::WindowInterface<T>& a_window) noexcept
{
    a_window.getName();
}


template <typename T>
void getHeight(const static_::WindowInterface<T>& a_window) noexcept
{
    a_window.getHeight();
}


template <typename T>
void getWidth(const static_::WindowInterface<T>& a_window) noexcept
{
    a_window.getWidth();
}


template <typename T>
void doNothing(const static_::WindowInterface<T>& a_window) noexcept
{
    a_window.doNothing();
}


template <typename TestFunc>
std::chrono::duration<double> runTest(const TestFunc& a_testFunc) noexcept
{
    const auto l_start = std::chrono::high_resolution_clock::now();
    a_testFunc();
    const auto l_finish = std::chrono::high_resolution_clock::now();

    return (l_finish - l_start);
}

const int g_counter = 10'000'000;
std::chrono::duration<double> g_test_1_result = std::chrono::duration<double>{};

int main () 
{
    // test 1
    {
        const auto l_test = []()
        {
            const auto l_window =
                    std::make_unique<static_::WindowImpl>("static_window",
                                                          5,
                                                          10);
            for (int i = 0; i < g_counter; i++)
            {
                getName(*l_window);
            }

        };

        g_test_1_result = runTest(l_test);
    }


    std::cout << "(g_test_1_result 1 ) g_counter: " << g_counter << " g_test_1_result: " << g_test_1_result.count() << std::endl << std::flush;
}
