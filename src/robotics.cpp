#include <ros/ros.h>
#include <std_msgs/String.h>
#include <cmath>

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


Position pasttransfromleftpos; 
Position pasttransfromheadpos;
Position pasttransfromrightpos;

geometry_msgs::TransformStamped body;
//nav_msgs::Odometry body;
//sensor_msgs::LaserScan laser;
//geometry_msgs::Twist base_cmd;



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


void printtransfrom(tf::StampedTransform body,string message){
  
  cout << message << "\n";
  cout << "FrameID: " << body.frame_id_ << " Child ID: " << body.child_frame_id_ << "\n"; 
  cout << "Sec: " << body.stamp_.toSec() <<" Nsec: " << body.stamp_.toNSec() << "\n";
  cout << "Translation" << "X: " << body.getOrigin().x() << "Y: " << body.getOrigin().y() << "Z: " << body.getOrigin().z() << "\n";
  cout << "Oritentation" << "OX: " << body.getRotation().x() << "OY: " << body.getRotation().y() << "OZ: " << body.getRotation().z() << "OW: " << body.getRotation().w() << "\n";

	
}

void transfromleft(tf::StampedTransform body){
  transfromleftpos.x=body.getOrigin().x();
  transfromleftpos.y=body.getOrigin().y();
  transfromleftpos.z=body.getOrigin().z();
  transfromleftpos.ox=body.getRotation().x();
  transfromleftpos.oy=body.getRotation().y();
  transfromleftpos.oz=body.getRotation().z();
  transfromleftpos.ow=body.getRotation().w();
  transfromleftpos.sec=body.stamp_.toSec();
  transfromleftpos.nsec=body.stamp_.toNSec();
  transfromleftpos.parentid=body.frame_id_;
  transfromleftpos.childid=body.child_frame_id_;
  
}

void transfromhead(tf::StampedTransform body){
  headpos.x=body.getOrigin().x();
  headpos.y=body.getOrigin().y();
  headpos.z=body.getOrigin().z();
  headpos.ox=body.getRotation().x();
  headpos.oy=body.getRotation().y();
  headpos.oz=body.getRotation().z();
  headpos.ow=body.getRotation().w();
  headpos.sec=body.stamp_.toSec();
  headpos.nsec=body.stamp_.toNSec();
  headpos.parentid=body.frame_id_;
  headpos.childid=body.child_frame_id_;
  
  cout << "FrameID: " << headpos.parentid << " Child ID: " << headpos.childid << "\n"; 
  cout << "Sec: " << headpos.sec <<"Nsec" << headpos.nsec << "\n";
  cout << "Translation" << "X: " << headpos.y << "Y: " << headpos.z << "Z: " << headpos.z << "\n";
  cout << "Oritentation" << "OX: " << headpos.ox << "OY: " << headpos.oy << "OZ: " << headpos.oz << "OW: " << headpos.ow << "\n";
	
}


void transfromright(tf::StampedTransform body){
	rightpos.x=body.getOrigin().x();
  rightpos.y=body.getOrigin().y();
  rightpos.z=body.getOrigin().z();
  rightpos.ox=body.getRotation().x();
  rightpos.oy=body.getRotation().y();
  rightpos.oz=body.getRotation().z();
  rightpos.ow=body.getRotation().w();
  rightpos.sec=body.stamp_.toSec();
  rightpos.nsec=body.stamp_.toNSec();
  rightpos.parentid=body.frame_id_;
  rightpos.childid=body.child_frame_id_;
  
  cout << "FrameID: " << rightpos.parentid << " Child ID: " << rightpos.childid << "\n"; 
  cout << "Sec: " << rightpos.sec <<"Nsec" << rightpos.nsec << "\n";
  cout << "Translation" << "X: " << rightpos.y << "Y: " << rightpos.z << "Z: " << rightpos.z << "\n";
  cout << "Oritentation" << "OX: " << rightpos.ox << "OY: " << rightpos.oy << "OZ: " << rightpos.oz << "OW: " << rightpos.ow << "\n";

}

void pasttransfromleft(tf::StampedTransform body){
  pasttransfromleftpos.x=body.getOrigin().x();
  pasttransfromleftpos.y=body.getOrigin().y();
  pasttransfromleftpos.z=body.getOrigin().z();
  pasttransfromleftpos.ox=body.getRotation().x();
  pasttransfromleftpos.oy=body.getRotation().y();
  pasttransfromleftpos.oz=body.getRotation().z();
  pasttransfromleftpos.ow=body.getRotation().w();
  pasttransfromleftpos.sec=body.stamp_.toSec();
  pasttransfromleftpos.nsec=body.stamp_.toNSec();
  pasttransfromleftpos.parentid=body.frame_id_;
  pasttransfromleftpos.childid=body.child_frame_id_;
  
}

void pasttransfromhead(tf::StampedTransform body){
  headpos.x=body.getOrigin().x();
  headpos.y=body.getOrigin().y();
  headpos.z=body.getOrigin().z();
  headpos.ox=body.getRotation().x();
  headpos.oy=body.getRotation().y();
  headpos.oz=body.getRotation().z();
  headpos.ow=body.getRotation().w();
  headpos.sec=body.stamp_.toSec();
  headpos.nsec=body.stamp_.toNSec();
  headpos.parentid=body.frame_id_;
  headpos.childid=body.child_frame_id_;
  
  cout << "FrameID: " << headpos.parentid << " Child ID: " << headpos.childid << "\n"; 
  cout << "Sec: " << headpos.sec <<"Nsec" << headpos.nsec << "\n";
  cout << "Translation" << "X: " << headpos.y << "Y: " << headpos.z << "Z: " << headpos.z << "\n";
  cout << "Oritentation" << "OX: " << headpos.ox << "OY: " << headpos.oy << "OZ: " << headpos.oz << "OW: " << headpos.ow << "\n";
  
}


