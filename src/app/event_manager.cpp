

#include "event_manager.h"

#include <vector>

#include "module_list.h"
#include "status_monitor.h"
#include "event_id.h"

// The event list.
// can be hard-coded or imported from a text file using a parameter handler, etc.
static std::vector<SErrorCondition> errorList = {
        {E_Temp_warning_flag,   E_MEDIUM},
        {E_Temp_error_flag,     E_HIGH}
};

CEventManager::CEventManager(std::shared_ptr<SModuleList> list)
    : m_pList(list)
{
    ImportErrorRules(errorList);
    m_pStatusMonitor = list->m_pStatusMonitor;
}

