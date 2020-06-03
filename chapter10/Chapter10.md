# Chapter10

1. 头文件`<algorithm>`以及`<numeric>`
2. 算法不直接操作容器，而是遍历由两个迭代器指定的一个元素范围来进行操作。通常情况下，算法遍历范围，对其中每个元素进行一些处理
3. 迭代器令算法不依赖于容器，但算法依赖于元素类型的操作
4. `find`算法(只读算法)

```c++
find(vec.cbegin(), vec.cend(), val);
find(begin(ia), end(ia), val);
```

5. `accumulate`算法(只读算法)`<numeric>`

接受三个参数，前两个指出需要求和的元素的范围，第三个参数是和的初值，参数类型决定了函数中使用哪个加法运算符以及返回值的类型

```c++
int sum = accumulate(vec.cbegin(), vec.cend(), 0);
string sum = accumulate(v.cbegin(), v.cend(), string(""));
```

6. 对于只读取而不改变元素的算法，通常最好使用`cbegin()`和`cend()`。但是，如果你计划使用算法返回的迭代器来改变元素的值，就需要使用`begin()`和`end()`的结果作为参数

7. `equal`算法(只读算法)

前提：那些只接受一个单一迭代器来表示第二个序列的算法，都假定第二个序列至少与第一个序列一样长

```c++
equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
```

8. `fill`算法

```c++
fill(vec.begin(), vec.end(), 0);
```

9. 算法不检查写操作，向目的位置迭代器写入数据的算法假定目的位置足够大，能容纳要写入的元素

10. `fill_n`算法

```c++
fill_n(vec.begin(), vec.size(), 0);
```

11. `back_inserter`定义在头文件`<iterator>`中，接受一个指向容器的引用，返回一个与该容器绑定的插入迭代器。当我们通过此迭代器赋值时，赋值运算符会调用`push_back`将一个具有给定值的元素添加到容器中
12. `copy`算法

接受三个迭代器，前两个表示一个输入范围，第三个表示目的序列的起始位置，**传递给`copy`的目的序列至少要包含与输入序列一样多的元素**

```c++
int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int a2[sizeof(a1)/sizeof(*a1)];
auto ret = copy(begin(a1), end(a1), a2);
```

13. `replace`算法

接受4个参数，前两个是迭代器，表示输入序列，后两个一个是要搜索的值，另一个是新值

```c++
replace(ilst.begin(), ilst.end(), 0, 42);
```

14. `replace_copy`算法

保留原序列不变，第三个迭代参数指出调整后序列的保存位置

```c++
replace_copy(ilst.cbegin(), ilst.cend(), back_inserter(ivec), 0, 42);
```

15. `sort`算法

```c++
sort(words.begin(), words.end());
```

16. `unique`算法

重排输入序列，将相邻的重复项“消除”，并返回一个指向不重复值范围末尾的迭代器，但并不改变容器的大小

```c++
unique(words.begin(), words.end());
```

17. 标准库算法对迭代器而不是容器进行操作。因此，算法不能(直接)添加或删除元素
18. 算法传递函数

```c++
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() <s2.size();
}
sort(words.begin(), words.end(), isShorter);
```

19. `stable_sort`算法

排序，且具有相同长度的元素按字典序排列

```c++
stable_sort(words.begin(), words.end(), isShorter);
```

20. lambda表达式

具有一个返回类型、一个参数列表和一个函数体

```c++
[capture list](parameter list)->return type{function body}
```

`capture list`(捕获列表)是一个lambda所在函数中定义的局部变量的列表(通常为空)；`return type`、`parameter list`和`function body`与任何普通函数一样，分别表示返回类型、参数列表和函数体，但是lambda必须使用尾置返回来指定返回类型

21. 如果lambda的函数体包含任何单一return语句之外的内容，且未指定返回类型，则返回void

22. 一个lambda只有在其捕获列表中捕获一个它所在函数中的局部变量，才能在函数体中使用该变量

23. `find_if`算法

```c++
auto wc = find_if(words.begin(), words.end(), [sz](const string &a){return a.size() > sz;});
```

24. `for_each`算法

```c++
for_each(wc, words.end(),
        [](const string &s){cout << s << " ";});
cout << endl;
```

一个lambda可以直接使用定义在当前函数之外的名字，`cout`不是定义在函数内部的局部名字，而是定义在头文件`iostream`中。因此，只要在函数出现的作用域中包含了头文件`iostream`，lambda就可以使用`cout`

25. 当定义一个lambda时，编译器生成一个与lambda对应的新的(未命名的)类类型，使用auto定义一个用lambda初始化的变量

```c++
auto f = [v1]{return v1;};
```

26. lambda值捕获可以是值或引用，当以引用方式捕获一个变量时，必须保证在lambda执行时变量是存在的

27. lambda指示编译器推断捕获列表,`&`采用捕获引用方式，`=`采用值捕获方式

28. lambda捕获列表

