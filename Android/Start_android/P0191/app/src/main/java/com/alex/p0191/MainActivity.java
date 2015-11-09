package com.alex.p0191;

import android.app.Activity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity implements View.OnClickListener {

    public final static int MENU_RESET_ID = 1;
    public final static int MENU_QUIT_ID = 2;

    public final static double EPS = 1e-9;

    EditText etNum1;
    EditText etNum2;
    Button btnAdd;
    Button btnSub;
    Button btnMult;
    Button btnDiv;
    TextView tvResult;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        etNum1 = (EditText) findViewById(R.id.etNum1);
        etNum2 = (EditText) findViewById(R.id.etNum2);

        btnAdd = (Button) findViewById(R.id.btnAdd);
        btnSub = (Button) findViewById(R.id.btnSub);
        btnMult = (Button) findViewById(R.id.btnMult);
        btnDiv = (Button) findViewById(R.id.btnDiv);

        tvResult = (TextView) findViewById(R.id.tvResult);

        btnAdd.setOnClickListener(this);
        btnSub.setOnClickListener(this);
        btnMult.setOnClickListener(this);
        btnDiv.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        double num1 = 0.0;
        double num2 = 0.0;
        double ans = 0.0;
        String expression = "";
        String oper = "";

        if (TextUtils.isEmpty(etNum1.getText().toString()) || TextUtils.isEmpty(etNum2.getText().toString())) {
            return;
        }

        num1 = Double.parseDouble(etNum1.getText().toString());
        num2 = Double.parseDouble(etNum2.getText().toString());
        boolean bad = false;

        switch (v.getId()) {
            case R.id.btnAdd:
                ans = num1 + num2;
                oper = "+";
                break;
            case R.id.btnSub:
                ans = num1 - num2;
                oper = "-";
                break;
            case R.id.btnMult:
                ans = num1 * num2;
                oper = "*";
                break;
            case R.id.btnDiv:
                if (Math.abs(num2) < EPS) {
                    Toast.makeText(getApplicationContext(), "Division by zero", Toast.LENGTH_SHORT).show();
                    bad = true;
                    break;
                }

                ans = num1 / num2;
                oper = "/";
                break;
            default:
                break;
        }

        if (bad) {
            tvResult.setText("");
            return;
        }

        expression += etNum1.getText().toString();
        expression += " " + oper + " ";
        expression += etNum2.getText().toString();
        expression += " = ";
        expression += String.valueOf(ans);

        tvResult.setText(expression);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        menu.add(0, MENU_RESET_ID, 0, "Reset");
        menu.add(0, MENU_QUIT_ID, 0, "Quit");

        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case MENU_RESET_ID:
                etNum1.setText("");
                etNum2.setText("");
                tvResult.setText("");
                break;
            case MENU_QUIT_ID:
                finish();
                break;
        }

        return super.onOptionsItemSelected(item);
    }
}