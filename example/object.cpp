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

void ObjectPrivate::setId(const char *id)
{
    if (id == NULL) {
        return;
    }

    strcpy(this->id, id);
}

Object::Object() : Pimpl()
{
    d_ptr->setId("");
    printf("Object::Object()\n");
}

Object::Object(const char *id) : Pimpl()
{
    d_ptr->setId(id);
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


