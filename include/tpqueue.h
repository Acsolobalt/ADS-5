// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
struct ITEM {
T data;
ITEM * next;
};
private:
TPQueue::ITEM * create(T data) {
ITEM * item = new ITEM;
item->data = data;
item->next = nullptr;
return item;
};
ITEM * head;
ITEM * tail;
public:
TPQueue() : head(nullptr), tail(nullptr) {}
~TPQueue() {
while (head)
pop();
}
void push(const T & data) {
if (tail && head) {
ITEM * item = create(data);
ITEM * temp = head;
while (temp) {
if (temp->next == nullptr) {
tail->next = item;
tail = tail->next;
} else {
if (item->data.prior > temp->next->data.prior) {
item->next = temp->next;
temp->next = item;
break;
}
}
}
} else {
head = create(data);
tail = head;
}
}
	
T pop() {
assert(head);
ITEM* tmp = head->next;
T data = head->data;
delete head;
head = tmp;
return data;
}
};

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
