EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:stm32
LIBS:graphic
LIBS:ttl_ieee
LIBS:hc11
LIBS:gennum
LIBS:cmos_ieee
LIBS:brooktre
LIBS:relays
LIBS:references
LIBS:rfcom
LIBS:transf
LIBS:supertex
LIBS:video
LIBS:stm8
LIBS:sensors
LIBS:powerint
LIBS:nxp_armmcu
LIBS:msp430
LIBS:microchip_pic16mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic10mcu
LIBS:logo
LIBS:ftdi
LIBS:ac-dc
LIBS:pspice
LIBS:microchip1
LIBS:elec-unifil
LIBS:74xgxx
LIBS:dc-dc
LIBS:test-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "WebDroid  Neuraxis"
Date "28 sep 2013"
Rev ""
Comp "BSUIR 2013"
Comment1 "Designed by Denis Vashchuk, Alex Lapuka"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L STM32F103C8 U1
U 1 1 52384296
P 4200 3150
F 0 "U1" H 3300 4300 60  0000 C CNN
F 1 "STM32F103C8" H 4150 3400 60  0000 C CNN
F 2 "" H 4200 3150 60  0000 C CNN
F 3 "" H 4200 3150 60  0000 C CNN
	1    4200 3150
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR01
U 1 1 52384351
P 5600 1800
F 0 "#PWR01" H 5600 1900 30  0001 C CNN
F 1 "VDD" H 5600 1910 30  0000 C CNN
F 2 "" H 5600 1800 60  0000 C CNN
F 3 "" H 5600 1800 60  0000 C CNN
	1    5600 1800
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR02
U 1 1 52384369
P 5000 4750
F 0 "#PWR02" H 5000 4750 30  0001 C CNN
F 1 "VSS" H 5000 4650 30  0000 C CNN
F 2 "" H 5000 4750 60  0000 C CNN
F 3 "" H 5000 4750 60  0000 C CNN
	1    5000 4750
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR03
U 1 1 5238437E
P 5450 2700
F 0 "#PWR03" H 5450 2700 30  0001 C CNN
F 1 "VSS" H 5450 2630 30  0000 C CNN
F 2 "" H 5450 2700 60  0000 C CNN
F 3 "" H 5450 2700 60  0000 C CNN
	1    5450 2700
	0    -1   1    0   
$EndComp
$Comp
L VSS #PWR04
U 1 1 5238438D
P 3750 1900
F 0 "#PWR04" H 3750 1900 30  0001 C CNN
F 1 "VSS" H 3750 1830 30  0000 C CNN
F 2 "" H 3750 1900 60  0000 C CNN
F 3 "" H 3750 1900 60  0000 C CNN
	1    3750 1900
	1    0    0    1   
$EndComp
$Comp
L VSS #PWR05
U 1 1 52384452
P 2950 3400
F 0 "#PWR05" H 2950 3400 30  0001 C CNN
F 1 "VSS" H 2950 3330 30  0000 C CNN
F 2 "" H 2950 3400 60  0000 C CNN
F 3 "" H 2950 3400 60  0000 C CNN
	1    2950 3400
	0    1    -1   0   
$EndComp
$Comp
L CRYSTAL 8MHz1
U 1 1 52384923
P 2100 2800
F 0 "8MHz1" H 2100 2950 60  0000 C CNN
F 1 "CRYSTAL" H 2100 2650 60  0000 C CNN
F 2 "~" H 2100 2800 60  0000 C CNN
F 3 "~" H 2100 2800 60  0000 C CNN
	1    2100 2800
	0    1    1    0   
$EndComp
$Comp
L CSMALL C3
U 1 1 52384985
P 1600 3000
F 0 "C3" H 1625 3050 30  0000 L CNN
F 1 "20pF" H 1625 2950 30  0000 L CNN
F 2 "~" H 1600 3000 60  0000 C CNN
F 3 "~" H 1600 3000 60  0000 C CNN
	1    1600 3000
	1    0    0    -1  
