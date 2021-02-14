

#include "status_monitor.h"



bool CStatusMonitor::SetEvent(const int ID)
{
    m_EventTable.emplace_back(ID);
    return true;
}

bool CStatusMonitor::GetEvent(const int ID)
{
    bool result = false;
    for(const auto& it : m_EventTable)
    {
        if(ID == it) {
            result = true;
            break;
        }
    }
    return result;
}

void CStatusMonitor::ClearAll()
{
    m_EventTable.empty();
}
