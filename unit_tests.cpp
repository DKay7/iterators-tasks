#include <gtest/gtest.h>
#include <vector>
#include <sstream>
#include <string>
#include <set>
#include "iterators.h"

//--------------------------------------------------------------------------------
// PRINT LEFT THAN
//--------------------------------------------------------------------------------

TEST(PrintLeftThanTest, EmptyVector)
{
    std::vector<int> empty{};
    std::stringstream ss;
    std::streambuf* backup = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    it::print_left_than(empty, 5);
    std::cout.rdbuf(backup);
    EXPECT_EQ(ss.str(), "");
}

TEST(PrintLeftThanTest, NumNotInVector)
{
    std::vector<int> data{1, 2, 3, 6};
    std::stringstream ss;
    std::streambuf* backup = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    it::print_left_than(data, 5);
    std::cout.rdbuf(backup);
    EXPECT_EQ(ss.str(), "");
}

TEST(PrintLeftThanTest, RegularCaseTest)
{
    std::vector<int> data{1, 2, 3, 0, -4, 5, 6, -9, 12};
    std::stringstream ss;
    std::streambuf* backup = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    it::print_left_than(data, 5);
    std::cout.rdbuf(backup);
    EXPECT_EQ(ss.str(), "6\n5\n-4\n0\n3\n2\n1\n");
}

//--------------------------------------------------------------------------------
// SPLIT STRING
//--------------------------------------------------------------------------------

TEST(splitStringTest, EmptyString) {
    std::string input = "";
    std::vector<std::string> expected = {};
    std::vector<std::string> actual = it::split_str(input);
    ASSERT_EQ(expected, actual);
}

TEST(splitStringTest, NoDelimiter) {
    std::string input = "this is a test";
    std::vector<std::string> expected = {"this", "is", "a", "test"};
    std::vector<std::string> actual = it::split_str(input);
    ASSERT_EQ(expected, actual);
}

TEST(splitStringTest, WithDelimiter) {
    std::string input = "this,is,a,test";
    std::vector<std::string> expected = {"this", "is", "a", "test"};
    std::vector<std::string> actual = it::split_str(input, ',');
    ASSERT_EQ(expected, actual);
}

TEST(splitStringTest, DelimiterAtBeginning) {
    std::string input = ",this,is,a,test";
    std::vector<std::string> expected = {"", "this", "is", "a", "test"};
    std::vector<std::string> actual = it::split_str(input, ',');
    ASSERT_EQ(expected, actual);
}

TEST(splitStringTest, DelimiterAtEnd) {
    std::string input = "this,is,a,test,";
    std::vector<std::string> expected = {"this", "is", "a", "test"};
    std::vector<std::string> actual = it::split_str(input, ',');
    ASSERT_EQ(expected, actual);
}

TEST(splitStringTest, MultipleDelimiters) {
    std::string input = "this is, a test";
    std::vector<std::string> expected = {"this", "is,", "a", "test"};
    std::vector<std::string> actual = it::split_str(input, ' ');
    ASSERT_EQ(expected, actual);
}

TEST(splitStringTest, TabDelimiter) {
    std::string input = "this\tis\ta\ttest";
    std::vector<std::string> expected = {"this", "is", "a", "test"};
    std::vector<std::string> actual = it::split_str(input, '\t');
    ASSERT_EQ(expected, actual);
}

//--------------------------------------------------------------------------------
// SetElementsGreaterThan
//--------------------------------------------------------------------------------

TEST(SetElementsGreaterThanTest, EmptySet) {
    std::set<int> s;
    int elem = 5;
    std::vector<int>  result = it::set_elements_greater_than<int>(s, elem);
    ASSERT_TRUE(result.empty());
}

TEST(SetElementsGreaterThanTest, AllElementsGreaterThan) {
    std::set<int> s = {10, 30, 20};
    int elem = 5;
    auto result = it::set_elements_greater_than(s, elem);
    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(result[0], 30);
    ASSERT_EQ(result[1], 20);
    ASSERT_EQ(result[2], 10);
}

TEST(SetElementsGreaterThanTest, ElementNotInSet) {
    std::set<std::string> s = {"a", "abc", "abcd", "ab"};
    std::string elem = "b";
    std::vector<std::string> result = it::set_elements_greater_than(s, elem);

    ASSERT_EQ(result.size(), 0);
}

TEST(SetElementsGreaterThanTest, RegularIntTest) {
    std::set<int> s = {51, 44, 756, -123, 12, -4, 0, 23};
    int elem = 23;
    auto result = it::set_elements_greater_than(s, elem);
    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(result[0], 756);
    ASSERT_EQ(result[1], 51);
    ASSERT_EQ(result[2], 44);
}

TEST(SetElementsGreaterThanTest, RegularStrTest) {
    std::set<std::string> s = {"c", "b", "cd", "a", "e", "d"};

    std::string elem = "b";
    std::vector<std::string> result = it::set_elements_greater_than(s, elem);

    ASSERT_EQ(result.size(), 4);
    ASSERT_EQ(result[0], "e");
    ASSERT_EQ(result[1], "d");
    ASSERT_EQ(result[2], "cd");
    ASSERT_EQ(result[3], "c");
}
//--------------------------------------------------------------------------------
