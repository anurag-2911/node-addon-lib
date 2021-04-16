#include <napi.h>
#include "lib/helloworldexample.h"
#include "lib/windows/registry/commonregistryoperation.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  helloworldexample::Init(env, exports);
  return windowsRegistryOperations::Init(env,exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
