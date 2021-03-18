int main()
{
    volatile int* p;

    {
        int i = 0;
        p = &i;
    }

    return *p;
}
