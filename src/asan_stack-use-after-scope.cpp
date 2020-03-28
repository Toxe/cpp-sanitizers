int main()
{
    int* p;

    {
        int i = 0;
        p = &i;
    }

    return *p;
}
