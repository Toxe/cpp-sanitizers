int main()
{
    int i = 10;
    bool* b = reinterpret_cast<bool*>(&i);

    return *b ? 0 : 1;
}