| 标识                 | 备注                                                         |
| -------------------- | ------------------------------------------------------------ |
| []                   | 空的捕获列表。lambda不能使用所在函数中变量。一个lambda只有捕获变量后才能使用它们 |
| [names]              | names是一个逗号分隔的名字列表，这些名字都是lambda所在函数的局部变量。默认情况下，捕获列表中的变量都被拷贝。名字前如果使用类&，则采用引用捕获方式 |
| [&]                  | 隐式捕获列表，采用引用捕获方式。lambda体中所使用的来自所在函数的实体都采用引用方式使用 |
| [=]                  | 隐式捕获列表，采用值捕获方式。lambda体将拷贝所使用的来自所在函数的实体的值 |
| [&, identifier_list] | identifier_list是一个逗号分隔的列表，包含0个或多个来自所在函数的变量。这些变量采用值捕获方式，而任何隐式捕获的变量都采用引用方式捕获。identifier_list中的名字前面不能使用& |
| [=, identifier_list] | identifier_list中的变量都采用引用方式捕获，而任何隐式捕获的变量都采用值方式捕获。identifier_list中的名字不能包括this,且这些名字之前必须使用& |

29. 可变lambda

默认情况下，对于一个值被拷贝的变量，lambda不会改变其值。如果我们希望能改变一个被捕获的变量的值，就必须在参数列表首加上关键字`muteable`

30. `transform`算法

```c++
transform(vi.begin(), vi.end(), vi.begin(), [](int i){return i < 0? -i : i;});
```

31. 当lambda有多个返回值时，必须使用尾置返回类型

```c++
//错误
transform(vi.begin(), vi.end(), vi.begin(), [](int i){if (i < 0) return -i; else return i;});
//正确
transform(vi.begin(), vi.end(), vi.begin(), [](int i)->int{if (i < 0) return -i; else return i;});
```

32. `bind`函数`<functional>`

`bind`是一个通用的函数适配器，它接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表；`arg_list`的参数可能包含形如`_n`的名字，其中`n`是一个整型。这些参数是“占位符”

```c++
auto newCallable = bind(callable, arg_list);
```

```c++
bool check_size(const string&s, string::size_type sz)
{
    retur s.size() >= sz;
}
auto check6 = bind(check_size, _1, 6);

//调用
string s = "hello";
bool b1 = check6(s);

auto wc = find_if(words.begin(), words.end(), [sz](const string　&a));
等价于
auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));
```

33. `_n`定义在`placeholders`命名空间
34. 绑定参数默认按值拷贝，如果要绑定引用参数，使用`ref`函数，`cref`生成一个保存`const`引用的类

35. `<iterator>`还定义了插入迭代器、流迭代器、反向迭代器以及移动迭代器
36. 插入迭代器

| 操作            | 备注                                                         |
| --------------- | ------------------------------------------------------------ |
| it = t          | 在it指定的当前位置插入值t。假定c是it绑定的容器，依赖于插入迭代器的不同种类，此赋值会分别调用c.push_back(t)、c.push_front(t)或c.insert(t, p),其中p为传递给inserter的迭代器位置 |
| *it, ++it, it++ | 这些操作虽然存在，但不会对it做任何事情。每个操作都返回it     |

37. `back_inserter`创建一个使用`push_back`的迭代器，只有在容器支持`push_back`的情况下，才可以使用`back_inserter`
38. `front_inserter`创建一个使用`push_front`的迭代器，只有在容器支持`push_front`的情况下，才可以使用`front_inserter`
39. `inserter`创建一个使用`insert`的迭代器。此函数接受第二个参数，这个参数必须是一个指向给定容器的迭代器。元素将被插入到给定迭代器所表示的元素之前

```c++
list<int> lst = {1, 2, 3, 4};
list<int> lst2, lst3; //空list
//拷贝完成后，lst2包含4 3 2 1
copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
//拷贝完成后，lst3包含1 2 3 4
copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
```

40. `iostream`迭代器

`istream_iterator`读取输入流，`ostream_iterator`向一个输出流写输入，这些迭代器将它们对应的流当作一个特定类型的元素序列来处理。通过使用流迭代器，使用泛型算法从流对象读取数据以及向其写入数据

41. `istream_iterator`操作

创建流迭代器，必须指定迭代器将要读写的对象类型。一个`istream_iterator`使用`>>`来读取流。因此，`istream_iterator`要读取的类型必须定义了输入运算符。当创建一个`istream_iterator`时，我们可以将它绑定到一个流。也可以默认初始化迭代器，创建一个可以当做尾后值使用的迭代器

```c++
istream_iterator<int> int_it(cin);	//从cin读取int
istream_iterator<int> int_eof;		//尾后迭代器
ifstream in("afile");
istream_iterator<string> str_it(in);	//从"afile"读取字符串
```

```c++
istream_iterator<int> in_iter(cin);	//从cin读取int
istream_iterator<int> eof;			//istream尾后迭代器
while(in_iter != eof)
    vec.push_back(*in_iter++);

或者

istream_iterator<int> in_iter(cin), eof;	//从cin读取int
vector<int> vec(in_iter, eof);				//从迭代器返回构造vec
```

