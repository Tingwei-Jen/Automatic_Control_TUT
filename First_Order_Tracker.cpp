#include <iostream>

void FirstOrderTracker(int ref, double &feedback){

	double error;
	double dt = 0.05;
	double xd;
	double K = 2;
	error = ref-feedback;
	xd = K*error;
	feedback += xd*dt;
}



int main(){
	
	int ref = 100;
	double feedback = 0;
	int i=0;
	while(i<100){
		FirstOrderTracker(ref, feedback);
		std::cout<<"ref: "<<ref<<"  feedback: "<<feedback<<std::endl;
		i++;
	}
	
	return 0;
}