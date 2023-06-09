#include <gtest/gtest.h>
#include "../include/WordScoreCalculator.h"
#include "../include/WordValidator.h"
#include <algorithm>

// Mock WordScorer class for testing
class MockWordScorer : public WordScorer {
public:
    int calculatePoints(const std::string& word) const override {
        // Return a fixed score for testing purposes
        // You can customize this implementation for your specific scoring logic
        if (word == "hello")
            return 5;
        else if (word == "world")
            return 10;
        else if (word == "testing")
            return 7;
        else
            return 0;  // Default score for other words
    }
};

WordScoreCalculator::WordScoreCalculator(const WordScorer& scorer) : scorer(scorer) {}

int WordScoreCalculator::calculateTotalScore(const std::vector<std::string>& words) const {
    int totalScore = 0;

    for (const std::string& word : words) {
        int wordScore = scorer.calculatePoints(word);
        totalScore += wordScore;
    }

    return totalScore;
}

// Test case for calculating total score with an empty list of words
TEST(WordScoreCalculatorTest, CalculateTotalScoreEmptyWords) {
    // Create a mock WordScorer object for testing
    MockWordScorer mockScorer;

    // Create a WordScoreCalculator object
    WordScoreCalculator calculator(mockScorer);

    // Provide an empty vector of words
    std::vector<std::string> words;

    // Calculate the total score
    int totalScore = calculator.calculateTotalScore(words);

    // The total score should be 0 for an empty list of words
    EXPECT_EQ(totalScore, 0);
}

// Test case for calculating total score with a list of words
TEST(WordScoreCalculatorTest, CalculateTotalScoreNonEmptyWords) {
    // Create a mock WordScorer object for testing
    MockWordScorer mockScorer;

    // Create a WordScoreCalculator object
    WordScoreCalculator calculator(mockScorer);

    // Provide a vector of words
    std::vector<std::string> words = { "hello", "world", "testing" };

    // Calculate the total score
    int totalScore = calculator.calculateTotalScore(words);

    // The total score should be the sum of individual word scores
    // based on the mock scorer's scoring logic
    int expectedScore = mockScorer.calculatePoints("hello") +
                        mockScorer.calculatePoints("world") +
                        mockScorer.calculatePoints("testing");
    EXPECT_EQ(totalScore, expectedScore);
}




std::vector<std::string> WordValidator::filterValidWords(const std::vector<std::string>& words, const std::vector<std::string>& validWords) {
    std::vector<std::string> filteredWords;
    for (const std::string& word : words) {
        if (std::binary_search(validWords.begin(), validWords.end(), word)) {
            filteredWords.push_back(word);
        }
    }
    return filteredWords;
}

// Test case for filtering valid words
TEST(WordValidatorTest, FilterValidWords) {
    WordValidator validator;

    std::vector<std::string> words = { "apple", "banana", "orange", "grape" };
    std::vector<std::string> validWords = { "apple", "grape" };

    std::vector<std::string> filteredWords = validator.filterValidWords(words, validWords);

    EXPECT_EQ(filteredWords.size(), 2);
    EXPECT_EQ(filteredWords[0], "apple");
    EXPECT_EQ(filteredWords[1], "grape");
}

// Test case for filtering valid words with an empty input
TEST(WordValidatorTest, FilterValidWordsEmptyInput) {
    WordValidator validator;

    std::vector<std::string> words;
    std::vector<std::string> validWords = { "apple", "grape" };

    std::vector<std::string> filteredWords = validator.filterValidWords(words, validWords);

    EXPECT_EQ(filteredWords.size(), 0);
}

// Test case for filtering valid words with an empty valid words list
TEST(WordValidatorTest, FilterValidWordsEmptyValidWords) {
    WordValidator validator;

    std::vector<std::string> words = { "apple", "banana", "orange", "grape" };
    std::vector<std::string> validWords;

    std::vector<std::string> filteredWords = validator.filterValidWords(words, validWords);

    EXPECT_EQ(filteredWords.size(), 0);
}

// Test case for filtering valid words with no matching words
TEST(WordValidatorTest, FilterValidWordsNoMatchingWords) {
    WordValidator validator;

    std::vector<std::string> words = { "apple", "banana", "orange", "grape" };
    std::vector<std::string> validWords = { "kiwi", "melon" };

    std::vector<std::string> filteredWords = validator.filterValidWords(words, validWords);

    EXPECT_EQ(filteredWords.size(), 0);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
