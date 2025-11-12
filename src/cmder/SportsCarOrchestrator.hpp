#pragma once

#include "NormalOrchestrator.hpp"

namespace adas
{

class SportsCarOrchestrator : public NormalOrchestrator
{
public:
    ActionGroup Move(const PoseHandler& poseHandler) const noexcept override
    {
        ActionGroup actionGroup;
        int StepCount = poseHandler.IsFast() ? 4 : 2;
        // 快速状态下移动4格
        // 正常状态下移动2格
        for (int i = 0; i < StepCount; ++i) {
            actionGroup.PushAction(GetStepAction(poseHandler));
        }

        return actionGroup;
    }

    ActionGroup TurnLeft(const PoseHandler& poseHandler) const noexcept override
    {
        ActionGroup actionGroup;

        if (poseHandler.IsFast()) {
            // 快速状态下：前进1格→左转→前进1格
            // 正常状态下：左转→前进1格
            actionGroup.PushAction(GetStepAction(poseHandler));
        }
        actionGroup.PushAction(GetTurnAction(poseHandler, true));
        actionGroup.PushAction(GetStepAction(poseHandler));

        return actionGroup;
    }

    ActionGroup TurnRight(const PoseHandler& poseHandler) const noexcept override
    {
        ActionGroup actionGroup;

        if (poseHandler.IsFast()) {
            // 快速状态下：前进1格→右转→前进1格
            // 正常状态下：右转→前进1格
            actionGroup.PushAction(GetStepAction(poseHandler));
        }
        actionGroup.PushAction(GetTurnAction(poseHandler, false));
        actionGroup.PushAction(GetStepAction(poseHandler));

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