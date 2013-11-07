EESchema Schematic File Version 2
LIBS:stm32
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
LIBS:netdroid-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "WebDroid  Neuraxis"
Date "7 nov 2013"
Rev ""
Comp "BSUIR 2013"
Comment1 "Designed by Denis Vashchuk, Alex Lapuka"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CRYSTAL 8MHz1
U 1 1 52384923
P 3550 4350
F 0 "8MHz1" H 3550 4500 60  0000 C CNN
F 1 "CRYSTAL" H 3550 4200 60  0000 C CNN
F 2 "~" H 3550 4350 60  0000 C CNN
F 3 "~" H 3550 4350 60  0000 C CNN
	1    3550 4350
	0    1    1    0   
$EndComp
$Comp
L CSMALL C3
U 1 1 52384985
P 3050 4550
F 0 "C3" H 3075 4600 30  0000 L CNN
F 1 "20pF" H 3075 4500 30  0000 L CNN
F 2 "~" H 3050 4550 60  0000 C CNN
F 3 "~" H 3050 4550 60  0000 C CNN
	1    3050 4550
	1    0    0    -1  
$EndComp
$Comp
L CSMALL C2
U 1 1 52384995
P 3050 4150
F 0 "C2" H 3075 4200 30  0000 L CNN
F 1 "20pF" H 3075 4100 30  0000 L CNN
F 2 "~" H 3050 4150 60  0000 C CNN
F 3 "~" H 3050 4150 60  0000 C CNN
	1    3050 4150
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR01
U 1 1 52384A32
P 2950 4350
F 0 "#PWR01" H 2950 4350 30  0001 C CNN
F 1 "VSS" H 2950 4280 30  0000 C CNN
F 2 "" H 2950 4350 60  0000 C CNN
F 3 "" H 2950 4350 60  0000 C CNN
	1    2950 4350
	0    1    -1   0   
$EndComp
$Comp
L CSMALL C1
U 1 1 52384A58
P 4000 3250
F 0 "C1" H 4025 3300 30  0000 L CNN
F 1 "100nF" H 4025 3200 30  0000 L CNN
F 2 "~" H 4000 3250 60  0000 C CNN
F 3 "~" H 4000 3250 60  0000 C CNN
	1    4000 3250
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR02
U 1 1 52384A67
P 4000 3350
F 0 "#PWR02" H 4000 3350 30  0001 C CNN
F 1 "VSS" H 4000 3280 30  0000 C CNN
F 2 "" H 4000 3350 60  0000 C CNN
F 3 "" H 4000 3350 60  0000 C CNN
	1    4000 3350
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH reset1
U 1 1 52384A97
P 3700 3150
F 0 "reset1" H 3850 3260 50  0000 C CNN
F 1 "SW_PUSH" H 3700 3070 50  0000 C CNN
F 2 "~" H 3700 3150 60  0000 C CNN
F 3 "~" H 3700 3150 60  0000 C CNN
	1    3700 3150
	1    0    0    -1  
$EndComp
Text Notes 9100 4550 0    60   ~ 0
service\dbg  115200 8N1 uart
$Comp
L BREAKER JP_BOOT1
U 1 1 52445DA3
P 1700 4700
F 0 "JP_BOOT1" H 1700 4650 50  0000 C CNN
F 1 "BREAKER" H 1700 4550 50  0000 C CNN
F 2 "~" H 1700 4700 60  0000 C CNN
F 3 "~" H 1700 4700 60  0000 C CNN
	1    1700 4700
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 52445DD4
P 950 4700
F 0 "R3" V 1030 4700 40  0000 C CNN
F 1 "10k" V 957 4701 40  0000 C CNN
F 2 "~" V 880 4700 30  0000 C CNN
F 3 "~" H 950 4700 30  0000 C CNN
	1    950  4700
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 52445DE3
P 2450 4700
F 0 "R5" V 2530 4700 40  0000 C CNN
F 1 "510" V 2457 4701 40  0000 C CNN
F 2 "~" V 2380 4700 30  0000 C CNN
F 3 "~" H 2450 4700 30  0000 C CNN
	1    2450 4700
	0    -1   -1   0   
$EndComp
$Comp
L VSS #PWR03
U 1 1 52445EB2
P 2700 4750
F 0 "#PWR03" H 2700 4750 30  0001 C CNN
F 1 "VSS" H 2700 4680 30  0000 C CNN
F 2 "" H 2700 4750 60  0000 C CNN
F 3 "" H 2700 4750 60  0000 C CNN
	1    2700 4750
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR04
U 1 1 524470BD
P 8900 4650
F 0 "#PWR04" H 8900 4650 30  0001 C CNN
F 1 "VSS" H 8900 4580 30  0000 C CNN
F 2 "" H 8900 4650 60  0000 C CNN
F 3 "" H 8900 4650 60  0000 C CNN
	1    8900 4650
	0    1    1    0   
$EndComp
$Comp
L CONN_2 ENG3
U 1 1 5247758D
P 10200 1400
F 0 "ENG3" V 10150 1400 40  0000 C CNN
F 1 "engpin" V 10250 1400 40  0000 C CNN
F 2 "~" H 10200 1400 60  0000 C CNN
F 3 "~" H 10200 1400 60  0000 C CNN
	1    10200 1400
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR05
U 1 1 5247767F
P 8550 2900
F 0 "#PWR05" H 8550 2900 30  0001 C CNN
F 1 "VSS" H 8550 2830 30  0000 C CNN
F 2 "" H 8550 2900 60  0000 C CNN
F 3 "" H 8550 2900 60  0000 C CNN
	1    8550 2900
	1    0    0    -1  
