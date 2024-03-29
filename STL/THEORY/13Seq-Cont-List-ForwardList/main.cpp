#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <string>
using namespace std;

class Person
{
    friend ostream &operator<<(ostream &os, const Person &p);
    string name;
    int age;

public:
    Person() : name{"Unknown"}, age{0} {}
    Person(string name, int age) : name(name), age(age) {}
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

ostream &operator<<(ostream &os, const Person &p)
{
    os << p.name << ":" << p.age;
    return os;
}

template <typename T>
void display(const list<T> &l)
{
    cout << "[";
    for (const auto &elem : l)
    {
        cout << elem << " ";
    }
    cout << "]" << endl;
}

void test1(){
    cout<<"\nTest1====================================="<<endl;
    
    list<int> l1{1,2,3,4,5};
    display(l1);

    list<string> l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);

    list<int> l3;
    l3 = {1,2,3,4,5,6,7,8,9,10};
    display(l3);

    list<int> l4(10,100);
    display(l4);
}

void test2(){
    cout<<"\nTest2 ============================================"<<endl;
    
    list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    cout<<"Size:"<<l.size()<<endl;

    cout<<"Front: "<<l.front()<<endl;
    cout<<"Back: "<<l.back()<<endl;

    l.clear();
    display(l);
    cout<<"Size:"<<l.size()<<endl;
}

void test3(){
    cout<<"\nTest3 ==========================="<<endl;

    list<int> l{1,2,3,4,5,6,7,8,9,10};
    display(l);

    l.resize(5);
    display(l);
    
    l.resize(10);
    display(l);

    list<Person> persons;

    persons.resize(5);          // uses the Person default constructor;
    display(persons);
}

void test4(){
    cout<<"\nTest4 ===================================="<<endl;

    list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    auto it = find(l.begin(), l.end(), 5);

    if (it != l.end())
    {
        l.insert(it,100);
    }
    display(l);

    list<int> l2{1000,2000,3000};
    l.insert(it, l2.begin(), l2.end());
    display(l);

    advance(it,-4);             //point to the 100; start from *it and goes back 4 elements
    cout<<*it<<endl;

    l.erase(it);
    display(l);
    
}

void test5(){
    cout<<"\nTest5===================================="<<endl;

    list<Person> nerds{
        {"Teodor", 17},
        {"Teo", 19},
        {"Ana", 25}
    };

    display(nerds);
    string name;
    int age{};
    
    cout<<"\nEnter the name of the next nerd:";
    getline(cin, name);
    
    cout<<"Enter their age: ";
    cin>>age;

    nerds.emplace_back(name,age);
    display(nerds);

    //Insert Fedor before Teodor
    auto it = find(nerds.begin(), nerds.end(), Person{"Teodor", 17});
    if (it != nerds.end())
    {
        nerds.emplace(it, "Fedor", 81);
    }
    display(nerds);
    
}

void test6(){
    cout<<"\nTest6 ======================================="<<endl;

    list<Person> nerds{
        {"Feodr", 81},
        {"Max", 16},
        {"Cerdak", 28}
    };

    display(nerds);
    nerds.sort();
    display(nerds);
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();

    return 0;
}