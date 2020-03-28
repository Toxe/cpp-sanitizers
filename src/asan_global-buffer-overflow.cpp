int values[10];

int main(int argc, char* argv[])
{
    values[9] = 10;
    values[10 + argc] = 11; // buffer overflow
}