$EndComp
$Comp
L DIODE D44
U 1 1 524844F0
P 9750 2950
F 0 "D44" H 9750 3050 40  0000 C CNN
F 1 "DIODE" H 9750 2850 40  0000 C CNN
F 2 "~" H 9750 2950 60  0000 C CNN
F 3 "~" H 9750 2950 60  0000 C CNN
	1    9750 2950
	0    1    -1   0   
$EndComp
$Comp
L DIODE D43
U 1 1 524844FF
P 9500 2850
F 0 "D43" H 9500 2950 40  0000 C CNN
F 1 "DIODE" H 9500 2750 40  0000 C CNN
F 2 "~" H 9500 2850 60  0000 C CNN
F 3 "~" H 9500 2850 60  0000 C CNN
	1    9500 2850
	0    -1   -1   0   
$EndComp
$Comp
L DIODE D41
U 1 1 5248450E
P 9500 2200
F 0 "D41" H 9500 2300 40  0000 C CNN
F 1 "DIODE" H 9500 2100 40  0000 C CNN
F 2 "~" H 9500 2200 60  0000 C CNN
F 3 "~" H 9500 2200 60  0000 C CNN
	1    9500 2200
	1    0    0    -1  
$EndComp
$Comp
L DIODE D42
U 1 1 5248451D
P 9800 2350
F 0 "D42" H 9800 2450 40  0000 C CNN
F 1 "DIODE" H 9800 2250 40  0000 C CNN
F 2 "~" H 9800 2350 60  0000 C CNN
F 3 "~" H 9800 2350 60  0000 C CNN
	1    9800 2350
	0    1    1    0   
$EndComp
$Comp
L VSS #PWR06
U 1 1 524846CF
P 9750 3150
F 0 "#PWR06" H 9750 3150 30  0001 C CNN
F 1 "VSS" H 9750 3080 30  0000 C CNN
F 2 "" H 9750 3150 60  0000 C CNN
F 3 "" H 9750 3150 60  0000 C CNN
	1    9750 3150
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR07
U 1 1 5248471E
P 10050 2200
F 0 "#PWR07" H 10050 2200 30  0001 C CNN
F 1 "VSS" H 10050 2130 30  0000 C CNN
F 2 "" H 10050 2200 60  0000 C CNN
F 3 "" H 10050 2200 60  0000 C CNN
	1    10050 2200
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR08
U 1 1 524852D5
P 2350 5250
F 0 "#PWR08" H 2350 5200 20  0001 C CNN
F 1 "+12V" H 2350 5350 30  0000 C CNN
F 2 "" H 2350 5250 60  0000 C CNN
F 3 "" H 2350 5250 60  0000 C CNN
	1    2350 5250
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 ENG1
U 1 1 524852E5
P 2900 5750
F 0 "ENG1" V 2850 5750 40  0000 C CNN
F 1 "engpin" V 2950 5750 40  0000 C CNN
F 2 "~" H 2900 5750 60  0000 C CNN
F 3 "~" H 2900 5750 60  0000 C CNN
	1    2900 5750
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR09
U 1 1 524852ED
P 1200 6000
F 0 "#PWR09" H 1200 6000 30  0001 C CNN
F 1 "VSS" H 1200 5930 30  0000 C CNN
F 2 "" H 1200 6000 60  0000 C CNN
F 3 "" H 1200 6000 60  0000 C CNN
	1    1200 6000
	1    0    0    -1  
$EndComp
$Comp
L DIODE D14
U 1 1 524852F5
P 2400 6050
F 0 "D14" H 2400 6150 40  0000 C CNN
F 1 "DIODE" H 2400 5950 40  0000 C CNN
F 2 "~" H 2400 6050 60  0000 C CNN
F 3 "~" H 2400 6050 60  0000 C CNN
	1    2400 6050
	0    1    -1   0   
$EndComp
$Comp
L DIODE D13
U 1 1 524852FB
P 2150 5950
F 0 "D13" H 2150 6050 40  0000 C CNN
F 1 "DIODE" H 2150 5850 40  0000 C CNN
F 2 "~" H 2150 5950 60  0000 C CNN
F 3 "~" H 2150 5950 60  0000 C CNN
	1    2150 5950
	0    -1   -1   0   
$EndComp
$Comp
L DIODE D11
U 1 1 52485301
P 2150 5300
F 0 "D11" H 2150 5400 40  0000 C CNN
F 1 "DIODE" H 2150 5200 40  0000 C CNN
F 2 "~" H 2150 5300 60  0000 C CNN
F 3 "~" H 2150 5300 60  0000 C CNN
	1    2150 5300
	1    0    0    -1  
$EndComp
$Comp
L DIODE D12
U 1 1 52485307
P 2450 5450
F 0 "D12" H 2450 5550 40  0000 C CNN
F 1 "DIODE" H 2450 5350 40  0000 C CNN
F 2 "~" H 2450 5450 60  0000 C CNN
F 3 "~" H 2450 5450 60  0000 C CNN
	1    2450 5450
	0    1    1    0   
