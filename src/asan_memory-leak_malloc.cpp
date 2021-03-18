// on macOS need to run with ASAN_OPTIONS=detect_leaks=true

#include <cstdlib>
#include <iostream>

int main()
{
    int* values = static_cast<int*>(malloc(10 * sizeof(int)));
    std::cout << "values[0] = " << values[0] << '\n';
    // free(values);
}
