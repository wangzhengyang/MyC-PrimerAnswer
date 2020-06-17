# Chapter17

1. `tuple`类型

| 操作                                       | 备注                                                         |
| ------------------------------------------ | ------------------------------------------------------------ |
| tuple<T1, T2, ..., Tn> t;                  | t是一个tuple，成员数为n，第i个成员的类型为Ti；所有成员都进行值初始化 |
| tuple<T1, T2, ..., Tn> t(v1, v2, ..., vn); | t是一个tuple，成员类型为T1...Tn，每个成员用对应的初始值vi进行初始化；此构造函数是explicit的 |
| make_tuple(v1, v2, ..., vn)                | 返回一个用给定初始值初始化的tuple；tuple的类型从初始值的类型推断 |
| t1 == t2<br />t1 != t2                     | 当两个tuple具有相同数量的成员且成员对应相等时，两个tuple相等。这两个操作使用成员的==运算符来完成。一旦发现某对成员不等，接下来的成员就不用比较了 |
| t1 relop t2                                | tuple的关系运算使用字典序；两个tuple必须具有相同数量的成员；使用<运算符比较t1的成员和t2中的对象成员 |
| get<i>(t)                                  | 返回t的第i个数据成员的引用；如果t是一个左值，结果是一个左值引用；否则，结果是一个右值引用；tuple的所有成员都是public的 |
| tuple_size<tupleType>::value               | 一个类模板，可以通过一个tuple类型来初始化。它有一个名为value的public constexpr static数据成员，类型为size_t，表示给定tuple类型中成员的数量 |
| tuple_element<i, tupleType>::type          | 一个类模板，可以通过一个整型常量和一个tuple类型来初始化；它有一个名为type的public成员，表示给定tuple类型中指定成员的类型 |

2. 可以将`tuple`看作一个“快速而随意”的数据结构
3. 由于`tuple`定义了`<`和`==`运算符；我们可以将`tuple`序列传递给算法，并且可以在无序容器中将`tuple`作为关键字类型
4. `bitset`类型

| 操作(初始化)                        | 备注                                                         |
| ----------------------------------- | ------------------------------------------------------------ |
| bitset<n> b;                        | b有n位；每一位均为0；此构造函数是一个constexpr               |
| bitset<n> b(u);                     | b是unsigned long long值u的低n位的拷贝；如果n大于unsigned long long的大小，则b中超出unsigned long long 的高位被置位0；此构造函数是一个constexpr |
| bitset<n> b(s, pos, m, zero, one);  | b是string s从位置pos 开始m个字符的拷贝。s只能包含字符zero或one；如果s包含任何其他字符，构造函数会抛出invalid_argument异常；字符在b中分别保存为zero和one；pos默认为0，m默认为string::npos，zero默认为`0`，one默认为`1` |
| bitset<n> b(cp, pos, m, zero, one); | 与上一个构造函数相同，但从cp指向的字符数组中拷贝字符；如果未提供m，则cp必须指向一个C风格字符串；如果提供了m，则从cp开始必须至少有m个zero或one字符 |
|                                     | 接受一个string或一个字符指针的构造函数是explicit的；在新标准中增加了为0和1指定其他字符的功能 |

5. `string`的下标编号习惯与`bitset`恰好相反：`string`中下标最大的字符(最右字符)用来初始化`bitset`中的低位(下标为0的二进制位)；当你用一个`string`初始化一个`bitset`时，要记住这个差别
6. `bitset`操作

| 操作                            | 备注                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| b.any()                         | b中是否存在置位的二进制位                                    |
| b.all()                         | b中所有位都置位了吗                                          |
| b.none()                        | b中不存在置位的二进制位吗                                    |
| b.count()                       | b中置位的位数                                                |
| b.size()                        | 一个constexpr函数，返回b中的位数                             |
| b.test(pos)                     | 若pos位置的位是置位的，则返回true，否则返回false             |
| b.set(pos, v)<br />b.set()      | 将位置pos处的位设置为bool值v；v默认为true，如果未传递实参，则将b中所有位置位 |
| b.reset(pos)<br />b.reset()     | 将位置pos处的位复位或将b中所有位复位                         |
| b.flip(pos)<br />b.flip()       | 改变位置pos处的位的状态或改变b中每一位的状态                 |
| b[pos]                          | 访问b中位置pos处的位；如果b是const的，则当该位置位时b[pos]返回一个bool值true，否则返回false |
| b.to_ulong()<br />b.to_ullong() | 返回一个unsigned long或一个unsigned long long 值，其位模式与b相同。如果b中位模式不能放入指定的结果类型，则抛出一个overflow_error异常 |
| b.to_string(zero, one)          | 返回一个string,表示b中的位模式；zero和one的默认值分别为0和1，用来表示b中的0和1 |
| os << b                         | 将b中二进制位打印为字符1或0，打印到流os                      |
| is >> b                         | 从is读取字符存入b；当下一个字符不是1或0时，或是已经读入b.size()个位时，读取过程停止 |