$EndComp
$Comp
L VSS #PWR010
U 1 1 5248530F
P 2400 6250
F 0 "#PWR010" H 2400 6250 30  0001 C CNN
F 1 "VSS" H 2400 6180 30  0000 C CNN
F 2 "" H 2400 6250 60  0000 C CNN
F 3 "" H 2400 6250 60  0000 C CNN
	1    2400 6250
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR011
U 1 1 52485315
P 2700 5300
F 0 "#PWR011" H 2700 5300 30  0001 C CNN
F 1 "VSS" H 2700 5230 30  0000 C CNN
F 2 "" H 2700 5300 60  0000 C CNN
F 3 "" H 2700 5300 60  0000 C CNN
	1    2700 5300
	1    0    0    -1  
$EndComp
$Comp
L STM32F100C4 U1
U 1 1 525CF722
P 6200 5100
F 0 "U1" H 4900 6750 60  0000 C CNN
F 1 "STM32F100C4" H 7250 3450 60  0000 C CNN
F 2 "LQFP48" H 6200 5100 40  0000 C CIN
F 3 "" H 6200 5100 60  0000 C CNN
	1    6200 5100
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR012
U 1 1 525CF740
P 6050 3350
F 0 "#PWR012" H 6050 3450 30  0001 C CNN
F 1 "VDD" H 6050 3460 30  0000 C CNN
F 2 "" H 6050 3350 60  0000 C CNN
F 3 "" H 6050 3350 60  0000 C CNN
	1    6050 3350
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR013
U 1 1 525CF74F
P 6200 3350
F 0 "#PWR013" H 6200 3450 30  0001 C CNN
F 1 "VDD" H 6200 3460 30  0000 C CNN
F 2 "" H 6200 3350 60  0000 C CNN
F 3 "" H 6200 3350 60  0000 C CNN
	1    6200 3350
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR014
U 1 1 525CF75E
P 6500 3350
F 0 "#PWR014" H 6500 3450 30  0001 C CNN
F 1 "VDD" H 6500 3460 30  0000 C CNN
F 2 "" H 6500 3350 60  0000 C CNN
F 3 "" H 6500 3350 60  0000 C CNN
	1    6500 3350
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR015
U 1 1 525CF76D
P 5900 6850
F 0 "#PWR015" H 5900 6850 30  0001 C CNN
F 1 "VSS" H 5900 6780 30  0000 C CNN
F 2 "" H 5900 6850 60  0000 C CNN
F 3 "" H 5900 6850 60  0000 C CNN
	1    5900 6850
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR016
U 1 1 525CF77C
P 6050 6850
F 0 "#PWR016" H 6050 6850 30  0001 C CNN
F 1 "VSS" H 6050 6780 30  0000 C CNN
F 2 "" H 6050 6850 60  0000 C CNN
F 3 "" H 6050 6850 60  0000 C CNN
	1    6050 6850
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR017
U 1 1 525CF78B
P 6200 6850
F 0 "#PWR017" H 6200 6850 30  0001 C CNN
F 1 "VSS" H 6200 6780 30  0000 C CNN
F 2 "" H 6200 6850 60  0000 C CNN
F 3 "" H 6200 6850 60  0000 C CNN
	1    6200 6850
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR018
U 1 1 525CF79A
P 6500 6850
F 0 "#PWR018" H 6500 6850 30  0001 C CNN
F 1 "VSS" H 6500 6780 30  0000 C CNN
F 2 "" H 6500 6850 60  0000 C CNN
F 3 "" H 6500 6850 60  0000 C CNN
	1    6500 6850
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR019
U 1 1 525CF8EF
P 8900 3950
F 0 "#PWR019" H 8900 3950 30  0001 C CNN
F 1 "VSS" H 8900 3880 30  0000 C CNN
F 2 "" H 8900 3950 60  0000 C CNN
F 3 "" H 8900 3950 60  0000 C CNN
	1    8900 3950
	0    1    1    0   
$EndComp
$Comp
L BREAKER JP_BOOT0
U 1 1 525CF90A
P 1700 4350
F 0 "JP_BOOT0" H 1700 4300 50  0000 C CNN
F 1 "BREAKER" H 1700 4200 50  0000 C CNN
F 2 "~" H 1700 4350 60  0000 C CNN
F 3 "~" H 1700 4350 60  0000 C CNN
	1    1700 4350
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 525CF916
P 950 4350
F 0 "R2" V 1030 4350 40  0000 C CNN
F 1 "10k" V 957 4351 40  0000 C CNN
F 2 "~" V 880 4350 30  0000 C CNN
F 3 "~" H 950 4350 30  0000 C CNN
	1    950  4350
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 525CF91C
P 2450 4350
F 0 "R4" V 2530 4350 40  0000 C CNN
F 1 "510" V 2457 4351 40  0000 C CNN
F 2 "~" V 2380 4350 30  0000 C CNN
F 3 "~" H 2450 4350 30  0000 C CNN
	1    2450 4350
	0    -1   -1   0   
$EndComp
$Comp
L VSS #PWR020
U 1 1 525CF922
P 2700 4400
F 0 "#PWR020" H 2700 4400 30  0001 C CNN
F 1 "VSS" H 2700 4330 30  0000 C CNN
F 2 "" H 2700 4400 60  0000 C CNN
F 3 "" H 2700 4400 60  0000 C CNN
	1    2700 4400
	1    0    0    -1  
