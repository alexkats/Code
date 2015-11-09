package com.alex.p0261;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

import java.text.SimpleDateFormat;
import java.util.Date;

public class DateActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.date);

        SimpleDateFormat sdf = new SimpleDateFormat("dd.MM.yyyy");
        String date = sdf.format(new Date(System.currentTimeMillis()));
        TextView tvDate = (TextView) findViewById(R.id.tvDate);
        tvDate.setText(date);
    }
}