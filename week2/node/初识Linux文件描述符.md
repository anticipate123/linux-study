# Linux文件描述符

------

## 知识储备

1.进程执行open系统调用，必须让文件和进程关联起来。每个进程的PCB中都有一个指向一张表的指针。这个表里面最重要的就是包含一个指针数组，数组里的每一个指针都指向一个打开文件，而==文件描述符（fd)==就是指针数组的下标。我们只要找到文件描述符，就可以找到对应的文件。

------

## open,close,read,write,lseek系统调用接口

1.open
open函数可以打开或创建一个文件，成功返回fd，否则返回-1；

```
int open(const char *pathname, int flags);
int open(const char *pathname, int flag, mode_t mode);
```

2.close:可以关闭一个打开的文件,成功返回0，失败返回1。

```
int close(int fd)
```

3.read 从打开文件中读取数据，读取成功则返回读到的字节数，如已到文件尾，则返回0。\*buf是一个指向要读取文件的文件指针。count是要求读取的字节数，返回值类型ssize_t。出错则返回-1。

```
ssize_t read(int fd,void*buf, size_t count);
```

4.write 向打开文件写入数据，若成功则返回写入的字节数，否则返回-1

```
ssize_t write (int fd,const void \*buf,size_f count);
```

------

### 参数说明

1.path参数是文件的名字
2.flag是多个常量*与或*构成的参数。几个常用的常量

> O\_RDONLY :只读打开（大多定义为0）
> O\_WRONLY：只写打开（大多定义为1）
> O\_RDWR：读写打开（定义为2）
> O\_EXEC：只执行打开
> O\_CREAT：文件不存在则创建它，使用时open函数需要说明==mode==参数，指定访问权限位。
> O\_EXCL：用来判断文件是否存在，与创建互为==原子操作==,就是说如果指定了 O\_CREAT





