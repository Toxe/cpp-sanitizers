int main(int argc, char* argv[])
{
    int values[10];
    values[0] = 0;
    return values[10 + argc];  // buffer overflow
}
