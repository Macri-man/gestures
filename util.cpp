#include <cmath>
#include <iostream>
#include <util.h>

bool isdistance(double dist,double cordist){
	return dist-.1 <= cordist || cordist <= dist+.1; 
}

double distance(Point start, Point end){
	return sqrt(((end.x-start.x)*(end.x-start.x))+((end.y-start.y)*(end.y-start.y))+((end.z-start.z)*(end.z-start.z)));
}

double lenArch(Point start,Point mid,Point end){
	double a=distance(start,mid);
	double b=distance(mid,end);
	double c=distance(start,end);
	double r=(a*b*c)/(sqrt((a+b+c)(b+c-a)(c+a-b)(a+b-c)));
	return r;
}

double angle(Point p1,Point p2){
	return arctan2(p2.y-p1.y,p2.x-p1.x)*180/M_PI;
}

bool start(Point first,Point second){
	return isdistance(distance(first,second),3);
}

bool end(Point first,Point second){
	return isdistance(distance(first,second),3);
}

bool isArch(Point start,Point mid,Point end){
	return (distance(start,mid)+distance(mid,end)==distance(start,end)+.1)||(distance(start,mid)+distance(mid,end)==distance(start,end)-.1);	
}

bool isSquare(Point upleft,Point upright,Point bottomright,Point bottemleft){
	double side1 = distance(upleft,upright);
	double side2 = distance(upright,bottomright);
	double side3 = distance(bottomright,bottomleft);
	double side4 = distance(bottomleft,upleft);
	
	return isdistance(side1,side3)&&isdistance(side2,side4); 
}

bool isTriangle(Point top,Point left,Point right){
	

}

bool isline(bool isdist){
	return isdist;
}