$EndComp
$Comp
L CSMALL C2
U 1 1 52384995
P 1600 2600
F 0 "C2" H 1625 2650 30  0000 L CNN
F 1 "20pF" H 1625 2550 30  0000 L CNN
F 2 "~" H 1600 2600 60  0000 C CNN
F 3 "~" H 1600 2600 60  0000 C CNN
	1    1600 2600
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR06
U 1 1 52384A32
P 1550 2800
F 0 "#PWR06" H 1550 2800 30  0001 C CNN
F 1 "VSS" H 1550 2730 30  0000 C CNN
F 2 "" H 1550 2800 60  0000 C CNN
F 3 "" H 1550 2800 60  0000 C CNN
	1    1550 2800
	0    1    -1   0   
$EndComp
$Comp
L CSMALL C1
U 1 1 52384A58
P 1250 3300
F 0 "C1" H 1275 3350 30  0000 L CNN
F 1 "100nF" H 1275 3250 30  0000 L CNN
F 2 "~" H 1250 3300 60  0000 C CNN
F 3 "~" H 1250 3300 60  0000 C CNN
	1    1250 3300
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR07
U 1 1 52384A67
P 1250 3400
F 0 "#PWR07" H 1250 3400 30  0001 C CNN
F 1 "VSS" H 1250 3330 30  0000 C CNN
F 2 "" H 1250 3400 60  0000 C CNN
F 3 "" H 1250 3400 60  0000 C CNN
	1    1250 3400
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH reset1
U 1 1 52384A97
P 950 3200
F 0 "reset1" H 1100 3310 50  0000 C CNN
F 1 "SW_PUSH" H 950 3120 50  0000 C CNN
F 2 "~" H 950 3200 60  0000 C CNN
F 3 "~" H 950 3200 60  0000 C CNN
	1    950  3200
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 523EA337
P 5300 1000
F 0 "R4" V 5380 1000 40  0000 C CNN
F 1 "510" V 5307 1001 40  0000 C CNN
F 2 "~" V 5230 1000 30  0000 C CNN
F 3 "~" H 5300 1000 30  0000 C CNN
	1    5300 1000
	0    -1   -1   0   
$EndComp
$Comp
L VSS #PWR08
U 1 1 523EA37B
P 5550 1000
F 0 "#PWR08" H 5550 1000 30  0001 C CNN
F 1 "VSS" H 5550 930 30  0000 C CNN
F 2 "" H 5550 1000 60  0000 C CNN
F 3 "" H 5550 1000 60  0000 C CNN
	1    5550 1000
	0    -1   1    0   
$EndComp
$Comp
L VDD #PWR09
U 1 1 523EA418
P 650 3400
F 0 "#PWR09" H 650 3500 30  0001 C CNN
F 1 "VDD" H 650 3510 30  0000 C CNN
F 2 "" H 650 3400 60  0000 C CNN
F 3 "" H 650 3400 60  0000 C CNN
	1    650  3400
	1    0    0    1   
$EndComp
$Comp
L R R1
U 1 1 52419944
P 1550 3450
F 0 "R1" V 1630 3450 49  0000 C CNN
F 1 "330" V 1557 3451 40  0000 C CNN
F 2 "~" V 1480 3450 30  0000 C CNN
F 3 "~" H 1550 3450 30  0000 C CNN
	1    1550 3450
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR010
U 1 1 52419A67
P 1550 3700
F 0 "#PWR010" H 1550 3660 30  0001 C CNN
F 1 "+3.3V" H 1550 3810 30  0000 C CNN
F 2 "" H 1550 3700 60  0000 C CNN
F 3 "" H 1550 3700 60  0000 C CNN
	1    1550 3700
	1    0    0    1   
