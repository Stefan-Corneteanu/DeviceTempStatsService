
package devicetempstats.service.api;

@VintfStability
interface IDeviceTempStatsService {

    float getCpuTemperature();
    float getGpuTemperature();
    float getAmbientTemperature();

    float getAverageCpuTemperature();
    float getAverageGpuTemperature();
    float getAverageAmbientTemperature();

    float getMaxCpuTemperature();
    float getMaxGpuTemperature();
    float getMaxAmbientTemperature();
}
