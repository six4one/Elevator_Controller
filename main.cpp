/*
 * main.cpp
 *
 * Application entry point for the Elevator controller.
 *
 * During development, main() launches the selected diagnostic
 * harness. The test implementation itself belongs in the harness.
 */

#include "ClearCore.h"

#include "DoorService/DoorServiceTestHarness.h"


#define SerialPort ConnectorUsb
#define baudRate 9600


/*
 * ------------------------------------------------------------
 * STARTUP COUNTDOWN
 * ------------------------------------------------------------
 *
 * Ten seconds to connect the serial monitor after firmware upload.
 */
static void StartupCountdown()
{
    for (int second = 10; second > 0; --second)
    {
        ConnectorLed.State(true);
        Delay_ms(250);

        ConnectorLed.State(false);
        Delay_ms(750);
    }
}


/*
 * ------------------------------------------------------------
 * HEARTBEAT
 * ------------------------------------------------------------
 *
 * Indicates that the selected test has completed and the
 * controller is still executing normally.
 */
static void Heartbeat()
{
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
}


int main(void)
{
    /*
     * ------------------------------------------------------------
     * SERIAL INITIALIZATION
     * ------------------------------------------------------------
     */
    SerialPort.Mode(Connector::USB_CDC);
    SerialPort.Speed(baudRate);
    SerialPort.PortOpen();


    /*
     * Give the operator time to connect the serial monitor.
     */
    StartupCountdown();


    /*
     * ------------------------------------------------------------
     * DOORSERVICE TEST
     * ------------------------------------------------------------
     */
    DoorService::DoorServiceTestHarness doorTest;

    SerialPort.SendLine("");
    SerialPort.SendLine("=== DoorService Test Selected ===");

    doorTest.RunBasicTest();


    /*
     * ------------------------------------------------------------
     * TEST COMPLETE
     * ------------------------------------------------------------
     */
    SerialPort.SendLine("");
    SerialPort.SendLine("Selected test returned.");
    SerialPort.SendLine("Entering heartbeat.");


    /*
     * Continue running after the test.
     */
    Heartbeat();


    return 0;
}