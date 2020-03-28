// need to run with:
// - ASAN_OPTIONS=check_initialization_order=true
// - ASAN_OPTIONS=check_initialization_order=true:strict_init_order=true

extern int global;

int __attribute__((noinline)) read_global()
{
    return global;
}

int depends_on_global = read_global();

int main()
{
    return depends_on_global;
}
