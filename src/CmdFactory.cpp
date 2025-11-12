#include "CmderFactory.hpp"

namespace adas
{

std::list<std::function<void(PoseHandler& poseHandler)>> CmderFactory::GetCmders(
    const std::string& commands) const noexcept
{
    std::list<std::function<void(PoseHandler & poseHandler)>> cmdList;

    for (char cmdChar : commands) {
        auto it = cmderMap.find(cmdChar);
        if (it != cmderMap.end()) {
            cmdList.push_back(it->second);
        }
        // 如果字符不在映射中，这里选择静默忽略
        // 可以根据需求改为抛出异常或其他处理方式
    }

    return cmdList;
}

}  // namespace adas