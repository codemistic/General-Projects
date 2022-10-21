package me.siddheshkothadi.chat.domain.model

import kotlinx.serialization.Serializable

@Serializable
data class User(
    val uid: String = "",
    val displayName: String = "",
    val email: String = "",
    val photoUrl: String = "",
    val publicKey: String = ""
)
