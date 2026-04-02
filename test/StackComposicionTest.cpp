#include <gtest/gtest.h>
#include <sstream>
#include "StackComposicion.h"

TEST(StackComposicionTest, PushYSize) {
    StackComposicion stack;
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.size(), 2);
}

TEST(StackComposicionTest, PopReduceSize) {
    StackComposicion stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
}

TEST(StackComposicionTest, TopRetornaValor) {
    StackComposicion stack;
    stack.push(1);
    stack.push(2); // 2 -> 1, tope = 2
    EXPECT_EQ(stack.top(), 2);
}

TEST(StackComposicionTest, TopNoModificaSize) {
    StackComposicion stack;
    stack.push(42);
    (void)stack.top();
    EXPECT_EQ(stack.size(), 1);
}

TEST(StackComposicionTest, TopStackVacio) {
    try {
        StackComposicion stack;
        (void)stack.top();
        FAIL() << "Se esperaba std::out_of_range";
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "Stack vacio");
    }
}

TEST(StackComposicionTest, PopStackVacio) {
    try {
        StackComposicion stack;
        stack.pop();
        FAIL() << "Se esperaba std::out_of_range";
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "Stack vacio");
    }
}

TEST(StackComposicionTest, PushPopOrdenLIFO) {
    StackComposicion stack;
    stack.push(1);
    stack.push(2);
    stack.push(3); // 3 -> 2 -> 1
    EXPECT_EQ(stack.top(), 3);
    stack.pop();   // 2 -> 1
    EXPECT_EQ(stack.top(), 2);
    stack.pop();   // 1
    EXPECT_EQ(stack.top(), 1);
}

TEST(StackComposicionTest, IsEmptyVerdadero) {
    StackComposicion stack;
    EXPECT_TRUE(stack.isEmpty());
}

TEST(StackComposicionTest, IsEmptyFalso) {
    StackComposicion stack;
    stack.push(1);
    EXPECT_FALSE(stack.isEmpty());
}

TEST(StackComposicionTest, PrintOperator) {
    StackComposicion stack;
    stack.push(1);
    stack.push(2);
    stack.push(3); // 3 -> 2 -> 1
    std::ostringstream os;
    os << stack;
    EXPECT_EQ(os.str(), "3 -> 2 -> 1\n");
}

TEST(StackComposicionTest, PopHastaVacia) {
    StackComposicion stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
}