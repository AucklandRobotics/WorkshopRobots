#include "main.h"

#define CONTROLLER 1
#define LEFTMOTORFRONT 2
#define LEFTMOTORBACK 1
#define RIGHTMOTORFRONT 9
#define RIGHTMOTORBACK 10
#define ARM 3

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
void operatorControl() {
	int leftPower,rightPower;
	setTeamName("Team1");
	while (1) {
		if (isJoystickConnected(CONTROLLER)){
			leftPower = joystickGetAnalog(CONTROLLER,3)-joystickGetAnalog(CONTROLLER,4);
			rightPower = joystickGetAnalog(CONTROLLER,3)+joystickGetAnalog(CONTROLLER,4);
			motorSet(LEFTMOTORFRONT,leftPower);
			motorSet(LEFTMOTORBACK,-leftPower);
			motorSet(RIGHTMOTORFRONT,-rightPower);
			motorSet(RIGHTMOTORBACK,rightPower);

			motorSet(ARM,joystickGetAnalog(CONTROLLER,2));

		}
	}
}



