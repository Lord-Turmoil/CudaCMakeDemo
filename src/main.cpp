#include <cstdio>
#include "kernel.cuh"


int main()
{
    constexpr int arraySize = 5;
    const int a[arraySize] = { 1, 2, 3, 4, 5 };
    const int b[arraySize] = { 10, 20, 30, 40, 50 };
    int c[arraySize] = { 0 };

    // Add vectors in parallel.
    addWithCuda(c, a, b, arraySize);

    printf("{ 1, 2, 3, 4, 5 } + { 10, 20, 30, 40, 50 } = { %d, %d, %d, %d, %d }\n",
           c[0], c[1], c[2], c[3], c[4]);

    // cudaDeviceReset must be called before exiting in order for profiling and
    // tracing tools such as Nsight and Visual Profiler to show complete traces.
    resetCuda();

    return 0;
}
