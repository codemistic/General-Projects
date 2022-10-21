package me.siddheshkothadi.chat.utils

import android.util.Base64
import java.nio.charset.StandardCharsets
import java.security.*
import java.security.spec.PKCS8EncodedKeySpec
import java.security.spec.X509EncodedKeySpec
import javax.crypto.Cipher

object RSAUtils {
    private val cipher = Cipher.getInstance("RSA/ECB/OAEPWithSHA1AndMGF1Padding")
    private val keyFactory: KeyFactory = KeyFactory.getInstance("RSA")
    private val keyPairGenerator: KeyPairGenerator = KeyPairGenerator.getInstance("RSA")

    fun encrypt(text: String, publicStr: String): String {
        val publicKey = generatePublicKey(publicStr)
        cipher.init(Cipher.ENCRYPT_MODE, publicKey)
        val encryptedBytes = cipher.doFinal(text.toByteArray(StandardCharsets.UTF_8))
        return Base64.encodeToString(encryptedBytes, Base64.DEFAULT)
    }

    fun decrypt(result: String?, privateStr: String): String {
        val privateKey = generatePrivateKey(privateStr)
        cipher.init(Cipher.DECRYPT_MODE, privateKey)
        val decryptedBytes = cipher.doFinal(Base64.decode(result, Base64.DEFAULT))
        return String(decryptedBytes)
    }

    private fun generatePrivateKey(privateStr: String): PrivateKey {
        val privateKeySpec = PKCS8EncodedKeySpec(Base64.decode(privateStr, Base64.DEFAULT))
        return keyFactory.generatePrivate(privateKeySpec)
    }

    private fun generatePublicKey(publicStr: String): PublicKey {
        val pubKeySpec = X509EncodedKeySpec(Base64.decode(publicStr, Base64.DEFAULT))
        return keyFactory.generatePublic(pubKeySpec)
    }

    fun getKeyPair(): Pair<String, String> {
        val keyPair = keyPairGenerator.generateKeyPair()
        val publicKey = keyToEncodedString(keyPair.public)
        val privateKey = keyToEncodedString(keyPair.private)

        return Pair(publicKey, privateKey)
    }

    private fun keyToEncodedString(key: Key): String {
        return Base64.encodeToString(key.encoded, Base64.DEFAULT)
    }
}