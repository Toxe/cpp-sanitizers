// on macOS need to run with ASAN_OPTIONS=detect_leaks=true

#include <iostream>

int main()
{
    auto values = new int[10];
    std::cout << "values[0] = " << values[0] << '\n';
    // delete[] values;
}
