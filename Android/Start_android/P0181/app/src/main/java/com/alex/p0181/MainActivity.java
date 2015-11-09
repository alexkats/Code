package com.alex.p0181;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.SeekBar;

public class MainActivity extends Activity implements SeekBar.OnSeekBarChangeListener {

    LinearLayout ll1;
    Button btn1;
    Button btn2;
    SeekBar sbWeight;
    LinearLayout.LayoutParams lp1;
    LinearLayout.LayoutParams lp2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        ll1 = (LinearLayout) findViewById(R.id.ll1);
        btn1 = (Button) findViewById(R.id.btn1);
        btn2 = (Button) findViewById(R.id.btn2);
        lp1 = (LinearLayout.LayoutParams) btn1.getLayoutParams();
        lp2 = (LinearLayout.LayoutParams) btn2.getLayoutParams();
        sbWeight = (SeekBar) findViewById(R.id.sbWeight);
        sbWeight.setOnSeekBarChangeListener(this);
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        int leftValue = progress;
        int rightValue = seekBar.getMax() - progress;
        lp1.weight = leftValue;
        lp2.weight = rightValue;
        btn1.setText(String.valueOf(leftValue));
        btn2.setText(String.valueOf(rightValue));
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {

    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {

    }
}