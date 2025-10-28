#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{

// 测试输入：FM
TEST(ExecutorFastTest, should_return_x_plus_2_given_status_is_fast_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("FM");
    // then
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 测试输入：FL
TEST(ExecutorFastTest, should_return_M_and_x_plus_1_given_status_is_fast_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("FL");
    // then
    const Pose target{1, 0, 'N'};  // 左转后朝北，快速模式下移动1单位
    ASSERT_EQ(target, executor->Query());
}

// 测试输入：FR
TEST(ExecutorFastTest, should_return_S_and_x_plus_1_given_status_is_fast_given_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("FR");
    // then
    const Pose target{1, 0, 'S'};  // 右转后朝南，快速模式下移动1单位
    ASSERT_EQ(target, executor->Query());
}

// 测试输入：FFM
TEST(ExecutorFastTest, should_return_y_plus_1_given_command_is_FFM_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("FFM");
    // then
    const Pose target{0, 1, 'N'};  // 朝北移动1单位
    ASSERT_EQ(target, executor->Query());
}

}  // namespace adas