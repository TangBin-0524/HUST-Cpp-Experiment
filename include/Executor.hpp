#pragma once
#include <string>
namespace adas
{
/* 汽车姿态 */
struct Pose {
    int x;
    int y;
    char heading;
};

enum class ExecutorType {
    NORMAL,
    SPORTS_CAR,
    BUS,
};

/*
    驾驶动作执行器接口
*/
class Executor
{
public:
    // Caller should delete *executor when it is no longer needed.
    static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'},
                                 const ExecutorType& executorType = ExecutorType::NORMAL) noexcept;

public:
    // 默认构造函数
    Executor(void) = default;
    // 默认析构函数
    virtual ~Executor(void) = default;

    // 不允许拷贝
    Executor(const Executor&) = delete;
    // 不允许赋值
    Executor& operator=(const Executor&) = delete;

public:
    // 查询当前汽车姿态，纯虚函数，留给子类具体实现
    virtual Pose Query(void) const noexcept = 0;
    // 新增加的纯虚函数，执行一个字符串表示的指令序列，如MLMRM，留给子类ExecutorImpl去实现
    virtual void Execute(const std::string& commands) noexcept = 0;
};
}  // namespace adas