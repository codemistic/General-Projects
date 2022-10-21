package me.siddheshkothadi.chat.utils

import android.util.Base64
import java.nio.charset.StandardCharsets
import java.security.Key
import javax.crypto.Cipher
import javax.crypto.KeyGenerator
import javax.crypto.spec.IvParameterSpec
import javax.crypto.spec.SecretKeySpec

object AESUtils {
    private val cipher = Cipher.getInstance("AES/CBC/PKCS5Padding")
    private val keyGenerator = KeyGenerator.getInstance("AES")

    init {
        keyGenerator.init(128)
    }

    fun encrypt(text: String, keyStr: String): String {
        val secretKeySpec = generateKeySpec(keyStr)
        cipher.init(Cipher.ENCRYPT_MODE, secretKeySpec, IvParameterSpec(ByteArray(16)))

        return Base64.encodeToString(
            cipher.doFinal(text.toByteArray(StandardCharsets.UTF_8)),
            Base64.DEFAULT
        )
    }

    fun decrypt(encryptedText: String, keyStr: String): String {
        val secretKeySpec = generateKeySpec(keyStr)
        cipher.init(Cipher.DECRYPT_MODE, secretKeySpec, IvParameterSpec(ByteArray(16)))

        return String(cipher.doFinal(Base64.decode(encryptedText, Base64.DEFAULT)))
    }

    fun getSecretKey(): String {
        val secretKey = keyGenerator.generateKey()
        return keyToEncodedString(secretKey)
    }

    private fun keyToEncodedString(key: Key): String {
        return Base64.encodeToString(key.encoded, Base64.DEFAULT)
    }

    private fun generateKeySpec(keyStr: String): SecretKeySpec {
        return SecretKeySpec(Base64.decode(keyStr, Base64.DEFAULT), "AES")
    }
}