// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
  struct SYM arr[size];
  int i = 0;
 public:
  void push() {
    if (i < size) {
      for (int j = i; j > -1; j--) {
        if (j && (item.prior <= arr[j - 1].prior)) {
          arr[j] = arr[j - 1];
        } else {
          arr[j] = item;
          break;
        }
      }
      ++i;
    }
  }
  SYM pop() {
    if (i > 0)
      return arr[--i];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
