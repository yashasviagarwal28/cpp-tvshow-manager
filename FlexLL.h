#ifndef FLEXLL_H
#define FLEXLL_H
#include <iostream>

// Compare function for int
inline int compare(const int& one, const int& two) {
    if (one < two) return -1;
    if (one > two) return 1;
    return 0;
}

template <typename T>
struct FlexLLNode{
  T data;
  FlexLLNode<T>* next;
  FlexLLNode<T>* prev;
  FlexLLNode(const T& value) : data(value), next(nullptr), prev(nullptr) {}

};

template <typename T>
class FlexLL{
 private:
  FlexLLNode<T>* head;
  FlexLLNode<T>* tail;
  mutable FlexLLNode<T>* iterate;
  unsigned int size;

  void copyFrom(const FlexLL<T>& other);
  
 public:
  FlexLL();
  ~FlexLL();
  FlexLL(const FlexLL<T>& other);
    FlexLL<T>& operator=(const FlexLL<T>& other);

  //bool functions-
  bool empty() const;
  bool flush();
  bool prepend(const T& value);
  bool append(const T& value);
  bool sort();
  bool thin();

  FlexLL &prepend(FlexLL &other, bool copy=true);

  bool rewind() const;
  bool finished() const;
  T proceed() const;
};

#include "FlexLL.cpp"


#endif
