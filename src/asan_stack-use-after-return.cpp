// need to run with ASAN_OPTIONS=detect_stack_use_after_return=true

int* return_pointer_to_stack_value()
{
    int i = 0;
    return &i;
}

int main()
{
    int* p = return_pointer_to_stack_value();
    return *p;
}
