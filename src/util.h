#ifndef  UTIL_H
#define  UTIL_H

typedef Point{
	double x;
	double y;
	double z;
} Point;

bool isdistance(double dist,double cordist);
double distance(double startx,double starty,double startz,double endx,double endy,double endz);
double lenArch(Point start,Point mid,Point end);

double angle(Point p1,Point p2);

bool start(Point first,Point second);
bool end(Point first,Point second);
bool isArch(Point start,Point mid,Point end);

bool isSquare(Point upleft,Point upright,Point bottomright,Point bottem left);
bool isTriangle(Point top,Point left,Point right);
bool isline(bool isdist);

#endif
