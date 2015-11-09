package com.alex.p0331;

import android.app.Activity;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity implements View.OnClickListener {

    EditText etText;
    Button btnSave;
    Button btnLoad;

    public final static String SAVED_TEXT = "saved";

    SharedPreferences sp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        etText = (EditText) findViewById(R.id.etText);
        btnSave = (Button) findViewById(R.id.btnSave);
        btnLoad = (Button) findViewById(R.id.btnLoad);
        btnSave.setOnClickListener(this);
        btnLoad.setOnClickListener(this);

        loadText();
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btnSave:
                saveText();
                break;
            case R.id.btnLoad:
                loadText();
                break;
            default:
                break;
        }
    }

    void saveText() {
        sp = getPreferences(MODE_PRIVATE);
        SharedPreferences.Editor editor = sp.edit();
        editor.putString(SAVED_TEXT, etText.getText().toString());
        editor.commit();
        Toast.makeText(this, "Text saved", Toast.LENGTH_SHORT).show();
    }

    void loadText() {
        sp = getPreferences(MODE_PRIVATE);
        String saved = sp.getString(SAVED_TEXT, "");
        etText.setText(saved);
        Toast.makeText(this, "Text loaded", Toast.LENGTH_SHORT).show();
    }

    @Override
    protected void onDestroy() {
        saveText();
        super.onDestroy();
    }
}