| 操作                        | 备注                                                         |
| --------------------------- | ------------------------------------------------------------ |
| istream_iterator<T> in(is); | in从输入流is读取类型为T的值                                  |
| istream_iterator<T> end;    | 读取类型为T的值的istream_iterator迭代器，表示尾后位置        |
| in1 == in2<br />in1 != in2  | in1和in2必须读取相同类型。如果它们都是尾后迭代器，或绑定到相同的输入，则两者相等 |
| *in                         | 返回从流中读取的值                                           |
| in->mem                     | 与(*in).mem的含义相同                                        |
| ++in, in++                  | 使用元素类型所定义的>>运算符从输入流中读取下一个值。与以往一样，前置版本返回一个指向递增后迭代器的引用，后置版本返回旧值 |

42. 使用算法操作流迭代器

```c++
istream_iterator<int> in(cin), eof;
cout << accumulate(in, eof, 0) << endl;
```

43. `ostream_iterator`操作

| 操作                            | 备注                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| ostream_iterator<T> out(os);    | out将类型为T的值写到输出流os中                               |
| ostream_iterator<T> out(os, d); | out将类型为T的值写到输出流os中，每个值后面都输出一个d。d指向一个空字符结尾的字符数组 |
| out = val                       | 用<<运算符将val写入到out所绑定的ostream中。val的类型必须与out可写的类型兼容 |
| *out，++out，out++              | 这些操作符是存在的，但不对out做任何事情。每个运算符都返回一个out |

```c++
ostream_iterator<int>　out_iter(cout, " ");
for(auto e : vec)
    *out_iter++ = e;
cout <<　endl;

或者
    
copy(vec.begin(), vec.end(), out_iter);
cout << endl;
```

44. 反向迭代器

递增一个反向迭代器(++it)会移动到前一个元素；递减一个迭代器(--it)会移动到下一个元素

除了`forward_list`之外，其他容器都支持反向迭代器。通过`rbegin`、`rend`、`crbegin`、`crend`成员函数来获得反向迭代器

```c++
sort(vec.begin(), vec.end()); 	//按“正常序”排序vec
sort(vec.rbegin(), vec.rend());	//按逆序排序
```

45. 通过`base()`将反向迭代器转化成为普通迭代器
46. 反向迭代器的目的是表示元素范围，而这些范围是不对称的，这导致一个重要的结果：当我们从一个普通迭代器初始化一个反向迭代器，或是给一个反向迭代器赋值时，结果迭代器与原迭代器指向的并不是相同的元素

47. 迭代器类别

| 类别           | 备注                                 |
| -------------- | ------------------------------------ |
| 输入迭代器     | 只读，不写；单遍扫描，只能递增       |
| 输出迭代器     | 只写，不读；单遍扫描，只能递增       |
| 前向迭代器     | 可读写；多遍扫描，只能递增           |
| 双向迭代器     | 可读写；多遍扫描，可递增递减         |
| 随机访问迭代器 | 可读写；多遍扫描，支持全部迭代器运算 |

48. 算法形参模式

```c++
alg(beg, end, other args);
alg(beg, end, dest, other args);
alg(beg, end, beg2, other args);
alg(beg, end, beg2, end2, other args);
```

49. `list`和`forward_list`特定容器算法

| 算法                                       | 备注                                                         |
| ------------------------------------------ | ------------------------------------------------------------ |
|                                            | 这些操作都返回void                                           |
| lst.merge(lst2)<br />lst.merge(lst2, comp) | 将来自lst2的元素合并到lst。lst和lst2都必须是有序的。元素将从lst2中删除。在合并之后，lst2变为空。第一个版本使用<运算符；第二个版本使用给定的比较操作 |
| lst.remove(val)<br />lst.remove_if(pred)   | 调用erase删除掉与给定值相等(==)或令一元谓词为真的每个元素    |
| lst.reverse()                              | 反转lst中元素的顺序                                          |
| lst.sort()<br />lst.sort(comp)             | 使用<或给定比较操作排序元素                                  |
| lst.unique()<br />lst.unique(pred)         | 调用erase删除同一个值得连续拷贝。第一个版本使用==；第二个版本使用给定的二元谓词 |

50. 链式类型`splice`算法

| 操作                                      | 备注                                                         |
| ----------------------------------------- | ------------------------------------------------------------ |
| lst.splice(args)或flst.splice_after(args) |                                                              |
| (p, lst2)                                 | p是一个指向lst中元素的迭代器，或一个指向flst首前位置的迭代器。函数将lst2的所有元素移动到lst中p之前的位置或是flst中p之后的位置。将元素从lst2中删除。lst2的类型必须于lst或flst相同，且不能是同一个链表 |
| (p, lst2, p2)                             | p2是一个指向lst2中位置的有效的迭代器。将p2指向的元素移动到lst中，或将p2之后的元素移动到flst中。lst2可以是与lst或flst相同的链表 |
| (p, lst2, b, e)                           | b和e必须表示lst2中的合法范围。将给定范围中的元素从lst2移动到lst或flst。lst2与lst(或flst)可以是相同的链表，但p不能指向给定范围中元素 |

