/*
* Elevator_IO.h
*
* Created: 2026-04-14 6:50:36 AM
*  Author: admin
*/


#ifndef ELEVATOR_IO_H_
#define ELEVATOR_IO_H_
#include "ClearCore.h"

static DigitalIn &powerFailureDetected = ConnectorDI6;
static DigitalIn &smokeDetected = ConnectorDI7;
static DigitalIn &perimeterSeal = ConnectorDI8;
static DigitalIn &cabOvertravel = ConnectorA9;
static DigitalIn &cabHome = ConnectorA10;
static DigitalIn &doorXHome = ConnectorA11;
static DigitalIn &doorYHome = ConnectorA12;

static DigitalInOut &faultState = ConnectorIO1;
static DigitalInOut &liftEnable = ConnectorIO2;

//	CCIO-8 EXPANSION BOARD ALIASES (1 of 8) ---
static CcioPin *callBasement_PB = nullptr;		//Input one of the call buttons for Basement level is pressed
static CcioPin *callGarage_PB = nullptr;		//Input one of the call buttons for Garage level is pressed
static CcioPin *callMain_PB = nullptr;		//Input one of the call buttons for Main level is pressed
static CcioPin *callAppartment_PB = nullptr;		//Input one of the call buttons for Apartment level is pressed
static CcioPin *cabStop_PB = nullptr;	//Input the stop button on the cab console is pressed (provisional)
static CcioPin *jogMode = nullptr;		//Input: key switch in the cab control cabinet is in "Jog" position
static CcioPin *doorXApproach = nullptr;	//Door X is in the home approach zone
static CcioPin *doorYApproach = nullptr;	//Door Y is in the home approach zone


//	CCIO-8 EXPANSION BOARD ALIASES (2 of 8) ---
static CcioPin *jogCabUp = nullptr;		//Input: one of the Cab UP jog buttons is pressed
static CcioPin *jogCabDown = nullptr;	//Input: one of the Cab Down jog buttons is pressed
static CcioPin *jogDoorXUp = nullptr;	//Input: one of the DoorX Up jog buttons is pressed
static CcioPin *jogDoorXDown = nullptr;	//Input: one of the DoorX Down jog buttons is pressed
static CcioPin *jogDoorYUp = nullptr;	//Input: one of the DoorY Up jog buttons is pressed
static CcioPin *jogDoorYDown = nullptr;	//Input: one of the DoorY Down jog buttons is pressed
static CcioPin *jog2Hand = nullptr;		//Input: one of the 2nd-hand buttons is pressed
static CcioPin *chainDownLimit = nullptr;	//Input: PX to limit how far down the hoist chains can go / hight of the counterweight

//	CCIO-8 EXPANSION BOARD ALIASES (3 of 8) ---
static CcioPin *cabBrake = nullptr;		//Input: Cab's mechanical safety brake system has been deployed
static CcioPin *runMode = nullptr;		//Input: key switch in main control cabinet is in "Run" position
static CcioPin *reset = nullptr;		//Input: key switch in main control cabinet is in "Reset" position
static CcioPin *cabOverLoad = nullptr;	//Input: chain tension monitor system reports an overload condition
static CcioPin *cabEmpty = nullptr;		//Input: chain tension monitor system reports that the cab is empty
static CcioPin *doorXClosed = nullptr;	//Input: door X is closed
static CcioPin *doorYClosed = nullptr;	//Input: door Y is closed
static CcioPin *cabOverspeed = nullptr;	//Input: cab speed governor is triggered by an over-speed condition

//	CCIO-8 EXPANSION BOARD ALIASES (4 of 8) ---
static CcioPin *doorXUpperBreach = nullptr;	//Input: Laser beam across Door X's upper edge has been breached
static CcioPin *doorXLowerBreach = nullptr;	//Input: Laser beam across Door X's lower edge has been breached
static CcioPin *doorYUpperBreach = nullptr;	//Input: Laser beam across Door Y's upper edge has been breached
static CcioPin *doorYLowerBreach = nullptr;	//Input: Laser beam across Door Y's lower edge has been breached
static CcioPin *cabXUpperBreach = nullptr;	//Input: Laser beam across the cab's upper threshold @ opening X has been breached
static CcioPin *cabXLowerBreach = nullptr;	//Input: Laser beam across the cab's lower threshold @ opening X has been breached
static CcioPin *cabYUpperBreach = nullptr;	//Input: Laser beam across the cab's upper threshold @ opening Y has been breached
static CcioPin *cabYLowerBreach = nullptr;	//Input: Laser beam across the cab's lower threshold @ opening Y has been breached

