#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Complex {
public:
    float real, imaginary;
    Complex(float r = 0, float i = 0) : real(r), imaginary(i) {}
    bool operator==(const Complex& other) const {
        return real == other.real && imaginary == other.imaginary;
    }
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << " + " << c.imaginary << "i";
        return os;
    }
};

class MyString {
public:
    char* str;

    MyString(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    ~MyString() {
        delete[] str;
    }

    bool operator==(const MyString& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator<(const MyString& other) const {
        return strcmp(str, other.str) < 0;
    }

    friend ostream& operator<<(ostream& os, const MyString& s) {
        os << s.str;
        return os;
    }
};

template <typename T>
class List {
    T* items;
    int count;
    int size;
public:
    List(int s = 10) : count(0), size(s) {
        items = new T[size];
    }

    List(const List& other) : count(other.count), size(other.size) {
        items = new T[size];
        for (int i = 0; i < count; i++)
            items[i] = other.items[i];
    }

    ~List() {
        delete[] items;
    }

    void add(const T& item) {
        if (count < size)
            items[count++] = item;
    }

    bool find(const T& item) const {
        for (int i = 0; i < count; i++)
            if (items[i] == item)
                return true;
        return false;
    }

    void sort() {
        std::sort(items, items + count);
    }

    int getCount() const { return count; }
    T& operator[](int index) const { return items[index]; }

    List& operator=(const List& other) {
        if (this != &other) {
            delete[] items;
            size = other.size;
            count = other.count;
            items = new T[size];
            for (int i = 0; i < count; ++i)
                items[i] = other.items[i];
        }
        return *this;
    }
};

template <typename T>
ostream& operator<<(ostream& os, const List<T>& list) {
    for (int i = 0; i < list.getCount(); i++)
        os << list[i] << endl;
    return os;
}

int main() {
    List<Complex> cList(100);
    cList.add(Complex(0, 0));
    cList.add(Complex(1, 1));
    cout << cList << endl;

    cout << std::boolalpha;
    cout << cList.find(Complex(1, 1)) << endl;
    cout << cList.find(Complex(1, 0)) << endl;

    List<MyString> sList(200);
    sList.add("Banana");
    sList.add("Apple");
    cout << sList << endl;
    cout << sList.find("Banana") << endl;
    cout << sList.find("Melon") << endl;

    List<MyString> s2List{sList};
    s2List.add("Strawberry");
    cout << s2List << endl;

    List<MyString> s3List(10);
    s3List = s2List;
    s3List.add("Grape");
    cout << s3List << endl;

    s3List.sort();
    cout << s3List << endl;
    
    return 0;
}
