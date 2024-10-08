#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

extern "C"
{
    enum DEVICE_TYPE
    {
        None = 0,
        Pro8,
        ST45,
        ST23,
        ST91,
        ST42,
        ST54,
        ST55,
        ST73,
        ST75,
        ST43,
        P7,
        ST21,
        ST60,
        ST70,
        P6,
        ST35,
    };

    int inateck_scanner_ble_init(void (*callback)(const char *));

    int inateck_scanner_ble_destroy();

    int inateck_scanner_ble_start_scan();

    int inateck_scanner_ble_stop_scan();

    const char *inateck_scanner_ble_get_devices();

    const char *inateck_scanner_ble_connect(const char *mac, void (*callback)(const char *));

    int inateck_scanner_ble_auth(const char *mac);

    int inateck_scanner_ble_disconnect(const char *mac);

    const char *inateck_scanner_ble_get_battery(const char *mac);

    const char *inateck_scanner_ble_get_hardware_version(const char *mac);

    const char *inateck_scanner_ble_bee_or_shake(const char *mac);

    const char *inateck_scanner_ble_get_software_version(const char *mac);

    const char *inateck_scanner_ble_get_setting_info(const char *mac, int device_type);

    const char *inateck_scanner_ble_set_setting_info(const char *mac, const char *cmd, int device_type);

    int inateck_scanner_ble_set_name(const char *mac, const char *name);

    int inateck_scanner_ble_set_time(const char *mac, long time);

    int inateck_scanner_ble_inventory_clear_cache(const char *mac);

    int inateck_scanner_ble_inventory_upload_cache(const char *mac);

    int inateck_scanner_ble_inventory_upload_cache_number(const char *mac);

    int inateck_scanner_ble_reset(const char *mac);

    int inateck_scanner_ble_restart(const char *mac);

    int inateck_scanner_ble_close_all_code(const char *mac);

    int inateck_scanner_ble_open_all_code(const char *mac);

    int inateck_scanner_ble_reset_all_code(const char *mac);

    const char *inateck_scanner_ble_sdk_version();

    int inateck_scanner_ble_debug(int is_debug);

} // extern "C"
