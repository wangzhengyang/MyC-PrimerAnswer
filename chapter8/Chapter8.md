# Chapter8

1. IO库类型和头文件

| 头文件     | 类型                                                         |
| ---------- | ------------------------------------------------------------ |
| `iostream` | `istream`,`wistream`从流读取数据 <br />`ostream`,`wostream`向流写入数据<br />`iostream`,`wiostream`读写流 |
| `fstream`  | `ifstream`,`wifstream`从文件读取数据<br />`ofstream`,`wofstream`向文件写入数据<br />`fstream`,`wfstream`读写文件 |
| `sstream`  | `istringstream`,`wistringstream`从`string`读取数据<br />`ostringstream`,`wostringstream`向`string`写入数据<br />`stringstream`,`wstringstream`读写`string` |

2. IO对象不能进行拷贝或赋值
3. IO库条件状态

| 类型              | 备注                                                         |
| ----------------- | ------------------------------------------------------------ |
| strm::iostate     | strm是一种IO类型，iostate是一种机器相关的类型，提供了表达条件状态的完整功能 |
| strm::badbit      | 指出流已崩溃                                                 |
| strm::failbit     | 指出一个IO操作失败了                                         |
| strm::eofbit      | 指出流到达了文件结束                                         |
| strm::goodbit     | 指出流未处于错误状态。此值保证为零                           |
| s.eof()           | 若流s的eofbit置位，则返回true                                |
| s.fail()          | 若流s的failbit或badbit置位，则返回true                       |
| s.bad()           | 若流s的badbit置位，则返回true                                |
| s.good()          | 若流s处于有效状态，则返回true                                |
| s.clear()         | 将流s中所有条件状态位复位，将流的状态设置为有效，返回void    |
| s.clear(flags)    | 根据给定的flags标志位，将流s中对应条件状态位复位。flags的类型为strm::iostate。返回void |
| s.setstate(flags) | 根据给定的flags标志位，将流s中对应条件状态位置位。flags的类型为strm::iostate。返回void |
| s.rdstate()       | 返回流s的当前状态条件，返回值类型为strm::iostate             |

4. 缓冲刷新有以下原因：

* 程序正常结束，作为`main`函数的`return`操作的一部分，缓冲刷新被执行
* 缓冲区满时，需要刷新缓冲区，而后新的数据才能继续写入缓冲区
* 使用操作符如`endl`来显式刷新缓冲区
* 在每个输出操作之后，可以用操纵符`unitbuf`设置流的内部状态，来清空缓冲区。默认情况下，对`err`是设置`unitbuf`的，因此写到`cerr`的内容都是立即刷新的
* 一个输出流可能被关联到另一个流。在这种情况下，当读写被关联的流时，关联到的流的缓冲区会被刷新

5. 刷新操作符

| 操作符  | 备注                                   |
| ------- | -------------------------------------- |
| `endl`  | 完成换行并刷新缓冲区                   |
| `flush` | 刷新缓冲区，但不输出任何额外字符       |
| `ends`  | 向缓冲区插入一个空字符，然后刷新缓冲区 |

6. `unitbuf`告诉流接下来的每次写操作之后都进行一次`flush`操作，`nounitbuf`操作符则重置流，使其恢复使用正常的系统管理的缓冲区刷新机制

```c++
cout << unitbuf; 		//所有输出操作都立即刷新缓冲区
cout <<　nounitbuf;	   //返回正常刷新模式
```

7. `tie`用来关联流

8. 文件流

| 操作                   | 备注                                                         |
| :--------------------- | ------------------------------------------------------------ |
| fstream fstrm;         | 创建一个未绑定的文件流。`fstream`是头文件`fstream`中定义的一个类型 |
| fstream fstrm(s);      | 创建一个`fstream`，并打开名为`s`的文件。`s`可以是`string`类型，或者是一个指向C风格字符串的指针。这些构造函数都是`explicit`的。默认的文件模式`mode`依赖于`fstream`的类型 |
| fstream fstrm(s, mode) | 与前一个构造函数类似，但按指定`mode`打开文件                 |
| fstrm.open(s)          | 打开名为`s`的文件，并将文件与`fstrm`绑定。`s`可以是一个`string`或一个指向C风格字符串的指针。默认的文件`mode`依赖于`fstream`类型。返回`void` |
| fstrm.close()          | 关闭与`fstrm`绑定的文件。返回`void`                          |
| fstrm.is_open()        | 返回一个`bool`值，指出与`fstrm`关联的文件是否成功打开且尚未关闭 |

9. 当一个`fstream`对象被销毁时，`close`会自动被调用
10. 文件模式

| 模式    | 备注                         |
| ------- | ---------------------------- |
| `in`    | 以读方式打开                 |
| `out`   | 以写方式打开                 |
| `app`   | 每次写操作前均定位到文件末尾 |
| `ate`   | 打开文件后立即定位到文件末尾 |
| `trunc` | 截断文件                     |
| binary  | 以二进制方式进行IO           |

11. 指定文件模式有如下限制

* 只可以对`ofstream`或`fstream`对象设定`out`模式

* 只可以对`ifstream`或`fstream`对象设定`in`模式

* 只有当`out`也被设定时才可设定`trunc`模式

* 只要`trunc`没被设定，就可以设定`app`模式。在`app`模式下，即使没有显式指定`out`模式，文件也总以输出方式被打开

* 默认情况下，即使我们没有指定`trunc`，以`out`模式打开的文件也会被截断。为了保留以`out`模式打开的文件的内容。我们必须同时指定`app`模式，这样只会将数据追加写到文件末尾；或者同时指定`in`模式，即打开文件同时进行读写操作

* `ate`和`binay`模式可用于任何类型的文件流对象，且可以与其他任何文件模式组合使用

12. 未指定文件模式时，`ifstream`关联的文件默认以`in`模式打开；`ofstream`关联的文件默认以`out`模式打开；`fstream`关联的文件默认以`in`和`out`模式打开
13. 默认情况下以`out`模式打开文件会丢弃已有数据，指定`app`模式阻止清空文件内容
14. 调用`open`接口需要确认文件模式
15. `string`流

| 操作             | 备注                                                         |
| ---------------- | ------------------------------------------------------------ |
| sstream strm;    | `strm`是一个未绑定的`stringstream`对象。`sstream`是头文件`sstream`中定义的一个类型 |
| sstream strm(s); | `strm`是一个`sstream`对象，保存`string s`的一个拷贝。此构造函数是`explicit` |
| strm.str()       | 返回`strm`所保存的`string`的拷贝                             |
| strm.str(s)      | 将`string s`拷贝到`strm`中。返回`void`                       |

16. 使用`istringstream`处理行内的单个单词
17. 使用`ostringstream`逐步构造输出，并通过`str()`来一并输出