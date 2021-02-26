## BQ27500EVM_Reverse_Engineering
Reverse Engineering BQ27500EVM Kit and the EV2300

## Getting Started
In this repository, I will do reverse engineering for the BQ27500EVM and the EV2300 Kit.

![alt text](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Pictures/EV2300_BQ27500.png)

The [EV2300](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Datasheets/sluu159e.pdf) is a USB to I²C/SMBus converter and it has [interface program](https://raw.githubusercontent.com/rxtxinv/BQ27500EVM_Reverse_Engineering/main/Pictures/ComputerSoftware.bmp) ( Works only on Windows XP ), so I had an old computer laying around, I installed windows XP and had a tests over the EV3200 with this setup like below:



![alt text](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Pictures/EV2300%20Setup.png?raw=true)


Here is a screenshot for the software:
![alt text](https://raw.githubusercontent.com/rxtxinv/BQ27500EVM_Reverse_Engineering/main/Pictures/ComputerSoftware.bmp)

The program worked fine and communicated with the BQ27500 kit.

Next, I will connect [(Saleae 8 Logic Analyzer)](https://usd.saleae.com/products/saleae-logic-8) inline with the I²C/SMBus and have a look while the program reading the data from the BQ27500EVM.

![alt text](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Pictures/EV2300%20Logic%20Analyzer%20Actual%20Setup.jpg?raw=true)

The saved capture for Logic 1.2.18 program : [24 MHz, 480 M Samples [3].logicdata](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Logic%20Analyzer%20Data%20Capture/Reading%20BQ27500's%20RAM/24%20MHz%2C%20480%20M%20Samples%20%5B3%5D.logicdata), you could open it and enable the I²C analysis, for more data captures visit this folder [(Logic_Analyzer_Data_Capture)](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/tree/main/Logic_Analyzer_Data_Capture)

Here is a screenshot for the Logic 1.2.18 program.
![alt text](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Logic_Analyzer_Data_Capture/Reading%20BQ27500's%20RAM/2020-12-25_5-27-51.png)

From the reverse engineering we get this info:
```
BQ27500 I²C Address: 0x55
I²C Frequency: 40KHz
```

## Datasheets & User manuals
* [slua448.pdf](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Datasheets/slua448.pdf) Quick Start Guide for bq2750x Family Gas Gauge.
* [slus914a.pdf](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Datasheets/slus914a.pdf) bq27500 System-Side Impedance Track Fuel Gauge Datasheet.
* [sluu159e.pdf](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Datasheets/sluu159e.pdf) EV2300 EVM Interface Board User Manual.
* [sluu287a.pdf](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Datasheets/sluu287a.pdf) bq2750xEVM System Side Single-Cell Impedance Track™
Technology Evaluation Module.
* [sluu298.pdf](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Datasheets/sluu298.pdf) Quick Start Guide for bq27500/1EVM Kit.

## Connecting the BQ27500EVM with the microcontroller
After Reading the Datasheet and verifying it with the captured data in the section above, I have written a code for NodeMCU ( Just for concept verification only ) and this is the final setup:
![alt text](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Pictures/NodeMCU%20Actual%20Setup.jpg)

Connection:
```
NodeMCU's D1 Pin: SCL
NodeMCU's D2 Pin: SDA
** Connecting the GND together **
```

## The Code:
* [ESP8266_BQ27500EVM.ino](https://raw.githubusercontent.com/rxtxinv/BQ27500EVM_Reverse_Engineering/main/NodeMCU%20Test%20Code%20(Arduino)/ESP8266_BQ27500EVM/ESP8266_BQ27500EVM.ino) NodeMCU Arduino Code ( Just for concept verification ).

The Output Data Over The UART:
```
Device Name: q27500
Pack's Voltage: 4187 mV , 4.19 V
Design Capacity: 2200 mAh
State Of Charge: 100 %
Nominal Available Capacity: 1000 mAh
Nominal Available Capacity: 1000 mAh
Remaining Capacity: 1000 mAh
FullCharge Capacity: 1000 mAh
Average Current: 100 mA
Time To Empty: -1 Minute/(s)
Time To Full: 151 Minute/(s)
Standby Current: -8 mA
Standby Time To Empty: 7500 Minute/(s)
Max Load Current: -1219 mA
Max Load Time To Empty: 49 mA
Available Energy: 3792 mWh
Average Power: 419 mW
Time To Empty At Constant Power: -1 Minute/(s)
Cycle Count: 1 Time/(s)
```

* STM32 Driver
* Computer Software


## Project History
* 24/12/2020 -> Started the project and protocol reverse engineering ( Done ).
* 25/12/2020 -> Writing NodeMCU's code for ( Concept Verification ) ( Done ).
*

## Support me on LinkedIn
Kindly, if my repository helped you. I need your support by endorsing my LinkedIn skills. ([Omar Khaled Mekkawy](https://www.linkedin.com/in/omar-mekkawy)). Thanks
