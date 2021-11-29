# Communication Protocols
## Wired
### Coomly used Serial Communciations in Embedded Systems
#### UART  - TX & RX (2 devices)
* 2 Wire
* Individual clocks used by the both parties
* Standard speed (9600, 115200) - Baud rate
* Parity
#### SPI - Serial Programming Interface (Master and Slave)
* 3 + 1 wire
    * Master In Slave Out
    * Master out Slave In
    * Clock
    * Individual Chip select
* Max - Number GPIO's availabel CS pins
* Frequency - 1/3 of Operating 
#### I2C - Inter IC  (Master & Slave), External Pull up resistors
* 2 wired
    * Serial Data
    * Serial Clock
* 7/9 bit Address for each entity
* Start - Data line going low, clock low
* Stop - Dataline going high, clock low
* 7 bit address + 1 bit of acknowledge
* 100k, 400K, 1.2M

#### Factors to decide on which communication prototocol to select
* Frequency
* Data throughput
* Number of pins available 
* Type of devices which needs to talk
* Error detection (UART & I2C) capability

### Other serial Communciation
* SDIO - uSD
* HDMI
* Ethernet
### Parallel

## Wireless
* Bluetooth
* Wifi
* LORA
* RFID
* GSM
