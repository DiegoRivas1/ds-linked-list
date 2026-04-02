#include "StackComposicion.h"
#include <stdexcept>
void StackComposicion::push(int data) {
    this->list.insert(data, 0);
}

void StackComposicion::pop() {
    if (this->isEmpty()) {
        throw std::out_of_range("Stack vacio");
    }
    this->list.remove(0);
}

void StackComposicion::print() const {
    this->list.print();
}

int StackComposicion::size() const {
    return this->list.size();
}

bool StackComposicion::isEmpty() const {
    return this->list.isEmpty();
}

int StackComposicion::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack vacio");
    }
    return this->list.searchPos(0);
}

std::ostream& operator<<(std::ostream& os, const StackComposicion& stack) {
    os << stack.list;
    return os;
}
