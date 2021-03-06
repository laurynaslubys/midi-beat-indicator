EESchema Schematic File Version 4
LIBS:kitchen_sink-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:AudioJack2 #JA1
U 1 1 5F98136D
P 6550 900
F 0 "#JA1" H 6370 883 50  0000 R CNN
F 1 "AudioJack2" H 6370 974 50  0000 R CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x02_P1.27mm_Vertical" H 6550 900 50  0001 C CNN
F 3 "~" H 6550 900 50  0001 C CNN
	1    6550 900 
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5F9AFE96
P 6350 1250
F 0 "#PWR07" H 6350 1000 50  0001 C CNN
F 1 "GND" H 6355 1077 50  0000 C CNN
F 2 "" H 6350 1250 50  0001 C CNN
F 3 "" H 6350 1250 50  0001 C CNN
	1    6350 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 1000 6350 1150
Connection ~ 5550 2400
Wire Wire Line
	4850 2400 5550 2400
Wire Wire Line
	4850 2350 4850 2400
$Comp
L Device:LED DSYNC1
U 1 1 5F9D6185
P 4850 2200
F 0 "DSYNC1" V 4889 2083 50  0000 R CNN
F 1 "RED" V 4798 2083 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 4850 2200 50  0001 C CNN
F 3 "~" H 4850 2200 50  0001 C CNN
	1    4850 2200
	0    -1   -1   0   
$EndComp
$Comp
L Device:R RSYNC1
U 1 1 5F9D5E36
P 4850 1800
F 0 "RSYNC1" H 4780 1754 50  0000 R CNN
F 1 "4.7k" H 4780 1845 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4780 1800 50  0001 C CNN
F 3 "~" H 4850 1800 50  0001 C CNN
	1    4850 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 900  5900 1350
Wire Wire Line
	6350 900  6000 900 
Connection ~ 5900 2400
Wire Wire Line
	5900 2400 5900 1750
Wire Wire Line
	5550 2150 5550 2400
Wire Wire Line
	5550 2400 5900 2400
$Comp
L power:GND #PWR06
U 1 1 5F98B0FA
P 5900 2400
F 0 "#PWR06" H 5900 2150 50  0001 C CNN
F 1 "GND" H 5905 2227 50  0000 C CNN
F 2 "" H 5900 2400 50  0001 C CNN
F 3 "" H 5900 2400 50  0001 C CNN
	1    5900 2400
	1    0    0    -1  
$EndComp
Connection ~ 5550 1550
Wire Wire Line
	5550 1550 5700 1550
Wire Wire Line
	5550 1550 5550 1850
Wire Wire Line
	5400 1550 5550 1550
$Comp
L SparkFun-DiscreteSemi:TRANS_NPN-P2N2222A Q1
U 1 1 5F980C59
P 5800 1550
F 0 "Q1" H 5944 1645 45  0000 L CNN
F 1 "TRANS_NPN-P2N2222A" H 5944 1561 45  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 5800 1800 20  0001 C CNN
F 3 "" H 5800 1550 50  0001 C CNN
F 4 "TRANS-09536" H 5944 1466 60  0000 L CNN "Field4"
	1    5800 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5F97F0A2
P 5550 2000
F 0 "R2" H 5480 1954 50  0000 R CNN
F 1 "4.7k" H 5480 2045 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5480 2000 50  0001 C CNN
F 3 "~" H 5550 2000 50  0001 C CNN
	1    5550 2000
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 5F97DD34
P 5250 1550
F 0 "R1" V 5043 1550 50  0000 C CNN
F 1 "10k" V 5134 1550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5180 1550 50  0001 C CNN
F 3 "~" H 5250 1550 50  0001 C CNN
	1    5250 1550
	0    1    1    0   
$EndComp
Wire Wire Line
	6800 3600 6800 3950
Connection ~ 6800 3600
$Comp
L power:GND #PWR09
U 1 1 5F91DFFA
P 6800 4900
F 0 "#PWR09" H 6800 4650 50  0001 C CNN
F 1 "GND" H 6805 4727 50  0000 C CNN
F 2 "" H 6800 4900 50  0001 C CNN
F 3 "" H 6800 4900 50  0001 C CNN
	1    6800 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3600 6800 3600
$Comp
L Device:LED DG3
U 1 1 5F929C0F
P 5800 3600
F 0 "DG3" H 5793 3816 50  0000 C CNN
F 1 "LED" H 5793 3725 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5800 3600 50  0001 C CNN
F 3 "~" H 5800 3600 50  0001 C CNN
	1    5800 3600
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED DB3
U 1 1 5F91E972
P 5800 4650
F 0 "DB3" H 5793 4866 50  0000 C CNN
F 1 "BLUE" H 5793 4775 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5800 4650 50  0001 C CNN
F 3 "~" H 5800 4650 50  0001 C CNN
	1    5800 4650
	-1   0    0    -1  
