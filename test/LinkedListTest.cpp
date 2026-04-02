#include <gtest/gtest.h>
#include <sstream>
#include "LinkedList.h"

TEST(LinkedListTest, InsertAlInicio) {
    LinkedList list;
    list.insert(1, 0);
    list.insert(2, 0);
    EXPECT_EQ(list.size(), 2);
}

TEST(LinkedListTest, InsertAlFinal) {
    LinkedList list;
    list.insert(1, 0);
    list.insert(2, 1);
    EXPECT_EQ(list.size(), 2);
}

TEST(LinkedListTest, InsertPosicionInvalida) {
    LinkedList list;
    EXPECT_THROW(list.insert(1, 5), std::out_of_range);
}

TEST(LinkedListTest, RemoveAlInicio) {
    LinkedList list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.remove(0);
    EXPECT_EQ(list.size(), 1);
}

TEST(LinkedListTest, RemovePosicionInvalida) {
    LinkedList list;
    EXPECT_THROW(list.remove(0), std::out_of_range);
}

//Insert y remove agregando tail que apuntara simepre al penultimo nodo

TEST(LinkedListTest, InsertYRemoveAlFinalUnElemento) {
    LinkedList list; // 1 -> 2 (head -> 1, tail -> 1)
    list.insert(1, 0);
    list.insert(2, 1);  // tail = head (penultimo)
    list.remove(1);     // eliminar ultimo
    EXPECT_EQ(list.size(), 1);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1\n");
}

TEST(LinkedListTest, InsertYRemoveAlFinalDosElementos) {
    LinkedList list; // 1 -> 2 -> 3 (head -> 1, tail -> 2)
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);  // tail apunta a nodo 1 (penultimo)
    list.remove(2);     // eliminar ultimo
    EXPECT_EQ(list.size(), 2);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1 -> 2\n");
}

TEST(LinkedListTest, InsertYRemoveAlFinalTresElementos) {
    LinkedList list; // 1 -> 2 -> 3 -> 4 (head -> 1, tail ->3)
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3);  // tail apunta a nodo 2 (penultimo)
    list.remove(3);     // eliminar ultimo
    EXPECT_EQ(list.size(), 3);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1 -> 2 -> 3\n");
}

TEST(LinkedListTest, InsertAlFinalMultiple) {
    LinkedList list;//// 1 -> 2 -> 3 -> 4 (head -> 1, tail ->3)
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1 -> 2 -> 3 -> 4\n");
}

//
TEST(LinkedListTest, SearchEncontrado) {
    LinkedList list;
    list.insert(42, 0);
    EXPECT_TRUE(list.search(42));
}

TEST(LinkedListTest, SearchNoEncontrado) {
    LinkedList list;
    list.insert(1, 0);
    EXPECT_FALSE(list.search(99));
}

TEST(LinkedListTest, IsEmptyVerdadero) {
    LinkedList list;
    EXPECT_TRUE(list.isEmpty());
}

TEST(LinkedListTest, IsEmptyFalso) {
    LinkedList list;
    list.insert(1, 0);
    EXPECT_FALSE(list.isEmpty());
}

TEST(LinkedListTest, PrintOperator) {
    LinkedList list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1 -> 2 -> 3\n");
}

TEST(LinkedListTest, PrintOperatorVacia) {
    LinkedList list;
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "");
}