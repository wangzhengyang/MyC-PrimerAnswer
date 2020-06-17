# Chapter19

1. `new`过程

* `new`表达式调用一个名为`operator new`(或者`operator new[]`)的标准库函数；该函数分配一块足够大的、原始的、未命名的内存空间以便存储特定类型的对象(或者对象的数组)
* 编译器运行相应的构造函数以构造这些对象，并为其传入初始值
* 对象被分配了空间并构造完成，返回一个指向该对象的指针

2. `delete`过程

* 对`sp`所指的对象或者`arr`所指的数组中的元素执行对应的析构函数
* 编译器调用名为`operator delete`(或者`operator delete[]`)的标准库函数释放内存空间

3. 当自定义了全局的`operator new`函数和`operator delete`函数后，我们就担负起了控制动态内存分配的职责；这两个函数必须是正确的；因为它们是程序整个处理过程中至关重要的一部分
4. `operator new`接口和`operator delete`接口`<new>`

```c++
//这些版本可能抛出异常
void *operator new(size_t);
void *operator new[](size_t);
void *operator delete(void*) noexcept;
void *operator delete[](void*) noexcept;

//这些版本承诺不会抛出异常
void *operator new(size_t, nothrow_t&) noexcept;
void *operator new[](size_t, nothrow_t&) noexcept;
void *operator delete(void*, nothrow_t&) noexcept;
void *operator delete[](void, nothrow_t&) noexcept;
```

5. `operator new`和`operator delete`使用`malloc`和`free`来实现真正的空间分配
6. 定位`new`

```c++
new (place_address) type
new (place_address) type (initializers)
new (place_address) type [size]
new (place_address) type [size] {braced initializer list}
```

7. 当只传入一个指针类型的实参时，定位`new`表达式构造对象但是不分配内存
8. 调用析构函数会销毁对象，但是不会释放内存
9. 使用`typeid`以及`dynamic_cast`运算符实现运行时类型识别(RTTI)
10. 使用RTTI必须要加倍小心；在可能的情况下，最好定义虚函数而非直接接管类型管理的重任

11. `dynamic_cast`运算符；`type`必须是一个类类型，并且通常情况下该类型应该含有虚函数

```c++
dynamic_cast<type*>(e)
dynamic_cast<type&>(e)
dynamic_cast<type&&>(e)
```

12. 我们可以对一个空指针执行`dynamic_cast`，结果是所需类型的空指针
13. 在条件部分执行`dynamic_cast`操作可以确保类型转换和结果检查在同一条表达式中完成
14. 如果一条`dynamic_cast`语句的转换目标是指针类型并且失败了，则结果为0；如果转换目标是引用类型并且失败了，则抛出一个`bad_cast`异常，该异常定义在`<typeinfo>`
15. `typeid`允许程序向表达式提问该对象的类型；`typeid`操作的结果是一个常量对象的引用，该对象的类型是标准库类型`type_info`或者`type_info`的公有派生类型；`typeid`作用于对象
16. 当`typeid`作用于指针时(而非指针所指的对象)，返回的结果是该指针的静态编译时类型
17. `type_info`类操作

| 操作          | 备注                                                         |
| ------------- | ------------------------------------------------------------ |
| t1 == t2      | 如果type_info对象t1和t2表示同一种类型，返回true；否则返回false |
| t1 != t2      | 如果type_info对象t1和t2表示不同的类型，返回true；否则返回false |
| t.name()      | 返回一个C风格字符串，表示类型名字的可打印形式；类型名字的生成方式因系统而异 |
| t1.before(t2) | 返回一个bool值，表示t1是否位于t2之前；before所采用的顺序关系是依赖于编译器的 |

18. 链接到C的预处理器

```c++
#ifdef __cplusplus
extern "C" {
#endif
//函数
#ifdef __cplusplus
}
#endif
```



