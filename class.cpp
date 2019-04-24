#include "ros/ros.h"
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <iostream> //lib use in c++
#include "conio.h"

#include "robot.h"

#define NODE_NAME "Track_class_node"
#define HELP_MSG "==========================\n"                           \
                 "Key usage:\n"                                           \
                 " h: Show this message\n"                                \
                 " space: stop all motion\n"                              \
                 "---------\n"                                            \
                 " Up arrow: Go front\n"                                  \
                 " Down arrow: Go back\n"                                 \
                 " Left arrow: Spin left\n"                               \
                 " Right arrow: Spin right\n"                             \
                 " t: set move speed\n"                                   \
                 " y: set move acceleration\n"                            \
                 "---------\n"                                            \
                 " a: front arm up\n"                                     \
                 " z: front arm down\n"                                   \
                 " s: back arm up\n"                                      \
                 " x: back arm down\n"                                    \
                 " c: set arm speed\n"                                    \
                 " v: set arm acceleration\n"                             \
                 " d: set the position of arm\n"                          \
                 " f: set current arm position as home position of arm\n" \
                 "---------\n"                                            \
                 " o: init dynamixel position\n"                          \
                 " i: dynamixel up\n"                                     \
                 " k: dynamixel down\n"                                   \
                 " j: dynamixel left\n"                                   \
                 " l: dynamixel right\n"                                  \
                 "---------\n"                                            \
                 " q: Quit the program\n"                                 \
                 "==========================\n"

#define KEY_UP    65
#define KEY_DOWN  66
#define KEY_RIGHT 67
#define KEY_LEFT  68

int main(int argc, char **argv)
{
    // init the ros node
    Robot robot(argc, argv, NODE_NAME);
    // rosInit(argc, argv, "Track_node");

    // set the frequency of the while loop to 100hz
    // avoid to publish the commands too frequently
    ros::Rate loop_rate(100);

    printf(HELP_MSG);

    int left_speed, right_speed, left_acc, right_acc;
    int front_angle, back_angle, front_speed, back_speed, front_acc, back_acc;

    char user_input;
    while(ros::ok())
    {
        user_input = getch();
        switch (user_input)
        {
            case KEY_UP:
                robot.move(FORWARD);
                break;
            case KEY_DOWN:
                robot.move(BACK);
                break;
            case KEY_RIGHT:
                robot.move(SPIN_RIGHT);
                break;
            case KEY_LEFT:
                robot.move(SPIN_LEFT);
                break;
            case ' ':
                robot.move(STOP);
                break;
            case 'a':
                robot.arm(FRONT_ARM_UP);
                break;
            case 'z':
                robot.arm(FRONT_ARM_DOWN);
                break;
            case 's':
                robot.arm(BACK_ARM_UP);
                break;
            case 'x':
                robot.arm(BACK_ARM_DOWN);
                break;
            case 'f':
                robot.setArmHomePosition();
                break;
            case 'd':
                printf("Set arm position (angle):");
                printf("front (degrees): ");
                scanf("%d", &front_angle);
                printf("back (degrees): ");
                scanf("%d", &back_angle);
                robot.armAngle(front_angle, back_angle);
                break;
            case 't':
                printf("Set move speed:");
                printf("left:");
                scanf("%d", &left_speed);
                printf("right:");
                scanf("%d", &right_speed);
                robot.setMoveSpeed(left_speed, right_speed);
                break;
            case 'y':
                printf("Set move acceleration:");
                printf("left:");
                scanf("%d", &left_acc);
                printf("right:");
                scanf("%d", &right_acc);
                robot.setMoveAcceleration(left_acc, right_acc);
                break;
            case 'c':
                printf("Set arm speed:");
                printf("front:");
                scanf("%d", &front_speed);
                printf("back:");
                scanf("%d", &back_speed);
                robot.setArmSpeed(front_speed, back_speed);
                break;
            case 'v':
                printf("Set arm acceleration:");
                printf("front:");
                scanf("%d", &front_acc);
                printf("back:");
                scanf("%d", &back_acc);
                robot. (front_acc, back_acc);
                break;
            case 'o':
                robot.dynamixelInit();
                break;
            case 'i':
                robot.dynamixel(DYNAMIXEL_UP);
                break;
            case 'k':
                robot.dynamixel(DYNAMIXEL_DOWN);
                break;
            case 'j':
                robot.dynamixel(DYNAMIXEL_LEFT);
                break;
            case 'l':
                robot.dynamixel(DYNAMIXEL_RIGHT);
                break;
            case 'q':
                printf("Quit %s\n", NODE_NAME);
                break;
            default:
                printf(HELP_MSG);
                break;
        }

        // if(y == 'p' || y == ' ')
        // {
        //     robot.move(STOP);
        // }

        // if(y == 't')
        // {
        //     int left_speed, right_speed;
        //     printf("set speed\n");
        //     printf("left: ");
        //     scanf("%d", &left_speed);
        //     printf("right: ");
        //     scanf("%d", &right_speed);

        //     if(left_speed < 300 || left_speed > 30000 || right_speed < 300 || right_speed > 30000)
        //         printf("speed must range in 300 ~ 30000\n");
        //     else
        //     {
        //         robot.setMoveSpeed(left_speed, right_speed);
        //     }
        // }

        // if(y == 'q')
        // {
        //     int left_acc, right_acc;
        //     printf("set acceleration\n");
        //     printf("left: ");
        //     scanf("%d", &left_acc);
        //     printf("right: ");
        //     scanf("%d", &right_acc);

        //     robot.setMoveAcceleration(left_acc, right_acc);
        // }

        // if(y == 'y')
        // {
        //     robot.setArmHomePosition();
        // }

        // if(y == 'g')
        // {
        //     int front, back;
        //     printf("set arm angle\n");
        //     printf("front: ");
        //     scanf("%d", &front);
        //     printf("back: ");
        //     scanf("%d", &back);
        //     robot.armAngle(front, back);
        // }
        // loop rate 100hz
        loop_rate.sleep();
    }
    return 0;
}
