package cn.zsw.jnitest;

import android.util.Log;

/**
 * @Author: zsw
 * @CreateDate: 2020/2/27 14:51
 * @Description:
 */
public class JNI {

    public static final String TAG = "LogTAG_Java>>";
    static {
        System.loadLibrary("native-lib");
    }

    private static String name = "java 静态成员变量";
    private String address = "hangzhou";
    private static void logCatMessage(String message){
        Log.d(TAG, "::: " + message);
    }

    public native String getStringFromJNITest();
    public native String javaPrintJniLogCat();

    /**
     * 静态方法打印相关日志，该方法在C层被调用
     */
    public static void jniPrintJavaLogCat(String message){
        logCatMessage(message);
        logCatMessage(name);
    }

    /**
     * 实例方法打印相关日志，该方法在C层被调用
     */
    public void instanceMethod(String message){
        logCatMessage(message);
    }

    /**
     * 通过该方法名可获取C 层相对应的方法
     * @param i
     */
    public static native void callStaticMethod(int i);

    public static native void callStaticMethod(long l,String string);


    public native void callInstanceMethod(int i);

    public native void callInstanceMethod(String str,long i);




}
