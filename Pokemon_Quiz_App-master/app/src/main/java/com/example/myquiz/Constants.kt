package com.example.myquiz

object Constants {

    const val User_Name:String = "user_name"
    const val totalQuestions:String = "total_question"
    const val correctAnswer:String = "correct_answers"

    fun getQuestions(): ArrayList<Questions>{
        val questionsList = ArrayList<Questions>()

        val que1 = Questions(
            1, "Identify this Pokemon.",
            R.drawable.pikachu,
            "Pikachu",
            "Charizard",
            "Piplup",
            "Doraemon",
            1
        )
        questionsList.add(que1)

        val que2 = Questions(
            2, "Identify this Pokemon.",
            R.drawable.bulbasaur,
            "Ditto",
            "Bulbasaur",
            "Lucario",
            "Snorlax",
            2
        )
        questionsList.add(que2)

        val que3 = Questions(
            3, "Identify this Pokemon.",
            R.drawable.meowth,
            "Meowth",
            "Charizard",
            "Eevee",
            "Nobita",
            1
        )
        questionsList.add(que3)

        val que4 = Questions(
            4, "Identify this Pokemon.",
            R.drawable.butterfree,
            "Piplup",
            "Butterfree",
            "Garchomp",
            "Pikachu",
            2
        )
        questionsList.add(que4)

        val que5 = Questions(
            5, "Identify this Pokemon.",
            R.drawable.draagonite,
            "Dragonite",
            "Charmander",
            "Dialga",
            "Gardevoir",
            1
        )
        questionsList.add(que5)

        val que6 = Questions(
            6, "Identify this Pokemon.",
            R.drawable.chansey,
            "Piplup",
            "Chomuske",
            "Hancock",
            "Chansey",
            4
        )
        questionsList.add(que6)

        val que7 = Questions(
            7, "Identify this Pokemon.",
            R.drawable.jigglypuff,
            "Piplup",
            "Jigglypuff",
            "Junkasaurus",
            "None of the above",
            2
        )
        questionsList.add(que7)

        val que8 = Questions(
            8, "Identify this Pokemon.",
            R.drawable.charizard,
            "Charmander",
            "Charizard",
            "Dragonite",
            "Pikasuke",
            2
        )
        questionsList.add(que8)

        val que9 = Questions(
            9, "Identify this Pokemon.",
            R.drawable.mudkip,
            "Squirtle",
            "Togepi",
            "Psyduck",
            "Mudkip",
            4
        )
        questionsList.add(que9)

        val que10 = Questions(
            10, "Identify this Pokemon.",
            R.drawable.piplup,
            "Piplup",
            "Mew",
            "Squirtle",
            "None of the above",
            1
        )
        questionsList.add(que10)

        return questionsList
    }
}