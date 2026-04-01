#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

LinkedList::LinkedList() : head(nullptr), length(0){

}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current !=nullptr) {
        Node* next = current->getNext();
        delete current;
        current = next;
    }
}

void LinkedList::insert(int data, int position) {
    if (position < 0 || position > length) {//posicion insercion final = length, posicion elemento final = length - 1
        throw std::out_of_range("Posicion invalida");
    }
    Node* newNode = new Node(data);

    //Insertamos al inicio
    if (position == 0) {
        newNode->setNext(head);
        head = newNode;
    }
    else {//Medio o al final
        //Insertar 4
        //Medio 0, 1, 2, 3 (position = 1, current -> 0, current -> next -> 1) = 0, 4, 1, 2, 3
        //Final 0, 1, 2, 3 (position = 4, current -> 3, current -> next -> nullptr) = 0, 1, 2, 3, 4
        Node* current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }
    length++;
}

void LinkedList::remove(int position) {
    if (position < 0 || position >= length) {//posicion eliminacion final = length - 1, posicion elemento final = length - 1
        throw std::out_of_range("Posicion invalida");
    }
    Node* toDelete;

    if (position == 0) {//Posicion inicial
        toDelete = head;
        head = head->getNext();
    }
    else {//Medio o al  final
        //Eliminar
        //Medio 0, 1, 2, 3 (position = 1, current -> 0, current -> next -> 2) = 0, 2, 3
        //Final 0, 1, 2, 3 (position = 3, current -> 3, current -> next -> nullptr) = 0, 1, 2
        Node* current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->getNext();
        }
        toDelete = current->getNext();
        current->setNext(toDelete->getNext());
    }
    delete toDelete;
    length--;
}

bool LinkedList::search(int data) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->getData() == data) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

void LinkedList::print() const {
    std::cout << *this;
}

int LinkedList::size() const {
    return this->length;
}

bool LinkedList::isEmpty() const {
    return this->length == 0;
}

std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    if (list.isEmpty()) {
        return os;
    }
    Node* current = list.head;
    for (int i = 0; i < list.length; i++) {
        os << *current;
        if (current->getNext() != nullptr) {
            os << " -> ";
        }
        current = current->getNext();
    }
    os << std::endl;
    return os;
}
