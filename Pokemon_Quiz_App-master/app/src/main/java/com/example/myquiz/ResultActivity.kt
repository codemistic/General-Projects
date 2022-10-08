package com.example.myquiz

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_result.*

class ResultActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_result)

        tvUsername.text = intent.getStringExtra(Constants.User_Name)

        val totalQuestions = intent.getIntExtra(Constants.totalQuestions,0)
        val correctQues = intent.getIntExtra(Constants.correctAnswer,0)

        tvScore.text = "Your score is $correctQues out of $totalQuestions."

        btnFinish.setOnClickListener{
            startActivity(Intent(this, MainActivity::class.java))
        }
    }
}