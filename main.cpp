#include "ToshibaVFS15.h"
#include <thread>
#include "modbus.h"

int main() {

//    ToshibaVFS15 inverter = ToshibaVFS15(8899, 5, "192.168.106.165");
//
//    inverter.tryConnect();
    //inverter.readStatus();
//    inverter.start();
//    inverter.setFrequency(20);
//    std::this_thread::sleep_for(10s);
    //inverter.setDirection(false);
    //std::this_thread::sleep_for(15s);
//    inverter.stop();
//    inverter.disconnect();
    ModbusDevice smd630 = ModbusDevice(8899, 1, "192.168.0.45");

    smd630.tryConnect();
    smd630.disconnect();

//    uint16_t buffer;
//    modbus mb = modbus("192.168.106.165", 8899);
//    mb.modbus_set_slave_id(4);
//    mb.modbus_connect();
//    mb.modbus_read_holding_registers(0xFD01, 1, &buffer);
//    cout<<buffer<<endl;
//    mb.modbus_write_register(0xFA00, 49664);
//    //std::this_thread::sleep_for(1s);
//    //mb.modbus_write_register(0xFA06, 50176);
//    mb.modbus_close();


    return 0;
}
