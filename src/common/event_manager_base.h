

#pragma once

#include <vector>
#include <memory>

struct SErrorCondition
{
    int error_ID;
    // more to come, etc.
};

class CStatusMonitor;

class CEventManagerBase
{
public:
    CEventManagerBase()=default;
    ~CEventManagerBase()=default;

    void ImportErrorRules(std::vector<SErrorCondition> errorRules);
    void RegisterStatusMonitor(std::shared_ptr<CStatusMonitor> statusMonitor);
    bool CheckForError();

protected:
    std::vector<SErrorCondition> m_ErrorRules;
    std::shared_ptr<CStatusMonitor> m_pStatusMonitor;
};
