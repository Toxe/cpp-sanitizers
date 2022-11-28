// on macOS need to run with ASAN_OPTIONS=detect_leaks=1

#include <cstdlib>

int main(int argc, char* argv[])
{
    int* values = static_cast<int*>(malloc(10 * sizeof(int)));
    values[1] = 0;
    int ret = values[argc];
    // free(values);
    return ret;
}
