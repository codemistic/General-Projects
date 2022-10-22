package me.siddheshkothadi.chat.ui.viewmodel

import android.util.Log
import android.widget.Toast
import androidx.compose.runtime.mutableStateOf
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.google.android.gms.auth.api.signin.GoogleSignInOptions
import com.google.firebase.auth.AuthCredential
import com.google.firebase.auth.ktx.auth
import com.google.firebase.ktx.Firebase
import dagger.hilt.android.lifecycle.HiltViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.first
import kotlinx.coroutines.launch
import me.siddheshkothadi.chat.ChatApplication
import me.siddheshkothadi.chat.domain.model.User
import me.siddheshkothadi.chat.domain.model.UserData
import me.siddheshkothadi.chat.domain.repository.UserRepository
import javax.inject.Inject

@HiltViewModel
class MainViewModel @Inject constructor(
    private val context: ChatApplication,
    private val userRepository: UserRepository
) : ViewModel() {
    private val clientIDWeb =
        "91794365719-fn0c30j3sqfstf3bf50ilkbmtfs3crl0.apps.googleusercontent.com"
    private val userData = userRepository.userData
    private val firebaseAuth = userRepository.firebaseAuth
    val gso = GoogleSignInOptions.Builder(GoogleSignInOptions.DEFAULT_SIGN_IN)
        .requestIdToken(clientIDWeb)
        .requestEmail()
        .build()

    val textState = mutableStateOf("")
    val users = userRepository.users
    val chats = userRepository.chats
    val isUserListLoading = userRepository.isUserListLoading

    val isSignedIn = MutableStateFlow(userRepository.firebaseAuth.currentUser != null)
    val isSigningIn = MutableStateFlow(false)
    val areMessagesLoading = MutableStateFlow(false)
    val isLoggingOut = MutableStateFlow(false)

    init {
        Firebase.auth.addAuthStateListener {
            viewModelScope.launch {
                isSigningIn.value = true
                val currentUserData = userData.first()
                val currentUser = it.currentUser
                if (currentUser == null) {
                    // Not logged in
                    if(currentUserData.privateKey.isNotEmpty()) {
                        userRepository.updateUserData(UserData())
                    }
                } else if(currentUserData.privateKey.isEmpty()) {
                    // New login
                    userRepository.deleteAllData(currentUser.uid)
                    userRepository.saveNewUser(currentUser)
                    Toast.makeText(context, "Login Successful", Toast.LENGTH_LONG).show()
                }
                // Else already logged in so do nothing

                isSigningIn.value = false
                isSignedIn.value = firebaseAuth.currentUser != null
            }
        }
    }

    fun addTextToChat(text: String, from: String, to: User, key: String) = viewModelScope.launch {
        if (text.isNotBlank()) {
            userRepository.addChat(text, from, to, key)
            textState.value = ""
        }
    }

    fun setTextState(it: String) {
        textState.value = it
    }

    fun signWithCredential(credential: AuthCredential) = viewModelScope.launch {
        try {
            isSigningIn.value = true
            userRepository.signWithCredential(credential)
            isSignedIn.value = false
        } catch (e: Exception) {
            Log.e("Auth Error", e.toString())
            isSigningIn.value = false
        }
    }

    fun signOut() = viewModelScope.launch {
        isLoggingOut.value = true
        userRepository.signOut(gso)
        isLoggingOut.value = false
    }

    fun clearChats() {
        userRepository.clearChats()
    }

    fun getCurrentUserUid(): String {
        return firebaseAuth.currentUser?.uid ?: ""
    }

    fun getCurrentUser(): User {
        return User(
            displayName = firebaseAuth.currentUser?.displayName.toString(),
            photoUrl = firebaseAuth.currentUser?.photoUrl.toString(),
            email = firebaseAuth.currentUser?.email.toString()
        )
    }

    fun addMessageEventListener(key: String) {
        userRepository.addMessageEventListener(key)
    }

    fun removeMessageEventListener(key: String) {
        userRepository.removeMessageEventListener(key)
    }
}