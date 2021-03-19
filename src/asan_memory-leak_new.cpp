// on macOS need to run with ASAN_OPTIONS=detect_leaks=true

int main(int argc, char* argv[])
{
    auto values = new int[10];
    values[1] = 0;
    int ret = values[argc];
    // delete[] values;
    return ret;
}
