

#include "test_control_app.h"
#include "status_monitor.h"
#include "event_manager.h"
#include "event_id.h"

#include <iostream>

CTestControlApp::CTestControlApp()
{
    m_pModuleList = std::make_shared<SModuleList>();
    m_pModuleList->m_pStatusMonitor = std::make_shared<CStatusMonitor>();
    m_pModuleList->m_pEventManager = std::make_shared<CEventManager>(m_pModuleList);
}

void CTestControlApp::interface_1(int data)
{
    if(data == -1)
        m_pModuleList->m_pStatusMonitor->SetEvent(EEventIDList::E_Temp_warning_flag);
}

void CTestControlApp::interface_2(int data)
{
    if(data == -1)
        m_pModuleList->m_pStatusMonitor->SetEvent(EEventIDList::E_Temp_error_flag);
}

void CTestControlApp::Process()
{
    // check if there is a system error
    // false means no error
    int result = m_pModuleList->m_pEventManager->CheckForError();

    switch(result)
    {
        case ESystemErrorIDList::E_LOW:
            std::cout << "LOW ERROR" << std::endl;
            break;
        case ESystemErrorIDList::E_MEDIUM:
            std::cout << "MEDIUM ERROR" << std::endl;
            break;
        case ESystemErrorIDList::E_HIGH:
            std::cout << "HIGH ERROR" << std::endl;
            break;
        case ESystemErrorIDList::E_NONE:
        default:
            std::cout << "NO ERROR" << std::endl;
            break;
    }

}
