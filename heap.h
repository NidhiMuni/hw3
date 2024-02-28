#ifndef HEAP_H
#define HEAP_H
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

  //for testing only
  //void print();

private:
  /// Add whatever helper functions and data members you need below
  size_t size_;
  std::vector<T> heap_;
  PComparator comp_;
  int ary_;

  void trickle_up(size_t index);
  void trickle_down(size_t index);
  void swap(size_t index1, size_t index2);
};

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
  size_ = 0;
  comp_ = c;
  ary_ = m;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){
  heap_.clear();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  heap_.push_back(item);
  size_++;
  size_t addedIndex = size_ - 1;
  trickle_up(addedIndex);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return (size_ == 0);
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return size_;
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(empty()){
    throw std::underflow_error("empty");
  }
  return heap_[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("empty");
  } else if (size_ == 1){
    //if there is only one element in the heap, just pop it
    heap_.erase(heap_.end() - 1);
    size_ = size_ - 1;
  } else {
    //if there is more than one, pop then rearrange
    swap(0, size_ - 1);
    heap_.erase(heap_.end() - 1);
    size_ = size_ - 1;
    trickle_down(0);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickle_up(size_t index){
  if (index > 0){
    size_t parentIndex = (index - 1)/ary_;
    if (parentIndex >= 0){
      //if this element is better than its parent, swap then rearrange
      if (comp_(heap_[index], heap_[parentIndex])){ 
        swap(index, parentIndex);
        trickle_up(parentIndex);
      }
    }
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickle_down(size_t index){
  size_t lastIndex = size_ - 1;
  T bestChild = heap_[index];
  size_t bestChildIndex = index;

  //find the best child
  for (size_t q = 1; q <= (size_t)ary_; q++){
    size_t childIndex = (ary_*index) + q;
    if (childIndex <= lastIndex){
      if (comp_(heap_[childIndex], bestChild)){ //this child is better than best child
        bestChild = heap_[childIndex];
        bestChildIndex = childIndex;
      }
    }
  }

  //compare the parent with the best child
  if (comp_(heap_[bestChildIndex], heap_[index])){ //if the best child is better than it
  //swap then rearrange
    swap(index, bestChildIndex);
    trickle_down(bestChildIndex);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::swap(size_t index1, size_t index2){
  T temp = heap_[index1];
  heap_[index1] = heap_[index2];
  heap_[index2] = temp;
}

/*template <typename T, typename PComparator>
void Heap<T,PComparator>::print(){
  cout << "Heap results: ";
  for (size_t i = 0; i < size_; i++){
    cout << heap_[i] << " ";
  }
  cout << endl;
}*/



#endif

