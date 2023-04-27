#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

Servo servo_section1_x;
Servo servo_section1_y;
Servo servo_section2_x;
Servo servo_section2_y;

void servox_sec1_cb( const std_msgs::UInt16& cmd_msg){
  servo_section1_x.writeMicroseconds(cmd_msg.data); 
}

void servoy_sec1_cb( const std_msgs::UInt16& cmd_msg){
  servo_section1_y.writeMicroseconds(cmd_msg.data); 
}

void servox_sec2_cb( const std_msgs::UInt16& cmd_msg){
  servo_section2_x.writeMicroseconds(cmd_msg.data); 
}

void servoy_sec2_cb( const std_msgs::UInt16& cmd_msg){
  servo_section2_y.writeMicroseconds(cmd_msg.data); 
}

ros::Subscriber<std_msgs::UInt16> sub1("Servox_sec1_us", servox_sec1_cb);
ros::Subscriber<std_msgs::UInt16> sub2("Servoy_sec1_us", servoy_sec1_cb);
ros::Subscriber<std_msgs::UInt16> sub3("Servox_sec2_us", servox_sec2_cb);
ros::Subscriber<std_msgs::UInt16> sub4("Servoy_sec2_us", servoy_sec2_cb);

void setup(){
  nh.initNode();
  nh.subscribe(sub1);
  nh.subscribe(sub2);
  nh.subscribe(sub3);
  nh.subscribe(sub4);
  
  servo_section1_x.attach(3); //attach it to pin 3
  servo_section1_y.attach(5); //attach it to pin 5
  servo_section2_x.attach(6); //attach it to pin 6
  servo_section2_y.attach(9); //attach it to pin 9
}

void loop(){
  nh.spinOnce();
  delay(1);
}
