#ifndef PIMPL_H
#define PIMPL_H

template <class Class, class ClassPrivate>
class Pimpl
{
public:
    explicit Pimpl();
    Pimpl(const Pimpl &other);
    Pimpl &operator=(const Pimpl &other);

protected:
    // Disable destruction through base class pointer
    // (see http://www.gotw.ca/publications/mill18.htm)
    ~Pimpl();

    // Fallbacks if the derived class does not implement them
    static ClassPrivate *make();
    static ClassPrivate *clone(ClassPrivate *p);
    static void unmake(ClassPrivate *p);

private:
    // Used to create an exception safe assignment operator
    // (see https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Copy-and-swap)
    void swap(Pimpl &other);

    ClassPrivate *_make() const;
    ClassPrivate *_clone(ClassPrivate *p) const;
    void _unmake(ClassPrivate *p) const; // Prevents MSVC warning C4150

protected:
    ClassPrivate *d_ptr;
};

template<class Class, class ClassPrivate>
Pimpl<Class, ClassPrivate>::Pimpl()
    : d_ptr(_make())
{

}

template<class Class, class ClassPrivate>
Pimpl<Class, ClassPrivate>::Pimpl(const Pimpl &other)
    : d_ptr(_clone(other.d_ptr))
{

}

template<class Class, class ClassPrivate>
Pimpl<Class, ClassPrivate> &Pimpl<Class, ClassPrivate>::operator=(const Pimpl &other)
{
    Pimpl copy(other);
    swap(copy);

    return *this;
}

template<class Class, class ClassPrivate>
Pimpl<Class, ClassPrivate>::~Pimpl()
{
    _unmake(d_ptr);
    d_ptr = 0;
}

template<class Class, class ClassPrivate>
ClassPrivate *Pimpl<Class, ClassPrivate>::make()
{
    return new ClassPrivate;
}

template<class Class, class ClassPrivate>
ClassPrivate *Pimpl<Class, ClassPrivate>::clone(ClassPrivate *p)
{
    return new ClassPrivate(*p);
}

template<class Class, class ClassPrivate>
void Pimpl<Class, ClassPrivate>::unmake(ClassPrivate *p)
{
    delete p;
}

template<class Class, class ClassPrivate>
void Pimpl<Class, ClassPrivate>::swap(Pimpl &other)
{
    ClassPrivate *tmp = d_ptr;
    d_ptr = other.d_ptr;
    other.d_ptr = tmp;
}

template<class Class, class ClassPrivate>
ClassPrivate *Pimpl<Class, ClassPrivate>::_make() const
{
    return ((Class const*)this)->make();
}

template<class Class, class ClassPrivate>
ClassPrivate *Pimpl<Class, ClassPrivate>::_clone(ClassPrivate *p) const
{
    return ((Class const*)this)->clone(p);
}

template<class Class, class ClassPrivate>
void Pimpl<Class, ClassPrivate>::_unmake(ClassPrivate *p) const
{
    ((Class const*)this)->unmake(p);
}

#endif // PIMPL_H
