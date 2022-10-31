package com.example.diceroller

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.diceroller.databinding.ActivityMainBinding


class MainActivity : AppCompatActivity() {
    private lateinit var mainBinding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        mainBinding = ActivityMainBinding.inflate(layoutInflater)
        val view = mainBinding.root
        setContentView(view)

        mainBinding.buttonScroll.setOnClickListener {
            rollDice()
        }

    }

    /**
    * This function is responsible for generation random integer between 1-6 and based on it updates the image of the dice
    * to show the output number
    */

    private fun rollDice() {
        (java.util.Random().nextInt(6) + 1)
            .also {
                mainBinding.diceImageview.setImageResource(
                    when (it) {
                        1 -> R.drawable.dice_1
                        2 -> R.drawable.dice_2
                        3 -> R.drawable.dice_3
                        4 -> R.drawable.dice_4
                        5 -> R.drawable.dice_5
                        6 -> R.drawable.dice_6
                        else -> R.drawable.empty_dice
                    }
                ) }
    }
}