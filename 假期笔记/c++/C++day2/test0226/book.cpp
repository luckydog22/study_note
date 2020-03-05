#include "book.h"
#include <string.h>
#include <iostream>

using namespace std;

Book::Book(const char *name, const char *author)
{
    this->name = new char[strlen(name)+1];
    this->author = new char[strlen(author)+1];
    strcpy(this->name, name);
    strcpy(this->author, author);
}

Book::~Book()
{
    delete[] name;
    delete[] author;
}

void Book::show()
{
    cout<<name<<" "<<author<<endl;
}

