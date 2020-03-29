// on macOS need to run with ASAN_OPTIONS=detect_leaks=true

#include <cstdlib>

int main()
{
    auto values = malloc(10 * sizeof(int));
    // free(values);
}