//	CCIO-8 EXPANSION BOARD ALIASES (5 of 8) ---
static CcioPin *cabAtBasement = nullptr;			//Input: The cab is at Basement level (B)
static CcioPin *cabAtGarage = nullptr;			//Input: The cab is at Garage level (G)
static CcioPin *cabAtMain = nullptr;			//Input: The cab is at Main level (1)
static CcioPin *cabAtAppartment = nullptr;			//Input: The cab is at Apartment level (2)
static CcioPin *extDoorsClosed = nullptr;	//Input: All 4 exterior access doors are closed
//static CcioPin *??? = nullptr;		//Spare I/O
//static CcioPin *??? = nullptr;		//Spare I/O
static CcioPin *homingSequence = nullptr;	//Output: ClearCore interacts with the safety circuitry to enable homing operations

//	CCIO-8 EXPANSION BOARD ALIASES (6 of 8) ---
static CcioPin *unlockDoorBasement = nullptr;		//Output: Unlock door B to permit entry to cab from outside.
static CcioPin *unlockDoorGarage = nullptr;		//Output: Unlock door G to permit entry to cab from outside.
static CcioPin *unlockDoorMain = nullptr;		//Output: Unlock door 1 to permit entry to cab from outside.
static CcioPin *unlockDoorAppartment = nullptr;		//Output: Unlock door 2 to permit entry to cab from outside.
static CcioPin *openDoorBasement = nullptr;		//Output: automatically open exterior door at basement level (provisional)
static CcioPin *openDoorGarage = nullptr;		//Output: automatically open exterior door at garage level (provisional)
static CcioPin *openDoorMain = nullptr;		//Output: automatically open exterior door at main level (provisional)
static CcioPin *openDoorAppartment = nullptr;		//Output: automatically open exterior door at apartment level



//	CCIO-8 EXPANSION BOARD ALIASES (7 of 8) ---
static CcioPin *callBasement_PL = nullptr;			//Output: illuminate 2 basement (B) level call buttons (in cab and @ ext door)
static CcioPin *callGarage_PL = nullptr;			//Output: illuminate 2 garage (G) level call buttons (in cab and @ ext door)
static CcioPin *callMain_PL = nullptr;			//Output: illuminate 2 main (1) level call buttons (in cab and @ ext door)
static CcioPin *callAppartment_PL = nullptr;			//Output: illuminate 2 apartment (2) level call buttons (in cab and @ ext door)
static CcioPin *stop_PL = nullptr;			//Output: illuminate the stop button on the cab console
static CcioPin *enableLaserX = nullptr;		//Output: enable the 2 laser emitters on door X
static CcioPin *enableLaserY = nullptr;		//Output: enable the 2 laser emitters on door Y
static CcioPin *XYEnable = nullptr;			//Output: enable the motor drives for both doors X and Y

//	CCIO-8 EXPANSION BOARD ALIASES (8 of 8) ---
static CcioPin *aviBit0 = nullptr;			//Output: bit 0 for the 4-bit parallel buss for cab audio and visual feedback modules
static CcioPin *aviBit1 = nullptr;			//Output: bit 1 for the 4-bit parallel buss for cab audio and visual feedback modules
static CcioPin *aviBit2 = nullptr;			//Output: bit 2 for the 4-bit parallel buss for cab audio and visual feedback modules
static CcioPin *aviBit3 = nullptr;			//Output: bit 3 for the 4-bit parallel buss for cab audio and visual feedback modules
static CcioPin *lubePump = nullptr;			//Output: enable the lubrication pump
static CcioPin *beeper = nullptr;			//Output: enable the audible beeper
static CcioPin *cabEnvironment = nullptr;	//Output: enable the cab lighting and ventilation
static CcioPin *cabSecure = nullptr;		//Output: report to the MQTT module that the cab is in a closed and secure state to monitor chain tension stability during motion

