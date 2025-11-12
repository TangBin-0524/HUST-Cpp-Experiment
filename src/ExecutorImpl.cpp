#include "ExecutorImpl.hpp"

#include <algorithm>
#include <functional>

#include "cmder/BusOrchestrator.hpp"
#include "cmder/CmderFactory.hpp"
#include "cmder/NormalOrchestrator.hpp"
#include "cmder/SportsCarOrchestrator.hpp"
#include "core/Singleton.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose, const ExecutorType executorType) noexcept
{
    CmderOrchestrator* orchestrator = nullptr;
    switch (executorType) {
    case ExecutorType::NORMAL: {
        orchestrator = new (std::nothrow) NormalOrchestrator();
        break;
    }
    case ExecutorType::SPORTS_CAR: {
        orchestrator = new (std::nothrow) SportsCarOrchestrator();
        break;
    }
    case ExecutorType::BUS: {
        orchestrator = new (std::nothrow) BusOrchestrator();
        break;
    }
    }

    return new (std::nothrow) ExecutorImpl(pose, orchestrator);
}

ExecutorImpl::ExecutorImpl(const Pose& pose, CmderOrchestrator* orchestrator) noexcept
    : posehandler(pose), orchestrator(orchestrator)
{
}

Pose ExecutorImpl::Query(void) const noexcept
{
    return posehandler.Query();
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
    std::for_each(cmders.begin(), cmders.end(),
                  [this](const Cmder& cmder) noexcept { cmder(posehandler, *orchestrator).DoOperate(posehandler); });
}
}  // namespace adas
