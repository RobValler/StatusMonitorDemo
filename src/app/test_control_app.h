
#pragma once

#include "module_list.h"

class CEventManager;
class CStatusMonitor;

class CTestControlApp
{
public:
    CTestControlApp();
    void interface_1(int data);
    void interface_2(int data);
    void Process();

private:
    std::shared_ptr<SModuleList> m_pModuleList;

};



