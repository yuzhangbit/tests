/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC), 
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: solver_test.cpp
 *   Created on: 08, 16, 2018 
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include <iostream>
#include <set>
#include <map>

#include "gtest/gtest.h"
#include "solver.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(angram_test, solver) {
    // testing data
    std::string str1 = "stls";
    std::string str2 = "tsls";
    std::string str3 = "sejf";
    // single function test
    EXPECT_EQ(true, anagram::Solver::isAnagram(str1, str2));
    EXPECT_EQ(false, anagram::Solver::isAnagram(str1, str3));
   
    // solving
    std::vector<std::string> data = {"lint","intl","inlt","code","others"};
    anagram::Solver::printDuplicates(data);
    
}

TEST(house_robber_test, solver) {
    // testing data
    std::vector<int> data = {3, 6, 4};
    // solving
    std::cout << house_robber::Solver::maxMoney(data) << std::endl;
    // testing
    EXPECT_EQ(6, house_robber::Solver::maxMoney(data));
}
