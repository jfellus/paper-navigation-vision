#include "api.h"
#include "robulab.h"
#include "diyaone.h"
#include "utils/V4LIn.h"

uint t = 0;
int main(int argc, char const *argv[]) {

	V4LIn image("/dev/video0");
	Robulab robot("192.168.1.2", 10000);

	float odoX, odoY, odoTheta;
	float speed, angle;

	char sImg[256];
	system("rm -rf data; mkdir -p data/images");
	FILE* fTrajectory = fopen("data/trajectory.txt", "w");

	image.start();
	for(t=0; ; t++) {
		printf("-----------------\n");
		printf("t=%u\n", t);

		robot.getOdo(&odoX, &odoY, &odoTheta);
		image.readFrame();
		printf("odo=(%f,%f,%f)\n", odoX, odoY, odoTheta);
		printf("image=(%u,%u)\n", image.w,image.h);

		control(t, odoX, odoY, odoTheta, image.data, image.w, image.h, &speed, &angle);

		printf("command=(%f,%f)\n", speed, angle);
		robot.setCommand(speed, angle);

		// Dump
		fprintf(fTrajectory, "%u %f %f %f %f %f\n", t, odoX, odoY, odoTheta, speed, angle);
		fflush(fTrajectory);
		FILE* fN = fopen("data/N", "w"); fprintf(fN, "%u", t); fclose(fN);
		sprintf(sImg, "data/images/%08u.jpg", t);
		save_jpg(image.data, image.w, image.h, sImg);
		sprintf(sImg, "ln -sf images/%08u.jpg data/image.jpg", t); system(sImg);
		printf("\n");
	}
	return 0;
}
