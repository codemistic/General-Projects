package me.siddheshkothadi.chat.domain.repository

import com.google.android.gms.auth.api.signin.GoogleSignInOptions
import com.google.firebase.auth.AuthCredential
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.FirebaseUser
import kotlinx.coroutines.flow.Flow
import me.siddheshkothadi.chat.domain.model.Message
import me.siddheshkothadi.chat.domain.model.User
import me.siddheshkothadi.chat.domain.model.UserData

interface UserRepository {
    val firebaseAuth: FirebaseAuth
    val userData: Flow<UserData>
    val chats: Flow<List<Message>>
    val users: Flow<List<User>>
    val isUserListLoading: Flow<Boolean>
    fun clearChats()
    fun addMessageEventListener(key: String)
    fun removeMessageEventListener(key: String)
    suspend fun deleteAllData(uid: String)
    suspend fun saveNewUser(firebaseUser: FirebaseUser)
    suspend fun getCurrentUser(): User
    suspend fun updateUserData(userData: UserData)
    suspend fun addChat(text: String, from: String, to: User, key: String)
    suspend fun signWithCredential(credential: AuthCredential)
    suspend fun signOut(gso: GoogleSignInOptions)
}