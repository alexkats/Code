package com.alex.p0281;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity implements View.OnClickListener {

    EditText etFirst;
    EditText etLast;
    Button btnSubmit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        etFirst = (EditText) findViewById(R.id.etFirst);
        etLast = (EditText) findViewById(R.id.etLast);
        btnSubmit = (Button) findViewById(R.id.btnSubmit);
        btnSubmit.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        Intent intent = new Intent(this, ViewActivity.class);
        intent.putExtra("First name", etFirst.getText().toString());
        intent.putExtra("Last name", etLast.getText().toString());
        startActivity(intent);
    }
}