$EndComp
$Comp
L R R2
U 1 1 5241A467
P 3800 1000
F 0 "R2" V 3880 1000 40  0000 C CNN
F 1 "10k" V 3807 1001 40  0000 C CNN
F 2 "~" V 3730 1000 30  0000 C CNN
F 3 "~" H 3800 1000 30  0000 C CNN
	1    3800 1000
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR011
U 1 1 5241A48F
P 3550 1000
F 0 "#PWR011" H 3550 960 30  0001 C CNN
F 1 "+3.3V" H 3550 1110 30  0000 C CNN
F 2 "" H 3550 1000 60  0000 C CNN
F 3 "" H 3550 1000 60  0000 C CNN
	1    3550 1000
	1    0    0    -1  
$EndComp
$Comp
L BREAKER JP_BOOT1
U 1 1 5241A550
P 4550 1000
F 0 "JP_BOOT1" H 4550 950 50  0000 C CNN
F 1 "BREAKER" H 4550 850 50  0000 C CNN
F 2 "~" H 4550 1000 60  0000 C CNN
F 3 "~" H 4550 1000 60  0000 C CNN
	1    4550 1000
	1    0    0    -1  
$EndComp
Text Notes 6850 2900 0    60   ~ 0
service\dbg  115200 8N1 uart
$Comp
L BREAKER JP_BOOT2
U 1 1 52445DA3
P 6150 5750
F 0 "JP_BOOT2" H 6150 5700 50  0000 C CNN
F 1 "BREAKER" H 6150 5600 50  0000 C CNN
F 2 "~" H 6150 5750 60  0000 C CNN
F 3 "~" H 6150 5750 60  0000 C CNN
	1    6150 5750
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR012
U 1 1 52445DC5
P 5150 5750
F 0 "#PWR012" H 5150 5710 30  0001 C CNN
F 1 "+3.3V" H 5150 5860 30  0000 C CNN
F 2 "" H 5150 5750 60  0000 C CNN
F 3 "" H 5150 5750 60  0000 C CNN
	1    5150 5750
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 52445DD4
P 5400 5750
F 0 "R3" V 5480 5750 40  0000 C CNN
F 1 "10k" V 5407 5751 40  0000 C CNN
F 2 "~" V 5330 5750 30  0000 C CNN
F 3 "~" H 5400 5750 30  0000 C CNN
	1    5400 5750
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 52445DE3
P 6900 5750
F 0 "R5" V 6980 5750 40  0000 C CNN
F 1 "510" V 6907 5751 40  0000 C CNN
F 2 "~" V 6830 5750 30  0000 C CNN
F 3 "~" H 6900 5750 30  0000 C CNN
	1    6900 5750
	0    -1   -1   0   
$EndComp
$Comp
L VSS #PWR013
U 1 1 52445EB2
P 7150 5800
F 0 "#PWR013" H 7150 5800 30  0001 C CNN
F 1 "VSS" H 7150 5730 30  0000 C CNN
F 2 "" H 7150 5800 60  0000 C CNN
F 3 "" H 7150 5800 60  0000 C CNN
	1    7150 5800
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 USART3
U 1 1 52446EDB
P 4550 4950
F 0 "USART3" V 4500 4950 50  0000 C CNN
F 1 "CONN1" V 4600 4950 40  0000 C CNN
F 2 "~" H 4550 4950 60  0000 C CNN
F 3 "~" H 4550 4950 60  0000 C CNN
	1    4550 4950
	0    1    1    0   
$EndComp
$Comp
L CONN_3 USART1
U 1 1 52446EEA
P 7000 3100
F 0 "USART1" V 6950 3100 50  0000 C CNN
F 1 "CONN2" V 7050 3100 40  0000 C CNN
F 2 "~" H 7000 3100 60  0000 C CNN
F 3 "~" H 7000 3100 60  0000 C CNN
	1    7000 3100
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR014
U 1 1 524470BD
P 6650 3000
F 0 "#PWR014" H 6650 3000 30  0001 C CNN
F 1 "VSS" H 6650 2930 30  0000 C CNN
F 2 "" H 6650 3000 60  0000 C CNN
F 3 "" H 6650 3000 60  0000 C CNN
	1    6650 3000
	0    1    1    0   
