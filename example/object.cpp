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

Object::Object()
{
    strcpy(d_ptr->id, "");
    printf("Object::Object(id)\n");
}

Object::Object(const char *id)
{
    strcpy(d_ptr->id, id);
    printf("Object::Object(id)\n");
}

Object::~Object()
{
    printf("Object::~Object()\n");
}

const char *Object::id() const
{
    return d_ptr->id;
}


