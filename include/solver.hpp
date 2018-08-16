/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC), 
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: solver.hpp
 *   Created on: 08, 16, 2018 
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#ifndef TESTS_SOLVER_HPP
#define TESTS_SOLVER_HPP

#include <vector>
#include <algorithm>

/****************************/
namespace anagram {

class Solver {
    /**
     * 1.先判断两个字符串是不是 anagram，
     * 2.找出重复的anagram,输出　
     */
 public:
    static bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }
        // 都是小写，可以为每一个字母建一个counter, 两个string分别更新字母的counter,
        // 如果是anagram，那么每一位counter都应该是0
        int counts[26] = {0};
        for (const auto& c: s) {
            counts[c - 'a']++;
        }
        for (const auto& c: t) {
            counts[c - 'a']--;
            if (counts[ c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
    
    static void printDuplicates(std::vector<std::string> &data) {
        std::cout << "repeating Anagram: ";
        std::size_t size = data.size();
        std::string anagram;
        bool find_flag = false;
        int jump = 0;
        for (std::size_t i = 0; i < size; i++) {
            if (!find_flag) {
                for (std::size_t j = i + 1; j < size; j++) {
                    if (isAnagram(data[i], data[j])) {
                        anagram = data[i];
                        find_flag = true;
                        jump = j;
                        std::cout << " " << data[i] << " " << data[j];
                        break;
                    }
                }
            } else {
                if (i > jump) {
                    if (isAnagram(data[i], anagram)) {
                        std::cout << " " << data[i];
                    }
                }
                
            }
        }
        std::cout << std::endl;
    }
};


}  // namespace anagram

/****************************/
namespace house_robber {

class Solver {
 public:
    static int maxMoney(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
       
        // 头尾不能同时rob, 取两个里最大的　
        return std::max(find(nums, 0, nums.size() - 1),
                   find(nums, 1, nums.size()));
    }
    
    static int find(std::vector<int>& nums, int start, int end) {
        int num_i = nums[start], num_i_1 = 0, num_i_2 = 0;
        for (int i = start + 1; i < end; ++i) {
            num_i_2 = num_i_1;
            num_i_1 = num_i;
            num_i = std::max(nums[i] + num_i_2, num_i_1);
        }
        return num_i;
    }
};

}  // namespace house_robber

#endif  // TESTS_SOLVER_HPP
