
#include <gtest/gtest.h>

#include "topology_sort.hpp"


TEST(TopologySort, EmptyGraph) {
    std::vector<std::vector<int>> adj;
    std::vector<int> result = TopologySort(adj);

    ASSERT_TRUE(result.empty());
}

TEST(TopologySort, SingleNode) {
    std::vector<std::vector<int>> adj = {{}};
    std::vector<int> result = TopologySort(adj);

    ASSERT_EQ(result, std::vector<int>{0});
}

TEST(TopologySort, DisconnectedComponents) {
    std::vector<std::vector<int>> adj = {{1, 2}, {3, 4}, {5}, {6}};
    std::vector<int> result = TopologySort(adj);


    ASSERT_EQ(result.size(), 7);
}

TEST(TopologySort, CyclicGraph) {
    std::vector<std::vector<int>> adj = {{1}, {2}, {0}};
    std::vector<int> result = TopologySort(adj);

    ASSERT_TRUE(result.empty());
}
