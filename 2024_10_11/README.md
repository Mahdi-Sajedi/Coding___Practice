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

- [introduction to OMP](https://ianfinlayson.net/class/cpsc425/notes/10-openmp) -> [Reductions & parallel for](https://ianfinlayson.net/class/cpsc425/notes/11-parfor) -> [3](http://www.inf.ufsc.br/~bosco.sobral/ensino/ine5645/OpenMP_Dynamic_Scheduling.pdf)

```c
#include <stdlib.h>
#include <omp.h>
#include <stdio.h>

#define THREADS 32
#define START 0
#define END 100000

/* the function called for each thread */
unsigned long sum_part() {
    /* get our thread id */
    int id = omp_get_thread_num();

    /* calculate the start and end points by evenly dividing the range */
    unsigned long start = ((END - START) / THREADS) * id;
    unsigned long end = start + ((END - START) / THREADS) - 1;

    /* the last thread needs to do all remaining ones */
    if (id == (THREADS - 1)) {
        end = END;
    }

    /* do the calculation */
    unsigned long i, sum = 0;
    for (i = start; i <= end; i++) {
        sum += i;
    }

    return sum;
}

int main() {
    unsigned long global_sum = 0;

    #pragma omp parallel num_threads(THREADS) reduction(+:global_sum)
    global_sum += sum_part();

    /* now all results are in */
    printf("Final answer = %lu.\n", global_sum);
    return 0;
}
```

The reduction is specified on the ”#pragma omp parallel” line. It consists of some operator from (+ * - & | ^ && ||) and some variable, separated by a colon

The goal of a reduction is to tell OpenMP that the operator needs to be applied for each thread individually, but can be done in any order.

### Parallel For Code Breaking Example

The code breaking example is also better accomplished with a parallel for loop:
```c
/* try each possible shift amount */
int found = 0, i;
#pragma omp parallel for num_threads(26) reduction(||:found)
for (i = 0; i < 26; i++) {
    found = found || break_code(encrypted, length, i);
}

if (!found) {
    printf("Text could not be cracked with this method!\n");
}
```

This is a better method since we can now adjust the number of threads and have the work automatically re-distributed amongst the threads.

Note we also use a reduction with the || operator to see if any of the threads are able to decrypt the text.

Fibonacci number generation program using for loop cannot be parallelized because of "loop carried dependence". 

[example](https://www.tezu.ernet.in/dcompsc/facility/HPCC/hypack/openmp-hypack-2013/openmp-codes-c-lang/omp-prime-datarace-condt.c) of data race; use critical to let only one thread run that section at any moment.
```cpp
// some code before this 
omp_set_num_threads(Noofthreads);
 
	/* OpenMP Parallel For Directive    */
	#pragma omp parallel for 
   	 for (number =3 ; number < Maxnumber  ; number += 2 )
    	{
                 if (is_prime(number))   
		{
           		  Array[ Countdatarace ] = number;
            		  Countdatarace++;  	 /* Data Race condition */
        	}	
   	 }


	/* OpenMP Parallel For Directive And Critical Section */
        #pragma omp parallel for
         for (number =3 ; number < Maxnumber  ; number += 2 )
        {
                 if (is_prime(number))
                {
                        #pragma omp critical
                        {
                          Primearray[ Countparallel ] = number;
                          Countparallel++;
                        }
                }
         }



        /* Serial computation */
	 for (number =3 ; number < Maxnumber  ; number += 2 )
        {
                 if (is_prime(number))
                {
                          Check[ Count ] = number;
                          Count++;
                }
         }
```
