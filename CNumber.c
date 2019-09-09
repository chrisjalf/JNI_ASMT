#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h> 

JNIEXPORT jintArray JNICALL Java_Number_firstNative(JNIEnv *env, jobject obj, jint array){
	//Create array with size of entered number
	jintArray arraySize = (*env)->NewIntArray(env, array);
	jint arrSize[array];
	if(arraySize == NULL){
	return NULL;
	}
	
	//Create random number and display them 
	printf("The values of the random number of the array is: ");
	int i, numless = 0;
	srand(time(0)); 
	for (int i = 0; i < array; i++) {
		arrSize[i] = rand() % 100;
		printf("%ld\t", arrSize[i]);
	}
	
	//Count the number below than 50
	for (i = 0; i < array; i++) {
		if (arrSize[i] < 50) {
			numless++;
		}
	}
	//Display the result
	printf("\nThe total number which is less than 50 is: %d\n", numless);

	(*env)->SetIntArrayRegion(env, arraySize, 0, array, arrSize);
	
	return arraySize;
}


JNIEXPORT jint JNICALL Java_Number_secondNative(JNIEnv *env, jobject obj, jintArray result){
	//Input the generated array from the first native method
	jsize len = (*env)->GetArrayLength(env, result);
	jint *num = (*env)->GetIntArrayElements(env, result, 0);
	
	//Choose the minimum and maximum number in the array
	int max = num[0];
	int min = num[0];
	int total = 0;
	//Find the minimum number
	for (int i = 1; i < len; i++) {
		if (num[i] < min) {
			min = num[i];
		}
	}
	
	//Find the maximum number
	for (int i = 1; i < len; i++) {
		if (num[i] > max) {
			max = num[i];
		}
	}
	
	(*env)->ReleaseIntArrayElements(env,result,num,0);
	
	//Calculate the difference of min and max number of the array
	total = max - min;
	return total;
}