$EndComp
$Comp
L CONN_4 USART2
U 1 1 525CFE49
P 9250 4100
F 0 "USART2" V 9200 4100 50  0000 C CNN
F 1 "CONN_4" V 9300 4100 50  0000 C CNN
F 2 "" H 9250 4100 60  0000 C CNN
F 3 "" H 9250 4100 60  0000 C CNN
	1    9250 4100
	1    0    0    -1  
$EndComp
$Comp
L CONN_4 USART1
U 1 1 525CFE58
P 9250 4800
F 0 "USART1" V 9200 4800 50  0000 C CNN
F 1 "CONN_4" V 9300 4800 50  0000 C CNN
F 2 "" H 9250 4800 60  0000 C CNN
F 3 "" H 9250 4800 60  0000 C CNN
	1    9250 4800
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR021
U 1 1 525CFE7D
P 8900 5150
F 0 "#PWR021" H 8900 5150 30  0001 C CNN
F 1 "VSS" H 8900 5080 30  0000 C CNN
F 2 "" H 8900 5150 60  0000 C CNN
F 3 "" H 8900 5150 60  0000 C CNN
	1    8900 5150
	0    1    1    0   
$EndComp
$Comp
L VDD #PWR022
U 1 1 525CFE85
P 8900 4950
F 0 "#PWR022" H 8900 5050 30  0001 C CNN
F 1 "VDD" H 8900 5060 30  0000 C CNN
F 2 "" H 8900 4950 60  0000 C CNN
F 3 "" H 8900 4950 60  0000 C CNN
	1    8900 4950
	0    -1   -1   0   
$EndComp
$Comp
L VDD #PWR023
U 1 1 525CFE98
P 8900 4250
F 0 "#PWR023" H 8900 4350 30  0001 C CNN
F 1 "VDD" H 8900 4360 30  0000 C CNN
F 2 "" H 8900 4250 60  0000 C CNN
F 3 "" H 8900 4250 60  0000 C CNN
	1    8900 4250
	0    -1   -1   0   
$EndComp
$Comp
L +12V #PWR024
U 1 1 525D045E
P 2800 6650
F 0 "#PWR024" H 2800 6600 20  0001 C CNN
F 1 "+12V" H 2800 6750 30  0000 C CNN
F 2 "" H 2800 6650 60  0000 C CNN
F 3 "" H 2800 6650 60  0000 C CNN
	1    2800 6650
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 ENG2
U 1 1 525D046A
P 3350 7150
F 0 "ENG2" V 3300 7150 40  0000 C CNN
F 1 "engpin" V 3400 7150 40  0000 C CNN
F 2 "~" H 3350 7150 60  0000 C CNN
F 3 "~" H 3350 7150 60  0000 C CNN
	1    3350 7150
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR025
U 1 1 525D0470
P 1650 7400
F 0 "#PWR025" H 1650 7400 30  0001 C CNN
F 1 "VSS" H 1650 7330 30  0000 C CNN
F 2 "" H 1650 7400 60  0000 C CNN
F 3 "" H 1650 7400 60  0000 C CNN
	1    1650 7400
	1    0    0    -1  
$EndComp
$Comp
L DIODE D24
U 1 1 525D0476
P 2850 7450
F 0 "D24" H 2850 7550 40  0000 C CNN
F 1 "DIODE" H 2850 7350 40  0000 C CNN
F 2 "~" H 2850 7450 60  0000 C CNN
F 3 "~" H 2850 7450 60  0000 C CNN
	1    2850 7450
	0    1    -1   0   
$EndComp
$Comp
L DIODE D23
U 1 1 525D047C
P 2600 7350
F 0 "D23" H 2600 7450 40  0000 C CNN
F 1 "DIODE" H 2600 7250 40  0000 C CNN
F 2 "~" H 2600 7350 60  0000 C CNN
F 3 "~" H 2600 7350 60  0000 C CNN
	1    2600 7350
	0    -1   -1   0   
$EndComp
$Comp
L DIODE D21
U 1 1 525D0482
P 2600 6700
F 0 "D21" H 2600 6800 40  0000 C CNN
F 1 "DIODE" H 2600 6600 40  0000 C CNN
F 2 "~" H 2600 6700 60  0000 C CNN
F 3 "~" H 2600 6700 60  0000 C CNN
	1    2600 6700
	1    0    0    -1  
$EndComp
$Comp
L DIODE D22
U 1 1 525D0488
P 2900 6850
F 0 "D22" H 2900 6950 40  0000 C CNN
F 1 "DIODE" H 2900 6750 40  0000 C CNN
F 2 "~" H 2900 6850 60  0000 C CNN
F 3 "~" H 2900 6850 60  0000 C CNN
	1    2900 6850
	0    1    1    0   
$EndComp
$Comp
L VSS #PWR026
U 1 1 525D048E
P 2850 7650
F 0 "#PWR026" H 2850 7650 30  0001 C CNN
F 1 "VSS" H 2850 7580 30  0000 C CNN
F 2 "" H 2850 7650 60  0000 C CNN
F 3 "" H 2850 7650 60  0000 C CNN
	1    2850 7650
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR027
U 1 1 525D0494
P 3150 6700
F 0 "#PWR027" H 3150 6700 30  0001 C CNN
F 1 "VSS" H 3150 6630 30  0000 C CNN
F 2 "" H 3150 6700 60  0000 C CNN
F 3 "" H 3150 6700 60  0000 C CNN
	1    3150 6700
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 ENG4
U 1 1 525D0888
P 10250 2650
F 0 "ENG4" V 10200 2650 40  0000 C CNN
F 1 "engpin" V 10300 2650 40  0000 C CNN
F 2 "~" H 10250 2650 60  0000 C CNN
F 3 "~" H 10250 2650 60  0000 C CNN
	1    10250 2650
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR028
U 1 1 525D088E
P 8500 1650
F 0 "#PWR028" H 8500 1650 30  0001 C CNN
F 1 "VSS" H 8500 1580 30  0000 C CNN
F 2 "" H 8500 1650 60  0000 C CNN
F 3 "" H 8500 1650 60  0000 C CNN
	1    8500 1650
	1    0    0    -1  
