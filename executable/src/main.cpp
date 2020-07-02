#include <iostream>
#include <library/library.hpp>

int main (int argc, char *argv[])
{
    std::cout << library::normal_function() << std::endl;
    std::cout << library::opencv_function() << std::endl;
    
    return 0;
}