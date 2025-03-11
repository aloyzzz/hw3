#include "stack.h"
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
Stack<T>::Stack():vector<T>()
{}

template <typename T>
Stack<T>::~Stack()
{}

template<typename T>
size_t Stack<T>::size() const
{
    return vector<T>::size();
}

template<typename T>
bool Stack<T>::empty() const
{
    return vector<T>::empty();
}

template<typename T>
void Stack<T>::push(const T &item)
{
    vector<T>::push_back(item);
}

template<typename T>
void Stack<T>::pop()
{
    if(Stack<T>::empty())
    {
        throw underflow_error("Stack is empty");
    }
    vector<T>::pop_back();
}

template<typename T>
T const& Stack<T>::top() const
{
    if(Stack<T>::empty())
    {
        throw underflow_error("Stack is empty");
    }
    return vector<T>::back();
}