void pasttransfromright(tf::StampedTransform body){
  rightpos.x=body.getOrigin().x();
  rightpos.y=body.getOrigin().y();
  rightpos.z=body.getOrigin().z();
  rightpos.ox=body.getRotation().x();
  rightpos.oy=body.getRotation().y();
  rightpos.oz=body.getRotation().z();
  rightpos.ow=body.getRotation().w();
  rightpos.sec=body.stamp_.toSec();
  rightpos.nsec=body.stamp_.toNSec();
  rightpos.parentid=body.frame_id_;
  rightpos.childid=body.child_frame_id_;
  
  cout << "FrameID: " << rightpos.parentid << " Child ID: " << rightpos.childid << "\n"; 
  cout << "Sec: " << rightpos.sec <<"Nsec" << rightpos.nsec << "\n";
  cout << "Translation" << "X: " << rightpos.y << "Y: " << rightpos.z << "Z: " << rightpos.z << "\n";
  cout << "Oritentation" << "OX: " << rightpos.ox << "OY: " << rightpos.oy << "OZ: " << rightpos.oz << "OW: " << rightpos.ow << "\n";

}



int main(int argc, char **argv){
	/// Name your node
	ros::init(argc, argv, "robotics");
	/// Every ros node needs a node handle, similar to your usual  file handle.
	ros::NodeHandle nh;
	//ros::Subscriber leftsub= nh.subscribe("/left_hand_1",100,&left);
 	//ros::Subscriber headsub = nh.subscribe("/head_1",100,&head);
 	//ros::Subscriber rightsub = nh.subscribe("/right_hand_1",100,&right);	
	tf::TransformListener leftlistener;
	tf::TransformListener headlistener;
	tf::TransformListener rightlistener;

  tf::TransformListener pastleftlistener;
  tf::TransformListener pastheadlistener;
  tf::TransformListener pastrightlistener;
	
	ros::Rate loop_rate(10);
	
	while(ros::ok()){
		tf::StampedTransform lefttransform;
		tf::StampedTransform headtransform;
		tf::StampedTransform righttransform;

    tf::StampedTransform pastlefttransform;
    tf::StampedTransform pastheadtransform;
    tf::StampedTransform pastrighttransform;
    try{
    	ros::Time now = ros::Time::now();
    	leftlistener.waitForTransform("/openni_depth_frame", "/left_hand_1",now, ros::Duration(3.0));
      leftlistener.lookupTransform("/openni_depth_frame", "/left_hand_1",now, lefttransform);

      ros::Time past = ros::Time::now() - ros::Duration(1.0);
      pastleftlistener.waitForTransform("/openni_depth_frame", "/left_hand_1",past, ros::Duration(1.0));
      pastleftlistener.lookupTransform("/openni_depth_frame", "/left_hand_1",past, pastlefttransform);
    }catch(tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
     	ros::Duration(1.0).sleep();
    }
    try{
    	ros::Time now= ros::Time::now();
    	headlistener.waitForTransform("/openni_depth_frame", "/head_1",now, ros::Duration(3.0));
      headlistener.lookupTransform("/openni_depth_frame", "/head_1",now, headtransform);

      ros::Time past = ros::Time::now() - ros::Duration(1.0);
      pastheadlistener.waitForTransform("/openni_depth_frame", "/head_1",past, ros::Duration(1.0));
      pastheadlistener.lookupTransform("/openni_depth_frame", "/head_1",past, pastheadtransform);
    }catch(tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }
    try{
    	ros::Time now = ros::Time::now();
    	rightlistener.waitForTransform("/openni_depth_frame", "/right_hand_1",now, ros::Duration(3.0));
     	rightlistener.lookupTransform("/openni_depth_frame", "/right_hand_1",now, righttransform);

      ros::Time past = ros::Time::now() - ros::Duration(1.0);
      pastrightlistener.waitForTransform("/openni_depth_frame", "/right_hand_1",past, ros::Duration(1.0));
      pastrightlistener.lookupTransform("/openni_depth_frame", "/right_hand_1",past, pastrighttransform);
    }catch(tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
     	ros::Duration(1.0).sleep();
    }
    printtransfrom(lefttransform,"CURRENT");
    transfromleft(lefttransform);

    //printtransfrom(headtransform);
    //printtransfrom(righttransform);

    printtransfrom(pastlefttransform,"PAST");
    pasttransfromleft(pastlefttransform);

    //printtransfrom(pastheadtransform);
    //printtransfrom(pastrighttransform);


    if(.5<sqrt(((pasttransfromleftpos.x-transfromleftpos.x)*(pasttransfromleftpos.x-transfromleftpos.x))+((pasttransfromleftpos.y-transfromleftpos.y)*(pasttransfromleftpos.y-transfromleftpos.y))+((pasttransfromleftpos.z-transfromleftpos.z)*(pasttransfromleftpos.z-transfromleftpos.z)))){
      cerr << "Start gestrure Recognition\n";
    }

	  ros::spinOnce();

	/// Sleep for as long as needed to achieve the loop rate.
	loop_rate.sleep();
	}
	return 0;
}