7. 如果`bitset`中的值不能放入给定类型中，则这两个操作会抛出一个`overflow_error`异常
8. 正则表达式`<regex>`

| 组件            | 备注                                                         |
| --------------- | ------------------------------------------------------------ |
| regex           | 表示有一个正则表达式的类                                     |
| regex_match     | 将一个字符序列与一个正则表达式匹配                           |
| regex_search    | 寻找第一个与正则表达式匹配的子序列                           |
| regex_replace   | 使用给定格式替换一个正则表达式                               |
| sregex_iterator | 迭代器适配器，调用regex_search来遍历一个string中所有匹配的子串 |
| smatch          | 容器类，保存在string中搜索的结果                             |
| ssub_match      | string中匹配的子表达式的结果                                 |

9. `regex_search`和`regex_match`的参数

| 操作                                | 备注                                                         |
| ----------------------------------- | ------------------------------------------------------------ |
|                                     | 注意：这些操作返回bool值，指出是否找到匹配                   |
| (seq, m, r, mft)<br />(seq, r, mft) | 在字符序列seq中查找regex对象r中的正则表达式；seq可以是一个string、表示范围的一对迭代器以及一个指向空字符结尾的字符数组的指针<br />m是一个match对象，用来保存匹配结果的相关细节；m和seq必须具有兼容的类型<br />mft是一个可选的regex_constants::match_flag_type值 |

10. `regex`(和`wregex`)选项

| 操作                            | 备注                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| regex r(re)<br />regex r(re, f) | re表示一个正则表达式，它可以是一个string、一个表示字符范围的迭代器对、一个指向空字符结尾的字符数组的指针、一个字符指针和一个计数器或者一个花括号包围的字符列表；f是指出对象如何处理的标志；f通过下面列出的值来设置；如果未指定f，其默认值为ECMAScript |
| r1 = re                         | 将r1中的正则表达式替换为re；re表示一个正则表达式，它可以是另一个regex对象、一个string、一个指向空字符结尾的字符数组的指针或是一个花括号包围的字符列表 |
| r1.assign(re, f)                | 与使用赋值运算符(=)效果相同；可选的标志f也与regex的构造函数中对应的参数含义相同 |
| r.mark_count()                  | r中子表达式的数目                                            |
| r.flags()                       | 返回r的标志集                                                |
|                                 | 注：构造函数和赋值操作可能抛出类型为regex_error的异常        |
|                                 | 定义regex时指定的标志(定义在regex和regex_constants::syntax_option_type)中 |
| icase                           | 在匹配过程中忽略大小写                                       |
| nosubs                          | 不保存匹配的子表达式                                         |
| optimize                        | 执行速度优先于构造速度                                       |
| ECMAScript                      | 使用ECMA-262指定的语法                                       |
| basic                           | 使用POSIX基本的正则表达式语法                                |
| extended                        | 使用POSIX扩展的正则表达式语法                                |
| awk                             | 使用POSIX版本的awk语言的语法                                 |
| grep                            | 使用POSIX版本的grep的语法                                    |
| egrep                           | 使用POSIX版本的egrep的语法                                   |

11. 一个正则表达式的语法是否正确是在运行时解析的
12. 正则表达式错误类型

