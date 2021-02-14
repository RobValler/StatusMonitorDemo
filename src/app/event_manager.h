
#pragma once

#include <memory>
#include "event_manager_base.h"

class SModuleList;

class CEventManager: public CEventManagerBase
{
public:
    CEventManager(std::shared_ptr<SModuleList> list);

public:
    std::shared_ptr<SModuleList> m_pList;

};
