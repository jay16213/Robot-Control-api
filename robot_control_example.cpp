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
#include <dynamixel_workbench_msgs/JointCommand.h>
#include "control_api.h"

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

        scanf("%c", &y);

        if(y == 'e')
        {
            break;
        }

        if(y == 'w')
        {
            printf("forward");
            goForward();
        }

        if(y == 's')
        {
            printf("back");
            goBack();
        }

        if(y == 'a')
        {
            printf("left");
            spinLeft();
        }

        if(y == 'd')
        {
            printf("right");
            spinRight();
        }

        if(y == 'p')
        {
            printf("stop");
            stopMotion();
        }

        // loop rate 100hz
        loop_rate.sleep();
    }
    return 0;
}
