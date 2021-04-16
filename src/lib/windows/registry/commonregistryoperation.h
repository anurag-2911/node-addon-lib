#include <napi.h>
#include <Windows.h>

namespace windowsRegistryOperations {

    bool setzappLaunchedRegistryKey();
    Napi::Boolean setHKCURegistryKeyWrapper(const Napi::CallbackInfo& info);

    Napi::Object Init(Napi::Env env, Napi::Object exports);
    
}