$EndComp
$Comp
L DIODE D33
U 1 1 525D089A
P 9450 1600
F 0 "D33" H 9450 1700 40  0000 C CNN
F 1 "DIODE" H 9450 1500 40  0000 C CNN
F 2 "~" H 9450 1600 60  0000 C CNN
F 3 "~" H 9450 1600 60  0000 C CNN
	1    9450 1600
	0    -1   -1   0   
$EndComp
$Comp
L LED LED1
U 1 1 525D110A
P 6600 7500
F 0 "LED1" H 6600 7600 50  0000 C CNN
F 1 "LED" H 6600 7400 50  0000 C CNN
F 2 "~" H 6600 7500 60  0000 C CNN
F 3 "~" H 6600 7500 60  0000 C CNN
	1    6600 7500
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 525D1119
P 6150 7500
F 0 "R6" V 6230 7500 40  0000 C CNN
F 1 "R" V 6157 7501 40  0000 C CNN
F 2 "~" V 6080 7500 30  0000 C CNN
F 3 "~" H 6150 7500 30  0000 C CNN
	1    6150 7500
	0    -1   -1   0   
$EndComp
$Comp
L VDD #PWR029
U 1 1 525D1128
P 5800 7500
F 0 "#PWR029" H 5800 7600 30  0001 C CNN
F 1 "VDD" H 5800 7610 30  0000 C CNN
F 2 "" H 5800 7500 60  0000 C CNN
F 3 "" H 5800 7500 60  0000 C CNN
	1    5800 7500
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR030
U 1 1 525D1137
P 6800 7500
F 0 "#PWR030" H 6800 7500 30  0001 C CNN
F 1 "VSS" H 6800 7430 30  0000 C CNN
F 2 "" H 6800 7500 60  0000 C CNN
F 3 "" H 6800 7500 60  0000 C CNN
	1    6800 7500
	0    -1   -1   0   
$EndComp
$Comp
L LED LED2
U 1 1 525D114A
P 9150 5550
F 0 "LED2" H 9150 5650 50  0000 C CNN
F 1 "LED" H 9150 5450 50  0000 C CNN
F 2 "~" H 9150 5550 60  0000 C CNN
F 3 "~" H 9150 5550 60  0000 C CNN
	1    9150 5550
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 525D1150
P 8700 5550
F 0 "R7" V 8780 5550 40  0000 C CNN
F 1 "R" V 8707 5551 40  0000 C CNN
F 2 "~" V 8630 5550 30  0000 C CNN
F 3 "~" H 8700 5550 30  0000 C CNN
	1    8700 5550
	0    -1   -1   0   
$EndComp
$Comp
L VSS #PWR031
U 1 1 525D1156
P 9400 5550
F 0 "#PWR031" H 9400 5550 30  0001 C CNN
F 1 "VSS" H 9400 5480 30  0000 C CNN
F 2 "" H 9400 5550 60  0000 C CNN
F 3 "" H 9400 5550 60  0000 C CNN
	1    9400 5550
	0    -1   -1   0   
$EndComp
$Comp
L VDD #PWR032
U 1 1 525D040F
P 8900 5250
F 0 "#PWR032" H 8900 5350 30  0001 C CNN
F 1 "VDD" H 8900 5360 30  0000 C CNN
F 2 "" H 8900 5250 60  0000 C CNN
F 3 "" H 8900 5250 60  0000 C CNN
	1    8900 5250
	0    -1   -1   0   
$EndComp
$Comp
L DIODE D34
U 1 1 525D07B2
P 9700 1700
F 0 "D34" H 9700 1800 40  0000 C CNN
F 1 "DIODE" H 9700 1600 40  0000 C CNN
F 2 "~" H 9700 1700 60  0000 C CNN
F 3 "~" H 9700 1700 60  0000 C CNN
	1    9700 1700
	0    1    -1   0   
$EndComp
$Comp
L VSS #PWR033
U 1 1 525D07B8
P 9700 1900
F 0 "#PWR033" H 9700 1900 30  0001 C CNN
F 1 "VSS" H 9700 1830 30  0000 C CNN
F 2 "" H 9700 1900 60  0000 C CNN
F 3 "" H 9700 1900 60  0000 C CNN
	1    9700 1900
	1    0    0    -1  
$EndComp
$Comp
L CONN_4 PSWD1
U 1 1 525D0A55
P 9250 5200
F 0 "PSWD1" V 9200 5200 50  0000 C CNN
F 1 "CONN_4" V 9300 5200 50  0000 C CNN
F 2 "" H 9250 5200 60  0000 C CNN
F 3 "" H 9250 5200 60  0000 C CNN
	1    9250 5200
	1    0    0    -1  
