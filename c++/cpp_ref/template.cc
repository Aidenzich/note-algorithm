// Function templates are special functions that can operate
// with generic types. This allows us to create a function template 
// whose functionality can be adapted to more than one type or class 
// without repeating the entire code for each type.
#include <iostream>
using namespace std;

template <class T>
T PRINT(T a){
    cout << a << "\n";
    return a;
}

int main(){
    string a = PRINT<string>("Hello");
    int b = PRINT<int>(99999);
    return 0;

}


