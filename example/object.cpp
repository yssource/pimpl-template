#include "object.h"
#include "object_p.h"

ObjectPrivate::ObjectPrivate()
{
    printf("ObjectPrivate::ObjectPrivate()\n");
}

ObjectPrivate::~ObjectPrivate()
{
    printf("ObjectPrivate::~ObjectPrivate()\n");
}

Object::Object() : Pimpl()
{
    strcpy(d_ptr->id, "");
    printf("Object::Object()\n");
}

Object::Object(const char *id) : Pimpl()
{
    strcpy(d_ptr->id, id);
    printf("Object::Object(id)\n");
}

Object::Object(const Object &other) : Pimpl(other)
{
    printf("Object::Object(other)\n");
}

Object::~Object()
{
    printf("Object::~Object()\n");
}

const char *Object::id() const
{
    return d_ptr->id;
}


