//
// Created by kajetan on 18.12.2019.
//

#include "ToshibaVFS15.h"

#define COMMAND_REGISTER 0xFA00
#define STATUS_REGISTER  0xFD01

ToshibaVFS15::ToshibaVFS15(int port, int slaveID, string IPAddress): ModbusDevice(port, slaveID, IPAddress){
    if(isConnected){
        readStatus();
    }
}
ToshibaVFS15::ToshibaVFS15(){}

void ToshibaVFS15::readStatus() {
    if(isConnected){
        modbus_read_registers(mb, STATUS_REGISTER, 1, &lastStatus);
        direction = !(lastStatus & (1 << 9));
        isStarted = lastStatus & (1 << 10);
    }
    cout<<"Last status "<<lastStatus<<endl;
}

void ToshibaVFS15::start() {
    if(isConnected && !isStarted){
        //writeRegister(COMMAND_REGISTER, 49664);
        writeRegister(COMMAND_REGISTER, 50176);   // set start flag
        readStatus();
        if(isStarted){
            cout<<"Inverter has started"<<endl;
        } else{
            cout<<"Inverter has not started"<<endl;
        }
    }
}
void ToshibaVFS15::stop() {
    if(isConnected && isStarted){
        writeRegister(COMMAND_REGISTER, 49152);   // set start flag
        readStatus();
        if(isStarted){
            cout<<"Inverter has not stopped"<<endl;
        } else{
            cout<<"Inverter has stopped"<<endl;
        }
    }
}
void ToshibaVFS15::setFrequency(uint16_t frequency) {
    if(isConnected){
        writeRegister(0xFA01, frequency*100);
    }
}
void ToshibaVFS15::setDirection(bool direction){
    writeRegister(COMMAND_REGISTER, 50176 | (direction*512));
}

