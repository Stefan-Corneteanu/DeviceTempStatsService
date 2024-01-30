# DeviceTempStatsService
An Android Binder Native service that simulates obtaining temperature data from CPU, GPU and ambient (actually reading data from a .csv file) and returning the current, average and maximum value registered for each of them.

# Prerequisites
Before using this service, an AOSP source must be synced on the user's computer (possible only on Ubuntu OS). The following steps must be followed:
1) Install the prerequisite packages depending on the version of Ubuntu of the user (as provided in Google's official documentation at https://source.android.com/docs/setup/start/initializing)
2) Install repo
```shell
sudo apt-get update
sudo apt-get install repo
```
If this method fails, there is an alternative method
```shell
curl https://storage.googleapis.com/git-repo-downloads/repo > ~/yourfolder/repo
chmod a+x ~/yourfolder/repo
```
3) Initialize repo and sync an Android source (I used Android 14 for Raspberry PI found at https://github.com/android-rpi/local_manifests)
```shell
repo init -u https://android.googlesource.com/platform/manifest -b android-14.0.0_r17
git clone https://github.com/android-rpi/local_manifests .repo/local_manifests -b arpi-14
repo sync -j $(nproc --all)
```
Note: sync command took me around 5 hours to finish

# Usage
1) With the AOSP source checked out, clone the repository into a folder under device
2) Include the makefile changes_stefan.mk in the makefile of the intended target (for instance, my target was sdk_car_x86_64, whose .mk is found at device/generic/car)
```shell
include device/[your_folder_name]/changes_stefan.mk
```
3) Build your target device (mine was sdk_car_x86_64-eng)
```shell
source build/envsetup.sh
lunch sdk_car_x86_64-eng
make -j $(nproc --all)
```
(m -j $(nproc --all) is an alternative for the make command)

Note: this may take some time, around 1 hour 15 minutes if this is the first build, following builds take less

# Testing (build successful required)
1) Open 2 terminals (reffered here as T1 and T2)
2) In T1 run the emulator
```shell
emulator -no-snapshot-load
```
Note: there should not be any issue with the SEPolicy, running the emulator with "-selinux permissive" shouldn't be necessary

3) Once the emulator started, in T2 run the following command
```shell
adb logcat | grep -i devicetempstats
```
If a message saying "service ready (registered version V2)" appears then the service is functional

# Known issues
1) The temperature_file.csv was not properly included in the build after make command is run, therefore the service will not be able to instantiate as it has an input file stream to a non-existent file.
Note: the service functionality was tested by replacing the input file stream with an input string stream built using as a parameter the .csv file's contents as a hardcoded string
