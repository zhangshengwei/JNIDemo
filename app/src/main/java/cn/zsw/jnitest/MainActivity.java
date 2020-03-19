package cn.zsw.jnitest;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private JNI jniDemo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        jniDemo = new JNI();
        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);

        tv.setText(jniDemo.getStringFromJNITest());

        TextView tv1 = findViewById(R.id.text1);
        tv1.setText("打印LogCat 日志内容:" + jniDemo.javaPrintJniLogCat());


        JNI.callStaticMethod(12);
        TextView tv2 = findViewById(R.id.text2);
        jniDemo.callInstanceMethod(2);

    }




}
