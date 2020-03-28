// on macOS need to run with ASAN_OPTIONS=detect_leaks=true

#include <stdlib.h>

int main()
{
    auto values = malloc(10 * sizeof(int));
    // free(values);
}
