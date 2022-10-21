package me.siddheshkothadi.chat.data.repository

import android.content.Context
import android.util.Log
import androidx.datastore.dataStore
import kotlinx.coroutines.flow.Flow
import me.siddheshkothadi.chat.ChatApplication
import me.siddheshkothadi.chat.data.UserDataSerializer
import me.siddheshkothadi.chat.domain.model.UserData
import me.siddheshkothadi.chat.domain.repository.DataStoreRepository
import javax.inject.Inject


class DataStoreRepositoryImpl @Inject constructor(
    context: ChatApplication
) : DataStoreRepository {
    private val Context.dataStore by dataStore("user-data.json", UserDataSerializer)
    private val userDataStore = context.dataStore

    override val userData: Flow<UserData>
        get() = userDataStore.data

    override suspend fun updateUserData(
        userData: UserData
    ) {
        userDataStore.updateData {
            userData
        }
    }
}