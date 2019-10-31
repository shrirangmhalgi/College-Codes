#include <jni.h>
#include <stdio.h>
#include "Calc.h"
 
// Implementation of native method sayHello() of HelloJNI class
JNIEXPORT void JNICALL Java_Calc_calculate(JNIEnv *env, jobject thisObj,jint a,jint b,jchar op) {
   int ans;
   if(op=='+')
   {
   		ans=a+b;
  	 	printf("\nAnswer : ");
   		printf("%d\n", ans);
   }
   
   if(op=='-')
   {
   		ans=a-b;
  	 	printf("\nAnswer : ");
   		printf("%d\n", ans);
   }
   
   if(op=='*')
   {
   		ans=a*b;
  	 	printf("\nAnswer : ");
   		printf("%d\n", ans);
   }
   
   if(op=='/')
   {
   		ans=a/b;
  	 	printf("\nAnswer : ");
   		printf("%d\n", ans);
   }
   return;
}
