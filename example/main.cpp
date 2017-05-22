#include <cstdio>

#include <global.h>

#include "object.h"

int main(int argc, char *argv[])
{
    UNUSED(argc)
    UNUSED(argv)

    Object foo("foo");
    printf("foo.id(): \"%s\"\n", foo.id());

    Object bar = foo;
    printf("bar.id(): \"%s\"\n", bar.id());

    return 0;
}
