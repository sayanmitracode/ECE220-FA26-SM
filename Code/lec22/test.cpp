// Template function; easy instances
// Template instantiation on classes Rect
// Operator overloading with Rct, const all the way

// template class mypair
    // size of instances

// copy constructor and destructor
    // shallow copy // compiler supplied copy constructor
    // assignment operator
    // Rule of 3

// iterators


#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// 6
template <typename T> class List;
template <typename T>
class Node {
    T data;
    Node<T>* next;
    Node(T d) {data = d; next = NULL;}
    friend class List<T>;
};

template <typename T>
class List {
    Node<T>* head;
    public:
        List() {head = NULL;}
        void add(T data){
            Node<T> * ptr = new Node<T>(data);
            ptr->next = head;
            head = ptr;
        }
        void show(){
            Node<T> * current = head;
            while (current!=NULL){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;

        }
};


int main(){
    List<int> myintlist;
    List<char> mycharlist;
    List<float> myfloatlist;
    myintlist.add(3);
    myintlist.add(4);
    myintlist.add(5);
    myintlist.add(37);
    myintlist.add(9);
    myintlist.add(01);
    myintlist.add(56);

    mycharlist.add('A');
    mycharlist.add('B');
    mycharlist.add('G');

    myfloatlist.add(5.67);
    myfloatlist.add(7.89);
    myfloatlist.add(9.10);

    myintlist.show();
    mycharlist.show();
    myfloatlist.show();
    printall(mycharlist);
    
}

// // 5

// using namespace std;

// int main(){
//     vector<int> myvec = {1,2};

//     // for (int i=0; i< myvec.size(); i++)
//     for (vector<int>::iterator it == myvec.begin(); it != myvec.end(); it++)
//     {
//         cout << *it << " ";
// //        cout << myvec.at(i) << " " ;
//     }
//     cout << " size:" << myvec.size() << " capacity:" << myvec.capacity() << endl;
    
//     myvec.push_back(6);
//     myvec.push_back(9);
    
//     cout << " size:" << myvec.size() << " capacity:" << myvec.capacity() << endl;

//     myvec.push_back(6);
//     myvec.push_back(9);
    
//     cout << " size:" << myvec.size() << " capacity:" << myvec.capacity() << endl;

//     myvec.pop_back();
//     myvec.pop_back();
//     myvec.pop_back(); 
//     myvec.pop_back();

//     cout << " size:" << myvec.size() << " capacity:" << myvec.capacity() << endl;


//     return 0;
// }

// // 4 // // // // // 

// class Person{
//     char* name;
//     int id;
//     public:
//         Person(const char* givenname, int givenid);
//         Person(const Person &other); 
//         Person operator=(const Person &rhs);
//         ~Person(){delete[] name;}
//         char * getname(){return name;}
//         int getid(){return id;}
//         void show();
// };  

// Person::Person(const char* givenname, int givenid){
//     name = new char[48];
//     strcpy(name,givenname); 
//     id = givenid;
// }

// Person::Person(const Person &other){
//     name = new char[48];
//     strcpy(name,other.name); 
//     id = other.id;        
//     return;
// }

// Person Person::operator=(const Person &rhs){
//     id = rhs.id;
//     strcpy(name,rhs.name);
//     return *this;
// }

// void Person::show(){
//     std::cout << name << " " << id << std::endl;
//     return;
// }

// int main()
// {
//     Person a("Jimmy", 12345);
//     Person b = a;
//     Person c("Ravi", 5678);
//     c = a;
//     a.show();
//     b.show();
//     c.show();
//     return 0;
// }

// 3 //
// template <typename T>
// class mypair{
//     T a;
//     T b;
//     public:
//         mypair(T first, T second){a = first; b = second;}
//         T getmin(){return (a<b)? a:b;}
// };
// int main(){
//     mypair<int> p1(1,3);
//     mypair<double> p2(1.1,3.3);
//     std::cout << p1.getmin() << std::endl;
//     std::cout << p2.getmin() << std::endl;
//     std::cout << sizeof(p1) << std::endl;
//     std::cout << sizeof(p2) << std::endl;
    
    
//     return 0;
// }

// 2 // 
// class Rectangle{
//     float length_;
//     float height_;
//     public:
//         Rectangle(){length_ =0; height_=0;}
//         Rectangle(float a, float b){length_ =a; height_=b;}
//         float area() const {return length_*height_;}
//         bool operator<(const Rectangle &a) const { return length_ < a.length_;}
// };

// template <typename T>
// T getmin (T a, T b) 
// {
//     return (a<b)? a: b;
// }

// double getmin(double a, double b){
//     return (a<b)? a: b;
// }

// int main(){
//     Rectangle rec1(4,5), rec2(9,2);
    
//     std::cout << getmin<int>(1,2) << std::endl;
//     std::cout << getmin(2.1,1.2) << std::endl;
//     std::cout << getmin('b','x') << std::endl;
//     std::cout << getmin(2,1.2) << std::endl;
//     std::cout << getmin<double>(2,1.2) << std::endl;
//     std::cout << getmin(rec1, rec2).area() << std::endl;

//     return 0;
// }

// 1 // 
// int getmin(int a, int b){
//     return (a<b)? a: b;
// }

// double getmin(double a, double b){
//     return (a<b)? a: b;
// }

// int main(){
//     std::cout << getmin(1,2) << std::endl;
//     std::cout << getmin(2.1,1.2) << std::endl;
//     return 0;
// }