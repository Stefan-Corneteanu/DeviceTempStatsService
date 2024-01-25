
package devicetempstats.service.api;

@VintfStability
interface IDeviceTempStatsService {

    void basicTypes(int anInt, long aLong, boolean aBoolean, float aFloat, double aDouble, String aString);

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