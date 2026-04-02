#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

LinkedList::LinkedList() : head(nullptr),tail(nullptr), length(0){

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
    if (position < 0 || position > length) {
        throw std::out_of_range("Posicion invalida");
    }
    Node* newNode = new Node(data);

    // Lista vacia O(1)
    if (isEmpty()) {
        head = newNode;
        tail = nullptr;
    }
    // Inicio O(1)
    else if (position == 0) {
        //Insertar 2, 3, 4
        // 0 (head -> 0, tail -> nullptr) = 2 -> 0
        // 2 -> 0 (head -> 2, tail -> 2) = 3 -> 2 -> 0
        // 3 -> 2 -> 0 (head -> 2, tail -> 2) = 4 -> 3 -> 2 -> 0
        newNode->setNext(head);
        head = newNode;
        if (length == 1) tail = head; // tail = penultimo = newNode = head
    }
    // Final O(1)
    else if (position == length) {
        //Insertar 2, 3, 4
        // 0 (head -> 0, tail -> nullptr) = 0 -> 2
        // 0 -> 2 (head -> 0, tail -> 0) = 0 -> 2 -> 3
        // 0 -> 2 -> 3 (head -> 0, tail -> 2) = 0 -> 2 -> 3 -> 4
        if (tail == nullptr) {
            // 1 elemento: tail es nullptr
            head->setNext(newNode);
            tail = head;
        } else {
            // 2+ elementos
            tail->getNext()->setNext(newNode);
            tail = tail->getNext();
        }
    }
    // Medio O(n)
    else {
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
    if (position < 0 || position >= length) {
        throw std::out_of_range("Posicion invalida");
    }
    Node* toDelete;

    // 1 elemento O(1)
    if (length == 1) {// position 0 = length - 1
        toDelete = head;
        head = nullptr;
        tail = nullptr;
    }
    // Inicio O(1)
    else if (position == 0) {
        //Eliminar
        // 2 -> 3 -> 4 (head -> 2, tail -> 3) = 3 -> 4
        // 3 -> 4 (head -> 3, tail -> 3) = 4
        // 4 (head -> 2, tail -> nullptr) = vacio
        toDelete = head;
        head = head->getNext();
        if (length == 2) tail = nullptr;
    }
    // Final O(n)
    else if (position == length - 1) {
        //Eliminar
        //2 -> 3 -> 4 -> 5 (head -> 2, tail -> 4) = 2 -> 3 -> 4
        // 2 -> 3 -> 4 (head -> 2, tail -> 3) = 2 -> 3
        // 2 -> 3 (head -> 2, tail -> 2) = 2
        // 2 (head -> 2, tail -> nullptr) = vacio
        if (length == 2) {
            // 2 elementos: eliminar ultimo, queda 1
            toDelete = head->getNext();
            head->setNext(nullptr);
            tail = nullptr;
        } else {
            // 3+ elementos: recorrer hasta nuevo penultimo
            // antes: head -> ... -> newPenultimo -> penultimo -> ultimo
            // despues: head -> ... -> newPenultimo -> penultimo (nuevo tail)
            Node* current = head;
            while (current->getNext() != tail) {
                current = current->getNext();
            }
            toDelete = tail->getNext(); // ultimo
            tail->setNext(nullptr);
            tail = current;            // tail retrocede al nuevo penultimo
        }
    }
    // Medio O(n)
    else {
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


/*
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
*/