//
// Created by DIEGO on 31/03/2026.
//

#ifndef DS_LINKED_LIST_LIST_H
#define DS_LINKED_LIST_LIST_H

//La clase no se puede instanciar directamente
class List {
public:
    virtual void insert(int data, int position) = 0;
    virtual void remove(int position) = 0;
    [[nodiscard]] virtual bool search(int data) const = 0;
    virtual void print() const = 0;
    [[nodiscard]] virtual int size() const = 0;
    [[nodiscard]] virtual bool isEmpty() const = 0;
    virtual ~List() = default; //Obligatorio en cl,ases asbtarctas
};

#endif //DS_LINKED_LIST_LIST_H