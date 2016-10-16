package com.example.wangkang.myapplication;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.wangkang.*;

public class MainActivity extends AppCompatActivity {

    public static String User_Add = "wangkang@qq.com";
    public static String User_Name = "wangkang";
    public static String User_Pwd = "123456";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final EditText editText_Address = (EditText)findViewById(R.id.mEditText_Address);
        final EditText editText_Password = (EditText)findViewById(R.id.mEditText_PWD);

        Button mButton_Login = (Button)findViewById(R.id.mButton_Login);
        mButton_Login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String Address = editText_Address.getText().toString();
                String Password = editText_Password.getText().toString();
                Log.i("输入的邮箱和密码","邮箱为："+Address+"， 密码为："+Password);

                Toast.makeText(MainActivity.this, "你点击了确认按钮.", Toast.LENGTH_LONG).show();

                if(Address.equals(User_Add)){
                    Log.i("Step Here.", "Debug by wangkang.");
                    if (Password.equals(User_Pwd)){
                        Log.i("输入的邮箱和密码正确","邮箱为："+Address+"， 用户名为："+User_Name);
                        Intent intent = new Intent(MainActivity.this, SecondActivity.class);
                        startActivity(intent);
                    }
                }
            }
        });

        Button mButton_Cancel = (Button)findViewById(R.id.mButton_Cancel);
        mButton_Cancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this, "你点击了取消按钮， 程序退出.", Toast.LENGTH_LONG).show();
                finish();
            }
        });

        Button mButton_Reedit = (Button)findViewById(R.id.mButton_Reedit);
        mButton_Reedit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this, "你点击了重新输入按钮.", Toast.LENGTH_LONG).show();
                editText_Address.setText("");
                editText_Address.setFocusable(true);
                editText_Password.setText("");
            }
        });
    }
}
