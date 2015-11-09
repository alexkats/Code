package com.alex.first;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

/**
 * Created by Alex on 23.01.15.
 */
public class MainActivity extends Activity {

    private TextView textView;
    private Button button;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_layout);
        textView = (TextView) findViewById(R.id.textView);
        button = (Button) findViewById(R.id.button2);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textView.setText("Hello World!!!");
            }
        });
    }

    public void sayHelloWorld(View view) {
        textView.setText("Hello World!");
    }

}
