package me.siddheshkothadi.chat.domain.model

data class Message(
    val from: String = "",
    val to: String = "",
    val timestamp: String = "",
    val timeIST: String = "",
    val content: String = "",
    val secretKey: String = ""
)
