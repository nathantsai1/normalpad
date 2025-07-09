# NormalPad

*Note: this is a hackboard, not a hackpad
## What is this?
This is a 75% keyboard inspired by the [Keychron Q1 Custom Keyboard](https://www.keychron.com/products/keychron-q1?srsltid=AfmBOorYcrgbMnQshTxcVkn31a3YPq6My79lAXlqjA35xHALWIpRg0Ld). It consists of 82 keys, hot-swappable switches a 3D printable case, and stabilizers. The bottom half is split in half to make it easier to sand

## Quick overview of repo
+ cad
    1. full_keyboard.stl
+ firmware
    1. normalPad.ino
+ pcb
    1. hackpad_v2.kicad_pcb
    2. hackpad_v2.kicad_prl
    3. hackpad_v2.kicad_pro
    4. hackpad_v2.kicad_sch
+ production
    + cad(stl)
        1. plate.stl
        2. upper_ex.stl
        3. bottom.stl
    1. normalPad.ino
    2. gerbers-zip.zip
+ src
    1. angle_bottom.png
    2. assembled_bottom.png
    3. bottom.png
    4. diagram.png
    5. pcb.png
    6. plate.png
    7. schem.png
    8. side_short.png
    9. side_long.png
    10. together.png
    11. top_plate.png
+ README.md
+ bom.csv
+ JOURNAL.md

*The more important files are contained in the production folder, README, and bom(in a ccsv file and at the end of this page)
## Why did I make this
I primarily started this for [HackPad v2](https://hackpad.hackclub.com/keyboard). However, during the process of making this, I learned more about the different types of switches, stabilizers, splitting up CAD designs into multiple parts, and all the parts of the keyboard. I learned a little bit more about the [Arduino Keyboard library](https://docs.arduino.cc/language-reference/en/functions/usb/Keyboard/), how to write relatively efficient code, and organize my pcb schematic and pcb in a larger scale than what I previously learned. As I had taken a break for a few months from my original keyboard design, I had stopped 

## Pictures of my design:
### Schematic:
<b>My diagram, which depicts the row and column numbers</b>

![diagram](./src/diagram.png)

<b>The schematic for the pcb, relatively organized in the order wanted</b>

![schematic](./src/schem.png)

### PCB
<b>My PCB</b>

![schematic](./src/pcb.png)

<b>PCB back</b>

![pcb back](./src/pcb_back.png)

<b>PCB front (w/key switch side)</b>

![pcb front](./src/pcb_front.png)

### CAD Case(Disassembled)
From top to bottom 

<b>Top plate</b>

![Top Plate](./src/top_plate.png)

<b>Plate</b>

![Plate](./src/plate.png)

<b>Bottom</b>

![Bottom](./src/normal_bottom.png)

### CAD case(relatively assembled)

<b>Assembled case</b>

![Bottom assembled](./src/normal_bottom.png)
![Top assembled](./src/assembled_top.png)

<b>Side analysis of case</b>

![side_long](./src/side_long.png)
![side_short](./src/side_short.png)

<b>sketch of designsadded to project</b>
in order: back case, front case, front pcb

![back_design](./src/design3.png)
![back_design](./src/face.png)
![back_design](./src/pcb_front.png)

## Bill of Materials
Also see [here](./BOM.csv)
|mfg name|	            Description|	        Price|	shipping|	total|	notes|
| ---|                          ---|              ---|      ---|     ---|    ---|
|ALIEXPRESS|	        [keycap set](https://www.aliexpress.us/item/3256803996370867.html)|	            9.23|	0|	    9.23| |
|ALIEXPRESS|	        [keyswitch(90)](https://www.aliexpress.us/item/3256807160745636.html)|	        25.17|	0|	        25.17| |
|ALIEXPRESS|	        taxes|	                0|	0|	        0| |
| | | | | | |
|JLCPCB|	            pcb|	                20.9|	17.13|	    38.03| |
| | | | | | |
|MECHANICAL KEYBOARD|    [hot swap(90)](https://mechanicalkeyboards.com/products/kailh-switch-hot-swap-socket)|	        9.9|   	5.8|	    15.15| |
|MECHANIAL KEYBOARDS|   [stabilizer](https://mechanicalkeyboards.com/products/durock-v3-pcb-mount-screw-in-stabilizer-tkl-kit)|	            15|	    6.27|	    21.27| |
| | | | | | |
|DIGIKEY|	            [Raspberry pi pico w/o header](https://www.digikey.com/en/products/detail/raspberry-pi/SC0915/13624793)|	    5|  	0|	        5| |
|DIGIKEY|	            [pin header 1x40](https://www.digikey.com/en/products/detail/amphenol-cs-commercial-products/G800W268018EU/17083164)|	    0.8|	|	        0.8| |
|DIGIKEY|	            [bolts(2Mx0.4 - 8mm*18)](https://www.digikey.com/en/products/detail/essentra-components/50M020040P008/11639927)|	1.76|	0|	        1.76| |
|DIGIKEY|	            [diode(84)](https://www.digikey.com/en/products/detail/comchip-technology/1N4001-G/1979654)|	            4.54|	0|	        4.54| |
|DIGIKEY|	            total(tariff+tax, shipping)|	        1.57|	4.99|	    6.56| |
|CAD CASE|	            cad case|	                |	|	        5.51| |
Total (with case and PCB): 133.02
Total (without case and PCB) 89.48
*PRICES IN USD
