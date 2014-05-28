

#include "mbed.h"
#include "Kernel.h"
#include <rosserial/ros.h>
#include <rosserial/std_msgs/ROSString.h>
#include <rosserial/std_msgs/Empty.h>
#include <rosserial/geometry_msgs/Pose2D.h>

ros::NodeHandle  nh;
char Gcode[100];
void getCommand_cb( const std_msgs::String& toggle_msg) {
    memset(Gcode,'\0',100);
    uint32_t leng_data=strlen((const char*) toggle_msg.data);
    memcpy(Gcode,toggle_msg.data,leng_data);
   
}

ros::Subscriber<std_msgs::String> gcode_sub("Gcode", &getCommand_cb );
geometry_msgs::Pose2D position;
ros::Publisher pos_pub("position", &position);



int main() {
    
    nh.initNode();
    nh.advertise(pos_pub);
    nh.subscribe(gcode_sub);
    Kernel* kernel=new Kernel();
    while (1) {
        position.x=0;
        position.y=0;
        position.theta=0;
        pos_pub.publish( &position );
        nh.spinOnce();
        kernel->call_event(ON_MAIN_LOOP);
        
    }
}