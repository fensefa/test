#include <iostream>
#include <string>
#include "Test.h"
JNIEXPORT jint JNICALL Java_Test_intMethod(JNIEnv* env, jobject obj, jint n)
{
    std::cout << "hello, jni int method\n";
    return 100 + n;
}
JNIEXPORT jstring JNICALL Java_Test_stringMethod(JNIEnv* env, jobject obj, jstring jstr)
{
    std::cout << "hello, jni str method\n";
    jboolean bl = false;
    const char* str = env->GetStringUTFChars(jstr, &bl);
    std::string cstr = std::string("jni_") + str;
    jstring res_str = env->NewStringUTF(cstr.c_str());
    return res_str;
}
