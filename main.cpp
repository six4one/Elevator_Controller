#include "ClearCore.h"
#include "Transport/TransportTestHarness.h"
#include "Transport/TransportTypes.h"

#define SerialPort ConnectorUsb
#define baudRate 9600

//TransportTestHarness harness;
Transport::TransportTestHarness harness;

int main(void)
{
	// USB serial initialization
	SerialPort.Mode(Connector::USB_CDC);
	SerialPort.Speed(baudRate);
	SerialPort.PortOpen();

	// Ten-second startup countdown.
	// The LED pulses once per second so the serial monitor can be opened
	// after firmware upload, before diagnostic output begins.
	for (int second = 10; second > 0; --second)
	{
		ConnectorLed.State(true);
		Delay_ms(250);

		ConnectorLed.State(false);
		Delay_ms(750);
	}

	// Execution markers bracket RunTo() so we can determine whether
	// the Transport test harness returns to main().
	SerialPort.SendLine();
	SerialPort.SendLine("=== Transport Test Diagnostic ===");
	SerialPort.SendLine("Countdown complete.");
	SerialPort.SendLine("About to run Transport test.");
	
	
//*******************************************************
//	Target Location for test harness
//	origin location are set inside TransportSequencer.cpp
//*******************************************************
	//harness.RunTo(TransportPositionId::Apartment);
	//harness.RunTo(TransportPositionId::Main);
	//harness.RunTo(TransportPositionId::Garage);
	harness.RunTo(TransportPositionId::Basement);

	// If this appears, RunTo() returned to main().
	SerialPort.SendLine("Transport test returned.");
	SerialPort.SendLine("Entering heartbeat.");

	// Heartbeat
	bool ledState = false;
	uint32_t lastHeartbeat = Milliseconds();

	while (true)
	{
		if (Milliseconds() - lastHeartbeat >= 1000)
		{
			lastHeartbeat = Milliseconds();

			ledState = !ledState;
			ConnectorLed.State(ledState);

			SerialPort.SendLine("Heartbeat");
		}
	}

	return 0;
}