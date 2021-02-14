

#include "event_manager.h"

#include <vector>

#include "module_list.h"
#include "status_monitor.h"
#include "event_id.h"

std::vector<SErrorCondition> errorList = {
        {E_Temp_warning_flag},
        {E_Temp_error_flag}
};

CEventManager::CEventManager(std::shared_ptr<SModuleList> list)
    : m_pList(list)
{
    ImportErrorRules(errorList);
    RegisterStatusMonitor(list->m_pStatusMonitor);
}

