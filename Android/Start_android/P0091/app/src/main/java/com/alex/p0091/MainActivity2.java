package com.alex.p0091;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity2 extends Activity implements View.OnClickListener {

    TextView tvOut;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        tvOut = (TextView) findViewById(R.id.tvOut);
        Button btnOk = (Button) findViewById(R.id.btnOk);
        Button btnCancel = (Button) findViewById(R.id.btnCancel);
        btnOk.setOnClickListener(this);
        btnCancel.setOnClickListener(this);


    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btnOk:
                tvOut.setText("OKAY");
                break;
            case R.id.btnCancel:
                tvOut.setText("CANCEL");
                break;
        }
    }
}