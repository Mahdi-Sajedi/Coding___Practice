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
-----------------------------------------------------------------------------------------------
```cpp
buffer = "12\t\t34 56\n";
std::stringstream parse(buffer); // parser
int v;
while (parse >> v){
  scratch[idx++] = v;
}
// or use parse.fail to identify failure of parsing integer
```
std::getline(file, buffer) reads a line from file and stores it in buffer. Lines are terminated by null character '\0'. parse will continue extracting integers until it cannot, i.e. end of line (nothing to read anymore) or seeing non-integer data (\t is fine).

-----------------------------------------------------------------------------------------------------
[CS149 Graph Assignment](https://github.com/stanford-cs149/biggraphs-ec/blob/main/common/graph.cpp)

output is a file pointer to which we are writing.
```cpp
void store_graph_binary(const char* filename, Graph graph) {
	FILE* output = fopen(filename, "wb");
	
	if (!output) {
		fprintf(stderr, "Could not open: %s\n", filename);
		exit(1);
	}

	int header[3];
	header[0] = GRAPH_HEADER_TOKEN;
	header[1] = graph->num_nodes;
	header[2] = graph->num_edges;

	if (fwrite(header, sizeof(int), 3, output) != 3) {
		fprintf(stderr, "Error writing header.\n");
		exit(1);
	}

	if (fwrite(graph->outgoing_starts, sizeof(int), graph->num_nodes, output) != (size_t)graph->num_nodes) {
		fprintf(stderr, "Error writing nodes.\n");
		exit(1);
	}

	if (fwrite(graph->outgoing_edges, sizeof(int), graph->num_edges, output) != (size_t)graph->num_edges) {
		fprintf(stderr, "Error writing edges.\n");
		exit(1);
	}

	fclose(output);
}
```
## OpenMP resources:

- [1](http://www.inf.ufsc.br/~bosco.sobral/ensino/ine5645/OpenMP_Dynamic_Scheduling.pdf)