inline void InitializeElevatorIO() {
	
	//Inputs connected to ClearCore
	powerFailureDetected.Mode(Connector::INPUT_DIGITAL);
	smokeDetected.Mode(Connector::INPUT_DIGITAL);
	perimeterSeal.Mode(Connector::INPUT_DIGITAL);
	cabOvertravel.Mode(Connector::INPUT_DIGITAL);
	cabHome.Mode(Connector::INPUT_DIGITAL);
	doorXHome.Mode(Connector::INPUT_DIGITAL);
	doorYHome.Mode(Connector::INPUT_DIGITAL);
	
	//Outputs connected to ClearCore
	faultState.Mode(Connector::OUTPUT_DIGITAL);
	liftEnable.Mode(Connector::OUTPUT_DIGITAL);
	
	// 2. Assign the expansion pins AFTER discovery has occurred
	callBasement_PB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA0);
	callGarage_PB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA1);
	callMain_PB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA2);
	callAppartment_PB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA3);
	cabStop_PB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA4);
	jogMode = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA5);
	doorXApproach= CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA6);
	doorYApproach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA7);
	
	jogCabUp = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB0);
	jogCabDown = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB1);
	jogDoorXUp = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB2);
	jogDoorXDown = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB3);
	jogDoorYUp = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB4);
	jogDoorYDown = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB5);
	jog2Hand = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB6);
	chainDownLimit = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB7);

	cabBrake = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC0);
	runMode = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC1);
	reset = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC2);
	cabOverLoad = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC3);
	cabEmpty = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC4);
	doorXClosed = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC5);
	doorYClosed = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC6);
	cabOverspeed = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC7);
	
	doorXUpperBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD0);
	doorXLowerBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD1);
	doorYUpperBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD2);
	doorYLowerBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD3);
	cabXUpperBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD4);
	cabXLowerBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD5);
	cabYUpperBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD6);
	cabYLowerBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD7);
	
	cabAtBasement = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE0);
	cabAtGarage = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE1);
	cabAtMain = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE2);
	cabAtAppartment = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE3);
	extDoorsClosed = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE4);
	// = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE5);
	// = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE6);
	homingSequence = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE7);	

	unlockDoorBasement = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF0);
	unlockDoorGarage = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF1);
	unlockDoorMain = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF2);
	unlockDoorAppartment = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF3);
	openDoorBasement = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF4);
	openDoorGarage = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF5);
	openDoorMain = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF6);
	openDoorAppartment = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF7);
	

	callBasement_PL = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG0);
	callGarage_PL = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG1);
	callMain_PL = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG2);
	callAppartment_PL = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG3);
	stop_PL = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG4);
	enableLaserX = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG5);
	enableLaserY = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG6);
	XYEnable= CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG7);	

	aviBit0 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH0);
	aviBit1 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH1);
	aviBit2 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH2);
	aviBit3 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH3);
	lubePump = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH4);
	beeper = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH5);
	cabEnvironment = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH6);
	cabSecure = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH7);
		
	//Inputs connected to CCIO-8
	if (callBasement_PB) callBasement_PB->Mode(Connector::INPUT_DIGITAL);
	if (callGarage_PB) callGarage_PB->Mode(Connector::INPUT_DIGITAL);
	if (callMain_PB) callMain_PB->Mode(Connector::INPUT_DIGITAL);
	if (callAppartment_PB) callAppartment_PB->Mode(Connector::INPUT_DIGITAL);
	if (cabStop_PB) cabStop_PB->Mode(Connector::INPUT_DIGITAL);
	if (jogMode) jogMode->Mode(Connector::INPUT_DIGITAL);
	if (doorXApproach) doorXApproach->Mode(Connector::INPUT_DIGITAL);
	if (doorYApproach) doorYApproach->Mode(Connector::INPUT_DIGITAL);
	
	if (jogCabUp) jogCabUp->Mode(Connector::INPUT_DIGITAL);
	if (jogCabDown) jogCabDown->Mode(Connector::INPUT_DIGITAL);
	if (jogDoorXUp) jogDoorXUp->Mode(Connector::INPUT_DIGITAL);
	if (jogDoorXDown) jogDoorXDown->Mode(Connector::INPUT_DIGITAL);
	if (jogDoorYUp) jogDoorYUp->Mode(Connector::INPUT_DIGITAL);
	if (jogDoorYDown) jogDoorYDown->Mode(Connector::INPUT_DIGITAL);
	if (jog2Hand) jog2Hand->Mode(Connector::INPUT_DIGITAL);
	if (chainDownLimit) chainDownLimit->Mode(Connector::INPUT_DIGITAL);
	
	if (cabBrake) cabBrake->Mode(Connector::INPUT_DIGITAL);
	if (runMode) runMode->Mode(Connector::INPUT_DIGITAL);
	if (reset) reset->Mode(Connector::INPUT_DIGITAL);
	if (cabOverLoad) cabOverLoad->Mode(Connector::INPUT_DIGITAL);
	if (cabEmpty) cabEmpty->Mode(Connector::INPUT_DIGITAL);
	if (doorXClosed) doorXClosed->Mode(Connector::INPUT_DIGITAL);
	if (doorYClosed) doorYClosed->Mode(Connector::INPUT_DIGITAL);
	if (cabOverspeed) cabOverspeed->Mode(Connector::INPUT_DIGITAL);
	
	if (doorXUpperBreach) doorXUpperBreach->Mode(Connector::INPUT_DIGITAL);
	if (doorXLowerBreach) doorXLowerBreach->Mode(Connector::INPUT_DIGITAL);
	if (doorYUpperBreach) doorYUpperBreach->Mode(Connector::INPUT_DIGITAL);
	if (doorYLowerBreach) doorYLowerBreach->Mode(Connector::INPUT_DIGITAL);
	if (cabXUpperBreach) cabXUpperBreach->Mode(Connector::INPUT_DIGITAL);
	if (cabXLowerBreach) cabXLowerBreach->Mode(Connector::INPUT_DIGITAL);
	if (cabYUpperBreach) cabYUpperBreach->Mode(Connector::INPUT_DIGITAL);
	if (cabYLowerBreach) cabYLowerBreach->Mode(Connector::INPUT_DIGITAL);
	
	if (extDoorsClosed) extDoorsClosed->Mode(Connector::INPUT_DIGITAL);
	if (cabAtBasement) cabAtBasement->Mode(Connector::INPUT_DIGITAL);
	if (cabAtGarage) cabAtGarage->Mode(Connector::INPUT_DIGITAL);
	if (cabAtMain) cabAtMain->Mode(Connector::INPUT_DIGITAL);
	if (cabAtAppartment) cabAtAppartment->Mode(Connector::INPUT_DIGITAL);
	
