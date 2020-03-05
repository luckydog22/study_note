#ifndef MYPRINT_H
#define MYPRINT_H

#define HEIGHT 3
#define WIDTH 4

class MyPrint
{
private:
    int arr[HEIGHT][WIDTH];
public:
    MyPrint();
    void print();
    void print(char space);
};

#endif // MYPRINT_H
