package com.alex.third;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

/**
 * Created by Alex on 23.01.15.
 */

public class MainActivity extends Activity {

    private EditText login;
    private EditText password;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_layout);
        login = (EditText) findViewById(R.id.editText);
        password = (EditText) findViewById(R.id.editText2);
    }

    public void sendData(View view) {
        Intent intent = new Intent(this, LastActivity.class);
        intent.putExtra("login", login.getText().toString());
        intent.putExtra("pass", password.getText().toString());
        startActivity(intent);
    }

}
