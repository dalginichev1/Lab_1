#include <gtest/gtest.h>
#include <cmath>
#include "closest_pair_tonum.h"

TEST(ClosestPairTonumTest, BasicCases) {
    // Тест из условия
    NumberPair result1 = closest_pair_tonum(10);
    EXPECT_EQ(result1.m, 5);    
    EXPECT_EQ(result1.n, 4);   
    
    NumberPair result2 = closest_pair_tonum(30);
    EXPECT_EQ(result2.m, 29);   
    EXPECT_EQ(result2.n, 20);  
    
    NumberPair result3 = closest_pair_tonum(50);
    EXPECT_EQ(result3.m, 45);   
    EXPECT_EQ(result3.n, 36);   
}

TEST(ClosestPairTonumTest, EdgeCases) {
    // Для значений меньше 6 не существует подходящих пар
    // Должны возвращать (0, 0) или бросать исключение
    
    NumberPair result1 = closest_pair_tonum(5);
    // Ожидаем специальное значение или проверяем исключение
    EXPECT_EQ(result1.m, 0);
    EXPECT_EQ(result1.n, 0);
    
    NumberPair result2 = closest_pair_tonum(3);
    EXPECT_EQ(result2.m, 0);
    EXPECT_EQ(result2.n, 0);
    
    NumberPair result3 = closest_pair_tonum(6);
    // Для 6 уже должна существовать пара (5, 4)
    EXPECT_EQ(result3.m, 5);
    EXPECT_EQ(result3.n, 4);
}
TEST(ClosestPairTonumTest, VerifyConditions) {
    std::vector<int> test_limits = {10, 20, 30, 40, 50};
    
    for (int limit : test_limits) {
        NumberPair result = closest_pair_tonum(limit);
        
        // Проверяем условия
        EXPECT_GT(limit, result.m);
        EXPECT_GT(result.m, result.n);
        EXPECT_GT(result.n, 0);
        
        // Проверяем свойства совершенных квадратов
        int sum = result.m + result.n;
        int diff = result.m - result.n;
        
        double sum_sqrt = std::sqrt(sum);
        double diff_sqrt = std::sqrt(diff);
        
        EXPECT_NEAR(sum_sqrt, std::round(sum_sqrt), 1e-10);
        EXPECT_NEAR(diff_sqrt, std::round(diff_sqrt), 1e-10);
    }
}

TEST(ClosestPairTonumTest, AdditionalCases) {
    // Дополнительные проверки
    NumberPair result = closest_pair_tonum(100);
    EXPECT_GT(100, result.m);
    EXPECT_GT(result.m, result.n);
    
    int sum = result.m + result.n;
    int diff = result.m - result.n;
    
    EXPECT_TRUE(std::abs(std::sqrt(sum) - std::round(std::sqrt(sum))) < 1e-10);
    EXPECT_TRUE(std::abs(std::sqrt(diff) - std::round(std::sqrt(diff))) < 1e-10);
}

TEST(ClosestPairTonumTest, SumAndDifferenceArePerfectSquares) {
    NumberPair result = closest_pair_tonum(50);
    
    int sum = result.m + result.n;
    int diff = result.m - result.n;
    
    // Проверяем что оба числа - полные квадраты
    double sum_sqrt = std::sqrt(sum);
    double diff_sqrt = std::sqrt(diff);
    
    EXPECT_TRUE(std::abs(sum_sqrt - std::round(sum_sqrt)) < 1e-10);
    EXPECT_TRUE(std::abs(diff_sqrt - std::round(diff_sqrt)) < 1e-10);
}