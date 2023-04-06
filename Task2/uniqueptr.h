#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H
#include "cfunc.cpp"
class Del {
public:
    void operator() (char* t) const {
        delete[] t;
    }
};

class unique_ptr {
private:
    char* ptr = nullptr;
public:
    unique_ptr() : ptr(nullptr) {}
    explicit unique_ptr(char* ptr) : ptr(ptr) {}
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr(unique_ptr&& other) noexcept;
    unique_ptr& operator=(unique_ptr&& other) noexcept;
    char& operator*();
    char* get() const;
    char* operator->();
    ~unique_ptr();
    void reset();
    explicit unique_ptr(size_t size) : ptr(new char[size]) {}
};

unique_ptr::unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr) {
    other.ptr = nullptr;
}

unique_ptr& unique_ptr::operator=(unique_ptr&& other) noexcept {
    ptr = other.ptr;
    other.ptr = nullptr;
    return *this;
}

char& unique_ptr::operator*() {
    return *ptr;
}

char* unique_ptr::get() const {
    return ptr;
}

char* unique_ptr::operator->() {
    return ptr;
}

unique_ptr::~unique_ptr() {
    if (ptr != nullptr) {
        Del()(ptr);
    }
}

void unique_ptr::reset() {
    if (ptr != nullptr) {
        Del()(ptr);
        ptr = nullptr;
    }
}

unique_ptr make_unique(const char* str) {
    char* ptr = new char[my_strlen(str) + 1];
    my_strcpy(ptr, str);
    return unique_ptr(ptr);
}

char* move_ptr(char*& x) noexcept {
    char* res = x;
    x = nullptr;
    return res;
}

#endif // UNIQUE_PTR_H
