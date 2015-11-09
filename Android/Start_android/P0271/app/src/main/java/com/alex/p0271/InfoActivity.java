package com.alex.p0271;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

import java.text.SimpleDateFormat;
import java.util.Date;

public class InfoActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.info);

        Intent intent = getIntent();
        String action = intent.getAction();
        String format = "";
        String textInfo = "";

        if (action.equals("com.alex.intent.action.showtime")) {
            format = "HH:mm:ss";
            textInfo = "Time: ";
        } else if (action.equals("com.alex.intent.action.showdate")) {
            format = "dd.MM.yyyy";
            textInfo = "Date: ";
        }

        SimpleDateFormat sdf = new SimpleDateFormat(format);
        String result = sdf.format(new Date(System.currentTimeMillis()));

        TextView tvInfo = (TextView) findViewById(R.id.tvInfo);
        tvInfo.setText(textInfo + result);
    }
}