#include <sys/resource.h> 
#include <sys/time.h> 
#include <unistd.h> 
#include<stdio.h> 

int main () 
{
	struct rlimit rl; 

	getrlimit (RLIMIT_CPU, &rl);

	printf("\n Default value is : %lld\n", (long long int)rl.rlim_cur); 

	rl.rlim_cur = 1; 

	setrlimit (RLIMIT_CPU, &rl); 

	getrlimit (RLIMIT_CPU, &rl); 

	printf("\n Default value now is : %lld\n", (long long int)rl.rlim_cur); 
                     // Simulate a long time consuming work 
	while (1); 

	return 0; 
}