$EndComp
$Comp
L DIODE D31
U 1 1 525D0DEE
P 9450 950
F 0 "D31" H 9450 1050 40  0000 C CNN
F 1 "DIODE" H 9450 850 40  0000 C CNN
F 2 "~" H 9450 950 60  0000 C CNN
F 3 "~" H 9450 950 60  0000 C CNN
	1    9450 950 
	1    0    0    -1  
$EndComp
$Comp
L DIODE D32
U 1 1 525D1199
P 9750 1100
F 0 "D32" H 9750 1200 40  0000 C CNN
F 1 "DIODE" H 9750 1000 40  0000 C CNN
F 2 "~" H 9750 1100 60  0000 C CNN
F 3 "~" H 9750 1100 60  0000 C CNN
	1    9750 1100
	0    1    1    0   
$EndComp
$Comp
L CONN_4 SERVO1
U 1 1 525D363D
P 4450 7450
F 0 "SERVO1" V 4400 7450 50  0000 C CNN
F 1 "CONN_4" V 4500 7450 50  0000 C CNN
F 2 "" H 4450 7450 60  0000 C CNN
F 3 "" H 4450 7450 60  0000 C CNN
	1    4450 7450
	0    1    1    0   
$EndComp
$Comp
L IR4426 KEY2
U 1 1 52663097
P 2200 7100
F 0 "KEY2" H 2200 6800 60  0000 C CNN
F 1 "IR4426" H 2200 7400 60  0000 C CNN
F 2 "" H 2150 7300 60  0000 C CNN
F 3 "" H 2150 7300 60  0000 C CNN
	1    2200 7100
	1    0    0    -1  
$EndComp
$Comp
L IR4426 KEY1
U 1 1 526630A6
P 1750 5700
F 0 "KEY1" H 1750 5400 60  0000 C CNN
F 1 "IR4426" H 1750 6000 60  0000 C CNN
F 2 "" H 1700 5900 60  0000 C CNN
F 3 "" H 1700 5900 60  0000 C CNN
	1    1750 5700
	1    0    0    -1  
$EndComp
$Comp
L IR4426 KEY3
U 1 1 526630B5
P 9050 1350
F 0 "KEY3" H 9050 1050 60  0000 C CNN
F 1 "IR4426" H 9050 1650 60  0000 C CNN
F 2 "" H 9000 1550 60  0000 C CNN
F 3 "" H 9000 1550 60  0000 C CNN
	1    9050 1350
	1    0    0    -1  
$EndComp
$Comp
L IR4426 KEY4
U 1 1 526630C4
P 9100 2600
F 0 "KEY4" H 9100 2300 60  0000 C CNN
F 1 "IR4426" H 9100 2900 60  0000 C CNN
F 2 "" H 9050 2800 60  0000 C CNN
F 3 "" H 9050 2800 60  0000 C CNN
	1    9100 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 4850 8900 4850
Wire Wire Line
	7700 4750 8900 4750
Wire Wire Line
	3050 4050 4700 4050
Connection ~ 3550 4650
Connection ~ 3550 4050
Wire Wire Line
	3050 4250 3050 4450
Wire Wire Line
	2950 4350 3050 4350
Connection ~ 3050 4350
Wire Wire Line
	2700 4700 2700 4750
Wire Wire Line
	9500 2650 9700 2650
Wire Wire Line
	9700 2650 9700 2150
Wire Wire Line
	8600 2650 8550 2650
Wire Wire Line
	8550 2650 8550 2900
Wire Wire Line
	9500 3050 9650 3050
Wire Wire Line
	9650 3050 9650 2750
Wire Wire Line
	9800 2150 9800 2050
Wire Wire Line
	9800 2050 10050 2050
Wire Wire Line
	10050 2050 10050 2200
Wire Wire Line
	9650 2750 9900 2750
Wire Wire Line
	9300 2200 9300 2350
Wire Wire Line
	9300 2350 9500 2350
Wire Wire Line
	9500 2350 9500 2550
Wire Wire Line
	2150 5750 2350 5750
Wire Wire Line
	2350 5750 2350 5250
Wire Wire Line
	1200 5750 1200 6000
Wire Wire Line
	2300 6150 2300 5850
Wire Wire Line
	2450 5250 2450 5150
Wire Wire Line
	2450 5150 2700 5150
Wire Wire Line
	2700 5150 2700 5300
Wire Wire Line
	2300 5850 2550 5850
Wire Wire Line
	1950 5300 1950 5450
Wire Wire Line
	1950 5450 2150 5450
Wire Wire Line
	2150 5450 2150 5650
Wire Wire Line
	2150 5650 2550 5650
Wire Wire Line
	1200 5750 1250 5750
Wire Wire Line
	2300 6150 2150 6150
Wire Wire Line
	7700 4150 8900 4150
Wire Wire Line
	7700 4050 8900 4050
Wire Wire Line
	2700 4350 2700 4400
Wire Wire Line
	1200 3850 1200 4350
Wire Wire Line
	4700 3850 1200 3850
Wire Wire Line
	3050 4650 3800 4650
Wire Wire Line
	3800 4650 3800 4200
Wire Wire Line
	3800 4200 4700 4200
Wire Wire Line
	4000 3150 4550 3150
Wire Wire Line
	4550 3150 4550 3700
Wire Wire Line
	4550 3700 4700 3700
Wire Wire Line
	7700 5150 8750 5150
Wire Wire Line
	8750 5150 8750 5050
Wire Wire Line
	8750 5050 8900 5050
