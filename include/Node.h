//
// Created by DIEGO on 31/03/2026.
//

#ifndef DS_LINKED_LIST_NODE_H
#define DS_LINKED_LIST_NODE_H

class Node {
    private:
        int data;
        Node* next;
    public:
        Node(int data, Node* next);
        [[nodiscard]] int getData() const; //Si alguien llama getData() y no usa el valor saldra alerta
        void setData(int newData);
        [[nodiscard]] Node* getNext() const;
        void setNext(Node* newNext);
};

/*
[[nodiscard]]
node.getData();  // warning: valor ignorado
int val = node.getData();  // correcto, sin warning

*/

#endif //DS_LINKED_LIST_NODE_H