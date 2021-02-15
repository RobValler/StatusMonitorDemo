

#pragma once

#include <vector>
#include <memory>


// system error codes
enum ESystemErrorIDList : int
{
    E_NONE = 0,
    E_LOW,
    E_MEDIUM,
    E_HIGH
};

// Event table structure
struct SErrorCondition
{
    int error_ID;
    int system_error_ID;
    // etc.
};

class CStatusMonitor;

class CEventManagerBase
{
public:
    CEventManagerBase()=default;
    ~CEventManagerBase()=default;

    void ImportErrorRules(std::vector<SErrorCondition> errorRules);
    int CheckForError();

protected:
    std::vector<SErrorCondition> m_ErrorRules;
    std::shared_ptr<CStatusMonitor> m_pStatusMonitor;
};
