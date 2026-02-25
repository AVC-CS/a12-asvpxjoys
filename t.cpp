#include <iostream>
using namespace std;
int globalInt = 100;

int printAddress(int* addr)
{
    int localInt = 20;
    cout << "Value of var addr: " << addr << endl;
    cout << "Address of var addr: " << &addr << endl;
    *addr = 30;
    cout << "Address of localInt: " << &localInt << endl;
    return 0;
}

int main()
{
    int num = 10;
    static int staticInt = 50;
    cout  << "Address of num: " << &num << endl;
    cout << "Address of globalInt: " << &globalInt << endl;
    cout << "Address of staticInt: " << &staticInt << endl;
    printAddress(&num);

    cout << "==========="  << endl;
    cout << "Address of main(): " << (void*)&main << endl;
    cout << "Address of printAddress(): " << (void*)&printAddress << endl;
    cout << "===========" << endl;
    char* heapVar1 = (char*)malloc(1024);
    char* heapVar2 = (char*)new int;
    cout << "Address of heapVar1: " << (void*)&heapVar1 << endl;
    cout << "Address of heapVar2: " << (void*)&heapVar2 << endl;
}