#pragma once

#include <memory>
#include <string>

#include "Executor.hpp"
#include "cmder/CmderOrchestrator.hpp"

namespace adas
{
/*
    Executor的具体实现
*/
class ExecutorImpl final : public Executor
{
public:
    // 构造函数
    explicit ExecutorImpl(const Pose& pose,CmderOrchestrator* orchestrator) noexcept;
    // 默认析构函数
    ~ExecutorImpl() noexcept = default;

    // 不能拷贝
    ExecutorImpl(const ExecutorImpl&) = delete;
    // 不能赋值
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

public:
    // 查询当前汽车姿态，是父类抽象方法Query的具体实现
    Pose Query(void) const noexcept override;
    // 第二阶段新增的纯虚函数，执行一个用字符串表示的命令
    void Execute(const std::string& commands) noexcept override;

private:
    PoseHandler posehandler;  // 状态管理类
    //ExecutorType executorType;
    std::unique_ptr<CmderOrchestrator> orchestrator;
};
}  // namespace adas