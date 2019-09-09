#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

JNIEXPORT void JNICALL Java_HonoursClassification_calculateDiploma(JNIEnv *env, jobject obj){
	float cgpa = 0, cgpaTwoDP;
	char classHons[12];
	
	printf("\n---------------------------------------------------------------\n");
	printf("|   Classification of Honours (Diploma)     |   CGPA          |\n");
	printf("|-------------------------------------------|-----------------|\n");
	printf("|   Distinction                             |   3.50 - 4.00   |\n");
	printf("|   Credit                                  |   3.00 - 3.49   |\n");
	printf("|   Pass                                    |   2.00 - 2.99   |\n");
	printf("---------------------------------------------------------------\n");

	printf("\nPlease enter your CGPA: ");
	scanf("%f", &cgpa);
	
	cgpaTwoDP = roundf(100 * cgpa) / 100;
	
	if( cgpaTwoDP >= 2.00 && cgpaTwoDP <= 2.99 )
		strcpy(classHons, "Pass");
	else if(cgpaTwoDP >= 3.0 && cgpaTwoDP < 3.49)
		strcpy(classHons, "Credit");
	else if(cgpaTwoDP >= 3.50 && cgpaTwoDP <= 4.00)
		strcpy(classHons, "Distinction");
	else{
		strcpy(classHons, "Invalid");
		printf("\nInvalid CGPA");
	}
	
	printf("\n---------------------------------------------\n");
	printf("|   Classification of Honours (Diploma)     | %s\n", classHons);
	printf("|-------------------------------------------|\n");
	printf("|   Your CGPA                               | %.2f\n", cgpa);
	printf("---------------------------------------------\n");
	
	return; 
}

JNIEXPORT void JNICALL Java_HonoursClassification_calculateDegree(JNIEnv *env, jobject obj){
	float cgpa = 0;
	
	printf("\n---------------------------------------------------------------\n");
	printf("|   Classification of Honours (Degree)      |   CGPA          |\n");
	printf("|-------------------------------------------|-----------------|\n");
	printf("|   First                                   |   3.67 - 4.00   |\n");
	printf("|   Second Upper                            |   3.33 - 3.66   |\n");
	printf("|   Second Lower                            |   2.67 - 3.32   |\n");
	printf("|   Third                                   |   2.0  - 2.66   |\n");
	printf("---------------------------------------------------------------\n");
	
	
	printf("\nPlease enter your CGPA: ");
	scanf("%f", &cgpa);
	
	return; 
}