// need to run with ASAN_OPTIONS=detect_stack_use_after_return=1

int* p;

void get_pointer_to_stack_value()
{
    int local = 0;
    p = &local;
}

int main()
{
    get_pointer_to_stack_value();
    return *p;
}
