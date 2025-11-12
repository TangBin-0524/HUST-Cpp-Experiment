#pragma once
#include <functional>

#include "../core/PoseHandler.hpp"
#include "CmderOrchestrator.hpp"

namespace adas
{

class MoveCommand final
{
public:
    ActionGroup operator()(PoseHandler& posehandler, const CmderOrchestrator& orchestrator) const noexcept
    {
        return orchestrator.Move(posehandler);
    }
};

class TurnLeftCommand final
{
public:
    ActionGroup operator()(PoseHandler& posehandler, const CmderOrchestrator& orchestrator) const noexcept
    {
        return orchestrator.TurnLeft(posehandler);
    }
};

class TurnRightCommand final
{
public:
    ActionGroup operator()(PoseHandler& posehandler, const CmderOrchestrator& orchestrator) const noexcept
    {
        return orchestrator.TurnRight(posehandler);
    }
};

class FastCommand final
{
public:
    ActionGroup operator()(PoseHandler& posehandler, const CmderOrchestrator& orchestrator) const noexcept
    {
        return ActionGroup({ActionType::BE_FAST_ACTION});
    }
};

class ReverseCommand final
{
public:
    ActionGroup operator()(PoseHandler& posehandler, const CmderOrchestrator& orchestrator) const noexcept
    {
        return ActionGroup({ActionType::BE_REVERSE_ACTION});
    }
};
class TurnRoundCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler, const CmderOrchestrator& orchestrator) const noexcept
    {
        return orchestrator.TurnRound(poseHandler);
    }
};
}  // namespace adas