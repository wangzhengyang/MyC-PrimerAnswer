# Chapter3

1. `using`声明，头文件不应该包含`using`声明，可以在源文件中使用
2. 标准库类型`string`

* 头文件`<string>`
* 定义和初始化`string`对象

```c++
string s1;
string s2(s1);
string s2 = s1;
string s3("value");
string s3 = "value";
string s4(n, 'c');
```

* `string`对象操作

```c++
os << s				将s写到输出流os当中，返回os
is >> s				从is中读取字符串赋给s，字符串以空白分隔，返回is
getline(is, s)		从is中读取一行赋给s，返回is
s.empty()			s为空返回true，否则返回false
s.size()			返回s中字符的个数
s[n]				返回s中第n个字符的引用，位置n从0计起
s1+s2				返回s1和s2连接后的结果
s1=s2				用s2的副本代替s1中原来的字符
s1==s2				如果s1和s2中所含的字符完全一样，则他们相等；string对象的相等性判断对字母的大小写敏感
s1!=s2
<,<=,>,>=			利用字符在字典中的顺序进行比较，且对字母的大小写敏感
```

* `string::size_type`类型
* 处理`string`对象中的字符

```c++
<cctype>
isalnum(c)			当c是字母或数字时为真
isalpha(c)			当c是字母时为真
iscntrl(c)			当c是控制字符时为真
isdigit(c)			当c是数字时为真
isgraph(c)			当c不是空格但可以打印时为真
islower(c)			当c是小写字母时为真
isprint(c)			当c是可打印字符时为真(即c是空格或c具有可视形式)
ispunct(c)			当c是标点符号时为真(即c不是控制字符、数字、字母、可打印空白中的一种)
isspace(c)			当c是空白时为真(即c是空格、横向制表符、纵向制表符、回车符、换行符、进纸符中的一种)
isupper(c)			当c是大写字母时为真
isxdigit(c)			当c是十六进制数字时为真
tolower(c)			如果c是大写字母，输出对应的小写字母，否则原样输出c
toupper(c)			如果c是小写字符，输出对象的大写字符，否则原样输出c
```

* 遍历处理字符串

```c++
string str("some string");
for(auto c : str) //无法字符串原有的值
    cout << c << endl;

for(auto &c : str) //改变字符串原有的值
    c = toupper(c);

for(decltype(s.size()) index = 0; index != s.size(); ++index)
    s[index] = toupper(s[index]);
```

3. 标准库类型`vector`

* 头文件`<vector>`
* `vector`是类模板，需要提供数据类型进行实例化

* 定义和初始化`vector`对象

```c++
vector<T> v1			v1是一个空vector，它潜在的元素是T类型的，执行默认初始化
vector<T> v2(v1)		v2中包含有v1所有元素的副本
vector<T> v2 = v1		等价于v2(v1)，v2中包含有v1所有元素的副本
vector<T> v3(n, val)	v3包含了n个重复的元素，每个元素的值都是val
vector<T> v4(n)			v4包含了n个重复地执行了值初始化的对象
vector<T> v5{a,b,c...}	v5包含了初始值个数的元素，每个元素被赋予相应的初始值
vector<T> v5={a,b,c...}	等价于v5{a,b,c...}
```

* 向`vector`对象中添加元素`push_back`
* **返回for语句体内不应改变其所遍历序列的大小**
* 其他`vector`操作

```c++
v.empty()				如果v不含有任何元素，返回真；否则返回假
v.size()				返回v中元素的个数
v.push_back(t)			向v的尾端添加一个值为t的元素
v[n]					返回v中第n个位置上元素的引用
v1 = v2					用v2中元素的拷贝替换v1中的元素
v1 = {a,b,c...}			用列表中元素的拷贝替换v1中的元素
v1 == v2				v1和v2相等当且仅当他们的元素数量相同且对应位置的元素值都相同
v1 != v2
<, <=, >, >=			顾名思义，以字典顺序进行比较
```

* `vector`对象(以及`string`对象)的下标运算符可用于访问已存在的元素，而不能用于添加元素

4. 迭代器

* `begin`成员负责返回指向第一个元素(或第一个字符)的迭代器
* `end`成员负责返回指向容器(或`string`对象)尾元素的下一位置的迭代器，如果容器为空，则`begin`和`end`返回的是同一个迭代器

* 迭代器运算符

```c++
*iter					返回迭代器iter所指元素的引用
iter->mem				解引用iter并获取该元素的名为mem的成员，等价于(*iter).mem
++iter					令iter指示容器中的下一个元素
--iter					令iter指示容器中的上一个元素
iter1 == iter2			判断两个迭代器是否相等(不相等)，如果两个迭代器指示的是同一个元素或者它们是同一个容器的尾后迭代器，则相等；反之，不相等
iter1 != iter2
```

* `iterator`迭代器类型，可以读写元素，`const_iterator`迭代器类型，只能读取但不能修改它所指的元素值
* `cbegin` `cend`分别返回指示容器第一个元素或最后元素下一个位置的迭代器，但其返回值都是`const_iterator`
* **迭代器失效**但凡使用了迭代器的循环体，都不要向迭代器所属的容器添加元素

* `difference_type`表示两个迭代器之间的距离
* 如果不清楚元素的确切个数，使用`vector`

4. 数组

* 数组的大小确定不变，不能随意向数组中添加元素
* 定义和初始化内置数组，数组的维度必须是常量表达式

```c++
unsigned cnt = 42; //不是常量表达式
constexpr unsigned sz = 42;
int arr[10];
int *parr[sz];
string bad[cnt]; //错误，cnt不是常量表达式
string strs[get_size()]; //当get_size()是constexpr时正确，否则错误
```

* 不能将数组的内容拷贝给其他数组作为其初始值，也不能用数组为其他数组赋值

* 访问数组元素，使用`<cstddef>`中定义的`size_t`类型
* `begin`返回数组首元素的指针，`end`返回指向数组尾元素下一位置的指针

```c++
int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int *beg = begin(ia);
int *last = end(ia);
```

* 指针相减的结果类型为`ptrdiff_t`类型，定义在`cstddef`文件中

5. C标准库`String`函数，定义于头文件`<cstring>`

```C++
strlen(p)			返回p的长度，空字符不计算在内
strcmp(p1, p2)		比较p1和p2的相等性，如果p1==p2，返回0；如果p1>p2,返回一个正值；如果p1<p2,返回一个负值
strcat(p1, p2)		将p2附加在p1之后，返回p1
strcpy(p1, p2)		将p2拷贝给p1，返回p1
```

6. 使用标准库`string`要比使用C风格字符串更加安全、更高效
7. `c_str`函数让`string`返回一个C风格的字符串，指针类型为`const char*`来确保不会改变字符数组内容；注意返回的是指针，所以如果`string`数据发送改变，那么`c_str`返回的内容也会发生改变，可以考虑重新拷贝一份
8. 可以使用数组初始化`vector`对象

```c++
int int_arr[] = {0, 1, 2, 3, 4, 5};
vector<int> ivec(begin(int_arr), end(int_arr));
```





