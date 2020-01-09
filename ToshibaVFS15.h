//
// Created by kajetan on 18.12.2019.
//

#ifndef MODBUSTESTER_TOSHIBAVFS15_H
#define MODBUSTESTER_TOSHIBAVFS15_H


#include "ModbusDevice.h"

class ToshibaVFS15: public ModbusDevice{
private:
    bool isStarted;
    bool direction;     // forward run = false ; reverse run = true;
    uint16_t frequency;
    uint16_t lastStatus;

public:
    void start();
    void stop();
    void readStatus();
    void setFrequency(uint16_t frequency);
    void setDirection(bool direction);
    void readFrequency();
    ToshibaVFS15();
    ToshibaVFS15(int port, int slaveID, string IPAddress);
};


#endif //MODBUSTESTER_TOSHIBAVFS15_H
