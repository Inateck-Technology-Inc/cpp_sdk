#include <iostream>
#include "inateck_scanner_ble_cpp.h"
#include <sstream>
#include <vector>

#ifdef _WIN32
#include <windows.h> // for Sleep function
#else
#include <unistd.h>
#endif

// latest lib version:
// https://github.com/Inateck-Technology-Inc/scanner_lib

void scan_callback(const char *msg)
{
    std::cout << msg << std::endl;
    return;
}

void code_callback(const char *msg)
{
    std::cout << msg << std::endl;
    return;
}

void connect(const char *device_id)
{
    const char *result = inateck_scanner_ble_connect(device_id);
    std::cout << "result: " << result << std::endl;
    result = inateck_scanner_ble_check_communication(device_id);
    std::cout << "result: " << result << std::endl;
    result = inateck_scanner_ble_auth(device_id);
    std::cout << "result: " << result << std::endl;
    result = inateck_scanner_ble_set_code_callback(device_id, code_callback);
}

void get_hardware_version(const char *device_id)
{
    const char *version = inateck_scanner_ble_get_hardware_version(device_id);
    std::cout << "version: " << version << std::endl;
}

void get_software_version(const char *device_id)
{
    const char *version = inateck_scanner_ble_get_software_version(device_id);
    std::cout << "version: " << version << std::endl;
}

void get_setting_info(const char *device_id)
{
    const char *settingInfo = inateck_scanner_ble_get_setting_info(device_id, INATECK_DEVICE_TYPE::ST75);
    std::cout << "settingInfo: " << settingInfo << std::endl;
}

void quiet(const char *device_id)
{
    const char *closeVolume = "[{\"flag\":1001,\"value\":0}]";
    const char *settingInfo = inateck_scanner_ble_set_setting_info(device_id, closeVolume, INATECK_DEVICE_TYPE::ST75);
    inateck_scanner_ble_bee_or_shake(device_id);
    std::cout << "settingInfo: " << settingInfo << std::endl;
}

void loud(const char *device_id)
{
    const char *openVolume = "[{\"flag\":1001,\"value\":4}]";
    const char *settingInfo = inateck_scanner_ble_set_setting_info(device_id, openVolume, INATECK_DEVICE_TYPE::ST75);
    inateck_scanner_ble_bee_or_shake(device_id);
    std::cout << "settingInfo: " << settingInfo << std::endl;
}

int main(int argc, char const *argv[])
{
    const char *result = inateck_scanner_ble_init();
    std::cout << "result: " << result << std::endl;

    result = inateck_scanner_ble_wait_available();
    std::cout << "result: " << result << std::endl;

    result = inateck_scanner_ble_set_discover_callback(scan_callback);
    std::cout << "result: " << result << std::endl;

    result = inateck_scanner_ble_start_discover();
    std::cout << "result: " << result << std::endl;

    #ifdef _WIN32
    Sleep(10000); // Sleep function takes milliseconds
    #else
    sleep(10);
    #endif

    result = inateck_scanner_ble_stop_discover();

    const char *device_id = "BluetoothLE#BluetoothLEf4:4e:fc:89:ee:4a-aa:2b:00:03:95:83";

    connect(device_id);

    #ifdef _WIN32
    Sleep(5000); // Sleep function takes milliseconds
    #else
    sleep(5);
    #endif

    inateck_scanner_ble_bee_or_shake(device_id);

    #ifdef _WIN32
    Sleep(5000); // Sleep function takes milliseconds
    #else
    sleep(5);
    #endif

    get_hardware_version(device_id);

    get_software_version(device_id);

    get_setting_info(device_id);

    quiet(device_id);

    #ifdef _WIN32
    Sleep(5000); // Sleep function takes milliseconds
    #else
    sleep(5);
    #endif

    loud(device_id);

    #ifdef _WIN32
    Sleep(5000); // Sleep function takes milliseconds
    #else
    sleep(5);
    #endif

    return 0;
}
