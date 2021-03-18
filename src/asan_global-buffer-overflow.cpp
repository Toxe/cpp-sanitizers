int values[10];

int main(int argc, char* argv[])
{
    values[0] = 0;
    return values[10 + argc]; // buffer overflow
}
