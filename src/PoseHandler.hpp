#pragma once

#include "Executor.hpp"

namespace adas
{

class PoseHandler final
{
public:
    PoseHandler(const Pose& pose) noexcept;    // 禁止拷贝构造
    PoseHandler(const PoseHandler&) = delete;  // 禁止拷贝赋值
    PoseHandler& operator=(const PoseHandler&) = delete;

public:
    void Move(void) noexcept;          // 向前移动
    void TurnLeft(void) noexcept;      // 向左转
    void TurnRight(void) noexcept;     // 向右转
    void Fast(void) noexcept;          // 切换模式
    bool IsFast(void) const noexcept;  // 是否处于快速模式
    Pose Query(void) const noexcept;   // 查询当前位置

private:
    Pose pose;         // 当前位置
    bool fast{false};  // 是否处于快速状态
};

}  // namespace adas