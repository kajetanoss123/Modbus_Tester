cmake_minimum_required(VERSION 3.15)
project(ModbusTester)

set(CMAKE_CXX_STANDARD 17)
find_library(MODBUS_LIB modbus)
add_executable(ModbusTester main.cpp ModbusDevice.cpp ModbusDevice.h ToshibaVFS15.cpp ToshibaVFS15.h modbus.cpp modbus.h modbus_exception.h)
target_link_libraries(ModbusTester ${MODBUS_LIB})