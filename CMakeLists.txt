cmake_minimum_required(VERSION 3.24)

project(cpp_sdk)

add_library(scannerBle SHARED IMPORTED )

set_target_properties(scannerBle PROPERTIES IMPORTED_IMPLIB_DEBUG "${PROJECT_SOURCE_DIR}/lib/inateck_scanner_ble.dll.lib")
# set_target_properties( scannerBle PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/lib/scanner_ble_x86_64-pc-windows-msvc.dll )
set_target_properties(scannerBle PROPERTIES IMPORTED_LOCATION_DEBUG "${PROJECT_SOURCE_DIR}/lib/inateck_scanner_ble.dll")
set_target_properties(scannerBle PROPERTIES IMPORTED_IMPLIB_RELEASE "${PROJECT_SOURCE_DIR}/lib/inateck_scanner_ble.dll")
set_target_properties(scannerBle PROPERTIES IMPORTED_LOCATION_RELEASE "${PROJECT_SOURCE_DIR}/lib/inateck_scanner_ble.dll")
set_target_properties(scannerBle PROPERTIES IMPORTED_IMPLIB_MINSIZEREL "${PROJECT_SOURCE_DIR}/lib/inateck_scanner_ble.dll")
set_target_properties(scannerBle PROPERTIES IMPORTED_LOCATION_MINSIZEREL "${PROJECT_SOURCE_DIR}/lib/inateck_scanner_ble.dll")
set_target_properties(scannerBle PROPERTIES IMPORTED_IMPLIB_RELWITHDEBINFO "${PROJECT_SOURCE_DIR}/lib/inateck_scanner_ble.dll")
set_target_properties(scannerBle PROPERTIES IMPORTED_LOCATION_RELWITHDEBINFO "${PROJECT_SOURCE_DIR}/lib/inateck_scanner_ble.dll")

add_executable(cpp_sdk main.cpp)

target_link_libraries(cpp_sdk scannerBle)
target_include_directories(cpp_sdk PUBLIC ${PROJECT_SOURCE_DIR}/include)
