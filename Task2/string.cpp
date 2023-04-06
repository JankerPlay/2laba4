//#include "uniqueptr.h"
//#include <limits>
//#include <utility>
//#include <string>
//#include <stdexcept>
//#include <iostream>
//#include <string.h>
//class string {
//private:
//    unique_ptr String;
//    size_t _size = 0;
//    size_t _capacity = 0;
//public:
//    string() = default;
//    string(const char* str)
//    {
//        _size = my_strlen(str);
//        _capacity = _size + 1;
//        String = make_unique(new char[_capacity]);
//        my_strncpy(String.get(), str, _capacity);
//    }
//    string(const string& other)
//    {
//        _size = other._size;
//        _capacity = other._capacity;
//        String = make_unique(new char[_capacity]);
//        my_strncpy(String.get(), other.String.get(), _capacity);
//    }
//    string(string&& other) noexcept
//    {
//        String = std::move(other.String);
//        _size = other._size;
//        _capacity = other._capacity;
//        other._size = 0;
//        other._capacity = 0;
//    }
//    ~string() = default;
//    string& operator=(const string& other)
//    {
//        if (this != &other) {
//            _size = other._size;
//            _capacity = other._capacity;
//            String = make_unique(new char[_capacity]);
//            my_strncpy(String.get(), other.String.get(), _capacity);
//        }
//        return *this;
//    }
//    string& operator=(string&& other) noexcept
//    {
//        String = std::move(other.String);
//        _size = other._size;
//        _capacity = other._capacity;
//        other._size = 0;
//        other._capacity = 0;
//        return *this;
//    }
//    bool operator==(const string& other) const
//    {
//        return my_strcmp(String.get(), other.String.get()) == 0;
//    }
//    bool operator!=(const string& other) const
//    {
//        return !(*this == other);
//    }
//    bool operator<(const string& other) const
//    {
//        return my_strcmp(String.get(), other.String.get()) < 0;
//    }
//    bool operator>(const string& other) const
//    {
//        return my_strcmp(String.get(), other.String.get()) > 0;
//    }
//    bool operator<=(const string& other) const
//    {
//        return my_strcmp(String.get(), other.String.get()) <= 0;
//    }
//    bool operator>=(const string& other) const
//    {
//        return my_strcmp(String.get(), other.String.get()) >= 0;
//    }
//    string operator+(const string& other) const
//    {
//        string result;
//        result._size = _size + other._size;
//        result._capacity = result._size + 1;
//        result.String = make_unique(new char[result._capacity]);
//        my_strncpy(result.String.get(), String.get(), _size);
//        my_strncpy(result.String.get() + _size, other.String.get(), other._size + 1);
//        return result;
//    }
//    string& operator+=(const string& other)
//    {
//        *this = *this + other;
//        return *this;
//    }
//    char operator[](size_t index) const
//    {
//        return String.get()[index];
//    }
//    char& operator[](size_t index)
//    {
//        return String.get()[index];
//    }
//    friend std::ostream& operator<<(std::ostream& os, const string& s)
//    {
//        os << s.String.get();
//        return os;
//    }
//    friend std::istream& operator>>(std::istream& is, string& s)
//    {
//        std::string str;
//        is >> str;
//        s = string(str.c_str());
//        return is;
//    }
//    void reserve(size_t new_capacity)
//    {
//        if (new_capacity > _capacity)
//        {
//            unique_ptr new_string(new_capacity);
//            my_memcpy(new_string.get(), String.get(), _size + 1);
//            String = std::move(new_string);
//            _capacity = new_capacity;
//        }
//    }
//    void resize(size_t new_size)
//    {
//        if (new_size > _size)
//        {
//            reserve(new_size);
//            my_memset(String.get() + _size, '\0', new_size - _size);
//        }
//        _size = new_size;
//    }
//    void push_back(char c)
//    {
//        if (_size + 1 >= _capacity)
//        {
//            reserve(_capacity == 0 ? 1 : _capacity * 2);
//        }
//        String.get()[_size++] = c;
//        String.get()[_size] = '\0';
//    }
//    string& append(const string& str)
//    {
//        *this += str;
//        return *this;
//    }
//    char* begin()
//    {
//        return String.get();
//    }
//    char* end()
//    {
//        return String.get() + _size;
//    }
//    size_t capacity() const
//    {
//        return _capacity;
//    }
//    size_t length() const
//    {
//        return _size;
//    }
//    void clear()
//    {
//        String.reset();
//        _size = 0;
//        _capacity = 0;
//    }
//    string& erase(size_t pos = 0, size_t len = std::string::npos)
//    {
//        len = std::min(len, _size - pos);
//        my_memmove(String.get() + pos, String.get() + pos + len, _size - len - pos + 1);
//        _size -= len;
//        return *this;
//    }
//    string& insert(size_t pos, const string& new_str)
//    {
//        size_t len = new_str.length();
//        if (pos > _size)
//        {
//            pos = _size;
//        }
//        if (_size + len > _capacity)
//        {
//            reserve(_size + len);
//        }
//        my_memmove(String.get() + pos + len, String.get() + pos, _size - pos + 1);
//        my_memcpy(String.get() + pos, new_str.c_str(), len);
//        _size += len;
//        return *this;
//    }
//    int compare(const string& str) const
//    {
//        return my_strcmp(String.get(), str.String.get());
//    }
//    char& front()
//    {
//        return String.get()[0];
//    }
//    char& back()
//    {
//        return String.get()[_size - 1];
//    }
//    const char* c_str() const
//    {
//        return String.get();
//    }
//    bool empty() const
//    {
//        return _size == 0;
//    }
//    size_t max_size() const
//    {
//        return std::numeric_limits<size_t>::max();
//    }
//    void pop_back()
//    {
//        if (_size > 0)
//        {
//            String.get()[--_size] = '\0';
//        }
//    }
//    size_t find(const string& str, size_t pos = 0) const
//    {
//        const char* c_str = String.get() + pos;
//        const char* sub_str = str.String.get();
//        const char* result = strstr(c_str, sub_str);
//        return result ? result - String.get() : std::string::npos;
//    }
//    string& replace(const string& old_str, const string& new_str)
//    {
//        size_t pos = 0;
//        size_t old_len = old_str.length();
//        size_t new_len = new_str.length();
//        while ((pos = find(old_str, pos)) != std::string::npos)
//        {
//            erase(pos, old_len);
//            insert(pos, new_str);
//            pos += new_len;
//        }
//        return *this;
//    }
//    string& substr(size_t pos, size_t len, const string& new_str)
//    {
//        if (pos > _size) {
//            throw std::out_of_range("Invalid position");
//        }
//        len = std::min(len, _size - pos);
//        erase(pos, len);
//        insert(pos, new_str);
//        return *this;
//    }
//};
