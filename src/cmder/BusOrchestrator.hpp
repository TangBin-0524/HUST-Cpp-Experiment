#pragma once

#include "NormalOrchestrator.hpp"

namespace adas
{

class BusOrchestrator : public NormalOrchestrator
{
public:
    ActionGroup Move(const PoseHandler& poseHandler) const noexcept override
    {
        ActionGroup actionGroup;

        // 快速状态下移动2格
        // 正常状态下移动1格
        if (poseHandler.IsFast()) {
            actionGroup.PushAction(GetStepAction(poseHandler));
        }
        actionGroup.PushAction(GetStepAction(poseHandler));

        return actionGroup;
    }

    ActionGroup TurnLeft(const PoseHandler& poseHandler) const noexcept override
    {
        ActionGroup actionGroup;

        // 快速状态下：前进2格→左转
        // 正常状态下：前进1格→左转
        if (poseHandler.IsFast()) {
            actionGroup.PushAction(GetStepAction(poseHandler));
        }
        actionGroup.PushAction(GetStepAction(poseHandler));
        actionGroup.PushAction(GetTurnAction(poseHandler, true));

        return actionGroup;
    }

    ActionGroup TurnRight(const PoseHandler& poseHandler) const noexcept override
    {
        ActionGroup actionGroup;

        // 快速状态下：前进2格→右转
        // 正常状态下：前进1格→右转
        if (poseHandler.IsFast()) {
            actionGroup.PushAction(GetStepAction(poseHandler));
        }
        actionGroup.PushAction(GetStepAction(poseHandler));
        actionGroup.PushAction(GetTurnAction(poseHandler, false));

        return actionGroup;
    }

private:
    ActionType GetTurnAction(const PoseHandler& poseHandler, bool isLeft) const noexcept
    {
        if (poseHandler.IsReverse()) {
            // 倒车状态下转向方向相反
            return isLeft ? ActionType::REVERSE_TURNLEFT_ACTION : ActionType::REVERSE_TURNRIGHT_ACTION;
        } else {
            return isLeft ? ActionType::TURNLEFT_ACTION : ActionType::TURNRIGHT_ACTION;
        }
    }
};

}  // namespace adas