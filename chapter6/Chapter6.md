# Chapter6

1. 函数的返回类型不能是数组类型或函数类型，但是可以是指向数组或函数的指针
2. 局部变量会隐藏在外层作用域中同名的其他所有声明
3. **局部静态变量**在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止时才被销毁，在此期间即使对象所在的函数结束执行也不会对它有影响
4. 当参数是引用类型时，它对应的实参被**引用传递**
5. 当实参的值被拷贝给形参时，则这样的实参被**值传递**
6. 当执行**指针拷贝操作**时，拷贝的是指针的值。拷贝之后，两个指针是不同的指针
7. 在C++语言中，建议使用引用类型的形参替代指针
8. 使用**引用传递**避免拷贝
9. 如果函数无需改变引用形参的值，最好将其声明为**常量引用**
10. 数组引用实参

```c++
void print(int (&arr)[10]){/*...*/}
```

11. `initializer_list`形参

```c++
initializer_list<T> lst;				默认初始化；T类型元素的空列表
initializer_list<T> lst{a, b, c...};	lst的元素数量和初始值一样多；lst的元素时对应初始值的副本；列表中的元素是const
lst2(lst)								拷贝或赋值一个initializer_list对象不会拷贝列表中的元素；拷贝后，原始列表和副本共享元素
lst2 = lst					
lst.size()								列表中的元素数量
lst.begin()								返回指向lst中首元素的指针
lst.end()								返回指向lst中尾元素下一位置的指针
```

12. `return`值返回如果函数返回类型不是引用类型，则返回的值是通过拷贝返回的一个副本；如果返回类型是引用，则不会产生拷贝
13. 不要返回局部对象的引用或指针
14. 返回是引用类型可以作为左值直接调用其他功能函数
15. 声明返回数组指针的函数

```c++
type (*function(parameter_list))[dimension]
    
int (*func(int i))[10]
```

16. 使用尾置返回类型

```c++
auto func(int i) -> int(*)[10];
```

17. 使用`const_cast`完成重载

```c++
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size()? s1:s2;
}

string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
    return const_cast<string&>(r);
}
```

18. **默认实参**在函数声明时为形参提供默认实参，但是一旦某个形参被赋予了默认值，它后面的所有形参都必须有默认值

```c++
typedef string::size_type sz;
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');
```

19. 通常应该在函数声明中指定默认实参，并将该声明放在合适的头文件中

20. 把内联函数和`constexpr`函数放在头文件中
21. `assert`预处理宏`<cassert>`,首先对`expr`求值，如果表达式为假(即0)，`assert`输出信息并终止程序的执行。如果表达式为真(即非0)，`assert`什么也不做

```c++
assert(expr);
```

22. `NDEBUG`预处理变量，`assert`的行为依赖于`NDEBUG`的预处理变量的状态。如果定义了`NDEBUG`，则`assert`什么也不做。默认情况下没有定义`NDEBUG`，此时`assert`将执行运行时检查
23. C++编译器预处理器变量

```c++
__func__			输出当前调试的函数名字
__FILE__			存放文件名的字符串字面值
__LINE__			存放当前行号的整形字面值
__TIME__			存放文件编译时间的字符串字面值
__DATA__			存放文件编译日期的字符串字面值
```

