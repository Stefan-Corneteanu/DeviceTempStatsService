#include "DeviceTempStatsService.hpp"
#include <utils/Log.h>
#include <signal.h>
#include <android/binder_ibinder.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>

#ifdef LOG_TAG
    #undef LOG_TAG
#endif
#define LOG_TAG "DeviceTempStatsService"

namespace dts_ns = devicetempstats::service;

int main(){

    ALOGI("%s: %d: starting service", __FUNCTION__, __LINE__);
    signal(SIGPIPE, SIG_IGN);

    if (ABinderProcess_setThreadPoolMaxThreadCount(1)){
        
        std::shared_ptr<dts_ns::DeviceTempStatsSystemService>dts_obj = dts_ns::DeviceTempStatsService.getInstance();
        
        if (dts_obj){
            binder_status_t status = AServiceManager_addService(dts_obj->asBinder().get(), dts_obj->getServiceName().c_str());
            
            if (status == STATUS.OK){
                int32_t version = -1;
                dts_obj->getInterfaceVersion(&version);
                ALOGI("%s: %d: service ready (registered version V%d)", __FUNCTION__, __LINE__, version);
                ABinderprocess_joinThreadPool();
                ALOGW("%s: %d: service joined", __FUNCTION__, __LINE__);
            }
            else{
                ALOGE("%s: %d: adding service failed", __FUNCTION__, __LINE__);
            }
        }
        else{
                ALOGE("%s: %d: service NULL", __FUNCTION__, __LINE__);
        }
    }
    else{
        ALOGE("%s: %d: configure thread-pool failed", __FUNCTION__, __LINE__);
    }

    return 0;
}