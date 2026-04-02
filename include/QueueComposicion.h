//
// Created by DIEGO on 02/04/2026.
//

#ifndef DS_LINKED_LIST_QUEUECOMPOSICION_H
#define DS_LINKED_LIST_QUEUECOMPOSICION_H

#include "LinkedList.h"
class QueueComposicion {
    private:
        LinkedList list;
    public:
        QueueComposicion() = default;
        ~QueueComposicion() = default;

        void enqueue(int data); //Insertamos al  final
        void dequeue(); //Eliminamos al  inicio
        [[nodiscard]] int front() const;
        [[nodiscard]] bool isEmpty() const;
        [[nodiscard]] int size() const;
        void print() const;

        friend std::ostream &operator<<(std::ostream &os, const QueueComposicion &comp);
};

#endif //DS_LINKED_LIST_QUEUECOMPOSICION_H