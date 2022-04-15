#include <windows.h>
/*#include <windns.h>*/

__declspec(dllexport) /*PDNS_SERVICE_INSTANCE*/ void* DnsServiceConstructInstance(
    PCWSTR       pServiceName,
    PCWSTR       pHostName,
    /*PIP4_ADDRESS*/ void* pIp4,
    /*PIP6_ADDRESS*/ void* pIp6,
    WORD         wPort,
    WORD         wPriority,
    WORD         wWeight,
    DWORD        dwPropertiesCount,
    PCWSTR * keys,
    PCWSTR * values
) {
    MessageBoxA(NULL, "a", NULL, MB_OK);
    return NULL;
}

__declspec(dllexport) void DnsServiceFreeInstance(
    /*PDNS_SERVICE_INSTANCE*/ void* pInstance
) {
    MessageBoxA(NULL, "b", NULL, MB_OK);
    return;
}

__declspec(dllexport) DWORD DnsServiceRegister(
    /*PDNS_SERVICE_REGISTER_REQUEST*/ void* pRequest,
    /*PDNS_SERVICE_CANCEL*/ void* pCancel
) {
    MessageBoxA(NULL, "c", NULL, MB_OK);
    return 1;
}

__declspec(dllexport) DWORD DnsServiceDeRegister(
    /*PDNS_SERVICE_REGISTER_REQUEST*/ void* pRequest,
    /*PDNS_SERVICE_CANCEL*/ void* pCancel
) {
    MessageBoxA(NULL, "d", NULL, MB_OK);
    return 1;
}

__declspec(dllexport) DWORD DnsServiceRegisterCancel(
    /*PDNS_SERVICE_CANCEL*/ void* pCancelHandle
) {
    MessageBoxA(NULL, "e", NULL, MB_OK);
    return 1;
}