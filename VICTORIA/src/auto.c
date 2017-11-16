/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */
void autonomous() {
//delay(2000); // pause for 2 sec before the program runs
  // raise arm for .5 sec
/*  motorSet(5,-120);
  motorSet(9,-120);
  motorSet(10,120);
  motorSet(8,120);
  delay(500);
  */
// continue with 20 for gravity for 9 sec
  motorSet(5,-20);
  motorSet(9,-20);
  motorSet(10,20);
  motorSet(8,20);
  delay(9000);

  // drive to first cone for 3.5 sec with full power
  motorSet(6,127);
  motorSet(7,127);
  motorSet(2,127);
  motorSet(3,127);
  delay(3500);
// drive to first cone for 1.5 sec with half power
  motorSet(6,60);
  motorSet(7,60);
  motorSet(2,60);
  motorSet(3,60);
  delay(1500);
// stop
  motorSet(6,0);
  motorSet(7,0);
  motorSet(2,0);
  motorSet(3,0);


  // pick up the mobile goal
  motorSet(4, 100);
  delay(1000);
  motorSet(4, -100);
  delay(1000);

  // Lower the arm for 2 sec
  motorSet(5,-120);
  motorSet(9,-120);
  motorSet(10,120);
  motorSet(8,120);
  delay(2000);

  // open claw
  motorSet(1,120);
  delay(1000);

  //raise arm for 2 sec
  motorSet(5,-120);
  motorSet(9,-120);
  motorSet(10,120);
  motorSet(8,120);
  delay(2000);
// continue with 20 for gravity for 9 sec
  motorSet(5,-20);
  motorSet(9,-20);
  motorSet(10,20);
  motorSet(8,20);
  delay(9000);

// drive back for 3.5 sec
motorSet(6,-127);
motorSet(7,-127);
motorSet(2,-127);
motorSet(3,-127);
delay(3500);


// put the mobile goal down
motorSet(4,127);

// go back a little
motorSet(6,120);
motorSet(7,120);
motorSet(2,120);
motorSet(3,120);
delay(500);

//----------------------------------------
// each piece of mat is 24 inches.
// aproxiamte 2.7 mat to get to the parking/mobile goal
// going at full speed, 1000 per 20 inches
motorSet(6,127);
motorSet(7,127);
motorSet(2,127);
motorSet(3,127);
delay(3240);
// at power 80, 15 degree 100 ms


// this program should take aprox






  //
}