$EndComp
$Comp
L Device:R RB3
U 1 1 5F91AFE6
P 5500 4650
F 0 "RB3" V 5293 4650 50  0000 C CNN
F 1 "1k" V 5384 4650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5430 4650 50  0001 C CNN
F 3 "~" H 5500 4650 50  0001 C CNN
	1    5500 4650
	0    -1   1    0   
$EndComp
$Comp
L Device:R RG3
U 1 1 5F91948D
P 5500 3600
F 0 "RG3" V 5293 3600 50  0000 C CNN
F 1 "1k" V 5384 3600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5430 3600 50  0001 C CNN
F 3 "~" H 5500 3600 50  0001 C CNN
	1    5500 3600
	0    -1   1    0   
$EndComp
$Comp
L Device:R RMIDI_1
U 1 1 5FA43F26
P 4700 6100
F 0 "RMIDI_1" V 4493 6100 50  0000 C CNN
F 1 "220" V 4584 6100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4630 6100 50  0001 C CNN
F 3 "~" H 4700 6100 50  0001 C CNN
	1    4700 6100
	0    1    1    0   
$EndComp
$Comp
L Device:R RMIDI_2
U 1 1 5FA44A8D
P 6100 5750
F 0 "RMIDI_2" H 6030 5704 50  0000 R CNN
F 1 "220" H 6030 5795 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6030 5750 50  0001 C CNN
F 3 "~" H 6100 5750 50  0001 C CNN
	1    6100 5750
	-1   0    0    1   
$EndComp
$Comp
L SparkFun-Connectors:DIN5-MIDI #JMIDI1
U 1 1 5FA4A1A9
P 5650 6300
F 0 "#JMIDI1" H 5650 5930 45  0000 C CNN
F 1 "DIN5" H 5650 5846 45  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x03_P1.27mm_Vertical" H 5650 6800 20  0001 C CNN
F 3 "" H 5650 6300 50  0001 C CNN
F 4 "CONN-09481" H 5650 5751 60  0000 C CNN "Field4"
	1    5650 6300
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR08
U 1 1 5FA6803F
P 6100 5400
F 0 "#PWR08" H 6100 5250 50  0001 C CNN
F 1 "VCC" H 6117 5573 50  0000 C CNN
F 2 "" H 6100 5400 50  0001 C CNN
F 3 "" H 6100 5400 50  0001 C CNN
	1    6100 5400
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR04
U 1 1 5FA95B8C
P 2400 4200
F 0 "#PWR04" H 2400 4050 50  0001 C CNN
F 1 "VCC" H 2417 4373 50  0000 C CNN
F 2 "" H 2400 4200 50  0001 C CNN
F 3 "" H 2400 4200 50  0001 C CNN
	1    2400 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT #RV1
U 1 1 5FAA26E5
P 1300 3000
F 0 "#RV1" H 1230 2954 50  0000 R CNN
F 1 "50k" H 1230 3045 50  0000 R CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x03_P1.27mm_Vertical" H 1300 3000 50  0001 C CNN
F 3 "~" H 1300 3000 50  0001 C CNN
	1    1300 3000
	-1   0    0    1   
$EndComp
$Comp
L power:VCC #PWR02
U 1 1 5FAA6A22
P 1300 2450
F 0 "#PWR02" H 1300 2300 50  0001 C CNN
F 1 "VCC" H 1317 2623 50  0000 C CNN
F 2 "" H 1300 2450 50  0001 C CNN
F 3 "" H 1300 2450 50  0001 C CNN
	1    1300 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5FAA9010
P 1300 3350
F 0 "#PWR03" H 1300 3100 50  0001 C CNN
F 1 "GND" H 1305 3177 50  0000 C CNN
F 2 "" H 1300 3350 50  0001 C CNN
F 3 "" H 1300 3350 50  0001 C CNN
	1    1300 3350
	1    0    0    -1  
$EndComp
$Comp
L SparkFun-Switches:MOMENTARY-SWITCH-SPST-PTH-6.0MM #S1
U 1 1 5FAAEDCD
P 1200 5250
F 0 "#S1" V 1105 5328 45  0000 L CNN
F 1 "MOMENTARY-SWITCH-SPST-PTH-6.0MM" V 1189 5328 45  0000 L CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x02_P1.27mm_Vertical" H 1200 5450 20  0001 C CNN
F 3 "" H 1200 5250 50  0001 C CNN
F 4 " SWCH-08441" V 1284 5328 60  0000 L CNN "Field4"
	1    1200 5250
	0    1    1    0   
