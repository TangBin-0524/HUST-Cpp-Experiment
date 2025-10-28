#pragma once
#include "PoseHandler.hpp"

namespace adas
{

// class ICommand
// {
// public:
//     // 纯虚函数DoOperate留给子类去实现
//     virtual void DoOperate(PoseHandler& posehandler) const noexcept = 0;
//     virtual ~ICommand() noexcept = default;
// };
class MoveCommand final// : public ICommand
{
public:
    void operator()(PoseHandler& posehandler)const noexcept{
        if (posehandler.IsFast())
            posehandler.Move();
        posehandler.Move();
    }
};
class TurnLeftCommand final// : public ICommand
{
public:
    void operator()(PoseHandler& posehandler) const noexcept
    {
        if (posehandler.IsFast())
            posehandler.Move();
        posehandler.TurnLeft();
    }
};
class TurnRightCommand final// : public ICommand
{
public:
    void operator()(PoseHandler& posehandler) const noexcept
    {
        if (posehandler.IsFast())
            posehandler.Move();
        posehandler.TurnRight();
    }
};
class FastCommand final// : public ICommand
{
public:
    void operator()(PoseHandler& posehandler) const noexcept
    {
        posehandler.Fast();
    }
};
}  // namespace adas