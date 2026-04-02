//
// Created by DIEGO on 01/04/2026.
//

#ifndef DS_LINKED_LIST_STACK_H
#define DS_LINKED_LIST_STACK_H

//#include "List.h"
#include "LinkedList.h"
//Usa un LinkedList de forma interna para sus operaciones
class StackComposicion{//Pila
private:
    LinkedList list;
public:
    StackComposicion() = default;
    ~StackComposicion() = default;

    //
    void push(int data);
    void pop();
    [[nodiscard]] int top() const; //Ver el de arriab sin eliminar
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] int size() const;
    void print() const;
    /*
    void insert(int data, int position) override;  // push
    void remove(int position) override;             // pop
    [[nodiscard]] bool search(int data) const override;
    void print() const override;
    [[nodiscard]] int size() const override;
    [[nodiscard]] bool isEmpty() const override;

    [[nodiscard]] int top() const;  // ver el tope sin eliminar
    */

    friend std::ostream& operator<<(std::ostream& os, const StackComposicion& stack);
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);
};

#endif //DS_LINKED_LIST_STACK_H