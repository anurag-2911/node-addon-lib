#include "commonregistryoperation.h"
#include <Windows.h>
#include <winnt.h>
#include <winreg.h>
#include<iostream>

bool windowsRegistryOperations::setzappLaunchedRegistryKey(){

    HKEY hKey;
    bool keywritten=true;
    LONG openRes = RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Microfocus\\zapp"), 0, KEY_ALL_ACCESS , &hKey);

    if (openRes==ERROR_SUCCESS) {
        
    } else {
       keywritten=false;
    }

    LPCTSTR data = TEXT("true");

    LONG setRes = RegSetValueEx(hKey, TEXT("launchCompleted"), 0, REG_SZ, (LPBYTE)data, strlen(data)+1);

    if (setRes == ERROR_SUCCESS) {
        
    } else {
        keywritten=false;
    }

    LONG closeOut = RegCloseKey(hKey);

    if (closeOut == ERROR_SUCCESS) {
       
    } else {
     keywritten=false;
    }

    return keywritten;
    
}

std::wstring toWide(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

Napi::Boolean windowsRegistryOperations::setHKCURegistryKeyWrapper(const Napi::CallbackInfo& info){

    Napi::Env env = info.Env();
    Napi::String subkey = info[0].As<Napi::String>();
    Napi::String value = info[1].As<Napi::String>();
    
    Napi::Boolean returnValue = Napi::Boolean::New(env, windowsRegistryOperations::setzappLaunchedRegistryKey());

    return returnValue;

}

Napi::Object windowsRegistryOperations::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("setzappLaunchedRegistryKey", Napi::Function::New(env, windowsRegistryOperations::setHKCURegistryKeyWrapper));
    return exports;
}


