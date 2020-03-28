int main()
{
    int* values = new int[10];
    delete[] values;
    return values[3]; // use after free
}
