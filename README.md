# Overview
Originally called "Reminder", this project is the brainchild of Joel Busa. It was intended to help people who have difficulty remembering whether or not they had completed a short, menial task. Users would simply press a button on the Recall device, and an LED would begin to blink for a duration of 30 minutes. If the user pressed the button again before the 30 minutes had elapsed, the LED would turn off.

[state diagram]

The goals of this design were:
* Small
* Low Power
* Stupid Cheap

[concept drawing]

# Hardware
* BOM
* schematics
* layouts
* gerbers, OSH Park links
* cost of build

## Discrete
* Discrete LED flasher circuit with passive components
** LM3909 equivalent
* Coin cell battery, CR2032 is most cost effective for the capacity
* Diffuse push button mechanical switch
* Current shunt for power measurement

## Microcontroller
* PIC10(L)F320 for power/cost/size
** ATTINY5 was lowest cost on DigiKey at $0.30 @ 5k, but 200/25 uA active/standby current at 1.8V
** PIC10LF320/322 is more expensive at $0.38 @ 3k, but 25/0.02 uA active/standby current at 1.8V
* Digital LED flasher circuit, isolation diodes
* Requires an ICSP programmer like PICkit 3 on eBay for $15


## Bluetooth Module
* Rigado BMD-300 for availability/libraries/size/power
* Rigado BMD-350 for size
* Hall effect switch for Baby Guardian
* GPIO breakout for tactile push button switch
* SWD interface for programming

## Custom BLE 
* BLE solution in smallest footprint, low cost
* bypass capacitors, DCDC, LF/HF crystals, PCB PIFA antenna, ceramic chip antenna
* shielding, FCC certification, 
* Hall effect switch for Baby Guardian
* GPIO breakout for tactile push button switch
* SWD interface for programming
* Reference Tindie nRF52 dev board

# Firmware
## PIC
## Nordic
Configured as a beacon, update major on button state change (indicates status in advertising packet to listening phone)
* battery level
* RSSI for distance

# Software
## Android
## iOS
## React Native

# Mechanical
* Silicone button with conductive pad
* Translucent key caps

* 3D design files for enclosure
* 3D design files for Baby Guardian clip
* 3D printed results
