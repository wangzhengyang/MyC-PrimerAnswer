#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class StrVec
{
public:
    StrVec() : start(nullptr), first_free(nullptr), end(nullptr) {}
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    void push_back(const string &);
    ~StrVec();
    size_t size() const { return first_free - start; }
    size_t capacity() const { return end - start; }
    void print();
private:
    void chk_n_alloc()
    {
        if (size() == capacity())
            realloc();
    }
    void realloc();
    void free();

private:
    allocator<string> alloc;
    string *start;
    string *first_free;
    string *end;
};

void StrVec::print()
{
    for(auto i = start; i != first_free; ++i){
        cout << *i << endl;
    }
}

StrVec::StrVec(const StrVec &svec)
{
    start = alloc.allocate(svec.end - svec.start);
    string *dest = start; string *src = svec.start;
    for(; src != svec.first_free;){
        alloc.construct(dest++, *src++);
    }
    first_free = dest;
    end = start + (svec.end - svec.start);
}

StrVec &StrVec::operator=(const StrVec &svec)
{
    string *pnew = alloc.allocate(svec.end - svec.start);
    free();
    start = pnew;
    string *dest = pnew; string *src = svec.start;
    for(;src != svec.first_free;){
        alloc.construct(dest++, *src++);
    }
    first_free = dest;
    end = start + (svec.end - svec.start);
    return (*this);
}

StrVec::~StrVec()
{
    free();
}

void StrVec::free()
{
    string *p = first_free;
    size_t i = 0;
    if (start)
    {
        for (; p != start;)
        {
            alloc.destroy(--p);
            i++;
        }
        cout << "free times:" << i << endl;
        alloc.deallocate(start, end - start);
    }
}

void StrVec::realloc()
{
    size_t sz = size() ? 2 * size() : 1;
    string *pnew = alloc.allocate(sz);
    string *dest = pnew;
    string *src = start;
    for (size_t i = 0; i < size(); ++i)
    {
        alloc.construct(dest++, std::move(*src++));
    }
    free();
    start = pnew;
    first_free = dest;
    end = pnew + sz;
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

int main()
{
    StrVec str;
    str.push_back("wangzhengyang");
    str.push_back("liuqin");
    str.push_back("love");
    str.print();

    StrVec str1(str);
    str1.push_back("shit");
    str.print();
    str1.print();

    StrVec str2;
    str2 = str1;
    str2.push_back("hello world");
    str.print();
    str1.print();
    str2.print();
    return 0;
}