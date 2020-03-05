#ifndef BOOK_H
#define BOOK_H


class Book
{
private:
    char* name;
    char* author;
public:
    Book(const char* name, const char* author);
    ~Book();
    void show();
};

#endif // BOOK_H
