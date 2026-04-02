#include <gtest/gtest.h>
#include <sstream>
#include "QueueComposicion.h"

TEST(QueueComposicionTest, EnqueueYSize) {
    QueueComposicion queue;
    queue.enqueue(1);
    queue.enqueue(2);
    EXPECT_EQ(queue.size(), 2);
}

TEST(QueueComposicionTest, DequeueReduceSize) {
    QueueComposicion queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.dequeue();
    EXPECT_EQ(queue.size(), 1);
}

TEST(QueueComposicionTest, OrdenFIFO) {
    QueueComposicion queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3); // 1 -> 2 -> 3
    EXPECT_EQ(queue.front(), 1);
    queue.dequeue();  // 2 -> 3
    EXPECT_EQ(queue.front(), 2);
    queue.dequeue();  // 3
    EXPECT_EQ(queue.front(), 3);
}

TEST(QueueComposicionTest, FrontRetornaValor) {
    QueueComposicion queue;
    queue.enqueue(42);
    queue.enqueue(99); // 42 -> 99, front = 42
    EXPECT_EQ(queue.front(), 42);
}

TEST(QueueComposicionTest, FrontNoModificaSize) {
    QueueComposicion queue;
    queue.enqueue(1);
    (void)queue.front();
    EXPECT_EQ(queue.size(), 1);
}

TEST(QueueComposicionTest, FrontQueueVacio) {
    try {
        QueueComposicion queue;
        (void)queue.front();
        FAIL() << "Se esperaba std::out_of_range";
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "Queue vacio");
    }
}

TEST(QueueComposicionTest, DequeueQueueVacio) {
    try {
        QueueComposicion queue;
        queue.dequeue();
        FAIL() << "Se esperaba std::out_of_range";
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "Queue vacio");
    }
}

TEST(QueueComposicionTest, IsEmptyVerdadero) {
    QueueComposicion queue;
    EXPECT_TRUE(queue.isEmpty());
}

TEST(QueueComposicionTest, IsEmptyFalso) {
    QueueComposicion queue;
    queue.enqueue(1);
    EXPECT_FALSE(queue.isEmpty());
}

TEST(QueueComposicionTest, PrintOperator) {
    QueueComposicion queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3); // 1 -> 2 -> 3
    std::ostringstream os;
    os << queue;
    EXPECT_EQ(os.str(), "1 -> 2 -> 3\n");
}

TEST(QueueComposicionTest, DequeueHastaVacia) {
    QueueComposicion queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.dequeue();
    queue.dequeue();
    EXPECT_TRUE(queue.isEmpty());
}

TEST(QueueComposicionTest, PrintOperatorVacia) {
    QueueComposicion queue;
    std::ostringstream os;
    os << queue;
    EXPECT_EQ(os.str(), "");
}