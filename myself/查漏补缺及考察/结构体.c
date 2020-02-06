1.结构体可以类比数组

int a[]={......};
int *p=&a;
int *p={.....} (//错误，定义整型指针，只放地址，不放数据

struct worker w1={.....};
struct worker *p=&w1;
struct worker *p={.....};//错误，同上

2.结构体一旦涉及到指针 必须用->
w->age=18;