Wire Wire Line
	2600 7150 2800 7150
Wire Wire Line
	2800 7150 2800 6650
Wire Wire Line
	1650 7150 1650 7400
Wire Wire Line
	2750 7550 2750 7250
Wire Wire Line
	2900 6650 2900 6550
Wire Wire Line
	2900 6550 3150 6550
Wire Wire Line
	3150 6550 3150 6700
Wire Wire Line
	2750 7250 3000 7250
Wire Wire Line
	2400 6700 2400 6850
Wire Wire Line
	2400 6850 2600 6850
Wire Wire Line
	2600 6850 2600 7050
Wire Wire Line
	2600 7050 3000 7050
Wire Wire Line
	1650 7150 1700 7150
Wire Wire Line
	2750 7550 2600 7550
Wire Wire Line
	8450 2750 8600 2750
Wire Wire Line
	8350 2550 8600 2550
Wire Wire Line
	9650 1400 9450 1400
Wire Wire Line
	9650 750  9650 1400
Wire Wire Line
	8550 1400 8500 1400
Wire Wire Line
	8500 1400 8500 1650
Wire Wire Line
	9450 1800 9600 1800
Wire Wire Line
	9600 1800 9600 1500
Wire Wire Line
	9600 1500 9850 1500
Wire Wire Line
	9250 950  9250 1100
Wire Wire Line
	9250 1100 9450 1100
Wire Wire Line
	9450 1100 9450 1300
Wire Wire Line
	9450 1300 9850 1300
Wire Wire Line
	4450 1500 8550 1500
Wire Wire Line
	4200 1300 8550 1300
Wire Wire Line
	7700 5350 8450 5350
Wire Wire Line
	8450 5350 8450 5550
Wire Wire Line
	7700 5250 8750 5250
Wire Wire Line
	8750 5250 8750 5350
Wire Wire Line
	8750 5350 8900 5350
Wire Wire Line
	9750 900  9750 800 
Wire Wire Line
	9750 800  10000 800 
Wire Wire Line
	10000 800  10000 950 
Wire Wire Line
	4700 6450 4600 6450
Wire Wire Line
	4600 6450 4600 7100
Wire Wire Line
	4700 6350 4500 6350
Wire Wire Line
	4500 6350 4500 7100
Wire Wire Line
	4700 6250 4400 6250
Wire Wire Line
	4400 6250 4400 7100
Wire Wire Line
	4700 6150 4300 6150
Wire Wire Line
	4300 6150 4300 7100
Connection ~ 9650 2550
Connection ~ 9600 1300
Connection ~ 2300 5850
Connection ~ 9650 2750
Connection ~ 2600 7050
Connection ~ 2900 7050
Connection ~ 2800 6700
Connection ~ 2400 5850
Connection ~ 2450 5650
Connection ~ 2350 5300
Connection ~ 2850 7250
Connection ~ 2750 7250
Connection ~ 9750 2750
Connection ~ 9700 2200
Connection ~ 9600 1500
Connection ~ 9700 1500
Connection ~ 9750 1300
Wire Wire Line
	3250 6450 1650 6450
Wire Wire Line
	1650 6450 1650 7050
Wire Wire Line
	1650 7050 1700 7050
Wire Wire Line
	3150 5550 3150 6350
Wire Wire Line
	3150 6350 1550 6350
Wire Wire Line
	1550 6350 1550 7250
Wire Wire Line
	1550 7250 1700 7250
Wire Wire Line
	1200 4900 3700 4900
Wire Wire Line
	3700 5150 4700 5150
Wire Wire Line
	3700 4900 3700 5150
Wire Wire Line
	1200 4700 1200 4900
Wire Wire Line
	1200 5100 3450 5100
Wire Wire Line
	1200 5100 1200 5650
Wire Wire Line
	1200 5650 1250 5650
Wire Wire Line
	1100 5000 3550 5000
Wire Wire Line
	1100 5000 1100 5850
Wire Wire Line
	1100 5850 1250 5850
Connection ~ 8900 4950
Connection ~ 2300 5650
Connection ~ 2750 7050
Connection ~ 9600 1400
Connection ~ 9650 950 
$Comp
L +12V #PWR034
U 1 1 52665274
P 9650 750
F 0 "#PWR034" H 9650 700 20  0001 C CNN
F 1 "+12V" H 9650 850 30  0000 C CNN
F 2 "" H 9650 750 60  0000 C CNN
F 3 "" H 9650 750 60  0000 C CNN
	1    9650 750 
	1    0    0    -1  
$EndComp
Connection ~ 9650 2650
Wire Wire Line
	9500 2550 9900 2550
Connection ~ 9800 2550
$Comp
L VDD #PWR035
U 1 1 5266570C
P 5900 3350
F 0 "#PWR035" H 5900 3450 30  0001 C CNN
F 1 "VDD" H 5900 3460 30  0000 C CNN
F 2 "" H 5900 3350 60  0000 C CNN
F 3 "" H 5900 3350 60  0000 C CNN
	1    5900 3350
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 52665712
P 4300 3400
F 0 "R1" V 4380 3400 49  0000 C CNN
F 1 "330" V 4307 3401 40  0000 C CNN
F 2 "~" V 4230 3400 30  0000 C CNN
F 3 "~" H 4300 3400 30  0000 C CNN
	1    4300 3400
	1    0    0    -1  
