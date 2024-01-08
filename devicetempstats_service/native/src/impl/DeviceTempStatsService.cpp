#include "DeviceTempStatsService.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utils/Log.h>
#ifdef LOG_TAG
    #undef LOG_TAG
#endif
#define LOG_TAG "DeviceTempStatsService"

::std::ifstream fin("../../../temperature_file.csv");

namespace devicetempstats{
    namespace service{

        DeviceTempStatsService::DeviceTempStatsService(){
            //initialize temperature values vectors
            cpu_temperature_values = new vector<float>();
            gpu_temperature_values = new vector<float>();
            ambient_temperature_values = new vector<float>();

            //discard the headers of the .csv file
            ::std::string header_line;
            getline(fin,header_line);

            //get temperature values from .csv file
            while (!fin.eof()){
                ::std::string csv_values_line;
                getline(fin, csv_values_line);
                ::std::stringstream csv_values(csv_values_line);
                ::std::string value;
                int i = 0;
                while (getline(csv_values,value,", ")){
                    switch (i){
                        case 0: ambient_temperature_values.push_back(::std::stof(value)) break;
                        case 1: cpu_temperature_values.push_back(::std::stof(value)) break;
                        case 2: gpu_temperature_values.push_back(::std::stof(value)) break;
                        default: ALOGE("%s: %d: error in implementing function to get temperature values", __FUNCTION__, __LINE__);
                    }
                    i++;
                }
            }
        }
        
        DeviceTempStatsService::~DeviceTempStatsService(){

        }

        ::std::shared_ptr<DeviceTempStatsService> DeviceTempStatsService::getInstance(){

            if (dts_instance == NULL){
                dts_instance = ndk::SharedRefBase::make<DeviceTempStatsService>();
            }

            return dts_instance;
        }
        
        ndk::ScopedAStatus DeviceTempStatsService::getCpuTemperature(float* _aidl_return){
            
            static int i = 0;
            _aidl_return = cpu_temperature_values[i];
            
            //mock register next value by incrementing vector index
            //make sure to not go out of range!
            if (i < 2)
                i++;
            return ndk::ScopedAStatus::ok();
        }

        ndk::ScopedAStatus DeviceTempStatsService::getGpuTemperature(float* _aidl_return){

            static int i = 0;
            _aidl_return = gpu_temperature_values[i];
            
            //mock register next value by incrementing vector index
            //make sure to not go out of range!
            if (i < 2)
                i++;
            return ndk::ScopedAStatus::ok();
        }

        ndk::ScopedAStatus DeviceTempStatsService::getAmbientTemperature(float* _aidl_return){

            static int i = 0;
            _aidl_return = ambient_temperature_values[i];
            
            //mock register next value by incrementing vector index
            //make sure to not go out of range!
            if (i < 2)
                i++;
            return ndk::ScopedAStatus::ok();
        }

        ndk::ScopedAStatus DeviceTempStatsService::getAverageCpuTemperature(float* _aidl_return){

            static int i = 0;
            _aidl_return = ::std::accumulate(cpu_temperature_values,cpu_temperature_values + (i+1), 0.0f)/(i+1);
            
            //mock register next value by incrementing vector index
            //make sure to not go out of range!
            if (i < 2)
                i++;
            return ndk::ScopedAStatus::ok();
        }

        ndk::ScopedAStatus DeviceTempStatsService::getAverageGpuTemperature(float* _aidl_return){

            static int i = 0
            _aidl_return = ::std::accumulate(gpu_temperature_values,gpu_temperature_values + (i+1), 0.0f)/(i+1);
            
            //mock register next value by incrementing vector index
            //make sure to not go out of range!
            if (i < 2)
                i++;
            return ndk::ScopedAStatus::ok();
        }

        ndk::ScopedAStatus DeviceTempStatsService::getAverageAmbientTemperature(float* _aidl_return){

            static int i = 0;
            _aidl_return = ::std::accumulate(ambient_temperature_values,ambient_temperature_values + (i+1), 0.0f)/(i+1);
            
            //mock register next value by incrementing vector index
            //make sure to not go out of range!
            if (i < 2)
                i++;
            return ndk::ScopedAStatus::ok();
        }

        ndk::ScopedAStatus DeviceTempStatsService::getMaxCpuTemperature(float* _aidl_return){

            static int i = 0;
            _aidl_return = ::std::max_element(cpu_temperature_values,cpu_temperature_values + (i+1));
            
            //mock register next value by incrementing vector index
            //make sure to not go out of range!
            if (i < 2)
                i++;
            return ndk::ScopedAStatus::ok();
        }

        ndk::ScopedAStatus DeviceTempStatsService::getMaxGpuTemperature(float* _aidl_return){

            static int i = 0;
            _aidl_return = ::std::max_element(gpu_temperature_values,gpu_temperature_values + (i+1));
            
            //mock register next value by incrementing vector index
            //make sure to not go out of range!
            if (i < 2)
                i++;
            return ndk::ScopedAStatus::ok();
        }

        ndk::ScopedAStatus DeviceTempStatsService::getMaxAmbientTemperature(float* _aidl_return){

            static int i = 0;
            _aidl_return = ::std::max_element(ambient_temperature_values,ambient_temperature_values + (i+1));
            
            //mock register next value by incrementing vector index
            //make sure to not go out of range!
            if (i < 2)
                i++;
            return ndk::ScopedAStatus::ok();           
        }
    }
}