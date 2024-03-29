#include <iostream>
#include <queue>
using namespace std;

class Person{
    friend ostream &operator<<(ostream &os, const Person &p);
    string name;
    int age;
public:
    Person(): name{"Unknown"}, age{0} {}
    Person(string name, int age): name(name), age(age) {}
    bool operator<(const Person &rhs) const{
        // return this->age < rhs.age;
        return this->name < rhs.name;
    }
    bool operator==(const Person &rhs) const{
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

ostream &operator<<(ostream &os, const Person &p){
    os << p.name <<":"<< p.age;
    return os;
}

template <typename T>
void display(priority_queue<T> pq){
    cout<<"[";
    while (!pq.empty())
    {
        T el = pq.top();
        pq.pop();
        cout<<el<<" ";    
    }
    cout<<"]"<<endl;
}

void test1(){
    cout<<"\nTest1==========================================="<<endl;

    priority_queue<int> pq;
    for(int i : {3,5,7,12,23,12,4,100,0,3,5,7}){
        pq.push(i);
    }

    cout<<"Size:"<<pq.size()<<endl;
    cout<<"Top:"<<pq.top()<<endl;

    display(pq);

    pq.pop();
    display(pq);
}

void test2(){
    cout<<"\nTest2====================================="<<endl;
    
    priority_queue<Person> pq;
    pq.push(Person{"A", 10});
    pq.push(Person{"B", 1});
    pq.push(Person{"C", 14});
    pq.push(Person{"D", 19});
    pq.push(Person{"E", 17});
    pq.push(Person{"F", 8});

    display(pq);
}


int main()
{
    // test1();
    test2();



    return 0;
}