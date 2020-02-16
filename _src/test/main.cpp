
// system
#include <iostream>
#include <memory>
#include <chrono>
#include <random>

// project
#include "../static/WindowInterface.hpp"
#include "../static/WindowImpl.hpp"

#include "../dynamic/WindowInterface.hpp"
#include "../dynamic/WindowImpl.hpp"

//
// Notes:
// 1) about random
//    https://stackoverflow.com/questions/288739/generate-random-numbers-uniformly-over-an-entire-range
//
// 2) https://stackoverflow.com/questions/34460744/flushing-the-cache-to-prevent-benchmarking-fluctiations
//

template <typename T>
void getName(const T& a_window) noexcept
{
    a_window.getName();
}


template <typename T>
void getHeight(const T& a_window) noexcept
{
    a_window.getHeight();
}


template <typename T>
void getWidth(const T& a_window) noexcept
{
    a_window.getWidth();
}


template <typename T>
void doNothing(const T& a_window) noexcept
{
    a_window.doNothing();
}


template <typename TestFunc, typename Param>
std::chrono::duration<double> runTest(const TestFunc& a_testFunc,
                                      const Param a_param) noexcept
{
    const auto l_start = std::chrono::high_resolution_clock::now();
    a_testFunc(a_param);
    const auto l_finish = std::chrono::high_resolution_clock::now();

    return (l_finish - l_start);
}


const int g_counter = 1'000'000;
auto g_test_static_result  = std::chrono::duration<double>{};
auto g_test_dynamic_result = std::chrono::duration<double>{};

int main () 
{

    // test 1
    const auto l_test_1 = [](const auto a_counter)
    {
        const auto l_window =
                std::make_unique<static_::WindowImpl>("static_window",
                                                      5,
                                                      10);
        for (int i = 0; i < a_counter; i++)
        {
            getName(*l_window);
            //getHeight(*l_window);
            //doNothing(*l_window);
        }

    };


    // test 2;
    const auto l_test_2 = [](const auto a_counter)
    {
        const auto l_window =
                std::make_unique<dynamic_::WindowImpl>("static_window",
                                                       5,
                                                       10);
        for (int i = 0; i < a_counter; i++)
        {
            getName(*l_window);
            //getHeight(*l_window);
            //doNothing(*l_window);
        }

    };


    g_test_static_result  = runTest(l_test_1, g_counter);
    g_test_dynamic_result = runTest(l_test_2, g_counter);


    std::cout << "(g_test_static_result) g_counter: " << g_counter << " g_test_1_result: " << g_test_static_result.count() << std::endl << std::flush;
    std::cout << "(g_test_dynamic_result) g_counter: " << g_counter << " g_test_2_result: " << g_test_dynamic_result.count() << std::endl << std::flush;

    std::cout << "size of static: " <<  sizeof(static_::WindowImpl)<< std::endl << std::flush;
    std::cout << "size of dynamic: " << sizeof(dynamic_::WindowImpl) << std::endl << std::flush;

    std::cout << "size of std::string: " <<  sizeof(std::string)<< std::endl << std::flush;
    std::cout << "size of int: " <<  sizeof(int)<< std::endl << std::flush;
}
