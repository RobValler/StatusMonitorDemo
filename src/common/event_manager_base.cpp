


#include "event_manager_base.h"

#include "status_monitor.h"

void CEventManagerBase::ImportErrorRules(std::vector<SErrorCondition> errorRules)
{
    // This function may be more complex if the import source is a differenct format.

    m_ErrorRules = errorRules;
}

int CEventManagerBase::CheckForError()
{
    int system_error = ESystemErrorIDList::E_NONE;

    // run through the error list one at a time.
    // check if an entry in the error list matches the StatusMonitor list.
    // if there is a match, throw an error.
    // if there is one or more matches, return false
    for(const auto& it: m_ErrorRules)
    {
        if( m_pStatusMonitor->GetEvent(it.error_ID) ){

            // only increment the system error code if the new code is higher
            if(system_error < it.system_error_ID)
                system_error = it.system_error_ID;
        }
    }

    return system_error;
}
