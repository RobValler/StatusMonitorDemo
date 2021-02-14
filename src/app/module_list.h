
#pragma once

#include <memory>

class CEventManager;
class CStatusMonitor;

struct SModuleList
{
    std::shared_ptr<CStatusMonitor> m_pStatusMonitor;
    std::shared_ptr<CEventManager> m_pEventManager;
};
