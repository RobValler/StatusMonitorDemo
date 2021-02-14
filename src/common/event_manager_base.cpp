


#include "event_manager_base.h"

#include "status_monitor.h"

void CEventManagerBase::ImportErrorRules(std::vector<SErrorCondition> errorRules)
{
    m_ErrorRules = errorRules;
}

void CEventManagerBase::RegisterStatusMonitor(std::shared_ptr<CStatusMonitor> statusMonitor)
{
    m_pStatusMonitor = statusMonitor;
}

bool CEventManagerBase::CheckForError()
{
    bool system_error = false;

    // run through the error list one at a time.
    // check if an entry in the error list matches the StatusMonitor list.
    // if there is a match, throw an error.
    // if there is one or more matches, return false
    for(const auto& it: m_ErrorRules)
    {
        if( m_pStatusMonitor->GetEvent(it.error_ID) )
            system_error = true;
    }

    return system_error;
}