| 类型             | 备注                                         |
| ---------------- | -------------------------------------------- |
|                  | 定义在regex和regex_constants::error_type中   |
| error_collate    | 无效的元素校对请求                           |
| error_ctype      | 无效的字符类                                 |
| error_escape     | 无效的转义字符或无效的尾置转义               |
| error_backref    | 无效的向后引用                               |
| error_brack      | 不匹配的方括号([或])                         |
| error_paren      | 不匹配的小括号((或))                         |
| error_brace      | 不匹配的花括号({或})                         |
| error_badbrace   | {}中无效的范围                               |
| error_range      | 无效的字符范围(如[z-a])                      |
| error_space      | 内存不足，无法处理此正则表达式               |
| error_badrepeat  | 重复字符(*、?、+或{)之前没有有效的正则表达式 |
| error_complexity | 要求的匹配过于复杂                           |
| error_stack      | 栈空间不足，无法处理匹配                     |

13. 正则表达式库类

| 如果输入序列类型 | 则使用正则表达式类                             |
| ---------------- | ---------------------------------------------- |
| string           | regex、smatch、ssub_match和sregex_iterator     |
| const char*      | regex、cmatch、csub_match和cregex_iterator     |
| wstring          | wregex、wsmatch、wssub_match和wsregex_iterator |
| const wchar_t*   | wregex、wcmatch、wcsub_match和wcregex_iterator |

14. `sregex_iterator`操作

| 操作                        | 备注                                                         |
| --------------------------- | ------------------------------------------------------------ |
|                             | 这些操作也适用于cregex_iterator、wsregex_iterator和wcregex_iterator |
| sregex_iterator it(b, e, r) | 一个sregex_iterator，遍历迭代器b和e表示的string；它调用sregex_search(b, e, r)将it定位到输入中第一个匹配的位置 |
| sregex_iterator end;        | sregex_iterator的尾后迭代器                                  |
| *it<br />it->               | 根据最后一个调用regex_search的结果，返回一个smatch对象的引用或一个指向smatch对象的指针 |
| ++it<br />it++              | 从输入序列当前匹配位置开始调用regex_search；前置版本返回递增后迭代器；后置版本返回旧值 |
| it1 == it2<br />it1 != it2  | 如果两个sregex_iterator都是尾后迭代器，则它们相等两个非尾后迭代器是从相同的输入序列和regex对象构造，则它们相等 |

15. `smatch`操作

| 操作                                       | 备注                                                         |
| ------------------------------------------ | ------------------------------------------------------------ |
|                                            | 这些操作也适用于cmath、wsmatch、wcmatch和对应的csub_match、wssub_match和wcsub_match |
| m.ready()                                  | 如果已经通过调用regex_search或regex_match设置了m，则返回ture；否则返回false；如果ready返回false，则对m进行操作是未定义的 |
| m.size()                                   | 如果匹配失败，则返回0；否则返回最近一次匹配的正则表达式中子表达式的数目 |
| m.empty()                                  | 若m.size()为0，则返回true                                    |
| m.prefix()                                 | 一个ssub_match对象，表示当前匹配之前的序列                   |
| m.suffix()                                 | 一个ssub_match对象，表示当前匹配之后的部分                   |
| m.format(...)                              | 见17表                                                       |
|                                            | 在接受一个索引的操作中，n的默认值为0且必须小于m.size()<br />第一个子匹配(索引为0)表示整个匹配 |
| m.length(n)                                | 第n个匹配的子表达式的大小                                    |
| m.position(n)                              | 第n个子表达式距序列开始的距离                                |
| m.str(n)                                   | 第n个子表达式匹配的string                                    |
| m[n]                                       | 对应第n个子表达式的ssub_match对象                            |
| m.begin(),m.end()<br />m.cbegin(),m.cend() | 表示m中sub_match元素范围的迭代器；与往常一样，cbegin和cend返回const_iterator |

16. 子匹配操作

| 操作              | 备注                                                         |
| ----------------- | ------------------------------------------------------------ |
|                   | 注意：这些操作适用于ssub_match、csub_match、wssub_match、wcsub_match |
| matched           | 一个public bool数据成员，指出此ssub_match是否匹配了          |
| first<br />second | public数据成员，指向匹配序列首元素和尾后位置的迭代器；如果未匹配，则first和second是相等的 |
| length()          | 匹配的大小；如果matched为false，则返回0                      |
| str()             | 返回一个包含输入中匹配部分的string；如果matched为false，则返回空string |
| s = ssub          | 将ssub_match对象ssub转化为string对象s；等于与s = ssub.str()；转换运算符不是explicit的 |

17. `regex_replace`正则表达式替换操作

| 操作                                                         | 备注                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| m.format(dest, fmt, mft)<br />m.format(fmt, mft)             | 使用格式化字符串fmt生成格式化输出，匹配在m中，可选的math_flag_type标志在mft中；第一个版本写入迭代器dest指向的目的位置并接受fmt参数，可以是一个string，也可以是表示字符数组中范围的一对指针；第二个版本返回一个string，保存输出，并接受fmt参数，可以是一个string，也可以是一个指向空字符结尾的字符数组的指针；mft的默认值为format_default |
| regex_replace(dest, seq, r, fmt, mft)<br />regex_replace(seq, r, fmt, mft) | 遍历seq，用regex_search查找与regex对象r匹配的子串；使用格式字符串fmt和可选的match_flag_type标志来生成输出；第一个版本将输出写到迭代器dest指定的位置，并接受一对迭代器seq表示返回；第二个版本返回一个string，保存输出，且seq既可以是一个string也可以是一个指向空字符结尾的字符数组的指针；在所有情况下，fmt既可以是一个string也可以是一个指向空字符结尾的字符数组的指针，且mft的默认值为match_default |

18. 匹配标志

| 标志              | 备注                                       |
| ----------------- | ------------------------------------------ |
|                   | 定义在regex_constants::match_flag_type中   |
| match_default     | 等价于format_default                       |
| match_not_bol     | 不将首字符作为行首处理                     |
| match_not_eol     | 不将尾字符作为行尾处理                     |
| match_not_bow     | 不将首字符作为单词首处理                   |
| match_not_eow     | 不将尾字符作为单词尾处理                   |
| match_any         | 如果存在多于一个匹配，则可返回任意一个匹配 |
| match_not_null    | 不匹配任何空序列                           |
| match_continuous  | 匹配必须从输入的首字符开始                 |
| match_prev_avail  | 输入序列包含第一个匹配之前的内容           |
| format_default    | 用ECMAScript规则替换字符串                 |
| format_sed        | 用POSIX sed规则替换字符串                  |
| format_no_copy    | 不输出输入序列中未匹配的部分               |
| format_first_only | 只替换子表达式的第一个出现                 |

19. 随机数库的组成

| 库   | 备注                                       |
| ---- | ------------------------------------------ |
| 引擎 | 类型，生成随机unsigned 整数序列            |
| 分布 | 类型，使用引擎返回服从特定概率分布的随机数 |

20. C++程序不应该使用库函数`rand`，而应使用`default_random_engine`类和恰当的分布类对象
21. 随机数引擎操作

| 操作                 | 备注                                       |
| -------------------- | ------------------------------------------ |
| Engine e;            | 默认构造函数；使用该引擎类型默认的种子     |
| Engine e(s);         | 使用整型值s作为种子                        |
| e.seed(s)            | 使用种子s重置引擎的状态                    |
| e.min()<br />e.max() | 此引擎可生成的最小值和最大值               |
| Engine::result_type  | 此引擎生成的unsigned整型类型               |
| e.discard(u)         | 将引擎推进u步；u的类型为unsigned long long |

22. 当我们说**随机数发生器**时，是指分布对象和引擎对象的组合
23. 一个给定的随机数发生器一直会生成相同的随机数序列；一个函数如果定义了局部的随机数发生器，应该将其(包括引擎和分布对象)定义为`static`的；否则，每次调用函数都会生成相同的序列
24. 设置随机数发生器种子；如果程序作为一个自动过程的一部分反复运行，将`time`的返回值作为种子的方式就无效了；它可能多次使用的都是相同的种子
25. 分布类型操作

| 操作                 | 备注                                                         |
| -------------------- | ------------------------------------------------------------ |
| Dist d;              | 默认构造函数；使d准备好被使用；其他构造函数依赖于Dist的类型；分布类型的构造函数是explicit |
| d(e)                 | 用相同的e连续调用d的话，会根据d的分布式类型生成一个随机数序列；e是一个随机数引擎对象 |
| d.min()<br />d.max() | 返回d(e)能生成的最小值和最大值                               |
| d.reset()            | 重建d的状态，使得随后对d的使用不依赖于d已经生成的值          |

26. 由于引擎返回相同的随机数序列，所以我们必须在循环外声明引擎对象；否则，每步循环都会创建一个新引擎，从而每步循环都会生成相同的值；类似的，分布对象也要保持状态，因此也应该在循环外定义

27. 当操作符改变流的格式状态时，通常改变后的状态对所有后续IO都生效；`boolalpha`操作符，默认情况下，bool值打印为1或0；使用`boolalpha`后，打印`true`或`false`
28. 操作符`hex`、`oct`和`dec`只影响整型运算对象，浮点值的表示形式不受影响
29. 使用`showbase`操作符打印八进制值或十六进制值，使用`noshowbase`取消
30. 使用`uppercase`操作符输出大写的X并将十六进制数字a-f以大写输出，使用`nouppercase`来重置
31. 使用IO对象的`precision`成员或使用`setprecision`操作符来改变精度，在头文件`<iomanip>`中
32. `iostream`操作符

| 操作符       | 备注                                      |
| ------------ | ----------------------------------------- |
| boolalpha    | 将true和false输出为字符串                 |
| *noboolalpha | 将true和false输出为1，0                   |
| showbase     | 对整型值输出表示进制的前缀                |
| *noshowbase  | 不生成表示进制的前缀                      |
| showpoint    | 对浮点值总是显示小数点                    |
| *noshowpoint | 只有当浮点值包含小数部分时才显示小数点    |
| showpos      | 对非负数显示+                             |
| *noshowpos   | 对非负数不显示+                           |
| uppercase    | 在十六进制值中打印0X，在科学计数法中打印E |
| *nouppercase | 在十六进制值中打印0x，在科学计数法中打印e |
| *dec         | 整型值显示为十进制                        |
| hex          | 整型值显示为十六进制                      |
| oct          | 整型值显示为八进制                        |
| left         | 在值的右侧添加填充字符                    |
| right        | 在值的左侧添加填充字符                    |
| internal     | 在符号和值之间添加填充字符                |
| fixed        | 浮点值显示为定点十进制                    |
| scientific   | 浮点值显示为科学记数法                    |
| hexfloat     | 浮点值显示为十六进制(c++11新特性)         |
| defaultfloat | 重置浮点数格式为十进制(c++11新特性)       |
| unitbuf      | 每次输出操作后都刷新缓冲区                |
| *nounitbuf   | 恢复正常的缓冲区刷新方式                  |
| *skipws      | 输入运算符跳过空白符                      |
| noskipws     | 输入运算符不跳过空白符                    |
| flush        | 刷新ostream缓冲区                         |
| ends         | 插入空字符，然后刷新ostream缓冲区         |
| endl         | 插入换行，然后刷新ostream缓冲区           |
|              | *表示默认流状态                           |

33. 除非需要控制浮点数的表示形式，否则由标准库选择记数法是最好的方式

34. `setw`类似`endl`，不改变输出流的内部状态；它只决定下一个输出的大小
35. `iomanip`操作符

| 操作            | 备注                    |
| --------------- | ----------------------- |
| setfill(ch)     | 用ch填充空白            |
| setprecision(n) | 将浮点精度设置为n       |
| setw(w)         | 读或写值的宽度为w个字符 |
| setbase(b)      | 将整数输出为b进制       |

36. 单字节低层IO操作

| 操作           | 备注                                           |
| -------------- | ---------------------------------------------- |
| is.get(ch)     | 从istream is读取下一个字节存入字符ch中，返回is |
| os.put(ch)     | 将字符ch输出到ostream os，返回os               |
| is.get()       | 将is的下一个字节作为int返回                    |
| is.putback(ch) | 将字符ch放回is，返回is                         |
| is.unget()     | 将is向后移动一个字节，返回is                   |
| is.peek()      | 将下一个字节作为int返回，但不从流中删除它      |

37. 多字节低层IO操作

| 操作                          | 备注                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| is.get(sink, size, delim)     | 从is中读取最多size个字节，并保存在字符数组中，字符数组的起始地址由sink给出；读取过程直到遇到字符delim或读取了size个字符或遇到文件尾时停止；如果遇到了delim，则将其留在输入流中，不读取出来存入sink |
| is.getline(sink, size, delim) | 与接受三个参数的get版本类型，但会读取并丢弃delim             |
| is.read(sink, size)           | 读取最多size个字节，存入字符数组sink中；返回is               |
| is.gcount()                   | 返回上一个未格式化读取操作从is读取的字节数                   |
| os.write(source, size)        | 将字符数组source中的size个字节写入os，返回os                 |
| is.ignore(size, delim)        | 读取并忽略最多size个字符，包括delim;与其他未格式化函数不同，ignore有默认参数；size的默认值为1，delim的默认值为文件尾 |

38. 流随机访问，只适用于`fstream`和`sstream`

| 函数                                   | 备注                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| tellg()<br />tellp()                   | 返回一个输入流中(tellg)或输出流中(tellp)标记的当前位置       |
| seekg(pos)<br />seekp(pos)             | 在一个输入流或输出流中将标记重定位到给定的绝对地址；pos通常是前一个tellg或tellp返回的值 |
| seekp(off, from)<br />seekg(off, from) | 在一个输入流或输出流中将标记定位到from之前或之后off个字符，from可以是下列值之一 beg：偏移量相对于流开始位置 cur：偏移量相对于流当前位置 end：偏移量相对于流结尾位置 |

39. 由于只有单一的标记，因此在读写操作间切换时，必须进行`seek`操作来重定位标记