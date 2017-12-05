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
 #define POTENTIOMETER_PORT 1

 void autonomous() {
  // need to further change test all the arm fuctions

    // keep the claw closed tight
    // while the potentiometer less than 10, the claw need to be close

    while(analogRead(POTENTIOMETER_PORT) <10)
    {
    motorSet(1,-127);
    }


    // arm up for 1 sec
    motorSet(5,-100);
    motorSet(9,-100);
    motorSet(10,-100);
    motorSet(8,100);
    delay(700);

// pause a bit
    motorSet(5,20);
    motorSet(9,20);
    motorSet(10,20);
    motorSet(8,-20);
    delay(50);

// stop the arm
motorSet(5,0);
motorSet(9,0);
motorSet(10,0);
motorSet(8,0);
delay(800);



  // lift down
    motorSet(4,127);
    delay(400);
    // stop
    motorSet(4,0);

// lift up
motorSet(4, 127);
delay(120);

motorSet(4,0);
//-------------------------
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
    delay(1800);

     // lift back
     motorSet(4,-127);
     delay(250);

     // stop lift
     motorSet(4,0);

     //arm down
     motorSet(5,55);
    motorSet(9,55);
    motorSet(10,55);
    motorSet(8,-55);
    delay(680);

    motorSet(5,-50);
    motorSet(9,-50);
    motorSet(10,-50);
    motorSet(8,50);
    delay(200);

    // arm stop
    motorSet(5,0);
   motorSet(9,0);
   motorSet(10,0);
   motorSet(8,0);
   delay(500);

    // *claw open
    motorSet(1,120);
    delay(250);

    // *arm up
    motorSet(5,-120);
    motorSet(9,-120);
    motorSet(10,-120);
    motorSet(8,120);
    delay(750);

//--------------------------------------------finish the liftsss
  // going back
     motorSet(6,-127);
     motorSet(7,-127);
     motorSet(2,127);
     motorSet(3,127);
     delay(1640);

  // turn for .85 seconds
     motorSet(6,-127);
     motorSet(7,-127);
     motorSet(2,-127);
     motorSet(3,-127);
      delay(850);

  // go forward a bit
      motorSet(6,127);
      motorSet(7,127);
      motorSet(2,-127);
      motorSet(3,-127);
      delay(300);
// stop
      motorSet(6,0);
      motorSet(7,0);
      motorSet(2,0);
      motorSet(3,0);
      delay(400);


// turn
motorSet(6,-127);
motorSet(7,-127);
motorSet(2,-127);
motorSet(3,-127);
 delay(950);
// drive
 motorSet(6,127);
 motorSet(7,127);
 motorSet(2,-127);
 motorSet(3,-127);
 delay(1300);

  // drive motors, stop
      motorSet(6,0);
      motorSet(7,0);
      motorSet(2,0);
      motorSet(3,0);


  // lift motor out for 0.8 sec

      motorSet(4,127);
      delay(500);

  // go back ward for 1.3 sec
      motorSet(6,-127);
      motorSet(7,-127);
      motorSet(2,127);
      motorSet(3,127);
      delay(1000);

  //EXPLANATIONS ----------------------------------------
  // each piece of mat is 24 inches.
  // aproxiamte 2.7 mat to get to the parking/mobile goal
  // going at full speed, 1000 per 20 inches
  // at speed 80, 15 degrees 100ms
}
