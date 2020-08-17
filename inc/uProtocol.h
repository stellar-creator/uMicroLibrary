/*
Autor:			Stellar Creator
Date Of Update: 17.08.2020
File:			uProtocol.h
*/

#ifndef UPROTOCOL_H
#define UPROTOCOL_H

#include "uGlobal.h"

// Defines
#define uDeviceType_Unspecified				0x00
#define uDeviceType_Controller				0x01
#define uDeviceType_Audio					0x02
#define uDeviceType_Video					0x03
#define uDeviceType_Input					0x04
#define uDeviceType_Output					0x05
#define uDeviceType_Sensor					0x06
#define uDeviceType_Monitor					0x07
#define uDeviceType_Spotlight				0x08
#define uDeviceType_Illuminator				0x09
#define uDeviceType_Detector				0x0A
#define uDeviceType_Calculator				0x0B
#define uDeviceType_Server					0x0C
#define uDeviceType_Recorder				0x0D
#define uDeviceType_Generator				0x0E
#define uDeviceType_Power					0x0F
#define uDeviceType_Communicator			0x10

#define uDeviceFunction_Unspecified			0x00
#define uDeviceFunction_Climat				0x01
#define uDeviceFunction_SpecialSpotlight	0x02
#define uDeviceFunction_ImpulseGenerator	0x03
#define uDeviceFunction_SensorRecorder		0x04
#define uDeviceFunction_Power 				0x05
#define uDeviceFunction_Emulator			0x06
#define uDeviceFunction_Messager			0x07
#define uDeviceFunction_Hub					0x08
#define uDeviceFunction_TemperatureSensor	0x09
#define uDeviceFunction_PressureSensor		0x0A
#define uDeviceFunction_LightSensor			0x0B

#define uDeviceMode_Both					0x00
#define uDeviceMode_OnlyRX					0x01
#define uDeviceMode_OnlyTX					0x02

// Structs
typedef struct __attribute__ ((packed)) {
	uData deviceType;
	uData deviceFunction;
	uData deviceAddress[2];
	uData deviceState;
	uData deviceMode;
	uData[16] deviceName;
	uData[16] deviceManufacture;
} uProtocolDescriptor;

typedef struct __attribute__ ((packed)) {
	uData checkOr;
	uData checkAnd;
	uData checkXor;
} uProtocolChecksum;

typedef struct __attribute__ ((packed)) {
	uData command[4];
	uData section[4];
	uData values[16];
} uProtocolData;

typedef struct __attribute__ ((packed)) {
	uData 					startByte;
	uProtocolDescriptor 	uDescriptor;
	uProtocolData			uCommandData;
	uData					endByte;
	uProtocolChecksum		uChecksum;
} uProtocol;


// Functions

#endif /* UPROTOCOL_H */