$EndComp
Connection ~ 4300 3150
Connection ~ 4000 3150
$Comp
L VDD #PWR036
U 1 1 52665832
P 4300 3650
F 0 "#PWR036" H 4300 3750 30  0001 C CNN
F 1 "VDD" H 4300 3760 30  0000 C CNN
F 2 "" H 4300 3650 60  0000 C CNN
F 3 "" H 4300 3650 60  0000 C CNN
	1    4300 3650
	-1   0    0    1   
$EndComp
$Comp
L VDD #PWR037
U 1 1 52665866
P 700 4350
F 0 "#PWR037" H 700 4450 30  0001 C CNN
F 1 "VDD" H 700 4460 30  0000 C CNN
F 2 "" H 700 4350 60  0000 C CNN
F 3 "" H 700 4350 60  0000 C CNN
	1    700  4350
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR038
U 1 1 5266586C
P 700 4700
F 0 "#PWR038" H 700 4800 30  0001 C CNN
F 1 "VDD" H 700 4810 30  0000 C CNN
F 2 "" H 700 4700 60  0000 C CNN
F 3 "" H 700 4700 60  0000 C CNN
	1    700  4700
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR039
U 1 1 52665974
P 3400 3150
F 0 "#PWR039" H 3400 3250 30  0001 C CNN
F 1 "VDD" H 3400 3260 30  0000 C CNN
F 2 "" H 3400 3150 60  0000 C CNN
F 3 "" H 3400 3150 60  0000 C CNN
	1    3400 3150
	0    -1   1    0   
$EndComp
Connection ~ 2300 5750
$Comp
L +12V #PWR040
U 1 1 52665C46
P 9700 2150
F 0 "#PWR040" H 9700 2100 20  0001 C CNN
F 1 "+12V" H 9700 2250 30  0000 C CNN
F 2 "" H 9700 2150 60  0000 C CNN
F 3 "" H 9700 2150 60  0000 C CNN
	1    9700 2150
	1    0    0    -1  
$EndComp
Connection ~ 2750 7150
$Comp
L VSS #PWR041
U 1 1 52665E0A
P 10000 950
F 0 "#PWR041" H 10000 950 30  0001 C CNN
F 1 "VSS" H 10000 880 30  0000 C CNN
F 2 "" H 10000 950 60  0000 C CNN
F 3 "" H 10000 950 60  0000 C CNN
	1    10000 950 
	1    0    0    -1  
$EndComp
Connection ~ 9750 3150
Connection ~ 2400 6250
Connection ~ 2800 6650
Connection ~ 4000 3350
Wire Wire Line
	3450 5100 3450 5850
Wire Wire Line
	3550 5000 3550 5750
Wire Wire Line
	3550 5750 4700 5750
Wire Wire Line
	3450 5850 4700 5850
Wire Wire Line
	3150 5550 4700 5550
Wire Wire Line
	3250 6450 3250 5650
Wire Wire Line
	3250 5650 4700 5650
Wire Wire Line
	7700 4450 8450 4450
Wire Wire Line
	8350 4550 7700 4550
Wire Wire Line
	8350 4550 8350 2550
Wire Wire Line
	8450 4450 8450 2750
$Comp
L CONN_2 ADC2
U 1 1 527B57AD
P 7800 2350
F 0 "ADC2" V 7750 2350 40  0000 C CNN
F 1 "CONN_2" V 7850 2350 40  0000 C CNN
F 2 "" H 7800 2350 60  0000 C CNN
F 3 "" H 7800 2350 60  0000 C CNN
	1    7800 2350
	0    -1   -1   0   
$EndComp
$Comp
L CONN_2 ADC1
U 1 1 527B57C9
P 7300 2350
F 0 "ADC1" V 7250 2350 40  0000 C CNN
F 1 "CONN_2" V 7350 2350 40  0000 C CNN
F 2 "" H 7300 2350 60  0000 C CNN
F 3 "" H 7300 2350 60  0000 C CNN
	1    7300 2350
	0    -1   -1   0   
$EndComp
$Comp
L VSS #PWR042
U 1 1 527B57D1
P 7200 2700
F 0 "#PWR042" H 7200 2700 30  0001 C CNN
F 1 "VSS" H 7200 2630 30  0000 C CNN
F 2 "" H 7200 2700 60  0000 C CNN
F 3 "" H 7200 2700 60  0000 C CNN
	1    7200 2700
	1    0    0    -1  
$EndComp
$Comp
L VSS #PWR043
U 1 1 527B57E0
P 7700 2700
F 0 "#PWR043" H 7700 2700 30  0001 C CNN
F 1 "VSS" H 7700 2630 30  0000 C CNN
F 2 "" H 7700 2700 60  0000 C CNN
F 3 "" H 7700 2700 60  0000 C CNN
	1    7700 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 3950 7900 3950
Wire Wire Line
	7900 3950 7900 2700
Wire Wire Line
	7700 3850 7800 3850
Wire Wire Line
	7800 3850 7800 2850
Wire Wire Line
	7800 2850 7400 2850
Wire Wire Line
	7400 2850 7400 2700
Wire Wire Line
	9350 5550 9400 5550
Wire Wire Line
	5900 7500 5800 7500
Wire Wire Line
	4200 1300 4200 5050
Wire Wire Line
	4200 5050 4700 5050
Wire Wire Line
	4450 1500 4450 4950
Wire Wire Line
	4450 4950 4700 4950
$EndSCHEMATC