//Spare I/O
//	if (???) ???->Mode(Connector::INPUT_DIGITAL);		//CCIO-8 module #5 D6
//	if (???) ???->Mode(Connector::INPUT_DIGITAL);		//CCIO-8 module #5 D7

//Outputs connected to CCIO-8
	if (homingSequence) homingSequence->Mode(Connector::OUTPUT_DIGITAL);
	
	if (unlockDoorBasement) unlockDoorBasement->Mode(Connector::OUTPUT_DIGITAL);
	if (unlockDoorGarage) unlockDoorGarage->Mode(Connector::OUTPUT_DIGITAL);
	if (unlockDoorMain) unlockDoorMain->Mode(Connector::OUTPUT_DIGITAL);
	if (unlockDoorAppartment) unlockDoorAppartment->Mode(Connector::OUTPUT_DIGITAL);
	if (openDoorBasement) openDoorBasement->Mode(Connector::OUTPUT_DIGITAL);
	if (openDoorGarage) openDoorGarage->Mode(Connector::OUTPUT_DIGITAL);
	if (openDoorMain) openDoorMain->Mode(Connector::OUTPUT_DIGITAL);
	if (openDoorAppartment) openDoorAppartment->Mode(Connector::OUTPUT_DIGITAL);
	
	if (callBasement_PL) callBasement_PL->Mode(Connector::OUTPUT_DIGITAL);
	if (callGarage_PL) callGarage_PL->Mode(Connector::OUTPUT_DIGITAL);
	if (callMain_PL) callMain_PL->Mode(Connector::OUTPUT_DIGITAL);
	if (callAppartment_PL) callAppartment_PL->Mode(Connector::OUTPUT_DIGITAL);
	if (stop_PL) stop_PL->Mode(Connector::OUTPUT_DIGITAL);
	if (enableLaserX) enableLaserX->Mode(Connector::OUTPUT_DIGITAL);
	if (enableLaserY) enableLaserY->Mode(Connector::OUTPUT_DIGITAL);
	if (XYEnable) XYEnable->Mode(Connector::OUTPUT_DIGITAL);
	
	if (aviBit0) aviBit0->Mode(Connector::OUTPUT_DIGITAL);
	if (aviBit1) aviBit1->Mode(Connector::OUTPUT_DIGITAL);
	if (aviBit2) aviBit2->Mode(Connector::OUTPUT_DIGITAL);
	if (aviBit3) aviBit3->Mode(Connector::OUTPUT_DIGITAL);
	if (lubePump) lubePump->Mode(Connector::OUTPUT_DIGITAL);
	if (beeper) beeper->Mode(Connector::OUTPUT_DIGITAL);
	if (cabEnvironment) cabEnvironment->Mode(Connector::OUTPUT_DIGITAL);
	if (cabSecure) cabSecure->Mode(Connector::OUTPUT_DIGITAL);
}

#endif /* ELEVATOR_IO_H_ */