
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

#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float64.h"
#include "robot_control_api.h"

int main(int argc, char **argv)
{
    // init the ros node
    rosInit(argc, argv, "Track_node");

    // set the frequency of the while loop to 100hz
    // avoid to publish the commands too frequently
    ros::Rate loop_rate(100);

    char y;
    while(ros::ok())
    {

        y = getch();

        if(y == 'e')
        {
            printf("exit\n");
            break;
        }

        if(y == 'w')
        {
            printf("forward\n");
            goForward();
        }

        if(y == 's')
        {
            printf("back\n");
            goBack();
        }

        if(y == 'a')
        {
            printf("left\n");
            spinLeft();
        }

        if(y == 'd')
        {
            printf("right\n");
            spinRight();
        }

        if(y == 'r')
        {
            printf("turn right\n");
            turnLeftRight(1500, 1000);
        }

        if(y == 'l')
        {
            printf("turn left\n");
            turnLeftRight(1000, 1500);
        }

        if(y == 'j')
        {
            printf("init arm angle\n");
            resetArmAngle();
        }

        if(y == 'p')
        {
            printf("stop\n");
            stopMotion();
        }

        // loop rate 100hz
        loop_rate.sleep();
    }
    return 0;
}
