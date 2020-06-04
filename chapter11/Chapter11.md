# Chapter11

1. 关联容器类型

| 类型                 | 备注                              |
| -------------------- | --------------------------------- |
| 按关键字有序保存元素 |                                   |
| map                  | 关联数组；保存关键字-值对         |
| set                  | 关键字即值，即只保存关键字的容器  |
| multimap             | 关键字可重复出现的map             |
| multiset             | 关键字可重复出现的set             |
| 无序集合             |                                   |
| unordered_map        | 用哈希函数组织的map               |
| unordered_set        | 用哈希函数组织的set               |
| unordered_multimap   | 哈希组织的map：关键字可以重复使用 |
| unordered_multiset   | 哈希组织的set：关键字可以重复出现 |

2. `map`与`set`中的关键字必须是唯一的，即对于一个给定的关键字，只能有一个元素的关键字等于它。`multimap`和`multiset`没有此限制，它们都允许多个元素具有相同的关键字

```c++
map<string, size_t> word_count;
string word;
while(cin >> word){
    ++word_count[word];
}
for(auto &w : word_count){
    cout << w.first << " occurs " << w.second <<　((w.second > 1)? " times" : " time") <<endl;
}

map<string, size_t> word_count;
set<string> exclude = {"The", "But", "And"};
string word;
while(cin >>　word){
    if(exclude.find(word) == exclude.end())
        ++word_count[word];
}
```



3. `map`、`multimap`、`set`以及`multiset`，关键字类型必须定义元素比较的方法。默认情况下，标准库使用关键字类型的`<`运算符来比较两个关键字
4. 使用关键字类型的比较函数

用来组织一个容器中元素的操作的类型。为了指定使用自定义的操作，必须在定义关联容器类型时提供此操作的类型。用尖括号指出要定义哪种类型的容器，自定义的操作类型必须在尖括号中紧跟着元素类型给出

```c++
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() <　rhs.isbn();
}
multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
```

5. `pair`定义在头文件`utility`

| 操作                      | 备注                                                         |
| ------------------------- | ------------------------------------------------------------ |
| pair<T1, T2> p;           | p是一个pair，两个类型分别为T1和T2的成员都进行了值初始化      |
| pair<T1, T2> p(v1, v2)    | p是一个成员类型为T1和T2的pair；first和second成员分别用v1和v2进行初始化 |
| pari<T1, T2>p = {v1, v2}; | 等价于p(v1, v2)                                              |
| make_pair(v1, v2)         | 返回一个用v1和v2初始化的pair。pair的类型从v1和v2的类型推断出来 |
| p.first                   | 返回p的名为first的(公有)数据成员                             |
| p.second                  | 返回p的名为second的(公有)数据成员                            |
| p1 relop p2               | 关系运算符(<、>、<=、>=)按字典序定义                         |
| p1 == p2<br />p1 != p2    | 当first和second成员分别相等时，两个pair相等。相等性判断利用元素的==运算符实现 |

6. 关联容器额外的类型别名

| 类型别名    | 备注                                                         |
| ----------- | ------------------------------------------------------------ |
| key_type    | 此容器类型的关键字类型                                       |
| mapped_type | 每个关键字关联的类型：只适用于map                            |
| value_type  | 对于set，与key_value相同<br />对于map，为pair<const key_type, mapped_type> |

7. 当解引用一个关联容器迭代器时，得到一个类型为容器的`value_type`的值的引用。对`map`而言，`value_type`是一个`pair`类型，其`first`成员保存`const`的关键字，`second`成员保存值
8. `set`类型同时定义了`iterator`和`const_iterator`类型，但都只允许只读方位`set`中的元素
9. 当使用一个迭代器遍历一个`map`、`multimap`、`set`或·`multiset`时，迭代器按关键字升序遍历元素
10. `insert`添加元素

| 操作                                   | 备注                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| c.insert(v)<br />c.emplace(args)       | v是value_type类型的对象；args用来构造一个元素，对于map和set，只有当元素的关键字不在c中时才插入(或构造)元素。函数返回一个pair，包含一个迭代器，指向具有指定关键字的元素，以及一个指示插入是否成功的bool值；对于multimap和multiset，总会插入(或构造)给定元素，并返回一个指向新元素的迭代器 |
| c.insert(b, e)<br />c.insert(il)       | b和e是迭代器，表示一个c::value_type类型值的返回；il是这种值的花括号列表，函数返回void；对于map和set，只插入关键字不在c中的元素。对于multimap和multiset，则会插入范围中的每个元素 |
| c.insert(p, v)<br />c.emplace(p, args) | 类型insert(v)(或emplace(args))，但将迭代器p作为一个提示，指出从哪里开始搜索新元素应该存储的位置。返回一个迭代器，指向具有给定关键字的元素 |