$EndComp
Wire Wire Line
	1200 4850 1200 5050
Wire Wire Line
	1600 3000 1750 3000
NoConn ~ 6050 6300
NoConn ~ 5250 6300
Wire Wire Line
	1200 5450 1200 5550
$Comp
L power:GND #PWR01
U 1 1 5FAAEDD3
P 1200 5700
F 0 "#PWR01" H 1200 5450 50  0001 C CNN
F 1 "GND" H 1205 5527 50  0000 C CNN
F 2 "" H 1200 5700 50  0001 C CNN
F 3 "" H 1200 5700 50  0001 C CNN
	1    1200 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 3000 1600 2750
Wire Wire Line
	1600 2750 1050 2750
Wire Wire Line
	1050 2750 1050 3000
Wire Wire Line
	1050 3000 1150 3000
Wire Wire Line
	1300 2450 1300 2550
Wire Wire Line
	1300 3150 1300 3250
$Comp
L power:GND #PWR010
U 1 1 5FBB9459
P 6500 6650
F 0 "#PWR010" H 6500 6400 50  0001 C CNN
F 1 "GND" H 6505 6477 50  0000 C CNN
F 2 "" H 6500 6650 50  0001 C CNN
F 3 "" H 6500 6650 50  0001 C CNN
	1    6500 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 5900 5650 5800
Wire Wire Line
	6500 5000 6500 6650
Wire Wire Line
	4850 6100 5000 6100
Wire Wire Line
	5650 5000 6500 5000
Wire Wire Line
	6000 6100 6100 6100
Wire Wire Line
	6100 5400 6100 5600
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5FC1C769
P 6350 6050
F 0 "#FLG02" H 6350 6125 50  0001 C CNN
F 1 "PWR_FLAG" H 6350 6223 50  0000 C CNN
F 2 "" H 6350 6050 50  0001 C CNN
F 3 "~" H 6350 6050 50  0001 C CNN
	1    6350 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 5900 6100 6000
Wire Wire Line
	6350 6050 6350 6100
Wire Wire Line
	6350 6100 6100 6100
Connection ~ 6100 6100
$Comp
L Connector:Conn_01x02_Female JBA1
U 1 1 5FC45873
P 6650 600
F 0 "JBA1" H 6678 576 50  0000 L CNN
F 1 "Conn_01x02_Female" H 6678 485 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x01_P2.54mm_Vertical" H 6650 600 50  0001 C CNN
F 3 "~" H 6650 600 50  0001 C CNN
	1    6650 600 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 600  6000 600 
Wire Wire Line
	6000 600  6000 900 
Connection ~ 6000 900 
Wire Wire Line
	6000 900  5900 900 
Wire Wire Line
	6450 700  6250 700 
Wire Wire Line
	6250 700  6250 1150
Wire Wire Line
	6250 1150 6350 1150
Connection ~ 6350 1150
Wire Wire Line
	6350 1150 6350 1250
$Comp
L Connector:Conn_01x03_Female JBMIDI1
U 1 1 5FC55419
P 5100 5450
F 0 "JBMIDI1" H 5128 5476 50  0000 L CNN
F 1 "Conn_01x03_Female" H 5128 5385 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 5100 5450 50  0001 C CNN
F 3 "~" H 5100 5450 50  0001 C CNN
	1    5100 5450
	0    -1   -1   0   
$EndComp
Connection ~ 5000 6100
Wire Wire Line
	5000 6100 5300 6100
Wire Wire Line
	5100 5800 5650 5800
Connection ~ 5650 5800
Wire Wire Line
	5650 5800 5650 5000
Wire Wire Line
	5200 5650 5200 5700
Wire Wire Line
	5200 5700 5950 5700
Wire Wire Line
	5950 5700 5950 6000
Wire Wire Line
	5950 6000 6100 6000
Connection ~ 6100 6000
Wire Wire Line
	6100 6000 6100 6100
Wire Wire Line
	5000 5650 5000 6100
Wire Wire Line
	5100 5650 5100 5800
Wire Wire Line
	1850 2550 1300 2550
Connection ~ 1300 2550
Wire Wire Line
	1300 2550 1300 2850
Wire Wire Line
	1750 3300 1750 3000
Connection ~ 1750 3000
Wire Wire Line
	1550 3400 1550 3250
Wire Wire Line
	1550 3250 1300 3250
Connection ~ 1300 3250
Wire Wire Line
	1300 3250 1300 3350
