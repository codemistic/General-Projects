package com.example.myquiz

import android.content.Intent
import android.graphics.Color
import android.graphics.Typeface
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.TextView
import androidx.core.content.ContextCompat
import kotlinx.android.synthetic.main.activity_quiz_questions.*

class QuizQuestionsActivity : AppCompatActivity(), View.OnClickListener {
    private var mCurrentPosition: Int = 1
    private var mQuestionList: ArrayList<Questions>? = null
    private var mSelectedOptionPosition:Int = 0;
    private var mCorrectAnswer: Int = 0
    private var mUsername: String? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_quiz_questions)

        mUsername = intent.getStringExtra(Constants.User_Name)

        tvOption1?.setOnClickListener(this)
        tvOption2?.setOnClickListener(this)
        tvOption3?.setOnClickListener(this)
        tvOption4?.setOnClickListener(this)
        btnSubmit?.setOnClickListener(this)

        mQuestionList = Constants.getQuestions()

        setQuestion()
        defaultOptionsView()

    }

    private fun setQuestion() {

        val question: Questions = mQuestionList!![mCurrentPosition - 1]
        progressBar?.progress =mCurrentPosition
        tvProgressNum?.text = "$mCurrentPosition/${progressBar?.max}"
        tv_question.text = question.question
        imgView?.setImageResource(question.image)
        tvOption1?.text = question.optionOne
        tvOption2?.text = question.optionTwo
        tvOption3?.text = question.optionThree
        tvOption4?.text = question.optionFour

        defaultOptionsView()
        if (mCurrentPosition == mQuestionList!!.size) {
            btnSubmit?.text = "FINISH"
        } else {
            btnSubmit?.text = "SUBMIT"
        }

    }

    private fun defaultOptionsView(){
        val options = ArrayList<TextView>()
        tvOption1?.let{
            options.add(0,it)
        }
        tvOption2?.let{
            options.add(1,it)
        }
        tvOption3?.let{
            options.add(2,it)
        }
        tvOption4?.let{
            options.add(3,it)
        }

        for (option in options ){
            option.setTextColor(Color.parseColor("#7A8089"))
            option.typeface = Typeface.DEFAULT
            option.background = ContextCompat.getDrawable(
                this,
                R.drawable.tv_option_bg
            )
        }
    }

    private fun selectedOptionView(tv: TextView, selectedOptionNum : Int){
        defaultOptionsView()

        mSelectedOptionPosition = selectedOptionNum

        tv.setTextColor((Color.parseColor("#363A43")))
        tv.setTypeface(tv.typeface,Typeface.BOLD)
        tv.background = ContextCompat.getDrawable(
            this,
            R.drawable.selected_option_border_bg
        )
    }


    override fun onClick(view: View?) {
        when ( view?.id){
            R.id.tvOption1 -> {
                tvOption1?.let{
                    selectedOptionView(it,1)
                }
            }
            R.id.tvOption2 -> {
                tvOption2?.let{
                    selectedOptionView(it,2)
                }
            }
            R.id.tvOption3 -> {
                tvOption3?.let{
                    selectedOptionView(it,3)
                }
            }
            R.id.tvOption4 -> {
                tvOption4?.let{
                    selectedOptionView(it,4)
                }
            }

            R.id.btnSubmit ->{

                if( mSelectedOptionPosition == 0){

                    mCurrentPosition++

                    when{
                        mCurrentPosition <= mQuestionList!!.size -> {
                            setQuestion()
                        }
                        else -> {
                          val intent = Intent( this, ResultActivity :: class.java)
                          intent.putExtra(Constants.User_Name,mUsername)
                          intent.putExtra(Constants.totalQuestions,mQuestionList!!.size)
                          intent.putExtra(Constants.correctAnswer,mCorrectAnswer)
                          startActivity(intent)
                          finish()
                        }
                    }
                } else {
                    val questions = mQuestionList?.get(mCurrentPosition-1)

                    if(questions!!.correctAnswer != mSelectedOptionPosition) {
                        answerView(mSelectedOptionPosition, R.drawable.wrong_option_bg)
                    }else{
                        mCorrectAnswer++
                    }
                    answerView(questions.correctAnswer, R.drawable.correct_option_bg)

                    if ( mCurrentPosition == mQuestionList!!.size){
                        btnSubmit.text = "FINISH"
                    } else{
                        btnSubmit.text = "Go to next question"
                    }

                    mSelectedOptionPosition = 0
                }

            }
        }
    }

    private fun answerView(answer:Int, drawableView :Int){
        when(answer){
            1 -> {
                tvOption1?.background = ContextCompat.getDrawable(
                    this,
                    drawableView
                )
            }
            2 -> {
                tvOption2?.background = ContextCompat.getDrawable(
                    this,
                    drawableView
                )
            }
            3 -> {
                tvOption3?.background = ContextCompat.getDrawable(
                    this,
                    drawableView
                )
            }
            4 -> {
                tvOption4?.background = ContextCompat.getDrawable(
                    this,
                    drawableView
                )
            }
        }
    }

}