$EndComp
Text Label 4350 4550 0    60   ~ 0
TX
$Comp
L CONN_3 SWD1
U 1 1 52447629
P 7100 2000
F 0 "SWD1" V 7050 2000 50  0000 C CNN
F 1 "CONN_3" V 7150 2000 40  0000 C CNN
F 2 "~" H 7100 2000 60  0000 C CNN
F 3 "~" H 7100 2000 60  0000 C CNN
	1    7100 2000
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR016
U 1 1 52447673
P 6750 2200
F 0 "#PWR016" H 6750 2200 30  0001 C CNN
F 1 "VSS" H 6750 2130 30  0000 C CNN
F 2 "" H 6750 2200 60  0000 C CNN
F 3 "" H 6750 2200 60  0000 C CNN
	1    6750 2200
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR?
U 1 1 524761E2
P 9700 750
F 0 "#PWR?" H 9700 700 20  0001 C CNN
F 1 "+12V" H 9700 850 30  0000 C CNN
F 2 "" H 9700 750 60  0000 C CNN
F 3 "" H 9700 750 60  0000 C CNN
	1    9700 750 
	1    0    0    -1  
$EndComp
Connection ~ 5600 2600
Wire Wire Line
	5600 4500 4750 4500
Wire Wire Line
	4750 4500 4750 4400
Wire Wire Line
	5600 2600 5450 2600
Wire Wire Line
	5600 1800 2700 1800
Wire Wire Line
	2700 1550 2700 3300
Wire Wire Line
	2700 2600 2950 2600
Wire Wire Line
	2700 3300 2950 3300
Connection ~ 2700 2600
Wire Wire Line
	5450 3200 6650 3200
Wire Wire Line
	5450 3100 6650 3100
Wire Wire Line
	4050 1900 4050 1000
Wire Wire Line
	1250 3200 2950 3200
Wire Wire Line
	1600 3100 2950 3100
Wire Wire Line
	2950 3000 2250 3000
Wire Wire Line
	2250 3000 2250 2500
Wire Wire Line
	2250 2500 1600 2500
Connection ~ 2100 3100
Connection ~ 2100 2500
Wire Wire Line
	1600 2700 1600 2900
Wire Wire Line
	1600 2800 1550 2800
Connection ~ 1600 2800
Connection ~ 2100 3200
Wire Wire Line
	650  3200 650  3400
Wire Wire Line
	4150 1900 4150 1150
Wire Wire Line
	4150 1150 8600 1150
Wire Wire Line
	4250 1900 4250 1250
Wire Wire Line
	4250 1250 8450 1250
Wire Wire Line
	4350 1350 7800 1350
Wire Wire Line
	4450 1900 4450 1450
Wire Wire Line
	4450 1450 7800 1450
Wire Wire Line
	4350 1900 4350 1350
Wire Wire Line
	5600 1800 5600 4500
Wire Wire Line
	4550 1900 4550 1550
Wire Wire Line
	4550 1550 7800 1550
Wire Wire Line
	4650 1900 4650 1650
Wire Wire Line
	4650 1650 7800 1650
Connection ~ 2700 1800
Wire Wire Line
	7150 5750 7150 5800
Wire Wire Line
	4750 1900 6750 1900
Wire Wire Line
	5450 2800 5700 2800
Wire Wire Line
	5700 2800 5700 2000
Wire Wire Line
	5700 2000 6750 2000
Wire Wire Line
	6750 2100 6750 2200
Wire Wire Line
	4450 4400 4450 4600
Wire Wire Line
	4550 4600 4550 4400
Wire Wire Line
	2950 3500 2700 3500
Wire Wire Line
	2700 3500 2700 4750
Wire Wire Line
	2950 3600 2800 3600
Wire Wire Line
	2800 3600 2800 4900
Wire Wire Line
	4200 5300 5650 5300
Wire Wire Line
	4200 5300 4200 4500
Wire Wire Line
	4200 4500 4350 4500
Wire Wire Line
	4350 4500 4350 4400
