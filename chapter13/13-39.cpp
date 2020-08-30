#include <string>
#include <memory>
#include <utility>
#include <iostream>

using namespace std;

class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    ~StrVec();
    void push_back(const string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }
    void reserve(size_t n);
    void resize(size_t n);
    void print();

private:
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    void reallocate();
    void free();
    pair<string *, string *> alloc_n_copy(const string *, const string *);

private:
    allocator<string> salloc;
    string *elements;
    string *first_free;
    string *cap;
};

void StrVec::print()
{
    for (auto i = elements; i != first_free; ++i)
    {
        cout << *i << endl;
    }
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    salloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = salloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
        {
            salloc.destroy(--p);
        }
        salloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return (*this);
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = salloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
    {
        salloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
    if (n == capacity())
    {
        return;
    }
    pair<string *, string *> newdata;
    if (elements + n < first_free)
    {
        newdata = alloc_n_copy(elements, elements + n);
    }
    else
    {
        newdata = alloc_n_copy(elements, first_free);
    }
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
}

void StrVec::resize(size_t n)
{
    if (n == size())
    {
        return;
    }
    if (n < size())
    {
        for (auto p = first_free; p != elements + n;)
        {
            salloc.destroy(--p);
        }
    }
    else
    {
        for (auto p = first_free; p != elements + n;)
        {
            salloc.construct(p++, string());
        }
    }
    first_free = elements + n;
}

int main()
{
    StrVec str;
    str.push_back("wang");
    str.push_back("zheng");
    str.push_back("yang");
    StrVec str1(str);
    StrVec str2 = str;
    str.print();
    str1.print();
    str2.print();
    return 0;
}