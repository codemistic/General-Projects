package me.siddheshkothadi.chat.domain.model

import kotlinx.serialization.Serializable
import me.siddheshkothadi.chat.domain.model.User

@Serializable
data class UserData(
    val user: User = User(),
    val privateKey: String = "",
    val secretKey: String = ""
)
