#pragma once
#include "ExecutorImpl.hpp"

namespace adas{

class ICommand
{
public:
    // 纯虚函数DoOperate留给子类去实现
    virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
    virtual ~ICommand() noexcept = default;
};
class MoveCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.isFast())
            executor.Move();
        executor.Move();
    }
};
class TurnLeftCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.isFast())
            executor.Move();
        executor.TurnLeft();
    }
};
class TurnRightCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.isFast())
            executor.Move();
        executor.TurnRight();
    }
};
class FastCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        executor.Fast();
    }
};
}