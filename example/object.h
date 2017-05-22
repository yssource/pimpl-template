#ifndef OBJECT_H
#define OBJECT_H

#include <cstdio>
#include <cstring>

#include <pimpl.h>

class ObjectPrivate;

class Object : private Pimpl<Object, ObjectPrivate>
{
public:
    Object();
    Object(const char *id);
    ~Object();

    const char *id() const;
};

#endif // OBJECT_H
