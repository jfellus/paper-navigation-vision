#include "../api.h"


void control(uint t, float odoX, float odoY, float odoTheta, unsigned char* image, uint w, uint h, float* outSpeed, float* outAngle) {
	usleep(100000);
	*outSpeed = 1;
	*outAngle = -1;
}
