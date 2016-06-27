#ifndef __INC_API_H__
#define __INC_API_H__

#include "utils.h"

void control(uint t, float odoX, float odoY, float odoTheta, unsigned char* image, uint w, uint h, float* outSpeed, float* outAngle);



class Robot {
public:
	Robot() {}
	virtual ~Robot() {}

	virtual void getOdo(float* odoX, float* odoY, float* odoTheta) = 0;
	virtual void setCommand(float speed, float angle) = 0;
};


#endif
