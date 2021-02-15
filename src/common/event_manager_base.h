

#pragma once

#include <vector>
#include <memory>



enum ESystemErrorIDList : int
{
    E_NONE = 0,
    E_LOW,
    E_MEDIUM,
    E_HIGH
};


struct SErrorCondition
{
    int error_ID;
    int system_error_ID;
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
    int CheckForError();

protected:
    std::vector<SErrorCondition> m_ErrorRules;
    std::shared_ptr<CStatusMonitor> m_pStatusMonitor;
};
