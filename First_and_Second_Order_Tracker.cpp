#include <iostream>

void FirstOrderTracker(int ref, double &feedback){

	double error = ref-feedback;
	double dt = 0.05;
	double xd;
	double K = 2;

	xd = K*error;
	feedback += xd*dt;
}
void SecondOrderTracker(int ref, double &feedback, double &xd){

	double error = ref-feedback;
	double dt = 0.05;
	double xdd;
	double NATURALFREQ = 2.0;
	double DAMPER = 0.7;

	xdd = NATURALFREQ*NATURALFREQ*error - 2*DAMPER*NATURALFREQ*xd;
  	xd += xdd*dt;
  	feedback += xd*dt;
}


int main(){
	
	int ref = 100;
	double feedback = 0;
	double xd = 0;

	int i=0;
	while(i<100){
		//FirstOrderTracker(ref, feedback);
		SecondOrderTracker(ref, feedback, xd);
		std::cout<<"ref: "<<ref<<"  feedback: "<<feedback<<std::endl;
		std::cout<<"xd: "<<xd<<std::endl;
		i++;
	}
	
	return 0;
}