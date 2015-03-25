#include <ros/ros.h>
#include <std_msgs/String.h>

#include <iostream>

#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <cmath>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TransformStamped.h>
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>
#include <sstream>
#include <string>

using namespace std;

void left(geometry_msgs::TransformStamped body);
void head(geometry_msgs::TransformStamped body);
void right(geometry_msgs::TransformStamped body);

typedef struct Position{
	double x;
	double y;
	double z;
	double ox;
	double oy;
	double oz;
	double sec;
	string id;
}Position;

Position leftpos; 
Position headpos;
Position rightpos;

geometry_msgs::TransformStamped body;
//nav_msgs::Odometry body;
sensor_msgs::LaserScan laser;
geometry_msgs::Twist base_cmd;



void left(geometry_msgs::TransformStamped body){
	tf::StampedTransform transform;
	tf::transformStampedMsgToTF(body,transform);
//	cout << "Stamp:" << transform.stamp << "Frame Id:" << transform.frame_id << "ChildFrame Id:" << transform.child_frame_id << "X:" << transform.x << "Y:" << << "Z" << << "XO:" << << "YO:" << << "ZO" << << "WO" << "\n";
}

void head(geometry_msgs::TransformStamped body){
	tf::StampedTransform transform;
	tf::transformStampedMsgToTF(body,transform);
}


void right(geometry_msgs::TransformStamped body){
	tf::StampedTransform transform;
	tf::transformStampedMsgToTF(body,transform);

}


int main(int argc, char **argv){
	/// Name your node
	ros::init(argc, argv, "gestures");
	/// Every ros node needs a node handle, similar to your usual  file handle.
	ros::NodeHandle nh;
	//ros::Subscriber leftsub= nh.subscribe("/left_hand",100,left);
 	//ros::Subscriber headsub = nh.subscribe("/head",100,head);
 	//ros::Subscriber rightsub = nh.subscribe("/right_hand",100,right);	
	// User input
	tf::TransformListener leftlistener;
	tf::TransformListener headlistener;
	tf::TransformListener rightlistener;
	
	ros::Rate loop_rate(10);
	
	while (ros::ok()){
		tf::StampedTransform lefttransform;
		tf::StampedTransform headtransform;
		tf::StampedTransform righttransform;
    try{
      leftlistener.lookupTransform("/openni_depth_frame", "/left_hand",ros::Time(0), lefttransform);
    }catch(tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
     	ros::Duration(1.0).sleep();
    }
    try{
      headlistener.lookupTransform("/openni_depth_frame", "/head",ros::Time(0), headtransform);
    }catch(tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }
    try{
     	rightlistener.lookupTransform("/openni_depth_frame", "/right_hand",ros::Time(0), righttransform);
    }catch(tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
     	ros::Duration(1.0).sleep();
    }
    
    checkStartGesture();
		ros::spinOnce();

		/// Sleep for as long as needed to achieve the loop rate.
		loop_rate.sleep();
	}
	return 0;
}
