//
// Created by DIEGO on 31/03/2026.
//

#ifndef DS_LINKED_LIST_LINKEDLIST_H
#define DS_LINKED_LIST_LINKEDLIST_H

#include "List.h"
#include "Node.h"

class LinkedList : public List {
    private:
        Node* head;
        Node* tail;
        int length;
    public:

        LinkedList();
        ~LinkedList() override;

        void insert(int data, int position) override;
        void remove(int position) override;
        [[nodiscard]] bool search(int data) const override;
        [[nodiscard]] int searchPos(int position) const;
        void print() const override;
        [[nodiscard]] int size() const override;
        [[nodiscard]] bool isEmpty() const override;
        [[nodiscard]] std::string toDot() const;
        friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);
};

#endif //DS_LINKED_LIST_LINKEDLIST_H