package me.siddheshkothadi.chat.domain.repository

import kotlinx.coroutines.flow.Flow
import me.siddheshkothadi.chat.domain.model.UserData

interface DataStoreRepository {
    val userData: Flow<UserData>

    suspend fun updateUserData(
        userData: UserData
    )
}