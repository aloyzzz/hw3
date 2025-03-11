#ifndef HEAP_H
#define HEAP_H
#include <algorithm>
#include <cstddef>
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below


    void heapify(int loc);
    void trickleup(int loc);
    int getparent(int index) const { return (index - 1) / m; }
    std::vector<T> vec;  // The underlying vector storing heap elements
    int m;                // The m-ary value
    PComparator comparator; 
};

// Add implementation of member functions here

//CTOR
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
    this->m=m;
    comparator=c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
  
}


// Empty check
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
    return vec.empty();
}

// Size Check
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
    return vec.size();
}

//Push
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  vec.push_back(item);
  trickleup(vec.size()-1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("Top empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vec[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(this->empty()){
    throw std::underflow_error("Top empty");
  }
  std::swap(vec[0],vec.back());
  vec.pop_back();
  if(!(this->size()>1))
  {
    heapify(0);
  }
}

//Heapify
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int loc)
{
  while(true)
  {
    int priority = loc;
    for(int i=0; i<m;i++)
    {
      int child = m*loc+(i+1);
      if(child<this->size()&&comparator(vec[child],vec[priority])) priority=child;
    }
    if(priority!=loc)
    {
      std::swap(vec[loc],vec[priority]);
      loc=priority;
    }
  }
}

//trickle
template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleup(int loc)
{
  while(loc>0)
  {
    size_t parent = (loc-1)/m;
    if(comparator(vec[loc],vec[parent]))
    {
      std::swap(vec[loc],vec[parent]);
      loc=parent;
    }
    else break;
  }
}

#endif

