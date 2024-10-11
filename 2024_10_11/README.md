Yellow
```cpp
#include <iostream>
#include <string_view>
 
int main()
{
    constexpr std::string_view unicode[]{"▀▄─", "▄▀─", "▀─▄", "▄─▀"};
 
    for (int y{}, p{}; y != 6; ++y, p = ((p + 1) % 4))
    {
        for (int x{}; x != 16; ++x)
            std::cout << unicode[p];
        std::cout << '\n';
    }
}

// list initialization, intro in C++11
// simply initialize y, p, x to 0 (also works for floats, pointers, or even objects (default constructor))
```
------------------------------------------------------------------------------------------
```cpp
#include <algorithm>
#include <cassert>
#include <cstring>
#include <string>
 
extern "C" void c_func(const char* c_str)
{
    printf("c_func called with '%s'\n", c_str);
}
 
int main()
{
    std::string const s("Emplary");
    const char* p = s.c_str();
    assert(s.size() == std::strlen(p));
    assert(std::equal(s.begin(), s.end(), p));
    assert(std::equal(p, p + s.size(), s.begin()));
    assert('\0' == *(p + s.size()));
 
    c_func(s.c_str());
}
// c_str() returns a C-style string (const char*) which is a pointer to a null_terminated character array that represents the content of the std::string
// C-style strings expect the string to terminate with a null character that mark the end of the string
// atoi() is a C-style function; it expects a C-style string as input
/*
std::string buffer;
//.
//.
//.
graph->num_edges = atoi(buffer.c_str());
*/
// std::string is a class
// c_str() transforms a string into a C-style string (returns a const char* pointer to the internal character array of the string ending with '\0') 
```
Output:
```cpp
c_func called with 'Emplary'
```
