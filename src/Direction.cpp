#include "Direction.hpp"

namespace adas
{

// 4种方向
static const Direction directions[4] = {{0, 'E'}, {1, 'S'}, {2, 'W'}, {3, 'N'}};

// 4种前进坐标
static const Point points[4] = {
    {1, 0},   // E
    {0, -1},  // S
    {-1, 0},  // W
    {0, 1}    // N
};

const Direction& Direction::GetDirection(const char heading) noexcept
{
    for (const auto& dir : directions) {
        if (dir.heading == heading) {
            return dir;
        }
    }
    return directions[3];  // 默认返回北方向
}

Direction::Direction(const unsigned index, const char heading) noexcept : index(index), heading(heading)
{
}

const Point& Direction::Move() const noexcept
{
    return points[index];
}

const Direction& Direction::LeftOne() const noexcept
{
    unsigned newIndex = (index + 3) % 4;  // 左转相当于索引减1，用模运算处理循环
    return directions[newIndex];
}

const Direction& Direction::RightOne() const noexcept
{
    unsigned newIndex = (index + 1) % 4;  // 右转相当于索引加1，用模运算处理循环
    return directions[newIndex];
}

const char Direction::GetHeading() const noexcept
{
    return heading;
}

}  // namespace adas