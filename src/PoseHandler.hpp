#pragma once

#include "Direction.hpp"
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
    void Forward(void) noexcept;   // 向前移动
    void Backward(void) noexcept;  // 向后移动

    void TurnLeft(void) noexcept;   // 向左转
    void TurnRight(void) noexcept;  // 向右转

    void Fast(void) noexcept;     // 加速模式
    void Reverse(void) noexcept;  // 倒车模式

    bool IsFast(void) const noexcept;     // 是否处于快速模式
    bool IsReverse(void) const noexcept;  // 是否处于倒车模式

    Pose Query(void) const noexcept;  // 查询当前位置

private:
    Point point;              // 当前坐标
    const Direction* facing;  // 当前朝向
    bool fast{false};         // 是否处于快速状态
    bool reverse{false};      // 是否处于倒车状态
};

}  // namespace adas