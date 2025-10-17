#include <gtest/gtest.h>

#include <memory>
#include <tuple>

#include "Executor.hpp"

namespace adas
{
bool operator==(const Pose &lhs, const Pose &rhs)
{
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}

// 测试用例1
TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    // given给定测试条件
    // 测试条件就是调用Executor的静态方法NewExecutor
    // 返回一个指向Executor对象的只能指针executor，这样我们就不需要去delete了
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when

    // then
    const Pose target({0, 0, 'E'});

    ASSERT_EQ(target, executor->Query());
}
// 测试用例2
TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    // when

    // then
    const Pose target({0, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("M");

    // then
    const Pose target({1, 0, 'E'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("M");

    // then
    const Pose target({-1, 0, 'W'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("M");

    // then
    const Pose target({0, 1, 'N'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("M");

    // then
    const Pose target({0, -1, 'S'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_facing_N_given_command_is_L_and_facing_is_E)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("L");

    // then
    const Pose target({0, 0, 'N'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("L");

    // then
    const Pose target({0, 0, 'W'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_facing_S_given_command_is_L_and_facing_is_W)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("L");

    // then
    const Pose target({0, 0, 'S'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("L");

    // then
    const Pose target({0, 0, 'E'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_facing_S_given_command_is_R_and_facing_is_E)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("R");

    // then
    const Pose target({0, 0, 'S'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_facing_W_given_command_is_R_and_facing_is_S)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("R");

    // then
    const Pose target({0, 0, 'W'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_facing_N_given_command_is_R_and_facing_is_W)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("R");

    // then
    const Pose target({0, 0, 'N'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_facing_E_given_command_is_R_and_facing_is_N)
{
    // given 给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

    // when 调用executor的Execute方法去执行命令
    executor->Execute("R");

    // then
    const Pose target({0, 0, 'E'});  // 命令正确时的姿势
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas