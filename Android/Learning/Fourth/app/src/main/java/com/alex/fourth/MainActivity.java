package com.alex.fourth;

import android.app.Activity;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.Toast;

/**
 * Created by Alex on 23.01.15.
 */

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_layout);
    }

    public void onShow(View view) {
        Toast toast = Toast.makeText(getApplicationContext(), "Hello!", Toast.LENGTH_SHORT);
        toast.setGravity(Gravity.CENTER, 0, -350);
        toast.show();
    }

}
