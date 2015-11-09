package com.alex.p0151;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends Activity {

    TextView tvColor;
    TextView tvSize;

    public final static int MENU_COLOR_RED = 1;
    public final static int MENU_COLOR_GREEN = 2;
    public final static int MENU_COLOR_BLUE = 3;
    public final static int MENU_SIZE_22 = 4;
    public final static int MENU_SIZE_26 = 5;
    public final static int MENU_SIZE_30 = 6;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        tvColor = (TextView) findViewById(R.id.tvColor);
        tvSize = (TextView) findViewById(R.id.tvSize);
        registerForContextMenu(tvColor);
        registerForContextMenu(tvSize);
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        switch (v.getId()) {
            case R.id.tvColor:
                menu.add(0, MENU_COLOR_RED, 0, "Red");
                menu.add(0, MENU_COLOR_GREEN, 0, "Green");
                menu.add(0, MENU_COLOR_BLUE, 0, "Blue");
                break;
            case R.id.tvSize:
                menu.add(0, MENU_SIZE_22, 0, "22");
                menu.add(0, MENU_SIZE_26, 0, "26");
                menu.add(0, MENU_SIZE_30, 0, "30");
                break;
        }

        super.onCreateContextMenu(menu, v, menuInfo);
    }

    @Override
    public boolean onContextItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case MENU_COLOR_RED:
                tvColor.setTextColor(Color.RED);
                tvColor.setText("Text color is red");
                break;
            case MENU_COLOR_GREEN:
                tvColor.setTextColor(Color.GREEN);
                tvColor.setText("Text color is green");
                break;
            case MENU_COLOR_BLUE:
                tvColor.setTextColor(Color.BLUE);
                tvColor.setText("Text color is blue");
                break;
            case MENU_SIZE_22:
                tvSize.setTextSize(22);
                tvSize.setText("Text size is 22");
                break;
            case MENU_SIZE_26:
                tvSize.setTextSize(26);
                tvSize.setText("Text size is 26");
                break;
            case MENU_SIZE_30:
                tvSize.setTextSize(30);
                tvSize.setText("Text size is 30");
                break;
        }

        return super.onContextItemSelected(item);
    }
}