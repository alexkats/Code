package com.alex.p0111;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {

    LinearLayout llBottom;
    TextView tvBottom;
    Button btnBottom;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        llBottom = (LinearLayout) findViewById(R.id.llBottom);
        tvBottom = (TextView) findViewById(R.id.tvBottom);
        btnBottom = (Button) findViewById(R.id.btnBottom);
        llBottom.setBackgroundResource(R.color.llBottomColor);
        tvBottom.setText(R.string.tvBottomText);
        btnBottom.setText(R.string.btnBottomText);
    }

}