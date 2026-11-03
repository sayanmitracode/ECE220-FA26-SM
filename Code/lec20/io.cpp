// Input and output with cin and cout
#include <iostream>
using namespace std;

int main() {
    char name[20];
    cout << "Enter your name: ";
    cin >> name;        // like scanf("%s")
    cout << "Your name is: " << name << endl;
    return 0;
}
