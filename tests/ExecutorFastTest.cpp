#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
TEST(ExecutorTest, should_return_x_plus_2_given_status_is_fast_command_is_M_and_facing_is_E)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("FM");

    // then
    const Pose target({2, 0, 'E'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_N_and_x_plus_1_given_status_is_fast_command_is_L_and_facing_is_E)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("FL");

    // then
    const Pose target({1, 0, 'N'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_S_and_x_plus_1_given_status_is_fast_given_command_is_R_and_facing_is_E)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("FR");

    // then
    const Pose target({1, 0, 'S'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_y_plus_1_given_command_is_FFM_and_facing_is_N)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("FFM");

    // then
    const Pose target({0, 1, 'N'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
}