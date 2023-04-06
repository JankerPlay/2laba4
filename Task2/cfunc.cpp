#include "errors.h"
#include <locale.h>
#include <ctype.h>
#include <stdio.h>
void* Memcpy(void* str1, const void* str2, size_t n) {
    char* dst = (char*)str1;
    char* src = (char*)str2;
    for (int i = 0; i < n; i++) {
        *(dst + i) = *(src + i);
    }
    return dst;
}
void* Memmove(void* str1, const void* str2, size_t n)
{
    char* dst = (char*)str1;
    char* src = (char*)str2;

    char* tmp = new char[n];
    for (int i = 0; i < n; i++) {
        *(tmp + i) = *(src + i);
    }
    for (int i = 0; i < n; i++) {
        *(dst + i) = *(tmp + i);
    }
    delete[] tmp;
    return dst;
}
char* Strcpy(char* str1, const char* str2)
{
    char* dst = str1;
    while (*str2 != '\0')
    {
        *dst++ = *str2++;
    }
    *dst = '\0';
    return str1;
}
char* Strncpy(char* str1, const char* str2, size_t n)
{
    if (str2 == nullptr)
    {
        return nullptr;
    }
    char* dst = str1;
    while (*str2 != '\0' && n--)
    {
        *dst++ = *str2++;
    }
    *dst = '\0';
    return str1;
}
char* Strcat(char* str1, const char* str2)
{
    char* dst = str1;
    while (*dst != '\0')
    {
        ++dst;
    }

    while (*str2 != '\0')
    {
        *dst++ = *str2++;
    }
    *dst = '\0';
    return str1;
}
char* Strncat(char* str1, const char* str2, size_t n)
{
    char* dst = str1;
    while (*dst != '\0')
    {
        ++dst;
    }
    while (*str2 != '\0' && n--)
    {
        *dst++ = *str2++;
    }
    *dst = '\0';
    return str1;
}
int Memcmp(const void* str1, const void* str2, size_t n)
{
    char* s1 = (char*)str1;
    char* s2 = (char*)str2;
    if (s1 == s2)
        return 0;
    while (n--)
    {
        if (*s1 != *s2)
        {
            return (*s1 > *s2 ? 1 : -1);
        }
        s1++;
        s2++;
    }
    return 0;
}
int Strcmp(const char* str1, const char* str2)
{
    char* s1 = (char*)str1;
    char* s2 = (char*)str2;
    if (s1 == s2)
        return 0;
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
        {
            return (*s1 > *s2 ? 1 : -1);
        }
        s1++;
        s2++;
    }
    return 0;
}
size_t Strlen(const char* s)
{
    size_t len = 0;
    while (*s != '\0')
    {
        ++len;
        ++s;
    }
    return len;
}
int Strncmp(const char* str1, const char* str2, size_t n)
{
    setlocale(LC_COLLATE, "C");
    char* s1 = (char*)str1;
    char* s2 = (char*)str2;
    if (s1 == s2)
        return 0;
    while (n-- && *s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
        {
            return (*s1 > *s2 ? 1 : -1);
        }
        s1++;
        s2++;
    }
    return 0;
}
int Strcoll(const char* str1, const char* str2, size_t n)
{
    const unsigned char* s1 = (const unsigned char*)str1;
    const unsigned char* s2 = (const unsigned char*)str2;
    if (s1 == s2)
    {
        return 0;
    }
    setlocale(LC_COLLATE, "");

    while (n-- > 0 && *s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
        {
            setlocale(LC_COLLATE, "C");
            return (*s1 > *s2 ? 1 : -1);
        }
        s1++;
        s2++;
    }
    int result = (*s1 == *s2) ? 0 : (*s1 > *s2 ? 1 : -1);
    setlocale(LC_COLLATE, "C");
    return result;
}
size_t Strxfrm(char* s1, const char* s2, size_t n)
{
    setlocale(LC_ALL, "");
    size_t len = Strlen(s2);
    size_t num_chars = n > len ? len : n;
    for (size_t i = 0; i < num_chars; ++i)
    {
        s1[i] = toupper(tolower(s2[i]));
    }
    s1[num_chars] = '\0';
    return num_chars;
}
char* Strchr(const char* str, int ch)
{
    while (*str)
    {
        if (*str == ch)
        {
            return (char*)str;
        }
        str++;
    }
    return (*str == ch) ? (char*)str : NULL;
}
char* Strtok(char* str, const char* delim)
{
    static char* ptr = nullptr;
    if (str)
    {
        ptr = str;
    }
    else if (!ptr)
    {
        return nullptr;
    }
    char* token = ptr;
    while (*ptr && Strchr(delim, *ptr))
    {
        ptr++;
    }
    if (!*ptr)
    {
        ptr = nullptr;
        return nullptr;
    }
    token = ptr;
    while (*ptr && !Strchr(delim, *ptr))
    {
        ptr++;
    }
    if (*ptr)
    {
        *ptr++ = '\0';
    }
    else
    {
        ptr = nullptr;
    }
    return token;
}
void* Memset(void* s, int c, size_t n)
{
    unsigned char* p = (unsigned char*)s;
    while (n--)
    {
        *p++ = (unsigned char)c;
    }
    return s;
}
char* Strerror(int errnum)
{
    size_t i;
    static char unknown_error[32];
    for (i = 0; i < sizeof(error_table) / sizeof(error_table[0]); i++)
    {
        if (error_table[i].code == errnum)
        {
            return (char*)error_table[i].message;
        }
    }
    snprintf(unknown_error, sizeof(unknown_error), "Unknown error %d", errnum);
    return unknown_error;
}
