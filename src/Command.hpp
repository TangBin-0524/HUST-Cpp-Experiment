#pragma once
#include <functional>

#include "ActionGroup.hpp"
#include "PoseHandler.hpp"

namespace adas
{

class MoveCommand final
{
public:
    ActionGroup operator()(PoseHandler& posehandler) const noexcept
    {
        ActionGroup actionGroup;
        const auto action =
            posehandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;

        if (posehandler.IsFast()) {
            actionGroup.PushAction(action);
        }

        actionGroup.PushAction(action);
        return actionGroup;
    }
};

class TurnLeftCommand final
{
public:
    ActionGroup operator()(PoseHandler& posehandler) const noexcept
    {
        ActionGroup actionGroup;

        if (posehandler.IsFast()) {
            const auto moveAction =
                posehandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(moveAction);
        }

        const auto turnAction =
            posehandler.IsReverse() ? ActionType::REVERSE_TURNLEFT_ACTION : ActionType::TURNLEFT_ACTION;
        actionGroup.PushAction(turnAction);

        return actionGroup;
    }
};

class TurnRightCommand final
{
public:
    ActionGroup operator()(PoseHandler& posehandler) const noexcept
    {
        ActionGroup actionGroup;

        if (posehandler.IsFast()) {
            const auto moveAction =
                posehandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(moveAction);
        }

        const auto turnAction =
            posehandler.IsReverse() ? ActionType::REVERSE_TURNRIGHT_ACTION : ActionType::TURNRIGHT_ACTION;
        actionGroup.PushAction(turnAction);

        return actionGroup;
    }
};

class FastCommand final
{
public:
    ActionGroup operator()(PoseHandler& posehandler) const noexcept
    {
        ActionGroup actionGroup;
        actionGroup.PushAction(ActionType::BE_FAST_ACTION);
        return actionGroup;
    }
};

class ReverseCommand final
{
public:
    ActionGroup operator()(PoseHandler& posehandler) const noexcept
    {
        ActionGroup actionGroup;
        actionGroup.PushAction(ActionType::BE_REVERSE_ACTION);
        return actionGroup;
    }
};
class TurnRoundCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        // 如果是倒车状态
        if (poseHandler.IsReverse()) {
            return ActionGroup();  // 在倒车状态下，什么都不做
        } else {
            if (poseHandler.IsFast()) {
                return ActionGroup({
                    // 在F状态下，TR指令需要四个原子Action
                    ActionType::FORWARD_1_STEP_ACTION,  // 向前一步
                    ActionType::TURNLEFT_ACTION,        // 左转
                    ActionType::FORWARD_1_STEP_ACTION,  // 向前一步
                    ActionType::TURNLEFT_ACTION,        // 左转
                });
            } else {
                // 正常状态
                return ActionGroup({
                    // 在正常状态下，TR指令需要三个原子Action
                    ActionType::TURNLEFT_ACTION,        // 左转
                    ActionType::FORWARD_1_STEP_ACTION,  // 向前一步
                    ActionType::TURNLEFT_ACTION,        // 左转
                });
            }
        }
    }
};
}  // namespace adas