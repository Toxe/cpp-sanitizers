int main(int argc, char* argv[])
{
    int* values = new int[10];
    values[9] = 10;
    values[10] = 11; // buffer overflow
    delete[] values;
}
