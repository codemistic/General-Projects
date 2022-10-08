package com.example.braintimer;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class MainActivity extends AppCompatActivity {
Button button0,button1,button2,button3,playAgain,go;
TextView timer,score,question,welcome,msg;
ArrayList<Integer>list=new ArrayList<>(Arrays.asList(0,0,0,0));
int randomAns,correct=0,totalQues=0;
boolean flag=true;
public void chooseAns(View view){
    if(flag==false)
        return;
    if(view.getTag().toString().equals(Integer.toString(randomAns))){
        correct++;
       msg.setText("Correct:)");
    }
    else {
        msg.setText("InCorrect:(");
    }
    totalQues++;
    score.setText(Integer.toString(correct)+"/"+Integer.toString(totalQues));
    play();
}
public void play(){

    Random random=new Random();
    int a=random.nextInt(31);
    int b=random.nextInt(31);
    question.setText(Integer.toString(a)+"+"+Integer.toString(b));
    int correctAns=a+b;
    randomAns=random.nextInt(4);
    list=new ArrayList<Integer>(Arrays.asList(0,0,0,0));
    for (int i = 0; i < 4; i++) {
        if(randomAns==i){
            list.set(randomAns,correctAns);
        }
        else {
            int incorrectAns=random.nextInt(61);
            while (incorrectAns==correctAns){
                incorrectAns=random.nextInt(61);
            }
            list.set(i,incorrectAns);
        }
    }
    button0.setText(Integer.toString(list.get(0)));
    button1.setText(Integer.toString(list.get(1)));
    button2.setText(Integer.toString(list.get(2)));
    button3.setText(Integer.toString(list.get(3)));
}
public void start(View view){
    go.setVisibility(View.INVISIBLE);
    welcome.setVisibility(View.INVISIBLE);
    button0.setVisibility(View.VISIBLE);
    button1.setVisibility(View.VISIBLE);
    button2.setVisibility(View.VISIBLE);
    button3.setVisibility(View.VISIBLE);
    timer.setVisibility(View.VISIBLE);
    question.setVisibility(View.VISIBLE);
    score.setVisibility(View.VISIBLE);
    msg.setVisibility(View.VISIBLE);
    play();
    new CountDownTimer(30100,1000) {

        @Override
        public void onTick(long millisUntilFinished) {
            timer.setText(Long.toString(millisUntilFinished / 1000) + "s");
        }

        @Override
        public void onFinish() {
            flag=false;
            playAgain.setVisibility(View.VISIBLE);
            msg.setVisibility(View.INVISIBLE);
        }
    }.start();

}
public void playAgain(View view){
    msg.setText("");
    flag=true;
    score.setText(Integer.toString(0)+"/"+Integer.toString(0));
    totalQues=0;
    correct=0;
    play();
    new CountDownTimer(30100,1000) {

        @Override
        public void onTick(long millisUntilFinished) {
            timer.setText(Long.toString(millisUntilFinished / 1000) + "s");
        }

        @Override
        public void onFinish() {
            flag=false;
            playAgain.setVisibility(View.VISIBLE);
            msg.setVisibility(View.INVISIBLE);
        }
    }.start();
    playAgain.setVisibility(View.INVISIBLE);
}
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        button0=findViewById(R.id.button0);
        button1=findViewById(R.id.button1);
        button2=findViewById(R.id.button2);
        button3=findViewById(R.id.button3);
        playAgain=findViewById(R.id.playAgainButton);
        go=findViewById(R.id.goButton);
        welcome=findViewById(R.id.welcomeTextView);
        question=findViewById(R.id.questionTextView);
        score=findViewById(R.id.scoreTextView);
        timer=findViewById(R.id.timerTextView);
        msg=findViewById(R.id.msgTextView);
    }
}