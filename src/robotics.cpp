#include <ros/ros.h>
#include <std_msgs/String.h>

#include <iostream>
#include <time.h>
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
  	double ow;
	double sec;
  	double nsec;
	string parentid;
  	string childid;
}Position;

Position leftpos; 
Position headpos;
Position rightpos;


Position transfromleftpos; 
Position transfromheadpos;
Position transfromrightpos;

geometry_msgs::TransformStamped body;
//nav_msgs::Odometry body;
sensor_msgs::LaserScan laser;
geometry_msgs::Twist base_cmd;



void left(geometry_msgs::TransformStamped body){
	tf::StampedTransform transform;
	tf::transformStampedMsgToTF(body,transform);
  

	leftpos.x=transform.getOrigin().x();
  	leftpos.y=transform.getOrigin().y();
  	leftpos.z=transform.getOrigin().z();
  	leftpos.ox=transform.getRotation().x();
  	leftpos.oy=transform.getRotation().y();
  	leftpos.oz=transform.getRotation().z();
  	leftpos.ow=transform.getRotation().w();
  	leftpos.sec=transform.stamp_.toSec();
  	leftpos.nsec=transform.stamp_.toNSec();
  	leftpos.parentid=transform.frame_id_;
  	leftpos.childid=transform.child_frame_id_;
  
  	cout << "FrameID:" << leftpos.parentid << "Child ID" << leftpos.childid << "\n"; 
  	cout << "Sec:" << leftpos.sec <<"Nsec" << leftpos.nsec << "\n";
  	cout << "Translation" << "X:" << leftpos.y << "Y:" << leftpos.z << "Z" << leftpos.z << "\n";
  	cout << "Oritentation" << "OX:" << leftpos.ox << "OY:" << leftpos.oy << "OZ" << leftpos.oz << "OW" << leftpos.ow << "\n";
}

void head(geometry_msgs::TransformStamped body){
	tf::StampedTransform transform;
	tf::transformStampedMsgToTF(body,transform);

}


void right(geometry_msgs::TransformStamped body){
	tf::StampedTransform transform;
	tf::transformStampedMsgToTF(body,transform);

}


void transfromleft(tf::StampedTransform body){

	
}

void transfromhead(tf::StampedTransform body){

	
}


void transfromright(tf::StampedTransform body){
	

}


int main(int argc, char **argv){
	/// Name your node
	ros::init(argc, argv, "gestures");
	/// Every ros node needs a node handle, similar to your usual  file handle.
	ros::NodeHandle nh;
	ros::Subscriber leftsub= nh.subscribe("/left_hand",100,left);
 	ros::Subscriber headsub = nh.subscribe("/head",100,head);
 	ros::Subscriber rightsub = nh.subscribe("/right_hand",100,right);	
	tf::TransformListener leftlistener;
	tf::TransformListener headlistener;
	tf::TransformListener rightlistener;
	
	ros::Rate loop_rate(10);
	
	while(ros::ok()){
		tf::StampedTransform lefttransform;
		tf::StampedTransform headtransform;
		tf::StampedTransform righttransform;
    try{
    	ros::Time now = ros::Time::now();
    	leftlistener.waitForTransform("/openni_depth_frame", "/left_hand",now, ros::Duration(3.0));
      leftlistener.lookupTransform("/openni_depth_frame", "/left_hand",ros::Time(0), lefttransform);
    }catch(tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
     	ros::Duration(1.0).sleep();
    }
    try{
    	ros::Time now= ros::Time::now();
    	headlistener.waitForTransform("/openni_depth_frame", "/head",now, ros::Duration(3.0));
      headlistener.lookupTransform("/openni_depth_frame", "/head",ros::Time(0), headtransform);
    }catch(tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }
    try{
    	ros::Time now = ros::Time::now();
    	rightlistener.waitForTransform("/openni_depth_frame", "/right_hand",now, ros::Duration(3.0));
     	rightlistener.lookupTransform("/openni_depth_frame", "/right_hand",ros::Time(0), righttransform);
    }catch(tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
     	ros::Duration(1.0).sleep();
    }
    transfromleft(lefttransform);
    transfromhead(headtransform);
    transfromright(righttransform);
	ros::spinOnce();

	/// Sleep for as long as needed to achieve the loop rate.
	loop_rate.sleep();
	}
	return 0;
}
