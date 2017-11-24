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
  // need to further change test all the arm fuctions

    // keep the claw closed tight
    motorSet(1,-120);
    delay(6000);
    
    // arm up for 1 sec
    motorSet(5,-120);
    motorSet(9,-120);
    motorSet(10,-120);
    motorSet(8,120);
    delay(1000);

  // hold, continue with 20 for gravity for 0.3 sec
    motorSet(5,20);
    motorSet(9,20);
    motorSet(10,20);
    motorSet(8,-20);
    delay(300);

  /*
  // lift down
    motorSet(4,127);
    delay(400);
    // stop
    motorSet(4,0);


    // drive to first cone for 3 sec with full power
    motorSet(6,127);
    motorSet(7,127);
    motorSet(2,-127);
    motorSet(3,-127);
    delay(2450);

  // stop for 2 sec
    motorSet(6,0);
    motorSet(7,0);
    motorSet(2,0);
    motorSet(3,0);
    delay(2000);

     // lift back
     motorSet(4,-127);
     delay(600);

     // stop lift
     motorSet(4,0);

     */

     // *arm down
     motorSet(5,120);
    motorSet(9,120);
    motorSet(10,120);
    motorSet(8,-120);
    delay(500);

    // *claw open
    motorSet(1,120);
    delay(500);

    // *arm up
    motorSet(5,-120);
    motorSet(9,-120);
    motorSet(10,-120);
    motorSet(8,120);
    delay(1100);

  /*
  // going back
     motorSet(6,-127);
     motorSet(7,-127);
     motorSet(2,127);
     motorSet(3,127);
     delay(1400);

  // turn for 1.3 seconds
     motorSet(6,-127);
     motorSet(7,-127);
     motorSet(2,-127);
     motorSet(3,-127);
      delay(1300);

  // go forward a bit
      motorSet(6,127);
      motorSet(7,127);
      motorSet(2,-127);
      motorSet(3,-127);
      delay(1200);

  // drive motors, stop
      motorSet(6,0);
      motorSet(7,0);
      motorSet(2,0);
      motorSet(3,0);
      delay(1000);

  // lift motor out for 1.6 sec

      motorSet(4,127);
      delay(1000);

  // go back ward for 1.5 sec
      motorSet(6,-127);
      motorSet(7,-127);
      motorSet(2,127);
      motorSet(3,127);
      delay(1300);
  */
  //EXPLANATIONS ----------------------------------------
  // each piece of mat is 24 inches.
  // aproxiamte 2.7 mat to get to the parking/mobile goal
  // going at full speed, 1000 per 20 inches
  // at speed 80, 15 degrees 100ms
}
