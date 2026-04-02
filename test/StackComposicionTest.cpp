#include <gtest/gtest.h>
#include <sstream>
#include "StackComposicion.h"

TEST(StackComposicionTest, PushAlInicio) {
    StackComposicion stack;
    stack.insert(1, 0); // push
    stack.insert(2, 0); // push
    EXPECT_EQ(stack.size(), 2);
}

TEST(StackComposicionTest, PopReduceSize) {
    StackComposicion stack;
    stack.insert(1, 0);
    stack.insert(2, 0);
    stack.remove(0); // pop
    EXPECT_EQ(stack.size(), 1);
}

TEST(StackComposicionTest, TopRetornaValor) {
    StackComposicion stack;
    stack.insert(1, 0);
    stack.insert(2, 0); // 2 -> 1, tope = 2
    EXPECT_EQ(stack.top(), 2);
}

TEST(StackComposicionTest, TopNoModificaSize) {
    StackComposicion stack;
    stack.insert(42, 0);
    (void)stack.top();  // Cast a void para ignorar el valor retornado
    EXPECT_EQ(stack.size(), 1);
}

TEST(StackComposicionTest, TopStackVacio) {
    try {
        StackComposicion stack;
        (void)stack.top();  // Cast a void para [[nodiscard]]
        FAIL() << "Se esperaba std::out_of_range";
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "Stack vacio");
    }
}

TEST(StackComposicionTest, PushPopOrdenLIFO) {
    StackComposicion stack;
    stack.insert(1, 0);
    stack.insert(2, 0);
    stack.insert(3, 0); // 3 -> 2 -> 1
    EXPECT_EQ(stack.top(), 3);
    stack.remove(0);    // 2 -> 1
    EXPECT_EQ(stack.top(), 2);
    stack.remove(0);    // 1
    EXPECT_EQ(stack.top(), 1);
}

TEST(StackComposicionTest, SearchEncontrado) {
    StackComposicion stack;
    stack.insert(42, 0);
    EXPECT_TRUE(stack.search(42));
}

TEST(StackComposicionTest, SearchNoEncontrado) {
    StackComposicion stack;
    stack.insert(1, 0);
    EXPECT_FALSE(stack.search(99));
}

TEST(StackComposicionTest, IsEmptyVerdadero) {
    StackComposicion stack;
    EXPECT_TRUE(stack.isEmpty());
}

TEST(StackComposicionTest, IsEmptyFalso) {
    StackComposicion stack;
    stack.insert(1, 0);
    EXPECT_FALSE(stack.isEmpty());
}

TEST(StackComposicionTest, PrintOperator) {
    StackComposicion stack;
    stack.insert(1, 0);
    stack.insert(2, 0);
    stack.insert(3, 0); // 3 -> 2 -> 1
    std::ostringstream os;
    os << stack;
    EXPECT_EQ(os.str(), "3 -> 2 -> 1\n");
}

TEST(StackComposicionTest, PopHastaVacia) {
    StackComposicion stack;
    stack.insert(1, 0);
    stack.insert(2, 0);
    stack.remove(0);
    stack.remove(0);
    EXPECT_TRUE(stack.isEmpty());
}