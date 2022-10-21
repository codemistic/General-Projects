package me.siddheshkothadi.chat.data.repository

import android.util.Log
import com.google.android.gms.auth.api.signin.GoogleSignIn
import com.google.android.gms.auth.api.signin.GoogleSignInOptions
import com.google.firebase.auth.ktx.auth
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.ValueEventListener
import com.google.firebase.database.ktx.database
import com.google.firebase.database.ktx.getValue
import com.google.firebase.ktx.Firebase
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.flow
import kotlinx.coroutines.tasks.await
import me.siddheshkothadi.chat.ChatApplication
import me.siddheshkothadi.chat.domain.model.Message
import me.siddheshkothadi.chat.domain.model.User
import me.siddheshkothadi.chat.domain.repository.FirebaseRepository
import javax.inject.Inject

class FirebaseRepositoryImpl @Inject constructor(
    private val context: ChatApplication
) : FirebaseRepository {
    private val database = Firebase.database
    private val chatRef = database.getReference("chats")
    private val userRef = database.getReference("users")
    private val _chats = MutableStateFlow<List<Message>>(emptyList())

    override suspend fun addChat(key: String, chatList: List<Message>) {
        chatRef.child(key).setValue(chatList).await()
    }

    override suspend fun signOut(gso: GoogleSignInOptions) {
        val uid = auth.uid!!
        GoogleSignIn.getClient(context, gso).signOut().await()
        deleteChatsOfUser(uid)
        deleteUser(uid)
        auth.signOut()
    }

    private val messageListener = object : ValueEventListener {
        override fun onDataChange(dataSnapshot: DataSnapshot) {
            val messages = dataSnapshot.getValue<List<Message>>()
            _chats.value = messages ?: emptyList()
        }

        override fun onCancelled(databaseError: DatabaseError) {
            Log.w("onCancelled", "loadPost:onCancelled", databaseError.toException())
        }
    }

    private val _isUserListLoading: MutableStateFlow<Boolean> = MutableStateFlow(false)
    override val isUserListLoading: Flow<Boolean>
        get() = _isUserListLoading

    override val auth = Firebase.auth

    override val encryptedChats: Flow<List<Message>>
        get() = _chats

    override val users: Flow<List<User>> = flow {
        _isUserListLoading.value = true
        val userSnapshot = userRef.get().await()
        val listOfUsers = userSnapshot.children.map {
            it.getValue(User::class.java) ?: User()
        }
        emit(listOfUsers)
        _isUserListLoading.value = false
    }

    override suspend fun deleteUser(uid: String) {
        val dataSnapshot = userRef.get().await()
        val filteredUsers = dataSnapshot.children.map {
            it.getValue(User::class.java)
        }.filter {
            it?.uid != uid
        }

        userRef.setValue(filteredUsers).await()
    }

    override suspend fun deleteChatsOfUser(uid: String) {
        val dataSnapshot = chatRef.get().await()
        val hashMap: HashMap<String, List<Message>> = hashMapOf()

        for (item in dataSnapshot.children) {
            item.key?.let {
                if (!it.contains(uid)) {
                    hashMap[it] = item.value as List<Message>
                }
            }
        }

        chatRef.setValue(hashMap).await()
    }

    override suspend fun saveNewUser(user: User) {
        userRef.child(user.uid).setValue(user).await()
    }

    override fun addMessageEventListener(key: String) {
        chatRef.child(key).addValueEventListener(messageListener)
    }

    override fun removeMessageEventListener(key: String) {
        chatRef.child(key).removeEventListener(messageListener)
    }

    override fun clearChats() {
        _chats.value = emptyList()
    }

    override fun isSignedIn(): Boolean {
        return auth.currentUser != null
    }
}