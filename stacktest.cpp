#include "stack.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    Stack<int> test;
    for(int i=0;i<10;i++)
    {
        test.push(i);
    }
    for(int i=0;i<10;i++)
    {
        cout<<test.top()<<endl;
        test.pop();
    }

}