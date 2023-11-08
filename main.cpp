#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <iphlpapi.h>
// #pragma comment(lib, "iphlpapi.lib")

using namespace std;

//---------------------------------------LOG---------------------------------------------------------
class logger
{
private:
    // vector<int> log;
    // int interval = 1000;

public:
    string getMAC() // To get MAC address in Windows OS
    {
        IP_ADAPTER_INFO *AdapterInfo;
        DWORD dwBufLen = sizeof(IP_ADAPTER_INFO);
        AdapterInfo = (IP_ADAPTER_INFO *)malloc(sizeof(IP_ADAPTER_INFO));
        if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == ERROR_BUFFER_OVERFLOW)
        {
            AdapterInfo = (IP_ADAPTER_INFO *)malloc(dwBufLen);
            if (AdapterInfo == NULL)
            {
                cout << "ERROR!";
                return "";
            }
        }
        if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == NO_ERROR)
        {
            PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;
            do
            {
                char macAddress[18];
                sprintf(macAddress, "%02x:%02x:%02x:%02x:%02x:%02x",
                        pAdapterInfo->Address[0],
                        pAdapterInfo->Address[1],
                        pAdapterInfo->Address[2],
                        pAdapterInfo->Address[3],
                        pAdapterInfo->Address[4],
                        pAdapterInfo->Address[5]);
                string MACaddressString(macAddress);
                free(AdapterInfo);
                return MACaddressString;
            } while (pAdapterInfo != NULL);
        }
        free(AdapterInfo);
        return "";
    }

    bool CheckWebBrowser()
    {
        vector<string> window_classes = {
            "Chrome_WidgetWin_1",
            "MozillaWindowClass",
            "Windows.UI.Core.CoreWindow"};
        for (const string &window_class : window_classes)
        {
            if (FindWindow(window_class.c_str(), NULL) != NULL)
            {
                cout << "\nyes\n";
                return true;
            }
        }
        cout << "\nno\n";
        return false;
    }

    // void Status() // To get the active pid
    // {
    //     DWORD aProcesses[1024], cbNeeded, cProcesses;
    //     if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
    //     {
    //         return;
    //     }
    //     cProcesses = cbNeeded / sizeof(DWORD);
    //     std::cout << "Process IDs:" << std::endl;
    //     for (unsigned int i = 0; i < cProcesses; i++)
    //     {
    //         if (aProcesses[i] != 0)
    //         {
    //             std::cout << aProcesses[i] << std::endl;
    //         }
    //     }
    // }
};

//---------------------------------------Executor---------------------------------------------------------
class executor
{
private:
    string command;

public:
};

//---------------------------------------Controller---------------------------------------------------------
class controller
{
private:
public:
};

int main()
{
    string ans;
    logger log;
    ans = log.getMAC();
    cout << ans << endl;
    // bool it = log.CheckWebBrowser();
    // log.Status();
    return 0;
}
