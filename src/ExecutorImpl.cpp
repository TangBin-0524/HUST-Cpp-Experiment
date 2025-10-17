#include "ExecutorImpl.hpp"

#include <new>

namespace adas
{
ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose)
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
Executor *Executor::NewExecutor(const Pose &pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}
void ExecutorImpl::Execute(const std::string &commands) noexcept
{
}
}  // namespace adas
