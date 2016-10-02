cmake_minimum_required(VERSION 3.6)
project(code)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Tests/CodeChallenge/main.cpp
    Tests/210_Course_Schedule_II.cc
    Tests/abc.cc
    210_Course_Schedule_II.cc
    AddTwoNumbers.cc
    AllPermutations.cc
    Anagram.cc
    BuySellStock.cc
    CombinationSumIV.cc
    CustomSet.cc
    FindMaxSum.cc
    FindPath.cc
    InPlaceSort.cc
    IsOneEditDistance.cc
    IsPaliandrome.cc
    KDistanceApart.cc
    KSmallestPairs.cc
    KthSmallestInSortedArr.cc
    LargestRectangleHistogram.cc
    LengthOfLongestSubstring.cc
    LongestPaliandrome.cc
    MedianOfSortedArray.cc
    MinPath.cpp
    NumOfIslands.cc
    NumOfIslandsII.cc
    PreOrder.cc
    RearrangeString.cc
    RegexMatching.cc
    RemoveDuplicates.cc
    ReverseWords.cc
    Search2DMatrix.cc
    Search2DSortedArray.cc
    SearchInsertPosition.cc
    ShiftedSortedArray.cpp
    SummaryRanges.cc
    test.cc
    ThreeSumClosest.cc
    TrieNodeImpl.cc
    TwoSum.cc
    ValidAnagram.cc
    WeightedUnionFind.cpp)

add_executable(code ${SOURCE_FILES})