#include <jni.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

JNIEXPORT jintArray JNICALL Java_ArrayMinMax_displayResult(JNIEnv *env, jobject obj, jint arrSize){
	int i, randNum, count = 0;
	jsize len = arrSize;
	jint arrRN[len];
	jintArray arrayRandNum;
	arrayRandNum = (*env)->NewIntArray(env, len);
	
	if(arrayRandNum == NULL){
		return NULL;
	}
	
	srand(time(0));
	
	for(i = 0; i < len; i++){
		randNum = rand() % 100 + 1;
		printf("%d ", randNum);
		if(randNum < 50){
			count++;
		}
		arrRN[i] = randNum;
	}
	
	(*env)->SetIntArrayRegion(env, arrayRandNum, 0, len, arrRN);
	
	printf("\nNumber of integer lesser than 50 in array: %d", count);
	return arrayRandNum;
}

JNIEXPORT jint JNICALL Java_ArrayMinMax_displayDifference(JNIEnv *env, jobject obj, jintArray arrayRandNum){
	int i, max = 0, min;
	jsize len = (*env)->GetArrayLength(env, arrayRandNum);
	jint *arrCopy = (*env)->GetIntArrayElements(env, arrayRandNum, 0); 
	
	for(i = 0; i < len; i++){	// loop to find max
		if(arrCopy[i] > max){
			max = arrCopy[i];
			min = max;
		}
	}
	
	for(i = 0; i < len; i++){	// loop to find min
		if(arrCopy[i] < min){
			min = arrCopy[i];
		}
	}
	
	printf("\nMax: %d", max);
	printf("\nMin: %d", min);
	
	(*env)->ReleaseIntArrayElements(env, arrayRandNum, arrCopy, 0);
	
	return (max - min);
}