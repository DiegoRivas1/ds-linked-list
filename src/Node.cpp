//
// Created by DIEGO on 31/03/2026.
//
#include "Node.h"

Node::Node(int data): data(data) {
    this->next = nullptr;
}

Node::Node(int data, Node *next) : data(data), next(next){}

Node::~Node() = default;

int Node::getData() const {
    return this->data;
}

void Node::setData(int newData) {
    this->data = newData;
}

Node *Node::getNext() const {
    return this->next;
}

void Node::setNext(Node *newNext) {
    this->next = newNext;
}

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os<<node.data;
    return os;
}