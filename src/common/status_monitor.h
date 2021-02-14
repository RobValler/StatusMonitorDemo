

#pragma once

#include <vector>

class CStatusMonitor
{
public:
    CStatusMonitor()=default;
    bool SetEvent(const int ID);
    bool GetEvent(const int ID);
    void ClearAll();

private:
    std::vector<int> m_EventTable;

};




