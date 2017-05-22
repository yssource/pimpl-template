#ifndef PIMPL_H
#define PIMPL_H

template <class Handle, class Impl>
class Pimpl
{
private:
    Impl *_make() const
    {
        return ((Handle const *)this)->make();
    }

    void _unmake(Impl *p) const
    {
        ((Handle const *)this)->unmake(p);
    }

    Impl *_clone(Impl *p) const
    {
        return ((Handle const *)this)->clone(p);
    }

    void swap(Pimpl &other)
    {
        Impl *temp = d_ptr;
        d_ptr = other.d_ptr;
        other.d_ptr = temp;
    }

public:
    explicit Pimpl();
    ~Pimpl();

    Pimpl(const Pimpl &other);
    Pimpl &operator=(const Pimpl &other);

    // Fallbacks
    static Impl *make()
    {
        return new Impl;
    }

    static void unmake(Impl *p)
    {
        delete p;
    }

    static Impl *clone(Impl *p)
    {
        return new Impl(*p);
    }

protected:
    Impl *d_ptr;
};

template<class Handle, class Impl>
Pimpl<Handle, Impl>::Pimpl() :
    d_ptr(_make())
{

}

template<class Handle, class Impl>
Pimpl<Handle, Impl>::~Pimpl()
{
    _unmake(d_ptr);
    d_ptr = 0;
}

template<class Handle, class Impl>
Pimpl<Handle, Impl>::Pimpl(const Pimpl &other) :
    d_ptr(_clone(other.d_ptr))
{

}

template<class Handle, class Impl>
Pimpl<Handle, Impl> &Pimpl<Handle, Impl>::operator=(const Pimpl &other)
{
    Pimpl copy(other);
    swap(copy);

    return *this;
}

#endif // PIMPL_H
