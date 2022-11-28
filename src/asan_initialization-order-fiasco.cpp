// need to run with:
// - ASAN_OPTIONS=check_initialization_order=true
// - ASAN_OPTIONS=check_initialization_order=true:strict_init_order=true

extern int global;

#if defined(__GNUC__) || defined(__clang_version__)
int __attribute__((noinline)) read_global()
#elif defined(_MSC_VER)
int __declspec(noinline) read_global()
#endif
{
    return global;
}

int depends_on_global = read_global();

int main()
{
    return depends_on_global;
}
