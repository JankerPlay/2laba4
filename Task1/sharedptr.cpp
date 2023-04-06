#include <iostream>
template<typename T>
class shared_ptr
{
private:
    T* ptr = nullptr;
    size_t* counter = nullptr;
    void clear();
public:
    shared_ptr() : ptr(nullptr), counter(nullptr) {};
    explicit shared_ptr(T* ptr) : ptr(ptr), counter(new size_t(1)) {};
    shared_ptr(const shared_ptr& other);
    shared_ptr& operator=(shared_ptr&& other) noexcept;
    T* get() const;
    T& operator*();
    T* operator->();
    [[nodiscard]] size_t count() const;
    ~shared_ptr();
};
template<typename T>
shared_ptr<T>::~shared_ptr() 
{
    clear();
}
template<typename T>
T* shared_ptr<T>::operator->()
{
    return ptr;
}
template<typename T>
T& shared_ptr<T>::operator*()
{
    return *ptr;
}
template<typename T>
T* shared_ptr<T>::get() const 
{
    return ptr;
}
template<typename T>
size_t shared_ptr<T>::count() const
{
    return *counter;
}
template<typename T>
shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr&& other) noexcept
{
    shared_ptr::_clean();
    ptr = other.ptr;
    counter = other.counter;
    other.ptr = other.counter = nullptr;
}
template<typename T>
void shared_ptr<T>::clear()
{
    if (--(*counter) == 0)
    {
        delete ptr;
        delete counter;
    }
}
template <typename T>
shared_ptr<T>::shared_ptr(const shared_ptr& other) 
{
    ptr = other.ptr;
    counter = other.counter;
    if (other.ptr != nullptr)
        (*counter)++;
}