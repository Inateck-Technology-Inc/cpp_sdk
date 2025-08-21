#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

extern "C" {

    enum INATECK_DEVICE_TYPE
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
        Pro8AI,
        ST45AI,
        ST23AI,
        ST91AI,
        ST42AI,
        ST54AI,
        ST55AI,
        ST73AI,
        ST75AI,
        ST43AI,
        P7AI,
        ST21AI,
        ST60AI,
        ST70AI,
        P6AI,
        ST35AI,
        ST46,
        ST46AI,
        ST72,
        ST72AI,
        ST75S,
        ST75SAI,
        ST36,
        ST36AI,
        ST61,
        ST61AI,
        ST47,
        ST47AI,
        PBS002,
        PRO8SE,
        PRO8SEAI,
        ST49,
        ST49AI,
        B560B,
        PBS005AI,
    };

    const char *inateck_scanner_ble_init(void);

    const char *inateck_scanner_ble_set_discover_callback(void (*callback)(const char*));
    
    const char *inateck_scanner_ble_wait_available(void);
    
    const char *inateck_scanner_ble_start_discover(void);
    
    const char *inateck_scanner_ble_stop_discover(void);
    
    const char *inateck_scanner_ble_get_devices(void);
    
    const char *inateck_scanner_ble_connect(const char *device_id);
    
    const char *inateck_scanner_ble_check_communication(const char *device_id);
    
    const char *inateck_scanner_ble_auth(const char *device_id);
    
    const char *inateck_scanner_ble_set_code_callback(const char *device_id,
                                                      void (*callback)(const char*));
    
    const char *inateck_scanner_ble_set_disconnect_callback(const char *device_id,
                                                            void (*callback)(const char*));
    
    const char *inateck_scanner_ble_disconnect(const char *device_id);
    
    const char *inateck_scanner_ble_get_battery(const char *device_id);
    
    const char *inateck_scanner_ble_get_hardware_version(const char *device_id);
    
    const char *inateck_scanner_ble_bee_or_shake(const char *device_id);
    
    const char *inateck_scanner_set_bee(const char *device_id,
                                        uint8_t voice_time,
                                        uint8_t silent_time,
                                        uint8_t count);
    
    const char *inateck_scanner_set_led(const char *device_id,
                                        uint8_t color,
                                        uint8_t light_time,
                                        uint8_t dark_time,
                                        uint8_t count);
    
    const char *inateck_scanner_ble_get_software_version(const char *device_id);
    
    const char *inateck_scanner_ble_get_mac(const char *device_id);
    
    const char *inateck_scanner_ble_get_setting_info(const char *device_id, int device_type);
    
    const char *inateck_scanner_ble_set_setting_info(const char *device_id,
                                                     const char *cmd,
                                                     int device_type);
    
    const char *inateck_scanner_ble_set_name(const char *device_id, const char *name);
    
    const char *inateck_scanner_ble_set_time(const char *device_id,
                                             int hour,
                                             int minute,
                                             int second,
                                             int year,
                                             int month,
                                             int day);
    
    const char *inateck_scanner_ble_inventory_clear_cache(const char *device_id);
    
    const char *inateck_scanner_ble_inventory_upload_cache(const char *device_id);
    
    const char *inateck_scanner_ble_inventory_upload_cache_number(const char *device_id);
    
    const char *inateck_scanner_ble_reset(const char *device_id);
    
    const char *inateck_scanner_ble_restart(const char *device_id);
    
    const char *inateck_scanner_ble_close_all_code(const char *device_id);
    
    const char *inateck_scanner_ble_open_all_code(const char *device_id);
    
    const char *inateck_scanner_ble_reset_all_code(const char *device_id);
    
    const char *inateck_scanner_ble_get_prefix(const char *device_id);
    
    const char *inateck_scanner_ble_set_prefix(const char *device_id,
                                               const uint8_t *prefix,
                                               uintptr_t prefix_len);
    
    const char *inateck_scanner_ble_get_suffix(const char *device_id);
    
    const char *inateck_scanner_ble_set_suffix(const char *device_id,
                                               const uint8_t *suffix,
                                               uintptr_t suffix_len);
    
    const char *inateck_scanner_ble_sdk_version(void);
    
    int inateck_scanner_ble_set_debug(int is_debug);
    
    int inateck_scanner_ble_send_hid_text(const char *text);
    
    const char *inateck_scanner_ble_set_hid_output(const char *device_id, int output_type);

} // extern "C"
