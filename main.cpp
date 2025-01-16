#include <iostream>
#include "inateck_scanner_ble_cpp.h"
#include <sstream>
#include <vector>
#include <unistd.h>

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
    const char *settingInfo = inateck_scanner_ble_get_setting_info(device_id, DEVICE_TYPE::ST75);
    std::cout << "settingInfo: " << settingInfo << std::endl;
}

void quiet(const char *device_id)
{
    const char *closeVolume = "[{\"flag\":1001,\"value\":0}]";
    const char *settingInfo = inateck_scanner_ble_set_setting_info(device_id, closeVolume, DEVICE_TYPE::ST75);
    inateck_scanner_ble_bee_or_shake(device_id);
    std::cout << "settingInfo: " << settingInfo << std::endl;
}

void loud(const char *device_id)
{
    const char *openVolume = "[{\"flag\":1001,\"value\":4}]";
    const char *settingInfo = inateck_scanner_ble_set_setting_info(device_id, openVolume, DEVICE_TYPE::ST75);
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

    // sleep(10);
    sleep(10);

    result = inateck_scanner_ble_stop_discover();

    const char *device_id = "BluetoothLE#BluetoothLEf4:4e:fc:89:ee:4a-aa:2b:00:03:95:83";

    connect(device_id);

    sleep(10);

    inateck_scanner_ble_bee_or_shake(device_id);

    sleep(5);

    get_hardware_version(device_id);

    get_software_version(device_id);

    get_setting_info(device_id);

    quiet(device_id);

    sleep(5);

    loud(device_id);

    sleep(5);

    return 0;
}
