#ifndef OBJECT_P_H
#define OBJECT_P_H

class ObjectPrivate
{
public:
    ObjectPrivate();
    ~ObjectPrivate();

    void setId(const char *id);

    char id[32];
};

#endif // OBJECT_P_H
