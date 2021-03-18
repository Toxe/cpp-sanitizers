int main(int argc, char* argv[])
{
    int* values = new int[10];
    delete[] values;
    return values[argc]; // use after free
}
