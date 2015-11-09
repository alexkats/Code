package com.alex.p0281;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class ViewActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view);
        Intent intent = getIntent();
        String first = intent.getStringExtra("First name");
        String last = intent.getStringExtra("Last name");
        TextView tvView = (TextView) findViewById(R.id.tvView);
        tvView.setText(first + " " + last);
    }
}