package com.alex.second;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

/**
 * Created by Alex on 23.01.15.
 */

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_layout);
    }

    public void goToNewActivity(View v) {
        Intent intent = new Intent(this, LastActivity.class);
        startActivity(intent);
    }

}