$Comp
L Connector:Conn_01x02_Female JBS1
U 1 1 5FC99800
P 1550 4600
F 0 "JBS1" H 1442 4275 50  0000 C CNN
F 1 "Conn_01x02_Female" H 1442 4366 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1550 4600 50  0001 C CNN
F 3 "~" H 1550 4600 50  0001 C CNN
	1    1550 4600
	-1   0    0    1   
$EndComp
Wire Wire Line
	1750 4600 1750 4750
Wire Wire Line
	1750 4750 1100 4750
Wire Wire Line
	1100 4750 1100 5550
Wire Wire Line
	1100 5550 1200 5550
Connection ~ 1200 5550
Wire Wire Line
	1200 5550 1200 5700
Wire Wire Line
	1750 4500 1850 4500
Wire Wire Line
	4850 1650 4850 1550
Connection ~ 4850 1550
Wire Wire Line
	4850 1550 5100 1550
Wire Wire Line
	2400 4300 2400 4250
$Comp
L power:GND #PWR0101
U 1 1 5FD94987
P 2400 4600
F 0 "#PWR0101" H 2400 4350 50  0001 C CNN
F 1 "GND" H 2405 4427 50  0000 C CNN
F 2 "" H 2400 4600 50  0001 C CNN
F 3 "" H 2400 4600 50  0001 C CNN
	1    2400 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 4600 2400 4500
Wire Wire Line
	1750 3000 2400 3000
Wire Wire Line
	1200 4850 1850 4850
Wire Wire Line
	1850 4500 1850 4850
Connection ~ 1850 4850
Wire Wire Line
	1850 4850 3750 4850
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5FE38F3F
P 2250 4600
F 0 "#FLG0102" H 2250 4675 50  0001 C CNN
F 1 "PWR_FLAG" H 2250 4773 50  0000 C CNN
F 2 "" H 2250 4600 50  0001 C CNN
F 3 "~" H 2250 4600 50  0001 C CNN
	1    2250 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 4600 2400 4600
Connection ~ 2400 4600
Wire Wire Line
	2400 4500 2650 4500
Wire Wire Line
	2400 4300 2650 4300
Wire Wire Line
	2650 3900 2400 3900
Wire Wire Line
	2400 3900 2400 3000
Wire Wire Line
	1850 3400 1550 3400
Wire Wire Line
	1850 3300 1750 3300
Wire Wire Line
	1850 3200 1850 2550
$Comp
L Connector:Conn_01x03_Female JBRV1
U 1 1 5FC7DB55
P 2050 3300
F 0 "JBRV1" H 1900 3000 50  0000 L CNN
F 1 "Conn_01x03_Female" H 1600 3100 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 2050 3300 50  0001 C CNN
F 3 "~" H 2050 3300 50  0001 C CNN
	1    2050 3300
	1    0    0    -1  
$EndComp
NoConn ~ 2650 4600
NoConn ~ 2650 4400
NoConn ~ 2650 4200
NoConn ~ 2650 4100
NoConn ~ 2650 4000
NoConn ~ 2650 3800
NoConn ~ 2650 3700
NoConn ~ 2650 3600
NoConn ~ 3550 4500
NoConn ~ 3550 4400
NoConn ~ 3550 4300
NoConn ~ 3550 4200
Wire Wire Line
	2550 1550 4850 1550
$Comp
L SparkFun-Boards:SPARKFUN_PRO_MICRO B1
U 1 1 5F9AA0B6
P 3100 4050
F 0 "B1" H 3100 3140 45  0000 C CNN
F 1 "SPARKFUN_PRO_MICRO" H 3100 3224 45  0000 C CNN
F 2 "Package_DIP:DIP-24_W15.24mm_Socket" H 3100 4850 20  0001 C CNN
F 3 "" H 3100 4050 50  0001 C CNN
F 4 "XXX-00000" H 3100 3319 60  0000 C CNN "Field4"
	1    3100 4050
	-1   0    0    1   
$EndComp
Wire Wire Line
	2550 1550 2550 3500
Wire Wire Line
	2550 3500 2650 3500
Wire Wire Line
	3750 4850 3750 4100
Wire Wire Line
	3750 4100 3550 4100
Wire Wire Line
	3850 6100 3850 4600
Wire Wire Line
	3850 4600 3550 4600
Wire Wire Line
	3850 6100 4550 6100
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5FBB19CF
P 2250 4250
F 0 "#FLG0101" H 2250 4325 50  0001 C CNN
F 1 "PWR_FLAG" H 2250 4423 50  0000 C CNN
F 2 "" H 2250 4250 50  0001 C CNN
F 3 "~" H 2250 4250 50  0001 C CNN
	1    2250 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 4250 2400 4250
