int main(int argc, char* argv[])
{
    int* values = new int[10];
    values[0] = 0;
    int ret = values[10 + argc];  // buffer overflow
    delete[] values;
    return ret;
}
