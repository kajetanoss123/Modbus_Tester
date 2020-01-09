//
// Created by kajetan on 18.12.2019.
//

#include "ModbusDevice.h"

ModbusDevice::ModbusDevice(){

}
ModbusDevice::ModbusDevice(int port, int slaveID, string IPAddress){
    this->port = port;
    this->slaveID = slaveID;
    this->IPAddress = IPAddress;
    this->isConnected = false;
}
void ModbusDevice::tryConnect() {
    mb = modbus_new_tcp(IPAddress.c_str(), port);
    modbus_set_slave(mb, slaveID);
    if (modbus_connect(mb) == 0) {
        isConnected = true;
        cout<<"Connection established"<<endl;
    }
    else {
        modbus_close(mb);
        modbus_free(mb);
        modbus_flush(mb);
        isConnected = false;
        cout<<"Connection not established"<<endl;
    }
}
void ModbusDevice::disconnect() {
    if(isConnected){
        modbus_close(mb);
        modbus_free(mb);
        modbus_flush(mb);
        isConnected = false;
    }
}
void ModbusDevice::writeRegister(int registerAddress, uint16_t valueToWrite){
    modbus_write_register(mb, registerAddress, valueToWrite);
}
void ModbusDevice::readRegister(int registerAddress, uint16_t destination) {
    modbus_read_registers(mb, registerAddress, 1, &destination);
}