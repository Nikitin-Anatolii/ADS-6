// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
 private:
  struct SYM arr[size];
  int i = 0;
 public:
  void push(SYM item) {
    if (i < size) {
      ++i;
      for (int j = i - 1; j >= 0; j--) {
        if (j && (item.prior <= arr[j - 1].prior)) {
          arr[j] = arr[j - 1];
        } else {
          arr[j] = item;
          break;
        }
      }
    }
  }
  SYM pop() {
    if (i > 0)
      return arr[--i];
    else
      std::cout << "!" << std::endl;
  }
};

#endif  // INCLUDE_TPQUEUE_H_
