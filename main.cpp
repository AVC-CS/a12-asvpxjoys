#include <iostream>
#include <cstdlib>  // for malloc
using namespace std;

// TODO: Declare 2 initialized global variables (DATA segment)
int globalVar1 = 100;
int globalVar2 = 200;
// TODO: Declare 2 uninitialized global variables (BSS segment)
int unGlobalVar1;
int unGlobalVar2;
// Stack check function: receives address from caller (parent frame)
// and compares with a local variable (child frame)
void checkStack(int* parentAddr) {
    int childVar = 0;
    cout << "--- STACK SEGMENT (Cross-function comparison) ---" << endl;
    // TODO: Print parentAddr value (points to main's local var - parent frame)
    cout << "Parent address: " << parentAddr << endl;
    // TODO: Print &parentAddr (parameter's own address - child frame)
    cout << "Parameter address: " << &parentAddr << endl;
    // TODO: Print &childVar (local var address - child frame)
    cout << "Child variable address: " << &childVar << endl;
    // TODO: Print "Stack grows: DOWN" or "UP" based on comparison
    //       Compare: parentAddr > &childVar ? "DOWN" : "UP"
    //       (parent frame address vs child frame address)
    cout << "Stack grows: " << (parentAddr > &childVar ? "DOWN" : "UP") << endl;
    cout << endl;
}

int main() {

    // TODO: Declare a local variable (STACK - will be passed to checkStack)
    int localVar = 80;

    // TODO: Allocate 2 heap variables using malloc (use larger sizes, e.g. 1024)
    //       Note: new may not allocate sequentially; malloc with larger sizes
    //       is more reliable for demonstrating heap growth direction
    char* heapVar1 = (char*)malloc(1024);
    char* heapVar2 = (char*)malloc(1024);
    cout << "=== MEMORY SEGMENT BOUNDARIES ===" << endl;
    cout << endl;

    // TODO: Print TEXT segment - 2 function addresses
    //       e.g., (void*)&main and (void*)&checkStack
    cout << "--- TEXT SEGMENT (Code) ---" << endl;
    // ...
     cout << "Address of main(): " << (void*)&main << endl;
     cout << "Address of fn2(): " << (void*)&checkStack << endl;
    // ...
    cout << endl;

    // TODO: Print DATA segment - 2 initialized global addresses + values
    cout << "--- DATA SEGMENT (Initialized Globals) ---" << endl;
    cout << "Address of globalVar1: " << &globalVar1 << " | Value: " << globalVar1 << endl;
    cout << "Address of globalVar2: " << &globalVar2 << " | Value: " << globalVar2 << endl;
    // ...
    cout << endl;

    // TODO: Print BSS segment - 2 uninitialized global addresses + values
    cout << "--- BSS SEGMENT (Uninitialized Globals) ---" << endl;
    cout << "Address of unGlobalVar1: " << &unGlobalVar1 << " | Value: " << unGlobalVar1 << endl;
    cout << "Address of unGlobalVar2: " << &unGlobalVar2 << " | Value: " << unGlobalVar2 << endl;
    // ...
    cout << endl;

    // STACK: call checkStack with address of your local variable
    // TODO: checkStack(&yourLocalVar);
    checkStack(&localVar);
    // TODO: Print HEAP segment - 2 heap addresses + comparison
    //       Print "Heap grows: UP" or "DOWN"
    cout << "--- HEAP SEGMENT (Dynamic Allocation) ---" << endl;
    cout << "Address of heapVar1: " << (void*)heapVar1 << endl;
    cout << "Address of heapVar2: " << (void*)heapVar2 << endl;
    if (heapVar1 < heapVar2) {
        cout << "Heap grows: UP" << endl;
    } else {
        cout << "Heap grows: DOWN" << endl;
    }
    // ...
    cout << endl;

    // TODO: Print relative position summary
    cout << "=== RELATIVE POSITION SUMMARY ===" << endl;
    cout << "TEXT(Code) : " << (void*)&main << endl;
    cout << "DATA(Init) : " << &globalVar1 << endl;
    cout << "BSS(Uninit) : " << &unGlobalVar1 << endl;
    cout << "STACK : " << &localVar << endl;
    cout << "HEAP : " << (void*)heapVar2 << endl;
    //cout << 
    // ...

    // TODO: Free all heap allocations
    free(heapVar1);
    free(heapVar2);

    return 0;
}

/*
 * EXPERIMENTAL RESULTS:
 * TODO: After running your program, explain what you observed:
 * - Which segment has the lowest addresses? Text code segment has the lowest addresses.
 * - Which has the highest? Heap segment has the highest addresses.
 * - Does stack grow down? How did you verify this? Stack grows down. This was verified by comparing the address of the parent variable in main (localVar) with the address of the child variable in checkStack (childVar) indicating that the stack grows downwards since the childVar address is lower than the parentVar address.
 * - Does heap grow up? How did you verify this? Heap grows up. This was verified by comparing the addresses of heapVar1 and heapVar2, where heapVar2 has a higher address than heapVar1, indicating that the heap grows upwards.
 * - What is the gap between HEAP and STACK? At first the gap is not so different, only 4 bits but the gap grows wider as more variables are added. The gap then increases, since the stack grows downwards from higher addresses and the heap grows upwards from lower addresses.
 */