11. `insert`返回值依赖于容器类型和参数。对于不包含重复关键字的容器，添加单一元素的`insert`和`emplace`版本返回一个`pair`,`pair`的`first`成员是一个迭代器，指向具有给定关键字的元素；`second`成员是一个bool值，指出元素是插入成功啊还是已经存在于容器中。`false`表示不插入，`true`表示插入成功

12. `multiset`和`multimap`添加元素，`insert`操作返回一个指向新元素的迭代器，无须返回一个bool值，因为`insert`总是向这类容器中加入一个新元素

13. 删除元素

| 操作          | 备注                                                         |
| ------------- | ------------------------------------------------------------ |
| c.erase(k)    | 从c中删除每个关键字为k的元素。返回一个size_type值，指出删除的元素的数量 |
| c.erase(p)    | 从c中删除迭代器p指定的元素。p必须指向c中一个真实元素，不能等于c.end()。返回一个指向p之后元素的迭代器，若p指向c中的尾元素，则返回c.end() |
| c.erase(b, e) | 删除迭代器对b和e所表示的范围中的元素。返回e                  |

使用`key_type`来进行删除操作，返回实际删除的元素数量

对于保存不重复关键字的容器，`erase`的返回值总是0或1；对允许重复关键字的容器，删除元素的数量可能大于1

14. `map`和`unordered_map`下标操作

| 操作    | 备注                                                         |
| ------- | ------------------------------------------------------------ |
| c[k]    | 返回关键字为k的元素；如果k不在c中，添加一个关键字为k的元素，对其进行值初始化 |
| c.at(k) | 访问关键字为k的元素，带参数检查；若k不在c中，抛出一个out_of_range异常 |

对一个`map`使用下标操作，其行为与数组或`vector`上的下标操作很不相同；使用一个不在容器中的关键字作为下标，会添加一个具有此关键字的元素到`map`中

15. `map`使用下标操作的返回值是`mapped_type`对象
16. 访问元素

| 操作             | 备注                                                         |
| ---------------- | ------------------------------------------------------------ |
|                  | lower_bound和upper_bound不适用于无序容器<br />下标和at操作是适用于非const的map和unordered_map |
| c.find(k)        | 返回一个迭代器，指向第一个关键字为k的元素，若k不在容器中，则返回尾后迭代器 |
| c.count(k)       | 返回关键字等于k的元素的数量。对于不允许重复关键字的容器，返回值永远是0或1 |
| c.lower_bound(k) | 返回一个迭代器，指向第一个关键字不小于k的元素                |
| c.upper_bound(k) | 返回一个迭代器，指向第一个关键字大于k的元素                  |
| c.equal_range(k) | 返回一个迭代器pair，表示关键字等于k的元素的范围。若k不存在，pair的两个成员均等于c.end() |

17. `multimap`或`multiset`查找元素，需要同时使用`count`(获取个数)和`find`(是否存在)来遍历查找到的所有对象

18. 如果关键字类型固有就是无序的，或者性能测试发现问题可以用哈希技术解决，就可以使用无序容器
19. 无序容器管理操作

| 操作                   | 备注                                                         |
| ---------------------- | ------------------------------------------------------------ |
| 桶接口                 |                                                              |
| c.bucket_count()       | 正在使用的桶的数目                                           |
| c.max_bucket_count()   | 容器能容纳的最多的桶的数目                                   |
| c.bucket_size(n)       | 第n个桶中有多少个元素                                        |
| c.bucket(k)            | 关键字为k的元素在哪个桶中                                    |
| 桶迭代                 |                                                              |
| local_iterator         | 可以用来访问桶中元素的迭代器类型                             |
| const_local_iterator   | 桶迭代器的const版本                                          |
| c.begin(n)，c.end(n)   | 桶n的首元素迭代器和尾后迭代器                                |
| c.cbegin(n)，c.cend(n) | 返回const_local_iterator                                     |
| 哈希策略               |                                                              |
| c.load_factor()        | 每个桶的平均元素数量，返回float值                            |
| c.max_load_factor()    | c试图维护的平均桶大小，返回float值。c会在需要时添加新的桶，以使得load_factor<=max_load_factor |
| c.rehash(n)            | 重组存储，使得bucket_count>=n且bucket_count>size/max_load_factor |
| c.reserve(n)           | 重组存储，使得c可以保存n个元素且不必rehash                   |