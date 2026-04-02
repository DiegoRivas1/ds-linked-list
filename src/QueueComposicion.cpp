#include "QueueComposicion.h"
#include <stdexcept>

void QueueComposicion::enqueue(int data) {
    this->list.insert(data, size());// O(1)
}

void QueueComposicion::dequeue() {
    if (this->isEmpty()) {
        throw std::out_of_range("Queue vacio");
    }
    this->list.remove(0);//O(1)
}

int QueueComposicion::front() const {
    if (this->isEmpty()) {
        throw std::out_of_range("Queue vacio");
    }
    return this->list.searchPos(0);
}

bool QueueComposicion::isEmpty() const {
    return this->list.isEmpty();
}

int QueueComposicion::size() const {
    return this->list.size();
}

void QueueComposicion::print() const {
    this->list.print();
}

std::string QueueComposicion::toDot() const {
    return this->list.toDot();
}

std::ostream &operator<<(std::ostream &os, const QueueComposicion &comp) {
    os << comp.list;
    return os;
}