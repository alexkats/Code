package com.alex.calculator;

import android.app.Activity;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.view.ContextMenu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity implements View.OnClickListener {

    Button btnClear;
    Button btnOpenBracket;
    Button btnCloseBracket;
    Button btnDiv;
    Button btnSeven;
    Button btnEight;
    Button btnNine;
    Button btnMul;
    Button btnFour;
    Button btnFive;
    Button btnSix;
    Button btnSub;
    Button btnOne;
    Button btnTwo;
    Button btnThree;
    Button btnAdd;
    Button btnZero;
    Button btnPoint;
    Button btnEquals;
    TextView output;
    boolean evaluated = false;
    boolean disabled_clear = true;

    String expression = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        findAllButtonsAndListen();
        output = (TextView) findViewById(R.id.output);
        registerForContextMenu(output);
    }

    public void findAllButtonsAndListen() {
        btnClear = (Button) findViewById(R.id.btnClear);
        btnOpenBracket = (Button) findViewById(R.id.btnOpenBracket);
        btnCloseBracket = (Button) findViewById(R.id.btnCloseBracket);
        btnDiv = (Button) findViewById(R.id.btnDiv);
        btnSeven = (Button) findViewById(R.id.btnSeven);
        btnEight = (Button) findViewById(R.id.btnEight);
        btnNine = (Button) findViewById(R.id.btnNine);
        btnMul = (Button) findViewById(R.id.btnMul);
        btnFour = (Button) findViewById(R.id.btnFour);
        btnFive = (Button) findViewById(R.id.btnFive);
        btnSix = (Button) findViewById(R.id.btnSix);
        btnSub = (Button) findViewById(R.id.btnSub);
        btnOne = (Button) findViewById(R.id.btnOne);
        btnTwo = (Button) findViewById(R.id.btnTwo);
        btnThree = (Button) findViewById(R.id.btnThree);
        btnAdd = (Button) findViewById(R.id.btnAdd);
        btnZero = (Button) findViewById(R.id.btnZero);
        btnPoint = (Button) findViewById(R.id.btnPoint);
        btnEquals = (Button) findViewById(R.id.btnEquals);

        btnClear.setOnClickListener(this);
        btnOpenBracket.setOnClickListener(this);
        btnCloseBracket.setOnClickListener(this);
        btnDiv.setOnClickListener(this);
        btnSeven.setOnClickListener(this);
        btnEight.setOnClickListener(this);
        btnNine.setOnClickListener(this);
        btnMul.setOnClickListener(this);
        btnFour.setOnClickListener(this);
        btnFive.setOnClickListener(this);
        btnSix.setOnClickListener(this);
        btnSub.setOnClickListener(this);
        btnOne.setOnClickListener(this);
        btnTwo.setOnClickListener(this);
        btnThree.setOnClickListener(this);
        btnAdd.setOnClickListener(this);
        btnZero.setOnClickListener(this);
        btnPoint.setOnClickListener(this);
        btnEquals.setOnClickListener(this);
        btnClear.setEnabled(false);
    }

    @Override
    public void onClick(View v) {
        int n = expression.length();

        if (v.getId() == R.id.btnClear) {
            if (evaluated) {
                expression = "";
                output.setText("");
                evaluated = false;
                disabled_clear = true;
                btnClear.setEnabled(false);
                btnClear.setText(R.string.clear);
                return;
            }

            expression = expression.substring(0, n - 1);
            output.setText(expression);

            if (expression.equals("")) {
                disabled_clear = true;
                btnClear.setEnabled(false);
            }

            return;
        }

        if (v.getId() == R.id.btnEquals) {
            double ans = new Evaluation().result(expression);
            String s = String.format("%.9f", ans);
            s = s.replace(',', '.');
            int k = s.length();

            for (int i = k - 1; i > -1; i--) {
                if (s.charAt(i) == '0') {
                    k--;
                    continue;
                }

                break;
            }

            if (s.charAt(k - 1) == '.') {
                k--;
            }

            s = s.substring(0, k);
            output.setText(s);
            expression = s;

            btnClear.setText(R.string.all_clear);

            if (disabled_clear) {
                disabled_clear = false;
                btnClear.setEnabled(true);
            }

            evaluated = true;
            return;
        }

        if (expression.equals("")) {
            disabled_clear = false;
            btnClear.setEnabled(true);
        }

        if (evaluated) {
            evaluated = false;
            btnClear.setText(R.string.clear);
        }

        if (v.getId() == R.id.btnSub) {
            expression += "-";
        } else {
            expression += ((Button) v).getText().toString().charAt(0);
        }

        output.setText(expression);
    }

    @Override
    protected void onSaveInstanceState(@NonNull Bundle outState) {
        outState.putString("Output", output.getText().toString());
        outState.putString("Expression", expression);
        outState.putBoolean("Evaluated", evaluated);
        outState.putBoolean("Disabled clear", disabled_clear);
        super.onSaveInstanceState(outState);
    }

    @Override
    protected void onRestoreInstanceState(@NonNull Bundle savedInstanceState) {
        output.setText(savedInstanceState.getString("Output"));
        expression = savedInstanceState.getString("Expression");
        evaluated = savedInstanceState.getBoolean("Evaluated");
        disabled_clear = savedInstanceState.getBoolean("Disabled clear");

        if (!disabled_clear) {
            btnClear.setEnabled(true);
        }

        if (evaluated) {
            btnClear.setText(R.string.all_clear);
        }

        super.onRestoreInstanceState(savedInstanceState);
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        if (v.getId() == R.id.output) {
            menu.add(0, 0, 0, R.string.clear_all);
        }

        if (expression.equals("")) {
            menu.setGroupVisible(0, false);
        } else {
            menu.setGroupVisible(0, true);
        }

        super.onCreateContextMenu(menu, v, menuInfo);
    }

    @Override
    public boolean onContextItemSelected(MenuItem item) {
        if (item.getItemId() == 0) {
            output.setText("");
            expression = "";
            disabled_clear = true;
            btnClear.setEnabled(false);
            btnClear.setText(R.string.clear);
            evaluated = false;
        }

        return super.onContextItemSelected(item);
    }
}