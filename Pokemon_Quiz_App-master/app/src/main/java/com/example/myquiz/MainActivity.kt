package com.example.myquiz

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.view.WindowManager
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.android.synthetic.main.custom_toast.*

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)


        btn_start.setOnClickListener {
            if(et_name.text.toString().isEmpty()){
                Toast(this).apply{
                    duration = Toast.LENGTH_LONG
                    view  =layoutInflater.inflate(R.layout.custom_toast,cstoast)
                    show()
                }
            }else{
                val intent = Intent(this, QuizQuestionsActivity::class.java)
                    intent.putExtra(Constants.User_Name,et_name.text.toString()) // here a constant value is used because it's better practice
                    startActivity(intent)
                    finish()

            }
        }


    }
}