Wire Wire Line
	2950 3700 2900 3700
Wire Wire Line
	2900 3700 2900 5050
Wire Wire Line
	3650 4400 3650 4450
Wire Wire Line
	3650 4450 3000 4450
Wire Wire Line
	3000 4450 3000 5200
$Comp
L IR4426 KEY?
U 1 1 524767BD
P 2550 6350
F 0 "KEY?" H 2600 6150 60  0000 C CNN
F 1 "IR4426" H 2550 6650 60  0000 C CNN
F 2 "" H 2600 6400 60  0000 C CNN
F 3 "" H 2600 6400 60  0000 C CNN
	1    2550 6350
	1    0    0    -1  
$EndComp
$Comp
L IR4426 KEY?
U 1 1 524767C3
P 2550 7150
F 0 "KEY?" H 2600 6950 60  0000 C CNN
F 1 "IR4426" H 2550 7450 60  0000 C CNN
F 2 "" H 2600 7200 60  0000 C CNN
F 3 "" H 2600 7200 60  0000 C CNN
	1    2550 7150
	1    0    0    -1  
$EndComp
$Comp
L CONN_4 P?
U 1 1 524767C9
P 4000 6650
F 0 "P?" V 3950 6650 50  0000 C CNN
F 1 "engine_23" V 4050 6650 50  0000 C CNN
F 2 "~" H 4000 6650 60  0000 C CNN
F 3 "~" H 4000 6650 60  0000 C CNN
	1    4000 6650
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR?
U 1 1 524767CF
P 2050 6350
F 0 "#PWR?" H 2050 6350 30  0001 C CNN
F 1 "VSS" H 2050 6280 30  0000 C CNN
F 2 "" H 2050 6350 60  0000 C CNN
F 3 "" H 2050 6350 60  0000 C CNN
	1    2050 6350
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR?
U 1 1 524767D5
P 2050 7150
F 0 "#PWR?" H 2050 7150 30  0001 C CNN
F 1 "VSS" H 2050 7080 30  0000 C CNN
F 2 "" H 2050 7150 60  0000 C CNN
F 3 "" H 2050 7150 60  0000 C CNN
	1    2050 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 7150 3100 7150
Wire Wire Line
	3100 6350 3350 6350
Connection ~ 3350 6350
Wire Wire Line
	3100 6250 3650 6250
Wire Wire Line
	3650 6250 3650 6500
Wire Wire Line
	3100 6450 3550 6450
Wire Wire Line
	3550 6450 3550 6600
Wire Wire Line
	3550 6600 3650 6600
Wire Wire Line
	3100 7050 3550 7050
Wire Wire Line
	3550 7050 3550 6700
Wire Wire Line
	3550 6700 3650 6700
Wire Wire Line
	3100 7250 3650 7250
Wire Wire Line
	3650 7250 3650 6800
$Comp
L +12V #PWR?
U 1 1 52476854
P 3350 6000
F 0 "#PWR?" H 3350 5950 20  0001 C CNN
F 1 "+12V" H 3350 6100 30  0000 C CNN
F 2 "" H 3350 6000 60  0000 C CNN
F 3 "" H 3350 6000 60  0000 C CNN
	1    3350 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 6000 3350 7150
Wire Wire Line
	2700 4750 650  4750
Wire Wire Line
	650  4750 650  7250
Wire Wire Line
	650  7250 2050 7250
Wire Wire Line
	2800 4900 800  4900
Wire Wire Line
	800  4900 800  7050
Wire Wire Line
	800  7050 2050 7050
Wire Wire Line
	2900 5050 1000 5050
Wire Wire Line
	1000 5050 1000 6450
Wire Wire Line
	1000 6450 2050 6450
Wire Wire Line
	3000 5200 1200 5200
Wire Wire Line
	1200 5200 1200 6250
Wire Wire Line
	1200 6250 2050 6250
Wire Wire Line
	5650 5300 5650 5750
Wire Wire Line
	4650 4400 4650 4600
