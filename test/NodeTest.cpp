#include <gtest/gtest.h>
#include "Node.h"

TEST(NodeTest, ConstructorSetsData) {
    Node node(42, nullptr);
    EXPECT_EQ(node.getData(), 42);
}

TEST(NodeTest, ConstructorSetsNext) {
    Node node2(10, nullptr);
    Node node1(5, &node2);
    EXPECT_EQ(node1.getNext(), &node2);
}

TEST(NodeTest, SetDataUpdatesValue) {
    Node node(1, nullptr);
    node.setData(99);
    EXPECT_EQ(node.getData(), 99);
}
//
TEST(NodeTest, SetNextUpdatesPointer) {
    Node node1(1, nullptr);
    Node node2(2, nullptr);
    node1.setNext(&node2);
    EXPECT_EQ(node1.getNext(), &node2);
}

TEST(NodeTest, PrintOperator) {
    Node node(42, nullptr);
    std::ostringstream os;
    os << node;
    EXPECT_EQ(os.str(), "42");
}