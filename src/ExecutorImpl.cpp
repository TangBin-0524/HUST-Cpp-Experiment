#include "ExecutorImpl.hpp"

#include <memory>
#include <new>

namespace adas
{
ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : pose(pose), isFast(false)
{
}

Pose ExecutorImpl::Query(void) const noexcept
{
    return pose;
}
/*
    std::nothrow 是C++标准库中的一个常量，用于指示在分配内存时不抛出任何异常。
    它是std::nothrow_t 类型的实例，通常用在new运算符和std::nothrow命名空间中，
    以请求内存分配器在分配失败是返回一个空指针，而不是抛出std::bad_alloc异常
*/
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}
void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    for (const auto cmd : commands) {
        std::unique_ptr<ICommand> cmder;
        if (cmd == 'M') {
            // 智能指针指向MoveCommand实例，不用担心delete了
            cmder = std::make_unique<MoveCommand>();
        } else if (cmd == 'L') {
            cmder = std::make_unique<TurnLeftCommand>();
        } else if (cmd == 'R') {
            cmder = std::make_unique<TurnRightCommand>();
        } else if (cmd == 'F') {
            isFast = !isFast;
        }
        if (cmder) {
            cmder->DoOperate(*this);
        }
    }
}
void ExecutorImpl::Move() noexcept
{
    if (pose.heading == 'E') {
        ++pose.x;
    } else if (pose.heading == 'W') {
        --pose.x;
    } else if (pose.heading == 'N') {
        ++pose.y;
    } else if (pose.heading == 'S') {
        --pose.y;
    }
}
void ExecutorImpl::TurnLeft() noexcept
{
    if (pose.heading == 'E') {
        pose.heading = 'N';
    } else if (pose.heading == 'W') {
        pose.heading = 'S';
    } else if (pose.heading == 'S') {
        pose.heading = 'E';
    } else if (pose.heading == 'N') {
        pose.heading = 'W';
    }
}
void ExecutorImpl::TurnRight() noexcept
{
    if (pose.heading == 'E') {
        pose.heading = 'S';
    } else if (pose.heading == 'W') {
        pose.heading = 'N';
    } else if (pose.heading == 'N') {
        pose.heading = 'E';
    } else if (pose.heading == 'S') {
        pose.heading = 'W';
    }
}
}  // namespace adas
