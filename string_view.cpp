#include <string_view>
using namespace std;

void f(wstring_view); // string_view that uses wchar_t’s

// pass a std::wstring:
std::wstring& s; f(s);

// pass a C-style null-terminated string (string_view is not null-terminated):
wchar_t* ns = ""; f(ns);

// pass a C-style character array of len characters (excluding null terminator):
wchar_t* cs, size_t len; f({cs,len});

// pass a WinRT string
winrt::hstring hs; f(hs);
