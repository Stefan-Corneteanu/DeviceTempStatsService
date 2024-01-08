#ifndef DEVICETEMPSTATSSERVICE
#define DEVICETEMPSTATSSERVICE

#include <aidl/devicetempstats/service/api/BnDeviceTempStatsServiceInterface>

namespace dts_api_ns = ::aidl::devicetempstats::service::api;
namespace devicetempstats{
    namespace service{
        class DeviceTempStatsService : public ::dts_api_ns::BnDeviceTempStatsServiceInterface
        {
        
        public:
            DeviceTempStatsService();
            ~DeviceTempStatsService();
            ::std::shared_ptr<BnDeviceTempStatsServiceInterface> getInstance();
            const ::std::string getServiceName(void){
                return ::std::string() + descriptor + "/default";
            }

            //interface callbacks
            ndk::ScopedAStatus getCpuTemperature(float* _aidl_return) final;
            ndk::ScopedAStatus getGpuTemperature(float* _aidl_return) final;
            ndk::ScopedAStatus getAmbientTemperature(float* _aidl_return) final;

            ndk::ScopedAStatus getAverageCpuTemperature(float* _aidl_return) final;
            ndk::ScopedAStatus getAverageGpuTemperature(float* _aidl_return) final;
            ndk::ScopedAStatus getAverageAmbientTemperature(float* _aidl_return) final;
            
            ndk::ScopedAStatus getMaxCpuTemperature(float* _aidl_return) final;
            ndk::ScopedAStatus getMaxGpuTemperature(float* _aidl_return) final;
            ndk::ScopedAStatus getMaxAmbientTemperature(float* _aidl_return) final;


        private:
            static ::std::shared_ptr<DeviceTempStatsService> dts_instance;
            ::std::vector<float> cpu_temperature_values;
            ::std::vector<float> gpu_temperature_values;
            ::std::vector<float> ambient_temperature_values;
        };
        
    }
}

#endif