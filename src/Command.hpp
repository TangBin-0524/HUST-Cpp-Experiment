#pragma once
#include "PoseHandler.hpp"

namespace adas
{

class MoveCommand final
{
public:
    void operator()(PoseHandler& posehandler) const noexcept
    {
        if (posehandler.IsFast()) {
            if (posehandler.IsReverse()) {
                posehandler.Backward();
            } else {
                posehandler.Forward();
            }
        }
        if (posehandler.IsReverse()) {
            posehandler.Backward();
        } else {
            posehandler.Forward();
        }
    }
};
class TurnLeftCommand final
{
public:
    void operator()(PoseHandler& posehandler) const noexcept
    {
        if (posehandler.IsFast()) {
            if (posehandler.IsReverse()) {
                posehandler.Backward();
            } else {
                posehandler.Forward();
            }
        }
        if (posehandler.IsReverse()) {
            posehandler.TurnRight();
        } else {
            posehandler.TurnLeft();
        }
    }
};
class TurnRightCommand final
{
public:
    void operator()(PoseHandler& posehandler) const noexcept
    {
        if (posehandler.IsFast()) {
            if (posehandler.IsReverse()) {
                posehandler.Backward();
            } else {
                posehandler.Forward();
            }
        }
        if (posehandler.IsReverse()) {
            posehandler.TurnLeft();
        } else {
            posehandler.TurnRight();
        }
    }
};
class FastCommand final
{
public:
    void operator()(PoseHandler& posehandler) const noexcept
    {
        posehandler.Fast();
    }
};
class ReverseCommand final
{
public:
    void operator()(PoseHandler& posehandler) const noexcept
    {
        posehandler.Reverse();
    }
};
}  // namespace adas