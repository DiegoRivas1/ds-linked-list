#include "StackComposicion.h"
#include <stdexcept>
void StackComposicion::insert(int data, int position) {
    this->list.insert(data, position);
}

void StackComposicion::remove(int position) {
    this->list.remove(position);
}

bool StackComposicion::search(int data) const {
    return this->list.search(data);
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
