//
// Created by kajetan on 18.12.2019.
//

#ifndef MODBUSTESTER_MODBUSDEVICE_H
#define MODBUSTESTER_MODBUSDEVICE_H

#include <modbus/modbus.h>
#include <iostream>

using namespace std;

 class ModbusDevice {
 protected:
    int port;
    int slaveID;
    string IPAddress;
    modbus_t *mb;
    bool isConnected;

 public:
    void tryConnect();
    void disconnect();
    void readRegister(int registerAddress, uint16_t destination);
    void writeRegister(int registerAddress, uint16_t valueToWrite);
    ModbusDevice();
    ModbusDevice(int port, int slaveID, string IPAddress);
};


#endif //MODBUSTESTER_MODBUSDEVICE_H
