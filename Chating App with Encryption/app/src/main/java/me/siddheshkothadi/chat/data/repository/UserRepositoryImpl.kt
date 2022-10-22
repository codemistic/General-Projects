package me.siddheshkothadi.chat.data.repository

import android.widget.Toast
import com.google.android.gms.auth.api.signin.GoogleSignInOptions
import com.google.firebase.auth.AuthCredential
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.FirebaseUser
import kotlinx.coroutines.flow.*
import kotlinx.coroutines.tasks.await
import me.siddheshkothadi.chat.ChatApplication
import me.siddheshkothadi.chat.domain.model.Message
import me.siddheshkothadi.chat.domain.model.User
import me.siddheshkothadi.chat.domain.model.UserData
import me.siddheshkothadi.chat.domain.repository.DataStoreRepository
import me.siddheshkothadi.chat.domain.repository.FirebaseRepository
import me.siddheshkothadi.chat.domain.repository.UserRepository
import me.siddheshkothadi.chat.utils.AESUtils
import me.siddheshkothadi.chat.utils.RSAUtils
import java.text.SimpleDateFormat
import java.util.*

class UserRepositoryImpl(
    private val context: ChatApplication,
    private val firebaseRepository: FirebaseRepository,
    private val dataStoreRepository: DataStoreRepository,
) : UserRepository {
    private suspend fun getCurrentUserData(): UserData {
        return userData.first()
    }

    private fun createNewUser(firebaseUser: FirebaseUser): UserData {
        val (publicKeyRSA, privateKeyRSA) = RSAUtils.getKeyPair()
        val secretKeyAES = AESUtils.getSecretKey()

        val newUser = User(
            uid = firebaseUser.uid,
            displayName = firebaseUser.displayName.toString(),
            email = firebaseUser.email.toString(),
            photoUrl = firebaseUser.photoUrl.toString(),
            publicKey = publicKeyRSA
        )

        return UserData(
            user = newUser,
            privateKey = privateKeyRSA,
            secretKey = secretKeyAES
        )
    }

    override val isUserListLoading: Flow<Boolean>
        get() = firebaseRepository.isUserListLoading

    override val userData: Flow<UserData>
        get() = dataStoreRepository.userData

    override suspend fun deleteAllData(uid: String) {
        firebaseRepository.deleteChatsOfUser(uid)
        firebaseRepository.deleteUser(uid)
    }

    override suspend fun signOut(gso: GoogleSignInOptions) {
        dataStoreRepository.updateUserData(UserData())
        firebaseRepository.signOut(gso)
        Toast.makeText(context, "Logged Out", Toast.LENGTH_LONG).show()
    }

    override fun addMessageEventListener(key: String) {
        firebaseRepository.addMessageEventListener(key)
    }

    override fun removeMessageEventListener(key: String) {
        firebaseRepository.removeMessageEventListener(key)
    }

    override suspend fun updateUserData(userData: UserData) {
        return dataStoreRepository.updateUserData(userData)
    }

    override fun clearChats() {
        firebaseRepository.clearChats()
    }

    override suspend fun addChat(text: String, from: String, to: User, key: String) {
        val chatList = firebaseRepository.encryptedChats.first().toMutableList()
        val currentUserData = getCurrentUserData()
        val encryptedText = AESUtils.encrypt(text, currentUserData.secretKey)
        val encryptedSecretKey = RSAUtils.encrypt(currentUserData.secretKey, to.publicKey)

        val tmstmp = System.currentTimeMillis().toString()

        chatList.add(
            Message(
                from = from,
                to = to.uid,
                timestamp = tmstmp,
                content = encryptedText,
                timeIST = SimpleDateFormat("MMM dd hh:mm:ss z yyyy", Locale.ENGLISH).format(Date(tmstmp)),
                secretKey = encryptedSecretKey
            )
        )

        firebaseRepository.addChat(key, chatList)
    }

    override suspend fun saveNewUser(firebaseUser: FirebaseUser) {
        val newUserData = createNewUser(firebaseUser)
        firebaseRepository.saveNewUser(newUserData.user)
        dataStoreRepository.updateUserData(newUserData)
    }

    override suspend fun signWithCredential(credential: AuthCredential) {
        firebaseRepository.auth.signInWithCredential(credential).await()
    }

    override suspend fun getCurrentUser(): User {
        return getCurrentUserData().user
    }

    override val chats: Flow<List<Message>>
        get() = firebaseRepository.encryptedChats.map { list ->
            list.map {
                val loggedInUser = getCurrentUserData()
                val receiver = it.to
                val decryptionSecretKey =
                    if (receiver == loggedInUser.user.uid) RSAUtils.decrypt(
                        it.secretKey,
                        loggedInUser.privateKey
                    ) else loggedInUser.secretKey

                val decryptedText = AESUtils.decrypt(it.content, decryptionSecretKey)

                Message(
                    from = it.from,
                    to = it.to,
                    timestamp = it.timestamp,
                    content = decryptedText,
                )
            }.sortedByDescending { it.timestamp }
        }

    override val users: Flow<List<User>>
        get() = firebaseRepository.users.map { list ->
            val filteredList = list.filter {
                it.uid != getCurrentUser().uid
            }
            return@map filteredList
        }

    override val firebaseAuth: FirebaseAuth
        get() = firebaseRepository.auth
}