# Chapter5

1. 在`switch`内部如果在某处一个带有初值的变量位于作用域之外，在另一个该变量位于作用域之内，则从前一处跳转到后一处的行为是非法行为
2. 范围`for`语句

```c++
for (declaration: expression)
    statement
```

3. try语句块和异常处理

* `throw表达式`，异常检测部分使用`throw`表达式来表示它遇到了无法处理的问题
* `try语句块`，异常处理部分使用`try`语句块处理异常。`try`语句块以关键字`try`开始，并以一个或多个`catch子句`结束。`try`语句块中代码抛出的异常通常会被某个`catch`子句处理。因为`catch`子句“处理”异常
* 一套**异常类**，用于在`throw`表达式和相关的`catch`子句之间传递异常的具体信息

4. `runtime_error`是标准库异常类型一种，定义在`stdexcept`头文件中。
5. `throw`表达式

```c++
throw runtime_error("error");
```

6. `try`语句块

```c++
try{
    program-statements
}catch(exception-declaration){
    handler-statements
}catch(exception-declartion){
    handler-statements
}//...
```

7. 标准异常`exception`头文件定义了最通用的异常类`exception`。它只报告异常的发生，不提供任何额外信息。`stdexcept`头文件定义了几种常见的异常类。`new`头文件定义了`bad_alloc`异常类型，`type_info`头文件定义了`bad_cast`异常类型

```c++
stdexcept定义的异常类
exception			最常见的问题
runtime_error		只有在运行时才能检测出的问题
range_error			运行时错误：生成的结果超出了有意义的值域范围
overflow_error		运行时错误：计算上溢
underflow_error		运行时错误：计算下溢
logic_error			程序逻辑错误
domain_error		逻辑错误：参数对应的结果值不存在
invalid_argument	逻辑错误：无效参数
length_error		逻辑错误：试图创建一个超出该类型最大长度的对象
out_of_range		逻辑错误：使用一个超出有效范围的值
```

8. 只能以默认初始化的方式初始化`exception`、`bad_alloc`、`bad_cast`对象，不允许为这些对象提供初始值。其他异常类型的行为则恰好相反，应该使用`string`对象或者C风格字符串初始化这些类型的对象，但是不允许使用默认初始化的方式，当创建此类对象时，必须提供初始值，该初始值含有错误相关的信息。
9. 异常类型只定义了一个名为`what`的成员函数，该函数没有任何参数，返回值是一个指向C风格字符串的`const char*`。该字符串的目的是提供关于异常的一些文本信息

