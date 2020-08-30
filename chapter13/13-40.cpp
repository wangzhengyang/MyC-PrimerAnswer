#include <string>
#include <memory>
#include <utility>
#include <iostream>

using namespace std;

class StrVec{
public:
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    ~StrVec();
    void push_back(const string &);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    string *begin() const {return elements;}
    string *end() const {return first_free;}
    void reserve(size_t n);
    void resize(size_t n);
    StrVec(initializer_list<string> &l);
    void print();
private:
    void chk_n_alloc(){if(size() == capacity()) reallocate();}
    void reallocate();
    void free();
    pair<string*, string*> alloc_n_copy(const string*, const string*);
private:
    allocator<string> alloc;
    string *elements;
    string *first_free;
    string *cap;
};

void StrVec::print()
{
    for(auto i = elements; i < first_free; ++i){
        cout << *i << endl;
    }
}

StrVec::StrVec(initializer_list<string> &l)
{
    auto data = alloc_n_copy(&(*l.begin()), &(*l.end()));
    elements = data.first;
    first_free = cap = data.second;
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if(elements){
        for(auto p = first_free; p != elements;){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
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
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i){
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
    if(n == capacity()){
        return;
    }
    pair<string*, string*> newdata;
    if(elements + n < first_free){
        newdata = alloc_n_copy(elements, elements + n);
    }else{
        newdata = alloc_n_copy(elements, first_free);
    }
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
}

void StrVec::resize(size_t n)
{
    if(n == size()){
        return;
    }
    if(n < size()){
        for(auto p = first_free; p != elements + n;){
            alloc.destroy(--p);
        }
    }else{
        for(auto p = first_free; p != elements +n;){
            alloc.construct(p++, string());
        }
    }
    first_free = elements + n;
}

int main()
{
    initializer_list<string> l({"wang", "zheng", "yang"});
    StrVec str(l);
    str.print();
    return 0;
}