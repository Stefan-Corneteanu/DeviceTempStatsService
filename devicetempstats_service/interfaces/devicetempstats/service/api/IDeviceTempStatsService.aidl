// IDeviceTempStatsService.aidl
package devicetempstats.service.api;

// Declare any non-default types here with import statements

@VintfStability
interface IDeviceTempStatsService {
    /**
     * Demonstrates some basic types that you can use as parameters
     * and return values in AIDL.
     */
    void basicTypes(int anInt, long aLong, boolean aBoolean, float aFloat,
            double aDouble, String aString);

    float getCpuTemperature();
    float getGpuTemperature();
    float getAmbientTemperature();

    float getAverageCpuTemperature();
    float getAverageGpuTemperature();
    float getAverageAmbientTemperature();

    float getMaxCpuTemperature();
    float getMaxGpuTemperature();
    float getMaxAmbientTemperature()
}