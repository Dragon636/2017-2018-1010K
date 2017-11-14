/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

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
int joystickGetAnalog( unsigned char joystick, //1 for master, 2 for partner
							unsigned char axis //1,2,3,4,on the joystick
						);

void motorset( unsigned char channel,
							int speed
						);

void operatorcontrol(){
		int power, turn;
		while(1){
			power= joystickGetAnalog (1,3);// vertical axis on right jotstick
			turn=  joystickGetAnalog (1,2);// horizontal axis on right joystc for turn
		motorSet(6, power + turn); // port 6 & 7 are left
		motorSet(7, power + turn);
		motorSet(3, power - turn); // port 2 & 3 are right
		motorSet(2, power - turn);


	if (joystickGetDigital(1, 6, JOY_UP)){
		motorSet(4, 127);// when 6U is ppressed, lift up
	}
	else if (joystickGetDigital(1, 6, JOY_DOWN)){
		motorSet(4, -127);// when 6D is pressed, lift down
	}
else
	{
	motorSet(4, 0); // when nothing is pressed, lift still
	}

	if (joystickGetDigital(2, 8, JOY_UP)){
		motorSet(5, -120);  // bottom right arm is -120
		motorSet(9, -120);  // upper right arm is -120
		motorSet(10, 120); // bottom left arm is 120
		motorSet(8, 120);  // upper left arm is 120
	}

	else if (joystickGetDigital(2,8, JOY_DOWN)){
		motorSet(5, 120);  // bottom right arm is 120
		motorSet(9, 120);  // upper right arm is 120
		motorSet(10,-120); // bottom left arm is -120
		motorSet(8, -120);  // upper left arm is -120
	}

else
	{
		motorSet(5, -20);  // bottom right arm is 120
		motorSet(9, -20);  // upper right arm is 120
		motorSet(10,20); // bottom left arm is -120
	}

	


	if (joystickGetDigital(2, 7, JOY_UP)){

		motorSet(1,120); // if on the partner controller, 7 up is press claw open
	}
	else if (joystickGetDigital(2,7,JOY_DOWN)){
		motorSet(1,-120); //. if on the partner controller, 7 down is pressed, claw close
	}

else
	{
	motorSet(1,0);
	}

	delay(20);
	}
