#include <unistd.h>

int main(int argc, char const *argv[])
{
    write(1, "hello syscall", 14);
    _exit(4);
}
