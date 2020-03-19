#include <jni.h>
#include <string>
#include <android/log.h>
#include <stdlib.h>
#include <stdio.h>

#define LOG_TAG "LogTAG_C++>>"
#define LOGV(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


/**
 * jstring ：返回值
 * Java_全类名_方法名
 * JNIEnv* env:里面有很多方法
 * jobject jobj：谁调用了这个方法就是谁的实例
 * 当前就是JNI.thi
 */
extern "C"
JNIEXPORT jstring JNICALL
Java_cn_zsw_jnitest_JNI_javaPrintJniLogCat(
        JNIEnv *env,
        jobject thiz) {
    LOGD("\nc函数中打印Log.e666\n");
    std::string hello = "日志打印完成";
    return env->NewStringUTF(hello.c_str());
}

/**
 * JNI  C 层调用java 层的静态方法
 * 1、根据类目录获取类对象
 * 2、根据静态方法名获取方法ID
 * 3、调用静态方法，传入类对象，方法ID，参数等
 * 补充说明: (Ljava/lang/String;)V 表示方法签名，前面的(Ljava/lang/String;)为参数类型，V为返回类型，V表示void
 */

extern "C" JNIEXPORT void JNICALL
Java_cn_zsw_jnitest_JNI_callStaticMethod__I(JNIEnv *env, jclass clazz, jint i) {
    // TODO: jni 调用java 静态方法
    // 获取指定的类，类文件目录为： 包名+类名 ，且 . 需要替换成
    jclass cls_printLog = env->FindClass("cn/zsw/jnitest/JNI");
    if (cls_printLog == NULL){
        LOGD("JNI 类对象获取失败");
        return ;
    }
    // 找到指定的静态方法
    jmethodID methodId =
            env->GetStaticMethodID(cls_printLog,"jniPrintJavaLogCat", "(Ljava/lang/String;)V");
    if(methodId == NULL){
        LOGD("JNI 类的方法ID获取失败");
        return;
    }

    // 找到对应的成员变量
    jfieldID  fld_name = env->GetStaticFieldID(cls_printLog,"name","Ljava/lang/String;");
    if (fld_name == NULL){
        return;
    }

    // 对java类的成员变量进行重新赋值
    jstring name = env->NewStringUTF("修改java 类中的成员变量");
    env->SetStaticObjectField(cls_printLog,fld_name,name);


    jstring message = env->NewStringUTF("jni 调用 java类的相关方法");
    if(message == NULL){
        LOGD("打印的字符串内容为空");
        return;
    }
    // 调用java层的方法
    env->CallStaticVoidMethod(cls_printLog,methodId,message);

    // 删除引用
    env->DeleteLocalRef(cls_printLog);
    env->DeleteLocalRef(message);
    env->DeleteLocalRef(name);
}

extern "C" JNIEXPORT void JNICALL
Java_cn_zsw_jnitest_JNI_callStaticMethod__JLjava_lang_String_2(JNIEnv *env, jclass clazz, jlong l,
                                                               jstring string) {
    // TODO: implement callStaticMethod()
}

extern "C" JNIEXPORT void JNICALL
Java_cn_zsw_jnitest_JNI_callInstanceMethod__I(JNIEnv *env, jobject jobject1, jint i) {
    // TODO: jni 调用java 实例方法
    jclass cls_printLog = env->FindClass("cn/zsw/jnitest/JNI");
    if (cls_printLog == NULL){
        LOGD("JNI 类对象获取失败");
        return ;
    }



    // 找到指定的构造方法，使用 init 作为标识
    jmethodID mtd_construct = env->GetMethodID(cls_printLog,"<init>","()V");
    if (mtd_construct == NULL){
        return;
    }

    // 创建相应对象
    jobject jni_object = env->NewObject(cls_printLog,mtd_construct,NULL);
    if (jni_object == NULL){
        return;
    }

    // 找到指定的静态方法
    jmethodID mtd_method =
            env->GetMethodID(cls_printLog,"instanceMethod", "(Ljava/lang/String;)V");
    if (mtd_method == NULL){
        return;
    }

    jstring message = env->NewStringUTF("jni 调用 java类的<<实例>>方法");
    env->CallVoidMethod(jni_object,mtd_method,message);

    env->DeleteLocalRef(message);
    env->DeleteLocalRef(cls_printLog);
    env->DeleteLocalRef(jni_object);
}

extern "C" JNIEXPORT void JNICALL
Java_cn_zsw_jnitest_JNI_callInstanceMethod__Ljava_lang_String_2J(JNIEnv *env, jobject thiz,
                                                                 jstring str, jlong i) {
    // TODO: implement callInstanceMethod()
}





