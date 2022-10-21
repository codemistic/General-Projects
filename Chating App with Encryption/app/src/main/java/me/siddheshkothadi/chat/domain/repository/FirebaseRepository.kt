package me.siddheshkothadi.chat.domain.repository

import com.google.android.gms.auth.api.signin.GoogleSignInOptions
import com.google.firebase.auth.FirebaseAuth
import kotlinx.coroutines.flow.Flow
import me.siddheshkothadi.chat.domain.model.Message
import me.siddheshkothadi.chat.domain.model.User

interface FirebaseRepository {
    val auth: FirebaseAuth
    val users: Flow<List<User>>
    val encryptedChats: Flow<List<Message>>
    val isUserListLoading: Flow<Boolean>
    suspend fun deleteUser(uid: String)
    suspend fun deleteChatsOfUser(uid: String)
    suspend fun saveNewUser(user: User)
    suspend fun addChat(key: String, chatList: List<Message>)
    suspend fun signOut(gso: GoogleSignInOptions)
    fun isSignedIn(): Boolean
    fun addMessageEventListener(key: String)
    fun removeMessageEventListener(key: String)
    fun clearChats()
}