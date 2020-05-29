# Chapter1

1. `iostream`库包含两个基础类型`istream`和`ostream`
2. `istream`定义了标准输入`cin`
3. `ostream`定义了标准输出`cout`、输出警告和错误信息`cerr`以及输出程序运行时的一般性信息`clog`
4. `while(std::cin >> value)`此循环条件实际上检测的是`std::cin`，使用一个`istream`对象作为条件时，其效果是检测流的状态。当遇到文件结束符，或遇到一个无效输入，`istream`对象状态变为无效，处于无效状态的`istream`对象会使条件变为假
5. 读`cin`会刷新`cout`，程序非正常终止时也会刷新`cout`
6. 默认情况下，写到`cerr`的数据是不缓冲的，`cerr`通常用于输出错误信息或其他不属于程序逻辑的输出内容
7. 默认情况下，写到`clog`的数据是被缓冲的，`clog`通常用于报告程序的执行信息，存入一个日志文件中

