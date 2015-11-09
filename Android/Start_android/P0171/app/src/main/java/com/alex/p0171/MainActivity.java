package com.alex.p0171;

import android.app.Activity;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.RadioGroup;
import android.widget.Toast;

public class MainActivity extends Activity implements View.OnClickListener {

    LinearLayout ll2;
    RadioGroup rgGravity;
    EditText et;
    Button btnCreate;
    Button btnClear;

    public final static int wrap = LinearLayout.LayoutParams.WRAP_CONTENT;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        ll2 = (LinearLayout) findViewById(R.id.ll2);
        rgGravity = (RadioGroup) findViewById(R.id.rgGravity);
        et = (EditText) findViewById(R.id.et);

        btnCreate = (Button) findViewById(R.id.btnCreate);
        btnClear = (Button) findViewById(R.id.btnClear);
        btnCreate.setOnClickListener(this);
        btnClear.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btnCreate:
                LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(wrap, wrap);
                int gr = Gravity.LEFT;

                switch (rgGravity.getCheckedRadioButtonId()) {
                    case R.id.rbLeft:
                        gr = Gravity.LEFT;
                        break;
                    case R.id.rbCenter:
                        gr = Gravity.CENTER;
                        break;
                    case R.id.rbRight:
                        gr = Gravity.RIGHT;
                        break;
                }

                lp.gravity = gr;
                Button newButton = new Button(getApplicationContext());
                newButton.setText(et.getText().toString());
                ll2.addView(newButton, lp);

                break;
            case R.id.btnClear:
                ll2.removeAllViews();
                Toast.makeText(getApplicationContext(), "All buttons were deleted!", Toast.LENGTH_SHORT).show();
                break;
        }
    }
}