Wire Wire Line
	4650 4600 5000 4600
Wire Wire Line
	5000 4600 5000 4750
Wire Wire Line
	3650 1900 3650 1800
Connection ~ 3650 1800
Wire Wire Line
	3950 1900 3950 1200
$Comp
L CONN_4 P?
U 1 1 52477232
P 8150 1500
F 0 "P?" V 8100 1500 50  0000 C CNN
F 1 "servo_12" V 8200 1500 50  0000 C CNN
F 2 "~" H 8150 1500 60  0000 C CNN
F 3 "~" H 8150 1500 60  0000 C CNN
	1    8150 1500
	1    0    0    -1  
$EndComp
$Comp
L IR4426 KEY?
U 1 1 5247723F
P 9100 1250
F 0 "KEY?" H 9150 1050 60  0000 C CNN
F 1 "IR4426" H 9100 1550 60  0000 C CNN
F 2 "" H 9150 1300 60  0000 C CNN
F 3 "" H 9150 1300 60  0000 C CNN
	1    9100 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 1250 8450 1350
Wire Wire Line
	8450 1350 8600 1350
$Comp
L IR4426 KEY?
U 1 1 5247734B
P 2050 1300
F 0 "KEY?" H 2100 1100 60  0000 C CNN
F 1 "IR4426" H 2050 1600 60  0000 C CNN
F 2 "" H 2100 1350 60  0000 C CNN
F 3 "" H 2100 1350 60  0000 C CNN
	1    2050 1300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3950 1200 2550 1200
Wire Wire Line
	2550 1400 3850 1400
Wire Wire Line
	3850 1400 3850 1900
$Comp
L CONN_2 P?
U 1 1 52477560
P 1150 1300
F 0 "P?" V 1100 1300 40  0000 C CNN
F 1 "engine_1" V 1200 1300 40  0000 C CNN
F 2 "~" H 1150 1300 60  0000 C CNN
F 3 "~" H 1150 1300 60  0000 C CNN
	1    1150 1300
	-1   0    0    -1  
$EndComp
$Comp
L CONN_2 P?
U 1 1 5247758D
P 10000 1250
F 0 "P?" V 9950 1250 40  0000 C CNN
F 1 "engine_4" V 10050 1250 40  0000 C CNN
F 2 "~" H 10000 1250 60  0000 C CNN
F 3 "~" H 10000 1250 60  0000 C CNN
	1    10000 1250
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR?
U 1 1 524775A2
P 1450 950
F 0 "#PWR?" H 1450 900 20  0001 C CNN
F 1 "+12V" H 1450 1050 30  0000 C CNN
F 2 "" H 1450 950 60  0000 C CNN
F 3 "" H 1450 950 60  0000 C CNN
	1    1450 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 950  1450 1300
Wire Wire Line
	1450 1300 1500 1300
Wire Wire Line
	9650 1250 9700 1250
Wire Wire Line
	9700 1250 9700 750 
$Comp
L VSS #PWR?
U 1 1 5247767F
P 8550 1500
F 0 "#PWR?" H 8550 1500 30  0001 C CNN
F 1 "VSS" H 8550 1430 30  0000 C CNN
F 2 "" H 8550 1500 60  0000 C CNN
F 3 "" H 8550 1500 60  0000 C CNN
	1    8550 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 1250 8550 1250
Wire Wire Line
	8550 1250 8550 1500
$Comp
L VSS #PWR?
U 1 1 524776EE
P 2600 1550
F 0 "#PWR?" H 2600 1550 30  0001 C CNN
F 1 "VSS" H 2600 1480 30  0000 C CNN
F 2 "" H 2600 1550 60  0000 C CNN
F 3 "" H 2600 1550 60  0000 C CNN
	1    2600 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 1300 2600 1300
Wire Wire Line
	2600 1300 2600 1550
Text Notes 4400 5200 0    60   ~ 0
115200 8N1 commands\n
Text Notes 5900 1350 0    60   ~ 0
For 2 servo
$EndSCHEMATC