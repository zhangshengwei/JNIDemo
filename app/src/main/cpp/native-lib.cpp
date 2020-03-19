#include <jni.h>
#include <string>
#include <android/log.h>

/**
 *  静态注册 JNIEXPORT jstring JNICALL
 *  对应规则： java + 包名 + 类名 + 方法名
 *  jsting : 表示该方法返回的类型
 *  env: C语音中的指针
 */
extern "C"
JNIEXPORT jstring JNICALL
Java_cn_zsw_jnitest_JNI_getStringFromJNITest(JNIEnv *env, jobject thiz) {
    // TODO: implement getStringFromJNITest()
    std::string hello = "java 获取 C 层的数据";
    return env->NewStringUTF(hello.c_str());
}



