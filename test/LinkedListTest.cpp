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

// Insert y remove agregando tail que apuntara siempre al penultimo nodo
TEST(LinkedListTest, InsertYRemoveFinalOInicio) {
    LinkedList list; // 1 (head -> 1, tail -> nullptr)
    list.insert(1, 0);
    list.remove(0);
    EXPECT_EQ(list.size(), 0);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "");
}

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
    LinkedList list; // 1 -> 2 -> 3 -> 4 (head -> 1, tail -> 3)
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
    LinkedList list; // 1 -> 2 -> 3 -> 4 (head -> 1, tail -> 3)
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1 -> 2 -> 3 -> 4\n");
}

// Insertar varios al inicio
TEST(LinkedListTest, InsertVariosAlInicio) {
    LinkedList list; // 4 -> 3 -> 2 -> 1 (head -> 4, tail -> 2)
    list.insert(1, 0);
    list.insert(2, 0);
    list.insert(3, 0);
    list.insert(4, 0);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "4 -> 3 -> 2 -> 1\n");
}

TEST(LinkedListTest, InsertVariosAlInicioYSize) {
    LinkedList list;
    list.insert(1, 0);
    list.insert(2, 0);
    list.insert(3, 0);
    EXPECT_EQ(list.size(), 3);
}

// Eliminar varios al final
TEST(LinkedListTest, RemoveVariosAlFinal) {
    LinkedList list; // 1 -> 2 -> 3 -> 4 -> 5 (head -> 1, tail -> 4)
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3);
    list.insert(5, 4);
    list.remove(4); // 1 -> 2 -> 3 -> 4
    list.remove(3); // 1 -> 2 -> 3
    list.remove(2); // 1 -> 2
    EXPECT_EQ(list.size(), 2);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1 -> 2\n");
}

TEST(LinkedListTest, RemoveVariosAlFinalHastaVacia) {
    LinkedList list; // 1 -> 2 -> 3 (head -> 1, tail -> 2)
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.remove(2); // 1 -> 2
    list.remove(1); // 1
    list.remove(0); // vacia
    EXPECT_EQ(list.size(), 0);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "");
}

// Insertar en medio
TEST(LinkedListTest, InsertEnMedio) {
    LinkedList list; // 1 -> 4 -> 2 -> 3
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 1); // insertar 4 en posicion 1
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1 -> 4 -> 2 -> 3\n");
}

// Eliminar en medio
TEST(LinkedListTest, RemoveEnMedio) {
    LinkedList list; // 1 -> 2 -> 3 -> 4
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3);
    list.remove(1); // eliminar posicion 1 = 1 -> 3 -> 4
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1 -> 3 -> 4\n");
}

TEST(LinkedListTest, RemoveVariosEnMedio) {
    LinkedList list; // 1 -> 2 -> 3 -> 4 -> 5
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3);
    list.insert(5, 4);
    list.remove(1); // 1 -> 3 -> 4 -> 5
    list.remove(1); // 1 -> 4 -> 5
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1 -> 4 -> 5\n");
}

//Busqueda de datos por valor
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
//Busqueda de datos por posicion

TEST(LinkedListTest, SearchPosInicio) {
    LinkedList list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    EXPECT_EQ(list.searchPos(0), 10);
}

TEST(LinkedListTest, SearchPosFinal) {
    LinkedList list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    EXPECT_EQ(list.searchPos(2), 30);
}

TEST(LinkedListTest, SearchPosMedio) {
    LinkedList list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    EXPECT_EQ(list.searchPos(1), 20);
}

/*

TEST(LinkedListTest, SearchPosInvalida) {
    LinkedList list;
    EXPECT_THROW((void)list.searchPos(0), std::out_of_range);
}

*/

TEST(LinkedListTest, SearchPosInvalida) {
    try {
        LinkedList list;
        [[maybe_unused]] int resultado = list.searchPos(0);
        FAIL() << "Se esperaba std::out_of_range";
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "Posicion invalida");
    }
}

TEST(LinkedListTest, SearchPosValida) {
    LinkedList list;
    list.insert(42, 0);
    // Agregar elementos a la lista
    int valor = list.searchPos(0);
    EXPECT_EQ(valor, 42);
}
//

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