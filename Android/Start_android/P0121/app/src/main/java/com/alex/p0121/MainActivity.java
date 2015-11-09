package com.alex.p0121;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity implements View.OnClickListener {

    TextView tvOut;
    Button btnOk;
    Button btnCancel;

    private static final String TAG = "myLogs";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        Log.d(TAG, "Find View elements");
        tvOut = (TextView) findViewById(R.id.tvOut);
        btnOk = (Button) findViewById(R.id.btnOk);
        btnCancel = (Button) findViewById(R.id.btnCancel);

        Log.d(TAG, "OnClickListener was set");
        btnOk.setOnClickListener(this);
        btnCancel.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        Log.d(TAG, "Find button by id");
        switch (v.getId()) {
            case R.id.btnOk:
                Log.d(TAG, "Button OK");
                tvOut.setText("OK button was clicked!");
                Toast.makeText(getApplicationContext(), "OK", Toast.LENGTH_LONG).show();
                break;
            case R.id.btnCancel:
                Log.d(TAG, "Button Cancel");
                tvOut.setText("Cancel button was clicked!");
                Toast.makeText(getApplicationContext(), "Cancel", Toast.LENGTH_LONG).show();
                break;
        }
    }
}