Connection ~ 2400 4250
Wire Wire Line
	2400 4250 2400 4200
Wire Wire Line
	4850 1950 4850 2050
$Comp
L Device:R RG2
U 1 1 5F91A9DE
P 5500 3250
F 0 "RG2" V 5293 3250 50  0000 C CNN
F 1 "1k" V 5384 3250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5430 3250 50  0001 C CNN
F 3 "~" H 5500 3250 50  0001 C CNN
	1    5500 3250
	0    -1   1    0   
$EndComp
$Comp
L Device:R RB1
U 1 1 5F91B206
P 5500 3950
F 0 "RB1" V 5293 3950 50  0000 C CNN
F 1 "1k" V 5384 3950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5430 3950 50  0001 C CNN
F 3 "~" H 5500 3950 50  0001 C CNN
	1    5500 3950
	0    -1   1    0   
$EndComp
$Comp
L Device:R RB2
U 1 1 5F91B4D6
P 5500 4300
F 0 "RB2" V 5293 4300 50  0000 C CNN
F 1 "1k" V 5384 4300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5430 4300 50  0001 C CNN
F 3 "~" H 5500 4300 50  0001 C CNN
	1    5500 4300
	0    -1   1    0   
$EndComp
$Comp
L Device:LED DB1
U 1 1 5F91F5AE
P 5800 3950
F 0 "DB1" H 5793 4166 50  0000 C CNN
F 1 "BLUE" H 5793 4075 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5800 3950 50  0001 C CNN
F 3 "~" H 5800 3950 50  0001 C CNN
	1    5800 3950
	-1   0    0    -1  
$EndComp
$Comp
L Device:R RG1
U 1 1 5F91AD16
P 5500 2900
F 0 "RG1" V 5293 2900 50  0000 C CNN
F 1 "1k" V 5384 2900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5430 2900 50  0001 C CNN
F 3 "~" H 5500 2900 50  0001 C CNN
	1    5500 2900
	0    -1   1    0   
$EndComp
$Comp
L Device:LED DG1
U 1 1 5F927A5E
P 5800 2900
F 0 "DG1" H 5793 3116 50  0000 C CNN
F 1 "LED" H 5793 3025 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5800 2900 50  0001 C CNN
F 3 "~" H 5800 2900 50  0001 C CNN
	1    5800 2900
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED DG2
U 1 1 5F929897
P 5800 3250
F 0 "DG2" H 5793 3466 50  0000 C CNN
F 1 "LED" H 5793 3375 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5800 3250 50  0001 C CNN
F 3 "~" H 5800 3250 50  0001 C CNN
	1    5800 3250
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED DB2
U 1 1 5F91F818
P 5800 4300
F 0 "DB2" H 5793 4516 50  0000 C CNN
F 1 "BLUE" H 5793 4425 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5800 4300 50  0001 C CNN
F 3 "~" H 5800 4300 50  0001 C CNN
	1    5800 4300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5950 3250 6800 3250
Wire Wire Line
	5950 2900 6800 2900
Wire Wire Line
	6800 2900 6800 3250
Connection ~ 6800 3250
Wire Wire Line
	6800 3250 6800 3600
Wire Wire Line
	3750 2900 5350 2900
Wire Wire Line
	3850 3250 3850 3600
Wire Wire Line
	3850 3600 3550 3600
Wire Wire Line
	3850 3250 5350 3250
Wire Wire Line
	3950 3600 5350 3600
Wire Wire Line
	5950 3950 6800 3950
Connection ~ 6800 3950
Wire Wire Line
	5950 4300 6800 4300
Wire Wire Line
	5950 4650 6800 4650
Wire Wire Line
	6800 3950 6800 4300
Connection ~ 6800 4300
Wire Wire Line
	6800 4300 6800 4650
Wire Wire Line
	6800 4650 6800 4900
Connection ~ 6800 4650
Wire Wire Line
	5350 4650 3950 4650
Wire Wire Line
	3950 4650 3950 4000
Wire Wire Line
	3950 4000 3550 4000
Wire Wire Line
	5350 4300 4100 4300
Wire Wire Line
	4100 4300 4100 3900
Wire Wire Line
	4100 3900 3550 3900
Wire Wire Line
	3550 3800 4250 3800
Wire Wire Line
	4250 3800 4250 3950
Wire Wire Line
	4250 3950 5350 3950
Wire Wire Line
	3750 3700 3550 3700
Wire Wire Line
	3750 2900 3750 3700
Wire Wire Line
	3950 3600 3950 3500
Wire Wire Line
	3950 3500 3550 3500
$EndSCHEMATC
