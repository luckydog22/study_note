1.总地址数 除以 一个所占的地址数=数组中元素个数
i < sizeof(a) / sizeof(a[0]);

2.char a[]="hello";
strlen(a)=5,sizeof(a)=6;