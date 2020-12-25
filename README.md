# BQ27500EVM_Reverse_Engineering
Reverse Engineering BQ27500EVM Kit and the EV2300

## Getting Started
In this repository, I will do reverse engineering for the BQ27500EVM and the EV2300 Kit.

![alt text](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Pictures/EV2300_BQ27500.png)

The EV2300 is a USB to SMBus converter and it has interface program ( Works only on Windows XP ), so I had an old computer laying around, I installed windows XP and had a tests over the EV3200 with this setup like below:

![alt text](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Pictures/EV2300%20Setup.png?raw=true)

Here is a screenshot for the software:
![alt text](https://raw.githubusercontent.com/rxtxinv/BQ27500EVM_Reverse_Engineering/main/Pictures/ComputerSoftware.bmp)

The program worked fine and communicated with the BQ27500 kit.

Next, I will connect [(Saleae 8 Logic Analyzer)](https://usd.saleae.com/products/saleae-logic-8) inline with the I2C/SMBus and have a look while the program reading the data from the BQ27500EVM.

![alt text](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Pictures/Actual%20Setup.jpg?raw=true)

The saved capture for Logic 1.2.18 program : [24 MHz, 480 M Samples [3].logicdata](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Logic%20Analyzer%20Data%20Capture/Reading%20BQ27500's%20RAM/24%20MHz%2C%20480%20M%20Samples%20%5B3%5D.logicdata), you could open it and enable the I2C analysis, for more capture data visit this folder [(Logic_Analyzer_Data_Capture)](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/tree/main/Logic_Analyzer_Data_Capture)

![alt text](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Logic_Analyzer_Data_Capture/Reading%20BQ27500's%20RAM/2020-12-25_5-27-51.png)

From the reverse engineering we get this info:
```
BQ27500 I2C Address: 0x55
```

## Datasheets & User manuals
* [slua448.pdf](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Datasheets/slua448.pdf) Quick Start Guide for bq2750x Family Gas Gauge.
* [slus914a.pdf](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Datasheets/slus914a.pdf) bq27500 System-Side Impedance Track Fuel Gauge Datasheet.
* [sluu159e.pdf](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Datasheets/sluu159e.pdf) EV2300 EVM Interface Board User Manual.
* [sluu287a.pdf](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Datasheets/sluu287a.pdf) bq2750xEVM System Side Single-Cell Impedance Track™
Technology Evaluation Module.
* [sluu298.pdf](https://github.com/rxtxinv/BQ27500EVM_Reverse_Engineering/blob/main/Datasheets/sluu298.pdf) Quick Start Guide for bq27500/1EVM Kit.

## Project History
* 25/12/2020 -> Started the project and protocol reverse engineering
*
*
